// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UISystemCommand.h"
#include "UAbilityAction_Order.generated.h"

class UAbilityAction;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class BB_RUNTIME_SYSTEM_API UAbilityAction_Order : public UISystemCommand 
{
	GENERATED_BODY()

private:
	typedef void(UAbilityAction::*funcPointer)(void);
	UAbilityAction* action;
	funcPointer func;
public:
	UAbilityAction_Order();
	void Init(UAbilityAction* action_, funcPointer func);
	void Execute();
	~UAbilityAction_Order();
};
