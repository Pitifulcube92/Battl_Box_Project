// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "UCommandAction.generated.h"
class UCommandAction_Order;
/************************************
* Command Action Class
*
* This is a derived action class that
* contains information specified for command
* like actions. This specializes in containing
* Actor components that can be executed when called
* through an interaction.
*

***********************************+*/

///Command action data structure
USTRUCT(BlueprintType)
struct BATTLE_BOX_API FCommandAction_Info
{
	GENERATED_USTRUCT_BODY()
public:
///Command component
	UPROPERTY(EditAnywhere, Category = "Command Action")
		class UActorComponent* command;
};

UCLASS(BlueprintType, Category = "Battle_Box")
class BATTLE_BOX_API UCommandAction : public UBaseAction
{
	GENERATED_BODY()

private:
///Command data structure
	UPROPERTY(EditAnywhere, Category = "Command Action")
		FCommandAction_Info commandInfo;
public:
///Command data Getter
	UFUNCTION(BlueprintCallable, Category = "Command Action")
		FCommandAction_Info GetCommandInfo() const;
};
