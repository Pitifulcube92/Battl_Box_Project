// Fill out your copyright notice in the Description page of Project Settings.

#include "BB_Runtime_System.h"
#include "UCommandAction_Order.h"
#include "../Battle_Box/Public/ActionClasses/UCommandAction.h"

UCommandAction_Order::UCommandAction_Order() : action(nullptr)
{
	func = nullptr;
}
void UCommandAction_Order::Init(UCommandAction* action_, funcPointer func_)
{
	action = action_;
	func = func_;
}
void UCommandAction_Order::Execute()
{
	(action->*func)();
}
UCommandAction_Order::~UCommandAction_Order()
{
	delete action;
	action = nullptr;
	func = nullptr;
}
