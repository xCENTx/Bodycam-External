#include "Unreal_functions.h"



FVector UnrealHelpers::ToVector(FRotator rotator)
{
    static float UROTTORAD = M_PI / 180.f;

    float pitch = rotator.Pitch * UROTTORAD;
    float yaw = rotator.Yaw * UROTTORAD;
    float roll = rotator.Roll * UROTTORAD;

    float cosPitch = cos(pitch);
    float sinPitch = sin(pitch);
    float cosYaw = cos(yaw);
    float sinYaw = sin(yaw);

    return FVector{ cosPitch * cosYaw, cosPitch * sinYaw, sinPitch };
}

FVector UnrealHelpers::SubtractVector(FVector a, FVector b)
{
    return FVector{ a.X - b.X, a.Y - b.Y, a.Z - b.Z };
}

float UnrealHelpers::DotProduct(FVector a, FVector b)
{
    return a.X * b.X + a.Y * b.Y + a.Z * b.Z;
}

void UnrealHelpers::GetAxes(FRotator r, FVector& x, FVector& y, FVector& z)
{
    x = ToVector(r);
    r.Yaw += 90.f;
    FRotator r2 = r;
    r2.Pitch = 0;
    y = ToVector(r2);
    y.Z = 0.0f;
    r.Yaw -= 90.f;
    r.Pitch += 90.f;
    z = ToVector(r);
}

bool UnrealHelpers::TransformWorldToScreen(FCameraCacheEntry CameraView, FVector WorldLocation, FVector2D& Screen2D, FVector2D cxSize, bool isRelative)
{
    //  Get Camera Information
    FRotator camRotation{};
    FVector vAxisX, vAxisY, vAxisZ, vDelta, vTransformed, camLocation;
    camLocation = CameraView.POV.Location;
    camRotation = CameraView.POV.Rotation;
    GetAxes(camRotation, vAxisX, vAxisY, vAxisZ);

    //  Calculate Transformed Position
    vDelta = SubtractVector(WorldLocation, camLocation);
    vTransformed.X = DotProduct(vDelta, vAxisY);
    vTransformed.Y = DotProduct(vDelta, vAxisZ);
    vTransformed.Z = DotProduct(vDelta, vAxisX);
    if (vTransformed.Z < 1.00f)
    {
        if (isRelative)
            return false;

        vTransformed.Z = 1.00f;
    }

    //  Get Screen & FOV
    float mFOV = CameraView.POV.Fov;
    FVector2D center = { cxSize.X * .5f, cxSize.Y * .5f };

    //  Transform to Screen Space
    Screen2D.X = center.X + vTransformed.X * (center.X / tanf(mFOV * M_PI / 360.f)) / vTransformed.Z;
    Screen2D.Y = center.Y - vTransformed.Y * (center.X / tanf(mFOV * M_PI / 360.f)) / vTransformed.Z;

    //  Within camera view
    if (isRelative && Screen2D.X <= 0.0f || Screen2D.Y <= 0.0f || Screen2D.X > cxSize.X || Screen2D.Y > cxSize.Y)
        return false;

    return true;
}

//  bool UnrealHelpers::TransformWorldToScreen(FVector WorldLocation, FVector2D* screen2D, bool isRelative)
//  {
//      // Get Variables
//      auto szScreen = g_GameInfo->GameWindowSize();
//      auto camera_view = g_GameInfo->CameraView();
//      auto isADS = g_GameInfo->IsADS();
//      auto zoom_scale = g_GameInfo->GetScopeZoomScale();
//  
//      if (isADS)
//      {
//          //  Camera FWD
//          FVector cam_fwd = GetForwardDirection(camera_view.POV.Rotation);
//          cam_fwd *= zoom_scale;
//          camera_view.POV.Location += cam_fwd;
//          //  camera_view.POV.Fov /= zoom_scale;
//      }
//  
//      return TransformWorldToScreen(camera_view, WorldLocation, *screen2D, { szScreen.x, szScreen.y }, isRelative);
//  }