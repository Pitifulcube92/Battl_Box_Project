// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "StatSheetObject.h"
#include "StatSheet_Actor.generated.h"

USTRUCT(BlueprintType)
struct FStatSheetData : public FTableRowBase 
{
		
};

UCLASS()
class BATTLE_BOX_API AStatSheet_Actor : public AActor
{
	GENERATED_BODY()
private: 
	StatSheetObject* statSheet;
public:	
	// Sets default values for this actor's properties
	AStatSheet_Actor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
