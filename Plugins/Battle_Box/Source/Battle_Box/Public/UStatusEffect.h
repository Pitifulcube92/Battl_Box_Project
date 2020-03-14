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
	//This will show effect name
	UPROPERTY(EditAnywhere)
		FString effectName;
	UPROPERTY(EditAnywhere)
		FString effectDiscription;
	UPROPERTY(EditAnywhere)
		class UActorComponent* effectAction;
	UFUNCTION()
		void BeginEffect() const;
	UFUNCTION()
		void ActivatEffect() const;
	UFUNCTION()
		void DeactivateEffect() const;
};
