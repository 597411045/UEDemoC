// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankNavMovementComponent.h"

#include <string>

#include "MyTankTrackMeshComponent.h"

void UMyTankNavMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	LTrack = Cast<UMyTankTrackMeshComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("LTrack")));
	RTrack = Cast<UMyTankTrackMeshComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("RTrack")));
	BodySM = Cast<UStaticMeshComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("Body")));
}


void UMyTankNavMovementComponent::MoveForward(float throttle)
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, *FString::SanitizeFloat(throttle));

	LTrack->SetThrottle(throttle);
	RTrack->SetThrottle(throttle);
}

void UMyTankNavMovementComponent::TurnRight(float throttle)
{
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, *FString::SanitizeFloat(throttle));
	LTrack->SetThrottle(throttle);
	RTrack->SetThrottle(-throttle);
}

void UMyTankNavMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	//Super::RequestDirectMove(MoveVelocity, bForceMaxSpeed);
	float ForwardThrow = FVector::DotProduct(GetOwner()->GetActorForwardVector().GetSafeNormal(),
	                                         MoveVelocity.GetSafeNormal());
	MoveForward(ForwardThrow);

	float RightThrow = FVector::CrossProduct(GetOwner()->GetActorForwardVector().GetSafeNormal(),
	                                         MoveVelocity.GetSafeNormal()).Z;
	TurnRight(RightThrow);
}
