// Fill out your copyright notice in the Description page of Project Settings.


#include "ActionAlgorithmComponent.h"

// Sets default values for this component's properties
UActionAlgorithmComponent::UActionAlgorithmComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UActionAlgorithmComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UActionAlgorithmComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UActionAlgorithmComponent::Init(FString actionName_, UStatSheetObject* target_, UStatSheetObject* owner_)
{
	target = target_;
	actionName = actionName_;
	owner = owner_;
}