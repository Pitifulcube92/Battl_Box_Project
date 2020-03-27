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

USTRUCT(BlueprintType)
struct BATTLE_BOX_API FAction_Info
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(EditAnywhere, Category = "Action Info")
		TMap<FString, UCommandAction*> commandMap;
	UPROPERTY(EditAnywhere, Category = "Action Info")
		TMap<FString, UItemAction*> itemMap;
	UPROPERTY(EditAnywhere, Category = "Action Info")
		TMap<FString, UAbilityAction*> abilityMap;	
	UPROPERTY(EditAnywhere, Category = "Action Info")
		TMap<FString, UItemAction*> equipmentMap;
};

USTRUCT(Blueprintable)
struct BATTLE_BOX_API FGeneralStat_Info
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "General Info")
		FString name;
	UPROPERTY(EditAnywhere, Category = "General Info")
		FString tag;
	UPROPERTY(EditAnywhere, Category = "General Info")
		TMap<FString, float> additionlStats;
};


UCLASS(BlueprintType)
class BATTLE_BOX_API UStatSheetObject : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		FGeneralStat_Info generalnInfo;
	UPROPERTY(EditAnywhere)
		FAction_Info actionInfo;
};
