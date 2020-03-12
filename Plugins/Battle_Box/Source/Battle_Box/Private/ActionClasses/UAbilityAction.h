// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "UAbilityAction.generated.h"


USTRUCT()
struct BATTLE_BOX_API FAbilityAction_Info
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	float duration;
	UPROPERTY()
	float abilityValue;
	UPROPERTY()
	ABILITYTYPE abilityType;
	UPROPERTY()
	TMap<FString, float> modStatMap;

};



UCLASS()
class BATTLE_BOX_API UAbilityAction : public UBaseAction
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FAbilityAction_Info abilityInfo;

};
