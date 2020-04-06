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
* Every initiations for this base class will assign it 
* to the owner of this object.
*
* Variables:
* -	Target : StatSheetObject pointer
* - Owner : StatSheetObject pointer
*
*
********************************/


USTRUCT(BlueprintType)
struct BATTLE_BOX_API FItemAction_Info
{
	GENERATED_USTRUCT_BODY()
public:
///Item Type 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Action")
		ITEMTYPE type;
///items value
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Action")
		int32 value;
///Item's Effect list 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Action")
		TArray<UAbilityAction*> effectList;
///Items basic states
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Action")
		TMap<FString, float> statModMap;
};


UCLASS(BlueprintType, Category = "Battle_Box")
class BATTLE_BOX_API UItemAction : public UBaseAction
{
	GENERATED_BODY()
private:
///Item Data structure 
	UPROPERTY(EditAnywhere, Category = "Item Action")
		struct FItemAction_Info itemInfo;
public:
///Return function for item data structure
	UFUNCTION(BlueprintCallable, Category = "Item Action")
		FItemAction_Info GetItemInfo() const;

};
