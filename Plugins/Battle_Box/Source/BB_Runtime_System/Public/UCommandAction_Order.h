// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UISystemCommand.h"
#include "UCommandAction_Order.generated.h"

class UCommandAction;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class BB_RUNTIME_SYSTEM_API UCommandAction_Order : public UISystemCommand
{
	GENERATED_BODY()
private:
	typedef void(UCommandAction::*funcPointer)(void);
	UCommandAction* action;
	funcPointer func;
public:
	UCommandAction_Order();
	void Init(UCommandAction* action_, funcPointer func_);
	void Execute();
	~UCommandAction_Order();
};
