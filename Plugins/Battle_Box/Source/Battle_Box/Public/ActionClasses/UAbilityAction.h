// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreMinimal.h"
#include "../Public/ActionClasses/UBaseAction.h"
#include "UAbilityAction.generated.h"


USTRUCT(BlueprintType, Category = "Battle_Box")
struct BATTLE_BOX_API FAbilityAction_Info
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	float duration;
	UPROPERTY(EditAnywhere)
	float abilityValue;
	UPROPERTY(EditAnywhere)
	ABILITYTYPE abilityType;
};



UCLASS(Blueprintable, BlueprintType, Category="Battle_Box")
class BATTLE_BOX_API UAbilityAction : public UBaseAction
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
		FAbilityAction_Info abilityInfo;
	UFUNCTION(BlueprintCallable)
		FAbilityAction_Info GetAbilityInfo() const;
};
