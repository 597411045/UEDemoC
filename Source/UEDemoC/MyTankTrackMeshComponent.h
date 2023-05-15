// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MyTankTrackMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UEDEMOC_API UMyTankTrackMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OhterActor, UPrimitiveComponent* OtherComponent,
	           FVector NormalImpluse, const FHitResult& Hit);

	UFUNCTION(BlueprintCallable)
	void SetThrottle(float param);

	UPROPERTY(BlueprintReadWrite)
	float throttle = 0;
	float maxForce = 1;
};
