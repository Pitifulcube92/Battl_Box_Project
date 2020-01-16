// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandAction.h"

CommandAction::CommandAction() : command(nullptr)
{
	SetName("");
	SetDiscription("");
	SetActionType(ACTIONTYPE::E_NONE);
	SetTargetType(TARGETTYPE::E_NONE);
	SetInteractionType(INTERACTIONTYPE::E_NONE);
	SetActionID(00);
	currentweapon = WEAPONTYPE::E_NONE;
}
CommandAction::CommandAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, const WEAPONTYPE currentWeap_,  BaseAction* const command_)
{
	SetName(name_);
	SetDiscription(discription_);
	SetActionType(action_);
	SetTargetType(target_);
	SetInteractionType(interaction_);
	SetActionID(actionID_);
	currentweapon = currentWeap_;
	command = command_;
}
CommandAction::CommandAction(CommandAction* const other_)
{
	SetName(other_->ReturnName());
	SetDiscription(other_->ReturnDiscription());
	SetActionType(other_->ReturnActionType());
	SetTargetType(other_->ReturnTargetType());
	SetInteractionType(other_->ReturnInteractionType());
	SetActionID(other_->ReturnActionID());
	currentweapon = ReturnWeaponType();
	command = ReturnAction();
}
void CommandAction::SetWeaponType(WEAPONTYPE type_)
{
	currentweapon = type_;
}
void CommandAction::SetCommand(BaseAction* action_)
{
	command = action_;
}
WEAPONTYPE CommandAction::ReturnWeaponType() const
{
	return currentweapon;
}
BaseAction* CommandAction::ReturnAction() const
{
	return command;
}
void CommandAction::OnDestroy()
{
	if(command)
	{
		delete command;
		command = nullptr;
	}
}
CommandAction::~CommandAction()
{
	OnDestroy();
}
