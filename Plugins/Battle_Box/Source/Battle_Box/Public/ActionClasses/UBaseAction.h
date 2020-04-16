// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Containers/Map.h"
#include "Battle_Box_Enums.h"
#include "UBaseAction.generated.h"
class UActionAlgorithmComponent;
class UBaseStatusEffect;
class UStatSheetObject;
/***********************************************
* Base Action class
*
* This class is the base class for any derived
* action class. It contains basic action
* information that all actions should have.
*
*
***********************************************/


USTRUCT(BlueprintType)
struct BATTLE_BOX_API FBaseAction_Info
{
	GENERATED_USTRUCT_BODY()

///Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Action")
		FString name;
///Discription
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Action")
		FString discription;
///Action type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Action")
		ACTIONTYPE action;
///Interaction type
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Action")
		INTERACTIONTYPE interaction;
///Action ID
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Action")
		int32 actionID;
///Action Algorithms
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Base Action")
		TSubclassOf<UActionAlgorithmComponent> actionAlgorithms;

};

UCLASS(BlueprintType)
class BATTLE_BOX_API UBaseAction : public UDataAsset
{
	GENERATED_BODY()
private:
///Base infomation variable
	UPROPERTY(EditAnywhere, Category = "Base Action")
		FBaseAction_Info baseInfo;
public:
///Getter function for Base information
	UFUNCTION(BlueprintCallable, Category = "Base Action")
		FBaseAction_Info GetBaseInfo() const;
///Setter function for Base Information
	UFUNCTION(BlueprintCallable, Category = "Base Action")
		void SetBaseInfo(FBaseAction_Info other_);
};
