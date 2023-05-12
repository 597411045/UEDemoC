// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankGameMode.h"

#include "MyTankController.h"

AMyTankGameMode::AMyTankGameMode(const FObjectInitializer& foi)
{
	static ConstructorHelpers::FClassFinder<APawn> BPClass(TEXT("Blueprint'/Game/Assets/BP/B_MyTank'"));
	DefaultPawnClass = BPClass.Class;

	PlayerControllerClass=AMyTankController::StaticClass();
}

void AMyTankGameMode::StartPlay()
{
	
	
	Super::StartPlay();

	check(GEngine!=nullptr);

	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow,TEXT("Tank"));

	
}