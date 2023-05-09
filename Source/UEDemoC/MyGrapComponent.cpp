// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGrapComponent.h"

#include <string>

#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
UMyGrapComponent::UMyGrapComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyGrapComponent::BeginPlay()
{
	Super::BeginPlay();

	Handle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	check(Handle!=nullptr);

	Input = GetOwner()->FindComponentByClass<UInputComponent>();
	check(Input!=nullptr);


	//static ConstructorHelpers::FClassFinder<AActor> WeaponBaseClass(TEXT("Blueprint'/Game/Assets/BP/B_3P_C'"));
	//AActor* tmpChild = GetOwner()->FindComponentByClass<UChildActorComponent>()->GetChildActor();
	UChildActorComponent* tmpChild = Cast<UChildActorComponent>(GetOwner()->GetDefaultSubobjectByName(TEXT("Weapon_1P_Actor")));
	//UE_LOG(LogTemp, Error, TEXT("%s"), *(tmpChild->GetClass()->GetName()));
	UE_LOG(LogTemp, Error, TEXT("%s"), *(tmpChild->GetName()));


	//Arrow = Cast<>;
	//check(Arrow!=nullptr);

	// float f = 0;
	// UFloatProperty* fp = FindField<UFloatProperty>(tmpChild->GetClass(), "NewVar_0");
	// f = fp->GetPropertyValue_InContainer(tmpChild);
	// FString s = FString::SanitizeFloat(f);
	// UE_LOG(LogTemp, Error, TEXT("%s"), *(s));

	Arrow = tmpChild->GetChildActor()->FindComponentByClass<UArrowComponent>();
	UE_LOG(LogTemp, Error, TEXT("%s"), *(Arrow->GetName()));

}


// Called every frame
void UMyGrapComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (UGameplayStatics::GetPlayerController(GetWorld(), 0)->WasInputKeyJustPressed(FKey("E")))
	{
		Grap();
		bIsHolding = true;
	}
	if (UGameplayStatics::GetPlayerController(GetWorld(), 0)->WasInputKeyJustReleased(FKey("E")))
	{
		Release();
		bIsHolding = false;
	}
	if (Handle->GrabbedComponent)
	{
		//Handle->SetTargetLocation(GetOwner()->GetActorLocation() + GetOwner()->GetActorRotation().Vector() * 1000);
		Handle->SetTargetLocation(Arrow->GetComponentLocation() + Arrow->GetComponentRotation().Vector() * 100);
	}
}

void UMyGrapComponent::Grap()
{
	FHitResult hit;
	FVector start;
	FRotator startRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(start, startRotation);

	FVector end;
	end = start + startRotation.Vector() * 200;

	FCollisionQueryParams cp(FName(TEXT("tmp")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(hit, start, end,
	                                        FCollisionObjectQueryParams(ECollisionChannel::ECC_Pawn),
	                                        cp);
	if (hit.GetActor())
	{
		DrawDebugLine(GetWorld(), start, end, FColor::Blue, false, 0.5f);

		check(Handle!=nullptr);
		//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow, hit.GetActor()->GetName());
		UE_LOG(LogTemp, Error, TEXT("%s Get hit"), *(hit.GetActor())->GetName());
		Handle->GrabComponentAtLocation(hit.GetComponent(), NAME_None, hit.Location);
	}
}

void UMyGrapComponent::Release()
{
	check(Handle!=nullptr);
	Handle->ReleaseComponent();
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Yellow,TEXT("Release"));
}

void UMyGrapComponent::RayCast()
{
}
