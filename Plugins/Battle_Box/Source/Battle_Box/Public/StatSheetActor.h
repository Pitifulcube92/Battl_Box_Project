// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Battle_Box/Private/UStatSheetObject.h"
#include "StatSheetActor.generated.h"

UCLASS()
class BATTLE_BOX_API AStatSheetActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStatSheetActor();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStatSheetObject* statSheet;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
