// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Battle_Box_Enums.h"
#include "UBaseAction.generated.h"
/***********************************************
* Base Action class
*	
* This class is the base class for any derived
* action class. It contains basic action 
* information that all actions should have.
*
***********************************************/

///Base action data structure
USTRUCT(BlueprintType)
struct FBaseAction_Info
{
	GENERATED_USTRUCT_BODY()
public:

///Name
	UPROPERTY(EditAnywhere)
		FString name;
///Discription
	UPROPERTY(EditAnywhere)
		FString discription;
///Action type
	UPROPERTY(EditAnywhere)
		ACTIONTYPE action;
///Target type
	UPROPERTY(EditAnywhere)
		TARGETTYPE target;
///SstatActionType
	UPROPERTY(EditAnywhere)
		STATACTION statAction;
///Interaction type
	UPROPERTY(EditAnywhere)
		INTERACTIONTYPE interaction;
///Action ID
	UPROPERTY(EditAnywhere)
		uint32 actionID;
};

UCLASS(Abstract, Category="Battle_Box")
class BATTLE_BOX_API UBaseAction : public UDataAsset
{
	GENERATED_BODY()
	
private:
///Base infomation variable
	UPROPERTY(EditAnywhere)
		FBaseAction_Info baseInfo;
public:
///Getter function for Base information
	UFUNCTION(BlueprintCallable)
		FBaseAction_Info GetBaseInfo() const;

	virtual void ExecuteAction() const;
	
};
