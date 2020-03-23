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


	UPROPERTY(EditAnywhere)
		TMap<FString, UCommandAction*> commandMap;
	UPROPERTY(EditAnywhere)
		TMap<FString, UItemAction*> itemMap;
	UPROPERTY(EditAnywhere)
		TMap<FString, UAbilityAction*> abilityMap;	
	UPROPERTY(EditAnywhere)
		TMap<FString, UItemAction*> equipmentMap;
};

USTRUCT(Blueprintable)
struct BATTLE_BOX_API FGeneralStat_Info
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
		FString name;
	UPROPERTY(EditAnywhere)
		FString tag;
	UPROPERTY(EditAnywhere)
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
