// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankTurretComponent.h"

UMyTankTurretComponent::UMyTankTurretComponent()
{
	//UStaticMesh* TurretSM = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(),NULL,TEXT("Turret"),
	//                                                           TEXT("/Game/Assets/TMPRES/Tank/tank_fbx_Barrel")));



	static ConstructorHelpers::FObjectFinder<UStaticMesh> TurretSM(TEXT("StaticMesh '/Game/Assets/TMPRES/Tank/tank_fbx_Barrel'"));
	UStaticMeshComponent::SetStaticMesh(TurretSM.Object);
	UE_LOG(LogTemp,Error,TEXT("MESH"));
}
