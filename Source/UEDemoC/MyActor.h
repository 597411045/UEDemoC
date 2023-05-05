// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UENUM()
enum _EnumParam
{
	E_1 = 0,
	E_2,
	E_3
};

USTRUCT(BlueprintType)
struct FStructParam :public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FString name;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int id;
};


UCLASS(Blueprintable, BlueprintType, ClassGroup="My", Config="Game",
	meta=(BlueprintSpawnableComponent))
//https://docs.unrealengine.com/5.1/en-US/class-specifiers/
class UEDEMOC_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActor();


	UPROPERTY(EditAnywhere, Category="TCategory", BlueprintReadWrite, BlueprintGetter=GetTInteger,
		BlueprintSetter=SetTInteger)
	int TInteger;
	UPROPERTY(EditAnywhere, Category="TCategory|SubCate", BlueprintReadWrite)
	uint8 TInteger1:1;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void PreInitializeComponents() override;

	virtual void PostInitializeComponents() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void BeginDestroy() override;

	UFUNCTION(BlueprintGetter)
	virtual int GetTInteger();

	UFUNCTION(BlueprintSetter)
	virtual void SetTInteger(int a);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Exec)
	FStructParam TBlueprintCallable(FStructParam param);

	UFUNCTION(Exec, BlueprintCallable, BlueprintImplementableEvent, meta=(DisplayName="TBlueprintImplementableEvent"),
		Category="Func|Sub")
	int TBlueprintImplementableEvent(_EnumParam In_EnumParam);
};
//meta=(ExpandEnumAsExecs="In_EnumParam")