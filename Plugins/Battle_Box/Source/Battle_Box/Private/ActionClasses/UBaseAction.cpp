// Fill out your copyright notice in the Description page of Project Settings.


#include "UBaseAction.h"
#include "Math/UnrealMathUtility.h"
#include "JsonParse.h"
#include "ResourceLoader.h"

UBaseAction::UBaseAction()
{
	name = "";
	discription = "";
	action = ACTIONTYPE::E_NONE;
	target = TARGETTYPE::E_NONE;
	interaction = INTERACTIONTYPE::E_NONE;
	statAction = STATACTION::E_NONE;
	actionID = 00;
}
bool UBaseAction::Init(FString name_, FString discription_, ACTIONTYPE action_, TARGETTYPE target_, INTERACTIONTYPE interaction_, STATACTION statAction_, const uint32 actionID_, bool IsFirstInstance_)
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
	
	if (name == name_ && discription == discription_ && action == action_ && target == target_ && interaction == interaction && statAction == statAction_ && actionID == actionID_)
		return true;
	else
		return false;
}
bool UBaseAction::Init(const UBaseAction* other_)
{
	name = other_->ReturnName();
	discription = other_->ReturnDiscription();
	target = other_->ReturnTargetType();
	actionID = other_->ReturnActionID();
	statAction = other_->ReturnStatActionType();

	if (name == other_->ReturnName() && discription == other_->ReturnDiscription() && action == other_->ReturnActionType() && target == other_->ReturnTargetType() && interaction == interaction && statAction == other_->ReturnStatActionType() && actionID == other_->ReturnActionID())
		return true;
	else
		return false;
}
uint32 UBaseAction::GenerateID()
{
	//Generate a uniqe ID for the action when made.

	//NOTE:This Function need to communicate with the resource system so that
	//we can check if there is no duplication
	uint32 tmpID = (uint32)FMath::FRandRange(0.0f, 100000.0f);

	bool IsUniqeID = true;
	while (IsUniqeID)
	{		
		if (ResourceLoader::GetInstance()->CheckAction(tmpID))
		{
			IsUniqeID = false;
			break;
		}
		tmpID = (uint32)FMath::FRandRange(0.0f, 100000.0f);
	}
	return tmpID;
}
void UBaseAction::SetName(const FString name_)
{
	name = name_;
}
void UBaseAction::SetDiscription(const FString discription_)
{
	discription = discription_;
}
void UBaseAction::SetActionType(const ACTIONTYPE type_)
{
	action = type_;
}
void UBaseAction::SetTargetType(const TARGETTYPE type_)
{
	target = type_;
}
void UBaseAction::SetInteractionType(const INTERACTIONTYPE type_)
{
	interaction = type_;
}
void UBaseAction::SetStatActionType(const STATACTION type_)
{
	statAction = type_;
}
void UBaseAction::SetActionID(const uint32 actionID_)
{
	actionID = actionID_;
}
FString UBaseAction::UBaseAction::ReturnName() const
{
	return name;
}
FString UBaseAction::ReturnDiscription() const
{
	return discription;
}
ACTIONTYPE UBaseAction::ReturnActionType() const
{
	return action;
}
TARGETTYPE UBaseAction::ReturnTargetType() const
{
	return target;
}
INTERACTIONTYPE UBaseAction::ReturnInteractionType() const
{
	return interaction;
}
STATACTION UBaseAction::ReturnStatActionType() const
{
	return statAction;
}
uint32 UBaseAction::ReturnActionID() const
{
	return actionID;
}
void UBaseAction::OnDestroy()
{
	//The clean up method
}
UBaseAction::~UBaseAction()
{
	OnDestroy();
}
