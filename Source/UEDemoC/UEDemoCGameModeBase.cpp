// Copyright Epic Games, Inc. All Rights Reserved.


#include "UEDemoCGameModeBase.h"

void AUEDemoCGameModeBase::StartPlay()
{
	Super::StartPlay();

	check(GEngine!=nullptr);

	GEngine->AddOnScreenDebugMessage(-1,10,FColor::Yellow,TEXT("HW"));
}
