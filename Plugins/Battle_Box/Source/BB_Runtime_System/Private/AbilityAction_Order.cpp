// Fill out your copyright notice in the Description page of Project Settings.

#include "BB_Runtime_System.h"
#include "UAbilityAction_Order.h"
#include "../Battle_Box/Public/ActionClasses/UAbilityAction.h"

UAbilityAction_Order::UAbilityAction_Order() : action(nullptr)
{
	func = nullptr;
}
void UAbilityAction_Order::Init(UAbilityAction* action_, funcPointer func_)
{
	action = action_;
	func = func_;
}
void UAbilityAction_Order::Execute()
{
	(action->*func)();
}
UAbilityAction_Order::~UAbilityAction_Order()
{
	delete action;
	action = nullptr;
	func = nullptr;
}
