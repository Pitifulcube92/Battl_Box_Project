// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UStatusEffect.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, Category="Battle_Box")
class BATTLE_BOX_API UStatusEffect : public UObject
{
	GENERATED_BODY()
private:
	///Actor component variable
	UPROPERTY(EditAnywhere)
		class UActorComponent* effectComponent;
public:
	///Effect's name 
	UPROPERTY(EditAnywhere)
		FString effectName;
	///This is the discription of the effect
	UPROPERTY(EditAnywhere)
		FString effectDiscription;
	///Return function for the actor component
	UFUNCTION()
		class UActorComponent* GetEffectComponent() const;
};
	
