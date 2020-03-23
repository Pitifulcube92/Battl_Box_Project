// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle_Box_Actor.h"
#include "UCommandAction.h"
#include "UItemAction.h"
#include "UAbilityAction.h"
#include "UBaseAction.h"
#include "Templates/Casts.h"


// Sets default values
ABattle_Box_Actor::ABattle_Box_Actor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattle_Box_Actor::BeginPlay()
{
	Super::BeginPlay();
	
}
//Creates and sends a order object to the receiver

void ABattle_Box_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

