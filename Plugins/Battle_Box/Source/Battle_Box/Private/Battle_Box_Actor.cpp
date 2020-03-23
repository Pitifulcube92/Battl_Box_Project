// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle_Box_Actor.h"
#include "UCommandAction.h"
#include "UItemAction.h"
#include "UAbilityAction.h"
#include "UBaseAction.h"
#include "Templates/Casts.h"
#include "../BB_Runtime_System/Public/UCommandAction_Order.h"
#include "../BB_Runtime_System/Public/UItemAction_Order.h"
#include "../BB_Runtime_System/Public/UAbilityAction_Order.h"

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
bool ABattle_Box_Actor::IsOrderReadyToSend(UBaseAction obj_,)
{

	return false;
}
//Creates and sends a order object to the receiver
UCommandAction_Order* ABattle_Box_Actor::SendCommandOrder(UCommandAction* action_, void(UCommandAction::*func_)())
{
	UCommandAction_Order* tmp = NewObject<UCommandAction_Order>();
	tmp->Init(action_,func_);
	return tmp;
}
//Creates and sends a order object to the receiver
UItemAction_Order* ABattle_Box_Actor::SendItemOrder(UItemAction* action_, void(UItemAction::*func_)())
{
	UItemAction_Order* tmp = NewObject<UItemAction_Order>();
	tmp->Init(action_, func_);
	return tmp;
}
//Creates and sends a order object to the receiver
UAbilityAction_Order* ABattle_Box_Actor::SendAbilityOrder(UAbilityAction* action_, void(UAbilityAction::*func_)())
{
	UAbilityAction_Order* tmp = NewObject<UAbilityAction_Order>();
	tmp->Init(action_,func_);
	return tmp;
}
// Called every frame
void ABattle_Box_Actor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

