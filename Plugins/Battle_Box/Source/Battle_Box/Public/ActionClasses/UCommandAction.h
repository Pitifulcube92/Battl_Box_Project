// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "UCommandAction.generated.h"

USTRUCT(BlueprintType)
struct BATTLE_BOX_API FCommandAction_Info
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere)
		bool isActionCommand;
	UPROPERTY(EditAnywhere)
		WEAPONTYPE currentweapon;
	UPROPERTY(EditAnywhere)
		class UActorComponent* command;
};

UCLASS(BlueprintType, Category = "Battle_Box")
class BATTLE_BOX_API UCommandAction : public UBaseAction
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		FCommandAction_Info commandInfo;
	
public:
	UFUNCTION(BlueprintCallable)
		FCommandAction_Info GetCommandInfo() const;
	UFUNCTION(BlueprintCallable)
		void BeginCommand() const;
	UFUNCTION(BlueprintCallable)
		void ActivateCommand() const;
	UFUNCTION(BlueprintCallable)
		void DeactivateCommand() const;
};
