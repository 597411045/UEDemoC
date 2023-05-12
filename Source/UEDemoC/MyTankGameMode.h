// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyTankGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UEDEMOC_API AMyTankGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AMyTankGameMode(const FObjectInitializer &foi);
	
	virtual void StartPlay() override;
};
