// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorWistComponent.h"

#include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UDoorWistComponent::UDoorWistComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoorWistComponent::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> alls;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AActor::StaticClass(),alls);
	for (int i = 0; i < alls.Num(); i++)
	{
		FString a=alls[i]->GetName();

		if(alls[i]->GetName().Contains(TEXT("TriggerVolume")))
		{
			BoxVolume =Cast<ATriggerVolume>( alls[i]);
			break;
		}
	}
}


// Called every frame
void UDoorWistComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                       FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (GetTotalMass() > MaxMass)
	{
		OnOpen.Broadcast();
	}
	else
	{
		OnClose.Broadcast();
	}
}

float UDoorWistComponent::GetTotalMass()
{
	float TotalMass = 0;
	TArray<AActor*> TmpItems;

	check(BoxVolume!=nullptr);
	BoxVolume->GetOverlappingActors(TmpItems);

	for (int i = 0; i < TmpItems.Num(); i++)
	{
		TotalMass += TmpItems[i]->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Error, TEXT("%f"), TotalMass);
	}

	return TotalMass;
}
