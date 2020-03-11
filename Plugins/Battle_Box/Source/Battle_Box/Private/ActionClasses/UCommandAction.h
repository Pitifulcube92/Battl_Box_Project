// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "UCommandAction.generated.h"

USTRUCT()
struct BATTLE_BOX_API FCommandAction_Info
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	bool isActionCommand;
	UPROPERTY()
	WEAPONTYPE currentweapon;
	UPROPERTY()
	UBaseAction* command;
};

UCLASS()
class BATTLE_BOX_API UCommandAction : public UBaseAction
{
	GENERATED_BODY()
public:
	UPROPERTY()
		FCommandAction_Info commandInfo;
};
