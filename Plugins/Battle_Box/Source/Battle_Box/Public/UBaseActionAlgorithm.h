// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UBaseActionAlgorithm.generated.h"
class UStatSheetObject;
/**
 *
 */
UCLASS(Abstract, Blueprintable)
class BATTLE_BOX_API UBaseActionAlgorithm : public UObject
{
	GENERATED_BODY()
private:
	UStatSheetObject* target;
public:
	UFUNCTION(BlueprintCallable, Category = "Action Algorithm")
		virtual void CallAlgorithm() PURE_VIRTUAL(UBaseActionAlgorithm::CallAlgorithm, ;);
	UFUNCTION(BlueprintCallable, Category = "Action Algorithm")
		void Init(UStatSheetObject* target_) { target = target_; };
};