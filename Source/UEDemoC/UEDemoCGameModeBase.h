// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "UEDemoCGameModeBase.generated.h"

/**
 * 
 */
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UEDEMOC_API AUEDemoCGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AUEDemoCGameModeBase(const FObjectInitializer &foi);
	
	virtual void StartPlay() override;
};
