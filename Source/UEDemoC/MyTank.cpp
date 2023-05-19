// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTank.h"

#include "MyTankTrackMeshComponent.h"

// Sets default values
AMyTank::AMyTank()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	//UStaticMesh* TurretSM = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(),NULL,TEXT("Turret"),
	//                                                           TEXT("/Game/Assets/TMPRES/Tank/tank_fbx_Barrel")));

	//static ConstructorHelpers::FObjectFinder<UStaticMesh> TurretSM(TEXT("StaticMesh '/Game/Assets/TMPRES/Tank/tank_fbx_Barrel'"));
	//UStaticMeshComponent::SetStaticMesh(TurretSM.Object);

	// Root = CreateDefaultSubobject<UBoxComponent>("Root");
	// Root->SetSimulatePhysics(true);
	// Root->SetEnableGravity(true);
	// Root->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	// SetRootComponent(Root);
	
	Body = CreateDefaultSubobject<UStaticMeshComponent>("Body");
	//Body->SetupAttachment(Root);
	Body->SetStaticMesh(Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr,
	                                                       TEXT(
		                                                       "StaticMesh'/Game/Assets/TMPRES/Tank/tank_fbx_Body.tank_fbx_Body'"))));
	SetRootComponent(Root);
	
	Turret = CreateDefaultSubobject<UStaticMeshComponent>("Turret");
	//Turret->SetupAttachment(Body,TEXT("Turret"));
	Turret->AttachToComponent(Body, FAttachmentTransformRules::SnapToTargetIncludingScale,TEXT("Turret"));
	Turret->SetStaticMesh(Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), nullptr,
	                                                         TEXT(
		                                                         "StaticMesh'/Game/Assets/TMPRES/Tank/tank_fbx_Turret.tank_fbx_Turret'"))));


	Barrel= CreateDefaultSubobject<UStaticMeshComponent>("Barrel");
	Barrel->AttachToComponent(Turret, FAttachmentTransformRules::SnapToTargetIncludingScale,TEXT("Barrel"));
	Barrel->SetStaticMesh(Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(),nullptr,TEXT("StaticMesh'/Game/Assets/TMPRES/Tank/tank_fbx_Barrel.tank_fbx_Barrel'"))));


	LTrack = CreateDefaultSubobject<UMyTankTrackMeshComponent>("LTrack");
	LTrack->SetStaticMesh(Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(),nullptr,TEXT("StaticMesh'/Game/Assets/TMPRES/Tank/tank_fbx_Track.tank_fbx_Track'"))));
	LTrack->AttachToComponent(Body, FAttachmentTransformRules::SnapToTargetIncludingScale,TEXT("Left Track"));

	RTrack = CreateDefaultSubobject<UMyTankTrackMeshComponent>("RTrack");
	RTrack->SetStaticMesh(Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(),nullptr,TEXT("StaticMesh'/Game/Assets/TMPRES/Tank/tank_fbx_Track.tank_fbx_Track'"))));
	RTrack->AttachToComponent(Body, FAttachmentTransformRules::SnapToTargetIncludingScale,TEXT("Right Track"));

}

// Called when the game starts or when spawned
void AMyTank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float AMyTank::GetHPPercent()
{
	return (float)CurHP / MaxHP;
}
