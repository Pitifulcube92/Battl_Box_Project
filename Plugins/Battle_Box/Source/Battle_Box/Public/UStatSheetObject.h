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
USTRUCT(BlueprintType, Category="Action Info")
struct BATTLE_BOX_API FAction_Info
{
	GENERATED_USTRUCT_BODY()
public:
///Command Action Map
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Action Info")
		TMap<FString, UCommandAction*> commandMap;
///Item Action Map
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Action Info")
		TMap<FString, UItemAction*> itemMap;
///Ability Action Map
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Action Info")
		TMap<FString, UAbilityAction*> abilityMap;
///Equipment Map (Sub Item Action map)
	UPROPERTY(EditAnywhere, BlueprintType, Category = "Action Info")
		TMap<FString, UItemAction*> equipmentMap;
};

USTRUCT()
struct BATTLE_BOX_API FGeneralStat_Info
{
	GENERATED_USTRUCT_BODY()
public:
///StatSheetObject Name
	UPROPERTY(EditAnywhere, BlueprintType, Category = "General Info")
		FString name;
///StatSheetObject Tag
	UPROPERTY(EditAnywhere, BlueprintType, Category = "General Info")
		FString tag;
///StatSheetObject additional Stat
	UPROPERTY(EditAnywhere, BlueprintType, Category = "General Info")
		TMap<FString, float> additionlStats;
};


UCLASS(Blueprintable, ClassGroup = "Battle_Box")
class BATTLE_BOX_API UStatSheetObject : public UDataAsset
{
	GENERATED_BODY()
public:
///General Info Data Structure
	UPROPERTY(EditAnywhere, BlueprintType)
		FGeneralStat_Info generalnInfo;
///Action Info Data Structure
	UPROPERTY(EditAnywhere, BlueprintType)
		FAction_Info actionInfo;
};
