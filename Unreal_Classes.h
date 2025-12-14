#pragma once

class UObject
{
public:
    char pad_0000[40];	//0x0000
};	//Size: 0x0028

class UWorld : public UObject
{
    char pad_0028[8];	//0x0028
    class ULevel* PersistentLevel;	//0x0030
    char pad_0038[280];	//0x0038
    class AGameModeBase* AuthorityGameMode;	//0x0150
    class AGameStateBase* GameState;	//0x0158
    char pad_0160[32];	//0x0160
};	//Size: 0x0180

class ULevel : public UObject
{
    char pad_0028[112];	//0x0028
    TArray<class AActor*> Actors;	//0x0098
    TArray<class AActor*> JunkActors;	//0x00A8
    char pad_00B8[32];	//0x00B8
};	//Size: 0x00D8

class AActor : public UObject
{
    char pad_0028[352];	//0x0028
    class APawn* Instigator;	//0x0188
    char pad_0190[8];	//0x0190
    class USceneComponent* RootComponent;	//0x0198
    char pad_01A0[240];	//0x01A0
};	//Size: 0x0290

class AInfo : public AActor
{
};	//Size: 0x0290

class AGameModeBase : public AInfo
{
    char pad_0290[96];	//0x0290
    class AGameStateBase* GameState;	//0x02F0
    char pad_02F8[24];	//0x02F8
};	//Size: 0x0310

class AGameStateBase : public AInfo
{
    char pad_0290[8];	//0x0290
    class AGameModeBase* AuthorityGameMode;	//0x0298
    char pad_02A0[8];	//0x02A0
    TArray<class APlayerState*> PlayerArray;	//0x02A8
    char pad_02B8[48];	//0x02B8
};	//Size: 0x02E8


class UActorComponent : public UObject
{
    char pad_0028[120];	//0x0028
};	//Size: 0x00A0

class USceneComponent : public UActorComponent
{
    char pad_00A0[136];	//0x00A0
    FVector RelativeLocation;	//0x0128
    FRotator RelativeRotation;	//0x0140
    FVector RelativeScale3D;	//0x0158
    FVector ComponentVelocity;	//0x0170
};	//Size: 0x0188

class UPrimitiveComponent : public USceneComponent
{
    char pad_0188[184];	//0x0188
    FTransform ComponentToWorld;	//0x0240
    char pad_02A0[800];	//0x02A0
};	//Size: 0x05C0

class UMeshComponent : public UPrimitiveComponent
{
    char pad_05C0[56];	//0x05C0
};	//Size: 0x05F8

class USkinnedMeshComponent : public UMeshComponent
{
    char pad_05F8[8];	//0x05F8
    class USkeletalMesh* SkeletalMesh;	//0x0600
    char pad_0608[8];	//0x0608
    class TArray<FTransform> BoneArray;	//0x0610
    char pad_0620[800];	//0x0620
};	//Size: 0x0940

class USkeletalMeshComponent : public USkinnedMeshComponent
{
    char pad_0940[128];	//0x0940
};	//Size: 0x09C0

class UPlayer : public UObject
{
    char pad_0028[8];	//0x0028
    class APlayerController* PlayerController;	//0x0030
    char pad_0038[24];	//0x0038
};	//Size: 0x0050

class ULocalPlayer : public UPlayer
{
    char pad_0050[120];	//0x0050
};	//Size: 0x00C8

class AController : public AActor
{
    char pad_0290[8];	//0x0290
    class APlayerState* PlayerState;	//0x0298
    char pad_02A0[48];	//0x02A0
    class APawn* Pawn;	//0x02D0
    char pad_02D8[8];	//0x02D8
    class ACharacter* Character;	//0x02E0
    class USceneComponent* TransformComponent;	//0x02E8
    char pad_02F0[96];	//0x02F0
};	//Size: 0x0350

class APlayerController : public AController
{
    char pad_0350[128];	//0x0350
};	//Size: 0x03D0

class APlayerState : public AInfo
{
    char pad_0290[4];	//0x0290
    int PlayerID;	//0x0294
    char pad_0298[112];	//0x0298
    class APawn* PawnPrivate;	//0x0308
    char pad_0310[120];	//0x0310
    wchar_t* PlayrNamePrivate;	//0x0388
};	//Size: 0x0390


class APawn : public AActor
{
    char pad_0290[56];	//0x0290
    class AController* Controller;	//0x02C8
    char pad_02D0[72];	//0x02D0
};	//Size: 0x0318


class ACharacter : public APawn
{
    class USkeletalMeshComponent* Mesh;	//0x0318
    class UCharacterMovement* CharacterMovement;	//0x0320
    char pad_0328[112];	//0x0328
};	//Size: 0x0398
