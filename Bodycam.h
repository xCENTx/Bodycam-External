#pragma once
#include "Unreal_Functions.h"

namespace Bodycam
{
    namespace Offsets
    {
        /*
            //  https://www.unknowncheats.me/forum/4103165-post1.html
            -- 
        */

        constexpr auto GWorld = 0x879A378;  //  48 8B 1D ? ? ? ? 48 85 DB 74 ? 41 B0

        namespace World
        {
            constexpr auto PersistentLevel = 0x30;      //  ULevel
            constexpr auto AuthorityGameMode = 0x0150;  //  AGameMode
            constexpr auto GameState = 0x0158;          //  AGameStateBase
            constexpr auto Levels = 0x170;              //  TArray<ULevel*>
            constexpr auto OwningGameInstance = 0x01B8; //  UGameInstance
        }

        namespace Level
        {
            constexpr auto Actors = 0x98;   //  TArray<AActor*>
        }

        namespace GameMode
        {

        }

        namespace GameStateBase
        {
            constexpr auto AuthorityGameMode = 0x0298;    //  AGameModeBAse
            constexpr auto PlayerArray = 0x02A8;          // TArray<APlayerState*>
        }

        namespace GameInstance
        {
            constexpr auto LocalPlayers = 0x0038;    //  TArray<ULocalPlayer*>
        }

        namespace UPlayer
        {
            constexpr auto PlayerController = 0x0030;    //  APlayerController
            constexpr auto ViewportClient = 0x0078;    //  UGameViewportClient
        }

        namespace Actor
        {
            constexpr auto Instigator = 0x0180; //  APawn
            constexpr auto RootComponent = 0x0198; //  USceneComponent
        }

        namespace Controller
        {
            using namespace Actor;

            constexpr auto PlayerState = 0x0298;            //  APlayerState
            constexpr auto Pawn = 0x02D0;                   //  APawn
            constexpr auto Character = 0x02E0;              //  ACharacter
            constexpr auto TransformComponent = 0x02E8;     //  USceneComponent
            constexpr auto Player = 0x0330;                 //  UPlayer
            constexpr auto AcknowledgedPawn = 0x0338;       //  APawn
            constexpr auto PlayerCameraManager = 0x0348;    //  APlayerCameraManager
        }

        namespace Pawn
        {
            using namespace Actor;

            constexpr auto PlayerState = 0x02B0;    //  APlayerState
            constexpr auto Controller = 0x0C8;    //  AController
            //  constexpr auto Name = 0x368;            //   FString : only visible for other pawns. not local player
        }

        namespace PlayerState
        {
            using namespace Actor;

            constexpr auto PawnPrivate = 0x0308;    //  APawn
            constexpr auto PlayerNamePrivate = 0x388;   //  wchar_t*
        }

        namespace Character
        {
            using namespace Pawn;

            constexpr auto Mesh = 0x0318;    //  USkeletalMeshComponent
            constexpr auto CharacterMovement = 0x0320;    //  UCharacterMovementComponent
        }

        namespace APlayerCameraManager
        {
            constexpr auto PCOwner = 0x02A0;    //  APlayerController
            constexpr auto TransformComponent = 0x02A8;    //  USceneComponent
            constexpr auto DefaultFOV = 0x02B8;    //  float
            constexpr auto DefaultOrthoWidth = 0x02C0;    //  float
            constexpr auto DefaultAspectRatio = 0x02C8;    //  float
            constexpr auto CameraCachePrivate = 0x1320;    //  FCameraCacheEntry
            constexpr auto LastFrameCameraCachePrivate = 0x1AF0;    //  FCameraCacheEntry
        }

        namespace USceneComponent
        {
            constexpr auto RelativeLocation = 0x0128;    //  FVector
            constexpr auto RelativeRotation = 0x0140;    //  FRotator
            constexpr auto RelativeScale3D = 0x0158;    //  FVector
            constexpr auto ComponentVelocity = 0x0170;    //  FVector
        }

        namespace USkeletalMeshComponent
        {
            constexpr auto ComponentToWorld = 0x0240;    //  FTransform
            constexpr auto BoneArray = 0x0610;    //  TArray<FTransform>
        }

    }

    //  AMFGGameCharacter
    struct GZCharacter
    {
        ACharacter ACharacter;	//0x0000
        char pad_0680[146];	//0x0680
        bool WantsAiming;	//0x0712
        char pad_0713[1];	//0x0713
        float CurrentADSTime;	//0x0714
        bool WeaponDown;	//0x0718
        char pad_0719[3];	//0x0719
        float WeaponReadyTime;	//0x071C
        char pad_0710[80];	//0x0720
        unsigned char TeamID;	//0x0770
        char pad_0771[95];	//0x0771
        __int64 HealthSystem;	//0x07D0
        char pad_07D8[224];	//0x07D8
        __int64 HelicopterInfo;	//0x08B8
        char pad_08D0[864];	//0x08D0
        bool IsBodyProtected;	//0x0C30
        bool IsHeadProtected;	//0x0C31
        bool IgnoreFriendlyDamage;	//0x0C32
        bool IgnorePlayerDamage;	//0x0C33
        char pad_0C34[177];	//0x0C34
        bool isAI;	//0x0CE5
        char pad_0CE6[10];	//0x0CE6
        bool isDead;	//0x0CF0
        char pad_0CF1[1];	//0x0CF1
        bool isRelaxed;	//0x0CF2
        char pad_0CF3[637];	//0x0CF3
    };	//Size: 0x0F80

