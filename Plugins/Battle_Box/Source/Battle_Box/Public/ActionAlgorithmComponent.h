// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ActionAlgorithmComponent.generated.h"
class UStatSheetObject;

UCLASS(Blueprintable, BlueprintType, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_BOX_API UActionAlgorithmComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActionAlgorithmComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStatSheetObject* target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStatSheetObject* owner;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString actionName;
protected:
// Called when the game starts
	virtual void BeginPlay() override;
public:	
// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
///This calls the whole algorithm 
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category = "Action Algorithm")
		void CallAlgorithm();
///This initialize the algorithum
	UFUNCTION(BlueprintCallable, Category = "Action Algorithm")
		void Init(FString actionName_, UStatSheetObject* target_);
};
