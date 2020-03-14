// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Battle_Box_Enums.h"
#include "UBaseAction.generated.h"


USTRUCT()
struct FBaseAction_Info
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere)
		FString name;
	UPROPERTY(EditAnywhere)
		FString discription;
	UPROPERTY(EditAnywhere)
		ACTIONTYPE action;
	UPROPERTY(EditAnywhere)
		TARGETTYPE target;
	UPROPERTY(EditAnywhere)
		STATACTION statAction;
	UPROPERTY(EditAnywhere)
		INTERACTIONTYPE interaction;
	UPROPERTY(EditAnywhere)
		uint32 actionID;
};

UCLASS()
class BATTLE_BOX_API UBaseAction : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
		FBaseAction_Info baseInfo;
	/*UFUNCTION(BlueprintCallable)
		FBaseAction_Info GetBaseInfo() const;*/
	
};
