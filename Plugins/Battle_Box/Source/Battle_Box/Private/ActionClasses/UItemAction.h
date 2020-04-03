// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "UItemAction.generated.h"

USTRUCT()
struct BATTLE_BOX_API FItemAction_Info
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	ITEMTYPE type;
	UPROPERTY()
	uint32 value;
	UPROPERTY()
	TArray<UAbilityAction*> effectList;
	UPROPERTY()
	TMap<FString, float> statModMap;
	UPROPERTY()
	DAMAGETYPE damageType;
};


UCLASS()
class BATTLE_BOX_API UItemAction : public UBaseAction
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FItemAction_Info itemInfo;
};
