// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MyTankTurretComponent.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent))
class UEDEMOC_API UMyTankTurretComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UMyTankTurretComponent();
	
};
