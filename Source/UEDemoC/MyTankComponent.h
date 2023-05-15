// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyTankComponent.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UEDEMOC_API UMyTankComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMyTankComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UStaticMeshComponent* TurretSM;
	UStaticMeshComponent* BarrelSM;
	UStaticMeshComponent* BodySM;

	//AMyTank* tankIns;


	void AimAt(FVector position);

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector ProStartPositon;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector ProEndPositon;

	void TurnTurret();
	void TurnBarrel();


	// void Tick(float DeltaSeconds) override;

	//virtual void SetPawn(APawn* InPawn) override;


	void AimToTarget();
	FVector TargetPosition;

	bool GetRayHitLocation(FVector& outVector);
	bool GetLookHitRotation(FVector direction,FVector& outVector);
};
