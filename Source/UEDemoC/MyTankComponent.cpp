// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankComponent.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMyTankComponent::UMyTankComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyTankComponent::BeginPlay()
{
	Super::BeginPlay();
	TurretSM = Cast<UStaticMeshComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("Turret")));
	BarrelSM = Cast<UStaticMeshComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("Barrel")));
	BodySM = Cast<UStaticMeshComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("Body")));
	//UE_LOG(LogTemp, Error, TEXT("%s"), *TurretSM->GetName());
	//UE_LOG(LogTemp, Error, TEXT("%s"), *BarrelSM->GetName());
	//UE_LOG(LogTemp, Error, TEXT("%s"), *BodySM->GetName());
}


// Called every frame
void UMyTankComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UMyTankComponent::AimAt(FVector position)
{
	FVector FireVec;
	FVector StartLocation = BarrelSM->GetSocketLocation("Projectile");
	bool isValid = false;
	isValid = UGameplayStatics::SuggestProjectileVelocity(this, FireVec, StartLocation, position, 2000, false, 0, 0,
	                                                      ESuggestProjVelocityTraceOption::DoNotTrace);

	ProStartPositon = StartLocation;
	ProEndPositon = position;
	if (isValid)
	{
		//TurnTurret();
		TurnBarrel();
	}
}

void UMyTankComponent::TurnTurret()
{
	FRotator startRotate = TurretSM->GetForwardVector().Rotation();
	FRotator endRotate = (ProEndPositon - ProStartPositon).Rotation();
	float delta = endRotate.Yaw - startRotate.Yaw;
	if (delta > 180)
	{
		delta -= 360;
	}
	else if (delta < -180)
	{
		delta += 360;
	}
	float turnSpeed = FMath::Clamp<float>(delta, -1, 1);
	float turnDelta = turnSpeed * 10 * GetWorld()->DeltaTimeSeconds;
	float newRotate = turnDelta + startRotate.Yaw;
	TurretSM->SetWorldRotation(FRotator(startRotate.Pitch, newRotate, startRotate.Roll));
}

void UMyTankComponent::TurnBarrel()
{
	FRotator startRotate = BarrelSM->GetForwardVector().Rotation();
	FRotator endRotate = (ProEndPositon - ProStartPositon).Rotation();
	float delta = endRotate.Pitch - startRotate.Pitch;
	float turnSpeed = FMath::Clamp<float>(delta, -1, 1);
	float turnDelta = turnSpeed * 10 * GetWorld()->DeltaTimeSeconds;
	float newRotate = turnDelta + startRotate.Pitch;

	newRotate=newRotate-TurretSM->GetForwardVector().Rotation().Pitch;
	newRotate = FMath::Clamp<float>(newRotate, -30, 30);
	BarrelSM->SetRelativeRotation(FRotator(newRotate, 0, 0));
}
