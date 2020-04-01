// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Containers/Map.h"
#include "Battle_Box_Enums.h"
#include "UBaseAction.generated.h"
class UBaseActionAlgorithm;
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

///Base action data structure
USTRUCT(BlueprintType)
struct FBaseAction_Info
{
	GENERATED_USTRUCT_BODY()
public:

///Name
	UPROPERTY(EditAnywhere, Category = "Base Action")
		FString name;
///Discription
	UPROPERTY(EditAnywhere, Category = "Base Action")
		FString discription;
///Action type
	UPROPERTY(EditAnywhere, Category = "Base Action")
		ACTIONTYPE action;
///Interaction type
	UPROPERTY(EditAnywhere, Category = "Base Action")
		INTERACTIONTYPE interaction;
///Action ID
	UPROPERTY(EditAnywhere, Category = "Base Action")
		uint32 actionID;
///Action Algorithms
	UPROPERTY(EditAnywhere, Category = "Base Action")
		TMap<FString, UBaseActionAlgorithm*> actionAlgorithms;
///Effect Objects
	UPROPERTY(EditAnywhere, Category = "Base Action")
		TMap<FString, UBaseStatusEffect*> effects;

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
///Calls in the algorithm by its given name
	UFUNCTION(BlueprintCallable, Category = "Base Action")
		void ExecuteAlgorithm(FString algorithmN, UStatSheetObject* target_);
};
