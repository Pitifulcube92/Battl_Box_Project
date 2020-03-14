// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "UAbilityAction.generated.h"


USTRUCT(BlueprintType)
struct BATTLE_BOX_API FAbilityAction_Info
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere)
		float duration;
	UPROPERTY(EditAnywhere)
		float abilityValue;
	UPROPERTY(EditAnywhere)
		ABILITYTYPE abilityType;
	UPROPERTY(EditAnywhere)
		class UStatusEffect* effect;
};



UCLASS(BlueprintType, Category = "Battle_Box")
class BATTLE_BOX_API UAbilityAction : public UBaseAction
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		FAbilityAction_Info abilityInfo;
	UFUNCTION(BlueprintCallable)
		FAbilityAction_Info GetAbilityInfo() const;
	UFUNCTION(BlueprintCallable)
		void ActivateEffect() const;
};	
