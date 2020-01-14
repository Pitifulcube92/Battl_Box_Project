// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAction.h"

BaseAction::BaseAction()
{
}
BaseAction::BaseAction(FString name_, FString discription_, ACTIONTYPE action_, TARGETTYPE target_, INTERACTIONTYPE interaction_, const uint32 actionID_)
{
	name = name_;
	discription = discription_;
	action = action_;
	target = target_;
	interaction = interaction_;
	actionID = actionID_;
}
BaseAction::BaseAction(const BaseAction* other_)
{
	name = other_->ReturnName();
	discription = other_->ReturnDiscription();
	target = other_->ReturnTargetType();
}
void BaseAction::SetName(const FString name_)
{
	name = name_;
}
void BaseAction::SetDiscription(const FString discription_)
{
	discription = discription_;
}
void BaseAction::SetAction(const ACTIONTYPE type_)
{
	action = type_;
}
void BaseAction::SetTarget(const TARGETTYPE type_)
{
	target = type_;
}
void BaseAction::SetInteraction(const INTERACTIONTYPE type_)
{
	interaction = type_;
}
void BaseAction::SetActionID(const uint32 actionID_)
{
	actionID = actionID_;
}
FString BaseAction::BaseAction::ReturnName() const
{
	return name;
}
FString BaseAction::ReturnDiscription() const
{
	return discription;
}
ACTIONTYPE BaseAction::ReturnActionType() const
{
	return action;
}
TARGETTYPE BaseAction::ReturnTargetType() const
{
	return target;
}
INTERACTIONTYPE BaseAction::ReturnInteractionType() const
{
	return interaction;
}
uint32 BaseAction::ReturnActionID() const
{
	return actionID;
}
void BaseAction::OnDestroy()
{
	//The clean up method
}
BaseAction::~BaseAction()
{
	OnDestroy();
}
