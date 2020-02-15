// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAction.h"
#include "Math/UnrealMathUtility.h"

BaseAction::BaseAction()
{
	name = "";
	discription = "";
	action = ACTIONTYPE::E_NONE;
	target = TARGETTYPE::E_NONE;
	interaction = INTERACTIONTYPE::E_NONE;
	actionID = 00;
}
BaseAction::BaseAction(FString name_, FString discription_, ACTIONTYPE action_, TARGETTYPE target_, INTERACTIONTYPE interaction_, STATACTION statAction_, const uint32 actionID_, TMap<FString, float> statMap_, bool IsFirstInstance_)
{
	name = name_;
	discription = discription_;
	action = action_;
	target = target_;
	interaction = interaction_;
	statAction = statAction_;
	//This will check if this instance is the first time.
	if (IsFirstInstance_)
		actionID = GenerateID();
	else
		actionID = actionID_;

}
BaseAction::BaseAction(const BaseAction* other_)
{
	name = other_->ReturnName();
	discription = other_->ReturnDiscription();
	target = other_->ReturnTargetType();
	actionID = other_->ReturnActionID();
	statAction = other_->ReturnStatActionType();
}
uint32 BaseAction::GenerateID()
{
	//Generate a uniqe ID for the action when made.
	return (uint32)FMath::FRandRange(0.0f, 100000.0f);
}
void BaseAction::SetName(const FString name_)
{
	name = name_;
}
void BaseAction::SetDiscription(const FString discription_)
{
	discription = discription_;
}
void BaseAction::SetActionType(const ACTIONTYPE type_)
{
	action = type_;
}
void BaseAction::SetTargetType(const TARGETTYPE type_)
{
	target = type_;
}
void BaseAction::SetInteractionType(const INTERACTIONTYPE type_)
{
	interaction = type_;
}
void BaseAction::SetStatActionType(const STATACTION type_)
{
	statAction = type_;
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
STATACTION BaseAction::ReturnStatActionType() const
{
	return statAction;
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
