// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "UItemAction.generated.h"
class UAbilityAction;
/********************************
* Item Action Class
*
* This is a derived class that contains information
* for item like actions. An item action contains
* detailed information about that would be key for an item.
* For example, currency value, type of item, or,
* the general status the item has.
*
********************************/


USTRUCT(BlueprintType)
struct BATTLE_BOX_API FItemAction_Info
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Item Action")
		ITEMTYPE type;
	UPROPERTY(EditAnywhere, Category = "Item Action")
		uint32 value;
	UPROPERTY(EditAnywhere, Category = "Item Action")
		TArray<UAbilityAction*> effectList;
	UPROPERTY(EditAnywhere, Category = "Item Action")
		TMap<FString, float> statModMap;
};


UCLASS(BlueprintType, Category = "Battle_Box")
class BATTLE_BOX_API UItemAction : public UBaseAction
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = "Item Action")
		struct FItemAction_Info itemInfo;
	UFUNCTION(BlueprintCallable, Category = "Item Action")
		FItemAction_Info GetItemInfo() const;

};
