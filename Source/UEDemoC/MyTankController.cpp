// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankController.h"

#include "MyTankComponent.h"

// void AMyTankController::Tick(float DeltaSeconds)
// {
// 	Super::Tick(DeltaSeconds);
// 	AimToTarget();
// }
//
// void AMyTankController::SetPawn(APawn* InPawn)
// {
// 	Super::SetPawn(InPawn);
//
// 	if (InPawn)
// 	{
// 		tankIns = Cast<AMyTank>(InPawn);
// 		if (!tankIns)
// 		{
// 			UE_LOG(LogTemp, Error, TEXT("No Tank Pawn"));
// 		}
// 	}
// }

// void AMyTankController::AimToTarget()
// {
// 	if (GetRayHitLocation(TargetPosition))
// 	{
// 		tankIns->FindComponentByClass<UMyTankComponent>()->AimAt(TargetPosition);
// 	}
// }

// bool AMyTankController::GetRayHitLocation(FVector& outVector)
// {
// 	int32 ViewX, ViewY;
// 	GetViewportSize(ViewX, ViewY);
//
// 	FVector position;
// 	FVector rotation;
//
// 	DeprojectScreenPositionToWorld(ViewX * 0.5f, ViewY * 0.3f, position, rotation);
// 	return GetLookHitRotation(rotation, outVector);
// }
//
// bool AMyTankController::GetLookHitRotation(FVector direction, FVector& outVector)
// {
// 	FHitResult hitR;
// 	if (GetWorld()->LineTraceSingleByChannel(
// 		hitR,
// 		PlayerCameraManager->GetCameraLocation(),
// 		PlayerCameraManager->GetCameraLocation() + direction * 10000,
// 		ECC_Visibility
// 	))
// 	{
// 		outVector = hitR.Location;
// 		if (hitR.GetActor() != nullptr)
// 		{
// 			GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, hitR.GetActor()->GetName());
// 		}
// 		return true;
// 	}
// 	return false;
// }
