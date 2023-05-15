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
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, TEXT("OnHit"));
	FVector force = throttle * GetForwardVector() * maxForce;
	FVector location = GetSocketLocation(FName("ForceLocation"));
	UPrimitiveComponent* root = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	root->AddForceAtLocation(force, location);

	float SideSpeed = FVector::DotProduct(root->GetComponentVelocity(), root->GetRightVector());
	float accelerate = SideSpeed / GetWorld()->DeltaTimeSeconds * -1;
	FVector finalForce=root->GetMass()*accelerate*GetRightVector()/2;
	root->AddForce(finalForce);
}

void UMyTankTrackMeshComponent::SetThrottle(float param)
{
	throttle = FMath::Clamp<float>(throttle + param, -1, 1);
}
