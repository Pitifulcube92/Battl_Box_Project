// Fill out your copyright notice in the Description page of Project Settings.


#include "StatSheetComponent.h"

// Sets default values for this component's properties
UStatSheetComponent::UStatSheetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	
	// ...
}


// Called when the game starts
void UStatSheetComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


// Called every frame
void UStatSheetComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UStatSheetComponent::ReturnName() const
{
	return data.Name;
}

FString UStatSheetComponent::ReturnTag() const
{
	return data.Tag;
}

int UStatSheetComponent::ReturnID() const
{
	return data.ID;
}

float UStatSheetComponent::ReturnMaxHP() const
{
	return data.MaxMP;
}

float UStatSheetComponent::ReturnMaxMP() const
{
	return data.MaxMP;
}

float UStatSheetComponent::ReturnCurrentHP() const
{
	return data.CurrentHP;
}

float UStatSheetComponent::ReturnCurrentMP() const
{
	return data.CurrentMP;
}

float UStatSheetComponent::ReturnPhysicalAtk() const
{
	return data.PhysicalAttack;
}

float UStatSheetComponent::ReturnPysicalDefence() const
{
	return data.PhysicalDefence;
}

float UStatSheetComponent::ReturnMagicAtk() const
{
	return data.MagicalAttack;
}

float UStatSheetComponent::ReturnMagicDefence() const
{
	return data.MagicalDefence;
}