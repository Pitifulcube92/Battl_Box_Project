// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "Engine/DataAsset.h"
#include "UStatSheetObject.generated.h"

class UItemAction;
class UCommandAction;
class UAbilityAction;
struct StatSheetData;
/*
*
* StatSheetObject Class
*
*
*
*
*
*
*
*
*
*
*
*/

///StatSheetObject Data structure
USTRUCT(BlueprintType)
struct BATTLE_BOX_API FAction_Info
{
	GENERATED_USTRUCT_BODY()

///Command Action Map
	UPROPERTY(EditAnywhere, Category = "Action Info")
		TMap<FString, UCommandAction*> commandMap;
///Item Action Map
	UPROPERTY(EditAnywhere, Category = "Action Info")
		TMap<FString, UItemAction*> itemMap;
///Ability Action Map
	UPROPERTY(EditAnywhere, Category = "Action Info")
		TMap<FString, UAbilityAction*> abilityMap;	
///Equipment Map (Sub Item Action map)
	UPROPERTY(EditAnywhere, Category = "Action Info")
		TMap<FString, UItemAction*> equipmentMap;
};

USTRUCT(Blueprintable)
struct BATTLE_BOX_API FGeneralStat_Info
{
	GENERATED_USTRUCT_BODY()
///StatSheetObject Name
	UPROPERTY(EditAnywhere, Category = "General Info")
		FString name;
///StatSheetObject Tag
	UPROPERTY(EditAnywhere, Category = "General Info")
		FString tag;
///StatSheetObject additional Stat
	UPROPERTY(EditAnywhere, Category = "General Info")
		TMap<FString, float> additionlStats;
};


UCLASS(BlueprintType)
class BATTLE_BOX_API UStatSheetObject : public UDataAsset
{
	GENERATED_BODY()
public:
///General Info Data Structure
	UPROPERTY(EditAnywhere)
		FGeneralStat_Info generalnInfo;
///Action Info Data Structure
	UPROPERTY(EditAnywhere)
		FAction_Info actionInfo;
};
