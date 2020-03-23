// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "UAbilityAction.generated.h"
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
	UPROPERTY(EditAnywhere)
		float duration;
	UPROPERTY(EditAnywhere)
		float abilityValue;
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
