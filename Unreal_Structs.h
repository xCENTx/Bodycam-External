#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>

struct Vector2
{
    float x, y;

    Vector2() : x(0), y(0) {}
    Vector2(float x, float y) : x(x), y(y) {}

    Vector2 operator+(const Vector2& other) const { return Vector2{ x + other.x, y + other.y }; }

    Vector2 operator-(const Vector2& other) const { return Vector2{ x - other.x, y - other.y }; }

    Vector2 operator*(float scalar) const { return Vector2{ x * scalar, y * scalar }; }

    Vector2 operator/(float scalar) const { return Vector2{ x / scalar, y / scalar }; }

    Vector2 operator=(float* other) const { return Vector2{ other[0], other[1] }; }

    Vector2& operator*=(const Vector2& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2 operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }
};  //  Size: 0x0008

struct Vector3
{
    float x, y, z;

    Vector3() : x(0), y(0), z(0) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    Vector3 operator+(const Vector3& other) const { return Vector3{ x + other.x, y + other.y, z + other.z }; }

    Vector3 operator-(const Vector3& other) const { return Vector3{ x - other.x, y - other.y, z - other.z }; }

    Vector3 operator*(float scalar) const { return Vector3{ x * scalar, y * scalar, z * scalar }; }

    Vector3 operator/(float scalar) const { return Vector3{ x / scalar, y / scalar, z / scalar }; }

    Vector3 operator=(float* other) const { return Vector3{ other[0], other[1], other[2] }; }

    Vector3& operator*=(const Vector3& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    bool IsValid()
    {
        return x == 0 && y == 0 && z == 0;
    }

    inline float Dot(Vector3 v)
    {
        return x * v.x + y * v.y + z * v.z;
    }

    inline float Distance(Vector3 v)
    {
        return float(sqrtf(powf(v.x - x, 2.0) + powf(v.y - y, 2.0) + powf(v.z - z, 2.0)));
    }

    float length(void) {
        auto sqr = [](float n) {
            return static_cast<float>(n * n);
            };

        return sqrt(sqr(x) + sqr(y) + sqr(z));
    }

    float distance_to(const Vector3& other) {
        Vector3 delta;
        delta.x = x - other.x;
        delta.y = y - other.y;
        delta.z = z - other.z;

        return delta.length();
    }

    inline float Length()
    {
        return sqrt(x * x + y * y + z * z);
    }

    Vector3 Normalize() {
        float magnitude = std::sqrt(x * x + y * y + z * z);
        Vector3 normalized;
        normalized.x = x / magnitude;
        normalized.y = y / magnitude;
        normalized.z = z / magnitude;
        return normalized;
    }

    Vector3 Cross(const Vector3& vector2)
    {
        float crossX = y * vector2.z - z * vector2.y;
        float crossY = z * vector2.x - x * vector2.z;
        float crossZ = x * vector2.y - y * vector2.x;

        return Vector3(crossX, crossY, crossZ);
    }


};  //  Size: 0x000C

struct Vector4
{
    float x, y, z, w;

    Vector4() : x(0), y(0), z(0), w(0) {}
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    Vector4 operator+(const Vector4& other) const { return Vector4{ x + other.x, y + other.y, z + other.z, w + other.w }; }

    Vector4 operator-(const Vector4& other) const { return Vector4{ x - other.x, y - other.y, z - other.z, w - other.w }; }

    Vector4 operator*(float scalar) const { return Vector4{ x * scalar, y * scalar, z * scalar, w * scalar }; }

    Vector4 operator/(float scalar) const { return Vector4{ x / scalar, y / scalar, z / scalar, w / scalar }; }

    Vector4 operator=(float* other) const { return Vector4{ other[0], other[1], other[2], other[3] }; }

    Vector4& operator*=(const Vector4& other)
    {
        x += other.x;
        y += other.y;
        z += other.z;
        w += other.w;
        return *this;
    }

    // Multiply two quaternions
    Vector4 operator* (const Vector4& other) const
    {
        return {
            w * other.x + x * other.w + y * other.z - z * other.y,
            w * other.y - x * other.z + y * other.w + z * other.x,
            w * other.z + x * other.y - y * other.x + z * other.w,
            w * other.w - x * other.x - y * other.y - z * other.z
        };
    }

