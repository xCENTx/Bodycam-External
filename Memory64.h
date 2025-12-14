#pragma once
#include <memoryapi.h>
#include <vector>
#include <string>

struct ProcessInfo
{
	std::string pName;
	DWORD dwPID;
	__int64 lpModuleBase;

};

class Memory
{
	ProcessInfo m_pProcInfo;
	
	// TEMPLATES
public:
	template<typename T>
	T Read(const HANDLE hProcess, const __int64 addr)
	{
		T result{};
		ReadProcessMemory(hProcess, (LPVOID)addr, &result, sizeof(result), nullptr))
		return result;
	}

	template<typename T>
	bool Write(HANDLE hProc, __int64 addr, const T& value)
	{
		return WriteProcessMemory(hProc, (LPVOID)addr, &value, sizeof(value), nullptr);
	}

	__int64 ReadPtr(const HANDLE hProc, const __int64 ptr, const std::vector<unsigned int> offsets = {})
	{
		if (offsets.size() <= 0)
			return Read<__int64>(hProc, ptr);

		__int64 addr = ptr;
		for (auto offset : offsets)
		{
			addr = Read<__int64>(hProc, addr);
			addr += offset;
		}

		return addr;
	}

public:
	static DWORD GetProcessID();
	static __int64 GetModuleBase();
	static ProcessInfo GetProcessInfo(); 
	__int64 ReadPtr(const HANDLE hProc, const __int64 ptr, const std::vector<unsigned int> offsets = {});
};