    enum Bones : __int32 {
        Root = 0,
        pelvis = 1,
        spine_01 = 2,
        spine_02 = 3,
        spine_03 = 4,
        clavicle_l = 5,
        upperarm_l = 6,
        lowerarm_l = 7,
        hand_l = 8,
        index_01_l = 9,
        index_02_l = 10,
        index_03_l = 11,
        index_03_l_end = 12,
        middle_01_l = 13,
        middle_02_l = 14,
        middle_03_l = 15,
        middle_03_l_end = 16,
        pinky_01_l = 17,
        pinky_02_l = 18,
        pinky_03_l = 19,
        pinky_03_l_end = 20,
        ring_01_l = 21,
        ring_02_l = 22,
        ring_03_l = 23,
        ring_03_l_end = 24,
        thumb_01_l = 25,
        thumb_02_l = 26,
        thumb_03_l = 27,
        thumb_03_l_end = 28,
        lowerarm_twist_01_l = 29,
        lowerarm_twist_01_l_end = 30,
        upperarm_twist_01_l = 31,
        upperarm_twist_01_l_end = 32,
        clavicle_r = 33,
        upperarm_r = 34,
        lowerarm_r = 35,
        hand_r = 36,
        index_01_r = 37,
        index_02_r = 38,
        index_03_r = 39,
        index_03_r_end = 40,
        middle_01_r = 41,
        middle_02_r = 42,
        middle_03_r = 43,
        middle_03_r_end = 44,
        pinky_01_r = 45,
        pinky_02_r = 46,
        pinky_03_r = 47,
        pinky_03_r_end = 48,
        ring_01_r = 49,
        ring_02_r = 50,
        ring_03_r = 51,
        ring_03_r_end = 52,
        thumb_01_r = 53,
        thumb_02_r = 54,
        thumb_03_r = 55,
        thumb_03_r_end = 56,
        lowerarm_twist_01_r = 57,
        lowerarm_twist_01_r_end = 58,
        upperarm_twist_01_r = 59,
        upperarm_twist_01_r_end = 60,
        neck_01 = 61,
        head = 62,
        head_end = 63,
        thigh_l = 64,
        calf_l = 65,
        calf_twist_01_l = 66,
        calf_twist_01_l_end = 67,
        foot_l = 68,
        ball_l = 69,
        ball_l_end = 70,
        thigh_twist_01_l = 71,
        thigh_twist_01_l_end = 72,
        thigh_r = 73,
        calf_r = 74,
        calf_twist_01_r = 75,
        calf_twist_01_r_end = 76,
        foot_r = 77,
        ball_r = 78,
        ball_r_end = 79,
        thigh_twist_01_r = 80,
        thigh_twist_01_r_end = 81,
        ik_foot_root = 82,
        ik_foot_l = 83,
        ik_foot_l_end = 84,
        ik_foot_r = 85,
        ik_foot_r_end = 86,
        ik_hand_root = 87,
        ik_hand_gun = 88,
        ik_hand_l = 89,
        ik_hand_l_end = 90,
        ik_hand_r = 91,
        ik_hand_r_end = 92,
        VB_ik_foot_l_Offset = 93,
        VB_ik_foot_r_Offset = 94,
        VB_RHS_ik_hand_gun = 95,
        VB_LHS_ik_hand_gun = 96,
        VB_RHS_ik_hand_l = 97,
        VB_LHS_ik_hand_r = 98,
        VB_ik_knee_target_l = 99,
        VB_ik_knee_target_r = 100,
        VB_Curves = 101,
        VB_foot_target_l = 102,
        VB_foot_target_r = 103,
        VB_hand_r = 104
    };

    std::vector<std::vector<int>> BoneVector
    {
        { Bones::hand_l, Bones::lowerarm_l, Bones::upperarm_l, Bones::neck_01 },            // Left hand -> neck
        { Bones::hand_r, Bones::lowerarm_r, Bones::upperarm_r, Bones::neck_01 },            // Right hand -> neck
        { Bones::ball_l, Bones::foot_l, Bones::calf_l, Bones::thigh_l, Bones::spine_01 },   // Left foot -> bottom spine
        { Bones::ball_r, Bones::foot_r, Bones::calf_r, Bones::thigh_r, Bones::spine_01 },   // Right foot -> bottom spine
        { Bones::spine_01, Bones::spine_02, Bones::neck_01, Bones::head }                   // Bottom spine -> head
    };
}