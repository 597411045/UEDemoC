// Copyright Epic Games, Inc. All Rights Reserved.


#include "UEDemoCGameModeBase.h"

#include "MyCharacter.h"

AUEDemoCGameModeBase::AUEDemoCGameModeBase(const FObjectInitializer& foi)
{
	static ConstructorHelpers::FClassFinder<AMyCharacter> BPClass(TEXT("Blueprint'/Game/Assets/BP/B_3P_C'"));
	DefaultPawnClass = BPClass.Class;

}

void AUEDemoCGameModeBase::StartPlay()
{
	
	Super::StartPlay();

	check(GEngine!=nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow,TEXT("3C"));
	
}
