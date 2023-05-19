// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTankTrackMeshComponent.h"

void UMyTankTrackMeshComponent::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UMyTankTrackMeshComponent::OnHit);
}

void UMyTankTrackMeshComponent::OnHit(UPrimitiveComponent* HitComponent, AActor* OhterActor,
                                      UPrimitiveComponent* OtherComponent, FVector NormalImpluse, const FHitResult& Hit)
{

	// UPrimitiveComponent* root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	//
	//
	// FVector force = throttle * GetForwardVector() * maxForce;
	//
	// //FVector location = GetSocketLocation(FName("ForceLocation"));
	// FVector location =GetComponentLocation();
	// GEngine->AddOnScreenDebugMessage(-1, 0.2, FColor::Green, location.ToString());
	//
	// root->AddForceAtLocation(force, location);
	//
	//
	// GEngine->AddOnScreenDebugMessage(-1, 0.2, FColor::Yellow, force.ToString());

	// float SideSpeed = FVector::DotProduct(root->GetRightVector(), root->GetComponentVelocity());
	// float accelerate = SideSpeed / GetWorld()->DeltaTimeSeconds * -1;
	// FVector finalForce = root->GetMass() * accelerate * GetRightVector() / 2;
	// root->AddForce(finalForce);
	//
	// throttle = 0;
	auto ForceApplied = GetForwardVector() * throttle * maxForce;
	auto ForceLocation = GetSocketLocation(FName("ForceLocation"));
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);

	auto RootComponent = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	auto TankVelocity = RootComponent->GetComponentVelocity();
	auto RightVector = RootComponent->GetRightVector();
	auto SideSpeed = FVector::DotProduct(TankVelocity, RightVector);
	float DeltaTime = GetWorld()->DeltaTimeSeconds;
	auto Acce = SideSpeed / DeltaTime * (-1);
	//F= m*a
	auto CorrectForce = RootComponent->GetMass()* Acce * GetRightVector() / 2;
	RootComponent->AddForce(CorrectForce);

	throttle = 0;
}

void UMyTankTrackMeshComponent::SetThrottle(float param)
{
	throttle = FMath::Clamp<float>(throttle + param, -1, 1);
}
