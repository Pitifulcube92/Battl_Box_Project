//// Fill out your copyright notice in the Description page of Project Settings.
//#pragma once
//
//#include "CoreMinimal.h"
//#include "UBaseAction.h"
//#include "Containers/Array.h"
//#include "Containers/Map.h"
//#include "UItemAction.generated.h"
//class UAbilityAction;
//
//USTRUCT()
//struct BATTLE_BOX_API FItemAction_Info
//{
//	GENERATED_USTRUCT_BODY() 
//public:
//	UPROPERTY(EditAnywhere)
//		ITEMTYPE type;
//	UPROPERTY(EditAnywhere)
//		uint32 value;
//	UPROPERTY(EditAnywhere)
//		TArray<UAbilityAction*> effectList;
//	UPROPERTY(EditAnywhere)
//	TMap<FString, float> statModMap;
//		UPROPERTY(EditAnywhere)
//	DAMAGETYPE damageType;
//};
//
//
//UCLASS(/*BlueprintType,*/)
//class BATTLE_BOX_API UItemAction : public UBaseAction
//{
//	GENERATED_BODY()
//public:
//	UPROPERTY(EditAnywhere)
//		struct FItemAction_Info itemInfo;
//	UFUNCTION(BlueprintCallable)
//		FItemAction_Info GetItemInfo() const;
//};
