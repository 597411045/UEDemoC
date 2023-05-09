// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/ArrowComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "MyGrapComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class UEDEMOC_API UMyGrapComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UMyGrapComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UPhysicsHandleComponent* Handle = nullptr;

	UInputComponent* Input = nullptr;

	UArrowComponent* Arrow = nullptr;

	virtual void Grap();

	virtual void Release();

	virtual void RayCast();

	bool bIsHolding;
};