    // Get the conjugate of the quaternion
    Vector4 GetConjugate() const { return { -x, -y, -z, w }; }
};  //  Size: 0x0010

struct FVector2D
{
    float X, Y;


    FVector2D()
    {
        X = 0;
        Y = 0;
    }

    FVector2D(float x, float y)
    {
        X = x;
        Y = y;
    }

    FVector2D operator+(const FVector2D& other) const { return FVector2D{ X + other.X, Y + other.Y }; }

    FVector2D operator-(const FVector2D& other) const { return FVector2D{ X - other.X, Y - other.Y }; }

    FVector2D operator*(float scalar) const { return FVector2D{ X * scalar, Y * scalar }; }

    FVector2D operator/(float scalar) const { return FVector2D{ X / scalar, Y / scalar }; }

    FVector2D operator=(float* other) const { return FVector2D{ other[0], other[1] }; }

    //  FVector2D operator=(const Vector2 other) const { return FVector2D{ other.x, other.y }; }

    //  FVector2D operator=(const ImVec2 other) const { return FVector2D{ other.x, other.y }; }

    FVector2D& operator*=(const FVector2D& other)
    {
        X += other.X;
        Y += other.Y;
        return *this;
    }


    bool IsValid() { return X == 0 && Y == 0; }
};

struct FVector
{
    double X;	//0x0000
    double Y;	//0x0008
    double Z;	//

    FVector()
    {
        X = 0;
        Y = 0;
        Z = 0;
    }

    FVector(double x, double y, double z)
    {
        X = x;
        Y = y;
        Z = z;
    }

    FVector operator+(const FVector& other) const { return FVector{ X + other.X, Y + other.Y, Z + other.Z }; }

    FVector operator-(const FVector& other) const { return FVector{ X - other.X, Y - other.Y, Z - other.Z }; }

    FVector operator*(float scalar) const { return FVector{ X * scalar, Y * scalar, Z * scalar }; }

    FVector operator/(float scalar) const { return FVector{ X / scalar, Y / scalar, Z / scalar }; }

    FVector operator=(float* other) const { return FVector{ other[0], other[1], other[2] }; }

    //  FVector operator=(const Vector3 other) const { return FVector{ other.x, other.y, other.z }; }

    FVector& operator+=(const FVector& other)
    {
        X += other.X;
        Y += other.Y;
        Z += other.Z;
        return *this;
    }

    FVector& operator*=(const FVector& other)
    {
        X *= other.X;
        Y *= other.Y;
        Z *= other.Z;
        return *this;
    }

    FVector& operator*=(const float scalar) {
        X *= scalar;
        Y *= scalar;
        Z *= scalar;
        return *this;
    }

    bool IsValid() { return X == 0 && Y == 0 && Z == 0; }


};	//Size: 0x0018

struct FRotator
{
    double Pitch;	//0x0000
    double Yaw; 	//0x0008
    double Roll;	//0x0010
};	//Size: 0x0018

struct FQuat
{
    double X;	//0x0000
    double Y;	//0x0008
    double Z;	//0x0010
    double W;	//0x0018

};	//Size: 0x0020

struct FTransform
{
    FQuat Rotation;	//0x0000
    FVector Translation;	//0x0020
    char pad_0038[8];	//0x0038
    FVector Scale3D;	//0x0040
    char pad_0058[8];	//0x0058
};	//Size: 0x0060

template <class T>
struct TArray
{
    T data;	    //0x0000
    int count;	//0x0008
    int max;	//0x000C

    __int32 Count() const;
    __int32 Max() const;
};	//Size: 0x0010

struct FString
{
    const wchar_t* data;
    int count;
    int max;
};

struct FMinimalViewInfo
{
    FVector Location;	//0x0000
    FRotator Rotation;	//0x0018
    float Fov;	//0x0030
    float DesiredFOV;	//0x0034
    float OrthoWidth;	//0x0038
    float OrthoNearClipPlane;	//0x003C
    float OrthoFarClipPlane;	//0x0040
    float PerspectiveNearClipPlane;	//0x0044
    float AspectRatio;	//0x0048
};	//Size: 0x07C0

struct FCameraCacheEntry
{
    float Timestamp;	//0x0000
    char pad_0004[12];	//0x0004
    FMinimalViewInfo POV;	//0x0010
};	//Size: 0x07D0