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

//USTRUCT()
//struct BATTLE_BOX_API FAction_Info
//{
//	GENERATED_USTRUCT_BODY()
//
//
//	UPROPERTY()
//		TMap<FString, UCommandAction*> commandMap;
//	UPROPERTY()
//		TMap<FString, UItemAction*> itemMap;
//	UPROPERTY()
//		TMap<FString, UAbilityAction*> abilityMap;	
//	UPROPERTY()
//		TMap<FString, UItemAction*> equipmentMap;
//};

//USTRUCT()
//struct BATTLE_BOX_API FGeneralStat_Info
//{
//	GENERATED_USTRUCT_BODY()
//
//	UPROPERTY()
//		FString name;
//	UPROPERTY()
//		FString tag;
//	UPROPERTY()
//		TMap<FString, float> statMap;
//};


UCLASS(Blueprintable)
class BATTLE_BOX_API UStatSheetObject : public UDataAsset
{
	GENERATED_BODY()
public:
	//UPROPERTY()
	//	FGeneralStat_Info generalnInfo;
	//UPROPERTY()
	//	FAction_Info actionInfo;
};
