// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "MyTankNavMovementComponent.generated.h"

/**
 * 
 */
class UMyTankTrackMeshComponent;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UEDEMOC_API UMyTankNavMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:
	UMyTankTrackMeshComponent* LTrack;
	UMyTankTrackMeshComponent* RTrack;
	UStaticMeshComponent* BodySM;


	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void MoveForward(float throttle);
	UFUNCTION(BlueprintCallable)

	void TurnRight(float throttle);

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

};
