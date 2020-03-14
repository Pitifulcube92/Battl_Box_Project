#include "../Public/ActionClasses/UCommandAction.h"
#include "Components/ActorComponent.h"

FCommandAction_Info UCommandAction::GetCommandInfo() const
{
	return commandInfo;
}

void UCommandAction::BeginCommand() const
{
	commandInfo.command->BeginPlay();
}

void UCommandAction::ActivateCommand() const
{
	commandInfo.command->Activate();
}

void UCommandAction::DeactivateCommand() const
{
	commandInfo.command->Deactivate();
}

