// Fill out your copyright notice in the Description page of Project Settings.


#include "UStatusEffect.h"
#include "Components/ActorComponent.h"

//This will let the component to start when the fucntion is called
void UStatusEffect::BeginEffect() const
{
	effectAction->BeginPlay();
}

void UStatusEffect::ActivatEffect() const
{
	effectAction->Activate();
}

void UStatusEffect::DeactivateEffect() const
{
	effectAction->Deactivate();
}