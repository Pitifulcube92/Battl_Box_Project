// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Delegates/Delegate.h"
#include "Battle_Box_Actor.generated.h"

class UStatSheetObject;
class UCommandAction_Order;
class UItemAction_Order;
class UAbilityAction_Order;
class UBaseAction;
class UCommandAction;
class UItemAction;
class UAbilityAction;


UCLASS()
class BATTLE_BOX_API ABattle_Box_Actor : public AActor
{
private:

	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintType)
		UStatSheetObject* statSheet;
public:	
	// Sets default values for this actor's properties
	ABattle_Box_Actor();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Battle_Box Actor")
		UStatSheetObject* GetStatSheet() const;
};
