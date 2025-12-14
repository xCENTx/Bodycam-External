#include "Memory64.h"

__int64 Memory::ReadPtr(const HANDLE hProc, const __int64 ptr, const std::vector<unsigned int> offsets = {})
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