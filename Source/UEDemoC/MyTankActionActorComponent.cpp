// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankActionACtorComponent.h"

#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UMyTankActionActorComponent::UMyTankActionActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyTankActionActorComponent::BeginPlay()
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
void UMyTankActionActorComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	AimToTarget();

	// ...
}

void UMyTankActionActorComponent::AimAt(FVector position)
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
		TurnTurret();
		TurnBarrel();
	}
}

void UMyTankActionActorComponent::TurnTurret()
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
	//TurretSM->SetWorldRotation(FRotator(startRotate.Pitch, newRotate, startRotate.Roll));
	TurretSM->AddLocalRotation(FRotator(0,turnDelta,0));
}

void UMyTankActionActorComponent::TurnBarrel()
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

void UMyTankActionActorComponent::AimToTarget()
{
	if (GetRayHitLocation(TargetPosition))
	{
		//tankIns->FindComponentByClass<UMyTankComponent>()->AimAt(TargetPosition);
		AimAt(TargetPosition);
	}
}

bool UMyTankActionActorComponent::GetRayHitLocation(FVector& outVector)
{
	int32 ViewX, ViewY;

	GetWorld()->GetFirstPlayerController()->
	GetViewportSize(ViewX, ViewY);

	FVector position;
	FVector rotation;

	GetWorld()->GetFirstPlayerController()->
	DeprojectScreenPositionToWorld(ViewX * 0.5f, ViewY * 0.5f, position, rotation);
	return GetLookHitRotation(rotation, outVector);
}

bool UMyTankActionActorComponent::GetLookHitRotation(FVector direction, FVector& outVector)
{
	FHitResult hitR;
	if (GetWorld()->LineTraceSingleByChannel(
		hitR,
		GetWorld()->GetFirstPlayerController()->
		PlayerCameraManager->GetCameraLocation(),
		GetWorld()->GetFirstPlayerController()->
		PlayerCameraManager->GetCameraLocation() + direction * 10000,
		ECC_Visibility
	))
	{
		outVector = hitR.Location;
		if (hitR.GetActor() != nullptr)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, hitR.GetActor()->GetName());
		}
		return true;
	}
	return false;
}