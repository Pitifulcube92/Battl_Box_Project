//// Fill out your copyright notice in the Description page of Project Settings.
//#pragma once
//
//#include "CoreMinimal.h"
//#include "UBaseAction.h"
//#include "UCommandAction.generated.h"
//
//USTRUCT()
//struct BATTLE_BOX_API FCommandAction_Info
//{
//	GENERATED_USTRUCT_BODY()
//public:
//	UPROPERTY(EditAnywhere)
//		bool isActionCommand;
//	UPROPERTY(EditAnywhere)
//		WEAPONTYPE currentweapon;
//	UPROPERTY(EditAnywhere)
//		class UActorComponent* command;
//};
//
//UCLASS(/*Blueprintable, BlueprintType,*/ )
//class BATTLE_BOX_API UCommandAction : public UBaseAction
//{
//	GENERATED_BODY()
//public:
//	UPROPERTY(EditAnywhere, BlueprintType)
//		FCommandAction_Info commandInfo;
//	
//public:
//	UFUNCTION(BlueprintCallable)
//		FCommandAction_Info GetCommandInfo() const;
//	UFUNCTION(BlueprintCallable)
//		void BeginCommand() const;
//	UFUNCTION(BlueprintCallable)
//		void ActivateCommand() const;
//	UFUNCTION(BlueprintCallable)
//		void DeactivateCommand() const;
//};
