// Fill out your copyright notice in the Description page of Project Settings.
#include "ItemAction.h"

ItemAction::ItemAction() : effectList(TArray<AbilityAction*>())
{
	SetName("");
	SetDiscription("");
	SetActionType(ACTIONTYPE::E_NONE);
	SetTargetType(TARGETTYPE::E_NONE);
	SetInteractionType(INTERACTIONTYPE::E_NONE);
	SetActionID(00);
	SetValue(00);
	SetDamageType(DAMAGETYPE::E_NONE);
}
ItemAction::ItemAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const  TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, TMap<FString, float> statMap_, const uint32 value_, const DAMAGETYPE damageType_, const TArray<AbilityAction*> effectArray_)
{
	SetName(name_);
	SetDiscription(discription_);
	SetActionType(action_);
	SetTargetType(target_); 
	SetInteractionType(interaction_);
	SetActionID(actionID_);
	
	value = value_;
	effectList = effectArray_;

}
ItemAction::ItemAction(const ItemAction* other_)
{
	SetName(other_->ReturnName());
	SetDiscription(other_->ReturnDiscription());
	SetActionType(other_ ->ReturnActionType());
	SetTargetType(other_->ReturnTargetType());
	SetInteractionType(other_->ReturnInteractionType());
	SetActionID(other_->ReturnActionID());
	SetValue(other_->ReturnValue());
}
void ItemAction::SetValue(const uint32 value_)
{
	value = value_;
}
void ItemAction::SetDamageType(const DAMAGETYPE type_)
{
	damageType = type_;
}
void ItemAction::SetType(const ITEMTYPE type_)
{
	type = type_;
}
void ItemAction::AddEffect(AbilityAction* const ability_)
{
	effectList.Add(ability_);
}
ITEMTYPE ItemAction::ReturnItemType() const
{
	return type;
}
uint32 ItemAction::ReturnValue() const 
{
	return value;
}
DAMAGETYPE ItemAction::ReturnDamageType() const
{
	return damageType;
}
TMap<FString, float> ItemAction::ReturnStatMap() const
{
	return statMap;
}
TArray<AbilityAction*> ItemAction::ReturnEffectList() const 
{
	return effectList;
}
void ItemAction::OnDestroy()
{
	//Clean up method
}
ItemAction::~ItemAction()
{
	OnDestroy();
}
