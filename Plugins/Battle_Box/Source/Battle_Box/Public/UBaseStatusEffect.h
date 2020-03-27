// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UBaseStatusEffect.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category= "Status_Effect")
class BATTLE_BOX_API UBaseStatusEffect : public UObject
{
	GENERATED_BODY()
public:
	///Effect's name 
	UPROPERTY(EditAnywhere, Category = "Status_Effect")
		FString effectName;
	///Effects's given value, used for any additional methods or as a default status
	UPROPERTY(EditAnywhere, Category = "Status_Effect")
		float effectValue;
	///Effect's given multiplier, used for any additional methods or as a default status
	UPROPERTY(EditAnywhere, Category = "Status_Effect")
		float effectMultipler;
	///This is the discription of the effect
	UPROPERTY(EditAnywhere, Category = "Status_Effect")
		FString effectDiscription;
	///This is a callback method for any methods given to the derived class;
	UFUNCTION(BlueprintCallable)
		virtual void CallEffect() PURE_VIRTUAL(UBaseStatusEffect::CallEffect, ;);
};
	
