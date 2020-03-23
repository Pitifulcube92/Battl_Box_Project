// Fill out your copyright notice in the Description page of Project Settings.

#include "BB_Runtime_System.h"
#include "UItemAction_Order.h"
#include "../Battle_Box/Public/ActionClasses/UItemAction.h"

UItemAction_Order::UItemAction_Order() : action(nullptr)
{
	func = nullptr;
}
void UItemAction_Order::Init(UItemAction* action_, funcPointer func_)
{
	action = action_;
	func = func_;
}
void UItemAction_Order::Execute()
{
	(action->*func)();
}
UItemAction_Order::~UItemAction_Order()
{
	delete action;
	action = nullptr;
	func = nullptr;
}
