// Fill out your copyright notice in the Description page of Project Settings.


#include "UCommandAction.h"
#include "JsonParse.h"

UCommandAction::UCommandAction() : command(nullptr)
{
	SetName("");
	SetDiscription("");
	SetActionType(ACTIONTYPE::E_NONE);
	SetTargetType(TARGETTYPE::E_NONE);
	SetInteractionType(INTERACTIONTYPE::E_NONE);
	SetActionID(00);
	currentweapon = WEAPONTYPE::E_NONE;
}
bool UCommandAction::Init(const FString name_, const FString discription_, const ACTIONTYPE action_, const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, TMap<FString, float> statMap_, const WEAPONTYPE currentWeap_,  UBaseAction* const command_)
{
	SetName(name_);
	SetDiscription(discription_);
	SetActionType(action_);
	SetTargetType(target_);
	SetInteractionType(interaction_);
	SetActionID(actionID_);
	currentweapon = currentWeap_;
	command = command_;
	if (&command)
		return true;
	else
		return false;
}
bool UCommandAction::Init(UCommandAction* const other_)
{
	SetName(other_->ReturnName());
	SetDiscription(other_->ReturnDiscription());
	SetActionType(other_->ReturnActionType());
	SetTargetType(other_->ReturnTargetType());
	SetInteractionType(other_->ReturnInteractionType());
	SetActionID(other_->ReturnActionID());
	currentweapon = ReturnWeaponType();
	command = ReturnAction();

	if (&command)
		return true;
	else
		return false;
}
bool UCommandAction::Init(CommandData const data_)
{
	SetName(data_.name);
	SetDiscription(data_.discription);
	SetActionID(data_.actionID);
	SetActionType(data_.actionType);
	SetTargetType(data_.targetType);
	currentweapon = data_.currentWeapon;
	//This part is where we search for the actual base action.

	if (&command)
		return true;
	else
		return false;
}
void UCommandAction::SetWeaponType(WEAPONTYPE type_)
{
	currentweapon = type_;
}
void UCommandAction::SetCommand(UBaseAction* action_)
{
	command = action_;
}
WEAPONTYPE UCommandAction::ReturnWeaponType() const
{
	return currentweapon;
}
UBaseAction* UCommandAction::ReturnAction() const
{
	return command;
}
void UCommandAction::OnDestroy()
{
	if(command)
	{
		delete command;
		command = nullptr;
	}
}
UCommandAction::~UCommandAction()
{
	OnDestroy();
}
