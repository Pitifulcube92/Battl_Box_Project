// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "UAbilityAction.generated.h"
class UBaseStatusEffect;
/************************************
*
* Ability Action Class
*
* This is a derived class that contains information
* for ability like actions. Within a Ability action,
* it conatins a mix of command action and item action like features,
* however is used for specificly for stat based
* abilities
*
* Ability Actions are uniqe because they can be used
* within a Command Action or Item Action.
*
************************************/

USTRUCT(BlueprintType)
struct BATTLE_BOX_API FAbilityAction_Info
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Ability Action")
		float duration;
	UPROPERTY(EditAnywhere, Category = "Ability Action")
		TArray<UBaseStatusEffect*> effects;
};



UCLASS(BlueprintType, Category = "Battle_Box")
class BATTLE_BOX_API UAbilityAction : public UBaseAction
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Ability Action")
		FAbilityAction_Info abilityInfo;
	UFUNCTION(BlueprintCallable)
		FAbilityAction_Info GetAbilityInfo() const;
	UFUNCTION(BlueprintCallable, Category = "Ability Action")
		void ActivateEffect() const;

};
