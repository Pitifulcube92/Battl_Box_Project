#include "../Public/ActionClasses/UCommandAction.h"
#include "../BB_Runtime_System/Public/UCommandAction_Order.h"
#include "Components/ActorComponent.h"

FCommandAction_Info UCommandAction::GetCommandInfo() const
{
	return commandInfo;
}
void UCommandAction::Test()
{

}
//UCommandAction_Order* SendOutOrder(UCommandAction* action_, void(UCommandAction::*func_)())
//{
//	/*UCommandAction_Order* tmp = new UCommandAction_Order();
//	return tmp;*/
//}