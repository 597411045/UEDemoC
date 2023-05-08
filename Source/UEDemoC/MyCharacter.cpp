// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
//#include "Runtime/Engine/Classes/Components/CapsuleComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CCameraCompo=CreateDefaultSubobject<UCameraComponent>(TEXT("CCameraCompo"));
	check(CCameraCompo!=nullptr);
	CCameraCompo->SetupAttachment(CastChecked<USceneComponent,UCapsuleComponent>(GetCapsuleComponent()));
	//CCameraCompo->bUsePawnControlRotation=true;


	CSkeMeshCompo=CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CSkeMeshCompo"));
	check(CSkeMeshCompo!=nullptr);
	CSkeMeshCompo->SetupAttachment(CastChecked<USceneComponent,UCapsuleComponent>(GetCapsuleComponent()));
	//CSkeMeshCompo->SetOnlyOwnerSee(true);
	//CSkeMeshCompo->bCastDynamicShadow=false;
	//CSkeMeshCompo->CastShadow=false;
	//CSkeMeshCompo->SetOwnerNoSee(true);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(GEngine != nullptr);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow,TEXT("Chara Begin Play"));

	CCameraCompo->SetRelativeLocation(FVector(-7.864304,-0.000015,60.000000));
	//CSkeMeshCompo->AttachToComponent(CastChecked<USceneComponent,UCapsuleComponent>(GetCapsuleComponent()),FAttachmentTransformRules(EAttachmentRule::SnapToTarget,true));

}
// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AMyCharacter::StartJimp);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AMyCharacter::StopJump);

	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Yellow,TEXT("SetupPlayerInputComponent"));
}

void AMyCharacter::MoveForward(float value)
{
	FVector DX;
	FVector DY;
	FVector DZ;
	FRotationMatrix(Controller->GetControlRotation()).GetScaledAxes(DX, DY, DZ);
	AddMovementInput(DX, value);
}

void AMyCharacter::MoveRight(float value)
{
	FVector DX;
	FVector DY;
	FVector DZ;
	FRotationMatrix(Controller->GetControlRotation()).GetScaledAxes(DX, DY, DZ);
	AddMovementInput(DY, value);
}

void AMyCharacter::StartJimp()
{
	bPressedJump = true;
}

void AMyCharacter::StopJump()
{
	bPressedJump = false;
}
