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
	UPROPERTY(EditAnywhere, BlueprintReadWrite,  Category = "Action Info")
		TMap<FString, UCommandAction*> commandMap;
///Item Action Map
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Info")
		TMap<FString, UItemAction*> itemMap;
///Ability Action Map
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Info")
		TMap<FString, UAbilityAction*> abilityMap;
///Equipment Map (Sub Item Action map)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Action Info")
		TMap<FString, UItemAction*> equipmentMap;
};

USTRUCT(BlueprintType, Category = "General Info")
struct BATTLE_BOX_API FGeneral_Info
{
	GENERATED_USTRUCT_BODY()
public:
///StatSheetObject Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General Info")
		FString name;
///StatSheetObject Tag
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General Info")
		FString tag;
///StatSheetObject additional Stat
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "General Info")
		TMap<FString, float> additionlStats;
};
	

UCLASS(Blueprintable, BlueprintType, Category = "StatSheet")
class BATTLE_BOX_API UStatSheetObject : public UDataAsset
{
	GENERATED_BODY()
public:
///General Info Data Structure
	UPROPERTY(EditAnywhere, BlueprintGetter=GetGeneralInfo)
		FGeneral_Info generalInfo;
///Action Info Data Structure
	UPROPERTY(EditAnywhere, BlueprintGetter=GetActionInfo)
		FAction_Info actionInfo;
///Return General Info
	UFUNCTION(BlueprintCallable, BlueprintGetter)
		FGeneral_Info GetGeneralInfo() const;
///Return Action Info
	UFUNCTION(BlueprintCallable, BlueprintGetter)
		FAction_Info GetActionInfo() const;
};
