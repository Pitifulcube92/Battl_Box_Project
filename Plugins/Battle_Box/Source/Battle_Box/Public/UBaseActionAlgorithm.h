// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UBaseActionAlgorithm.generated.h"
class UStatSheetObject;
/**
 *
 *Base Action Algorithm
 *
 *This is a base class that is use to make 
 *derived classes that will contain custom made algorithms
 *to use for the actions.
 *
 *
 */
UCLASS(Abstract, Blueprintable)
class BATTLE_BOX_API UBaseActionAlgorithm : public UObject
{
	GENERATED_BODY()
private:
	UStatSheetObject* target;
	UStatSheetObject* owner;
public:
///This calls the whole algorithm 
	UFUNCTION(BlueprintCallable, Category = "Action Algorithm")
		virtual void CallAlgorithm() PURE_VIRTUAL(UBaseActionAlgorithm::CallAlgorithm, ;);
///This initialize the algorithum
	UFUNCTION(BlueprintCallable, Category = "Action Algorithm")
		void Init(UStatSheetObject* owner_) { owner = owner_; };
///Set the target for this algorithm.
	UFUNCTION(BlueprintCallable, Category = "Action Algorithm")
		void SetTarget(UStatSheetObject* target_) { target = target_; };

};