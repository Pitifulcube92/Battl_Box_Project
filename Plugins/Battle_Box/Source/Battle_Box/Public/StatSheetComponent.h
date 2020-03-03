// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "StatSheetObject.h"
#include "StatSheetComponent.generated.h"

USTRUCT(BlueprintType)
struct FStatSheetData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FString Name = "";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FString Tag = "";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		int ID = 0;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float MaxHP = 0.0f;	  
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float CurrentHP = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float MaxMP = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float CurrentMP = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float PhysicalDefence = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float PhysicalAttack = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float MagicalDefence = 0.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		float MagicalAttack = 0.0f;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_BOX_API UStatSheetComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this component's properties
	UStatSheetComponent();
	//UPROPERTY(BlueprintAssignable, EditAnywhere, BlueprintReadWrite)
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		 FStatSheetData data;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	FString ReturnName() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	FString ReturnTag() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	int ReturnID() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	float ReturnMaxHP() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	float ReturnMaxMP() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	float ReturnCurrentHP() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	float ReturnCurrentMP() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	float ReturnPhysicalAtk() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	float ReturnPysicalDefence() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	float ReturnMagicAtk() const;
	UFUNCTION(BlueprintGetter, BlueprintCallable)
	float ReturnMagicDefence() const;
};
