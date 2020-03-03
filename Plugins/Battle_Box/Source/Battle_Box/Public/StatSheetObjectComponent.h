//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "Components/ActorComponent.h"
//#include "Engine/DataTable.h"
//#include "Private/StatSheetObject.h"
//#include "StatSheetObjectComponent.generated.h"
//
//USTRUCT(BlueprintType)
//struct FStatSheetData : public FTableRowBase
//{
//	GENERATED_BODY()
//
//	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
//		float MAXHP = 0.0f;
//	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
//		float CurrentHP = 0.0f;
//	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
//		float MAXMP = 0.0f;
//	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
//		float CurrentMP = 0.0f;
//	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
//		float PhysicalDefence = 0.0f;
//	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
//		float PhysicalAttack = 0.0f;
//	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
//		float MagicalDefence = 0.0f;
//	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
//		float MagicalAttack = 0.0f;
//};
//
//UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
//class BATTLE_BOX_API UStatSheetObjectComponent : public UActorComponent
//{
//	GENERATED_BODY()
//private:
//	StatSheetObject* StatSheet;
//public:	
//	// Sets default values for this component's properties
//	UStatSheetObjectComponent();
//
//protected:
//	// Called when the game starts
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
//
//		
//};
