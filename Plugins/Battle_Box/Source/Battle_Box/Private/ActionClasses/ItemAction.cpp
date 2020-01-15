// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemAction.h"

ItemAction::ItemAction()
{
}
ItemAction::ItemAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const  TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, const uint32 value_, const DAMAGETYPE damageType_, const TArray<AbilityAction*> effectArray_)
{

}
ItemAction::ItemAction(const ItemAction* other_)
{

}
void ItemAction::SetValue(const uint32 value_)
{

}
void ItemAction::AddEffect(const AbilityAction* ability_)
{

}
uint32 ItemAction::ReturnValue()
{
	return value;
}
TArray<AbilityAction*> ItemAction::ReturnEffectList()
{
	return effectList;
}
ItemAction::~ItemAction()
{
}
