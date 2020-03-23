// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UISystemCommand.h"
#include "UItemAction_Order.generated.h"

class UItemAction;
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class BB_RUNTIME_SYSTEM_API UItemAction_Order : public UISystemCommand 
{
	GENERATED_BODY()
private:
	typedef void(UItemAction::*funcPointer)(void);
	UItemAction* action;
	funcPointer func;
public:
	UItemAction_Order();
	void Init(UItemAction* action_, funcPointer func);
	void Execute();
	~UItemAction_Order();
};
