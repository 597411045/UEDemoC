// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	FString str = "BeginPlay";
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Red, str);
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyActor::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	FString str = "PreInitializeComponents";
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Blue, str);
}

void AMyActor::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	FString str = "PostInitializeComponents123";
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, str);
}

void AMyActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	FString str = "EndPlay";
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, str);
}

void AMyActor::BeginDestroy()
{
	FString str = "BeginDestroy";
	GEngine->AddOnScreenDebugMessage(-1, 100, FColor::Green, str);
	Super::BeginDestroy();
}
