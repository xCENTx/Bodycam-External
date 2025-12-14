#pragma once
#include "Unreal_structs.h"
#include "Unreal_Classes.h"

class UnrealHelpers
{
public:
    static FVector ToVector(FRotator rotator);
    static FVector SubtractVector(FVector a, FVector b);
    static float DotProduct(FVector a, FVector b);
    static void GetAxes(FRotator r, FVector& x, FVector& y, FVector& z);
    static bool TransformWorldToScreen(FCameraCacheEntry CameraView, FVector WorldLocation, FVector2D& Screen2D, FVector2D cxSize, bool isRelative);
    static bool TransformWorldToScreen(FVector WorldLocation, FVector2D* screen2D, bool isRelative);
};