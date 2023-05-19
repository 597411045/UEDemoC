// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "MyTank.generated.h"

class UMyTankTrackMeshComponent;
UCLASS()
class UEDEMOC_API AMyTank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	 UFUNCTION(BlueprintPure)
	 float GetHPPercent();
	
	 UPROPERTY(EditAnywhere,BlueprintReadWrite)
	 int MaxHP=100;
	 UPROPERTY(EditAnywhere,BlueprintReadWrite)
	 int CurHP=MaxHP;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UMyTankTrackMeshComponent* LTrack;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UMyTankTrackMeshComponent* RTrack;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* Turret;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* Barrel;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UStaticMeshComponent* Body;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBoxComponent* Root;
};
