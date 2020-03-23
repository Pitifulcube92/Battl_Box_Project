#include "../Public/ActionClasses/UCommandAction.h"
#include "../BB_Runtime_System/Public/UCommandAction_Order.h"
#include "Components/ActorComponent.h"

FCommandAction_Info UCommandAction::GetCommandInfo() const
{
	return commandInfo;
}
