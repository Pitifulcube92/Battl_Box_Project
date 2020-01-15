// Fill out your copyright notice in the Description page of Project Settings.


#include "CommandAction.h"

CommandAction::CommandAction()
{
}
CommandAction::CommandAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, const WEAPONTYPE currentWeap_, const BaseAction* command_)
{
	SetName(name_);
	SetDiscription(discription_);
	SetActionType(action_);
	SetTargetType(target_);
	SetInteractionType(interaction_);
	SetActionID(actionID_);

}
void CommandAction::SetWeaponType(WEAPONTYPE type_)
{
	currentweapon = type_;
}
void CommandAction::SetCommand(BaseAction* action_)
{

}
WEAPONTYPE CommandAction::ReturnWeaponType() const
{

}
BaseAction* CommandAction::ReturnAction() const
{

}
void CommandAction::OnDestroy()
{

}
CommandAction::~CommandAction()
{
}
