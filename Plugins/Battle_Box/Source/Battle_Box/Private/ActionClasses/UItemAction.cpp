// Fill out your copyright notice in the Description page of Project Settings.
#include "UItemAction.h"
#include "ResourceLoader.h"
#include "Private/ActionClasses/UAbilityAction.h"
#include "Debugger.h"


UItemAction::UItemAction() : effectList(TArray<UAbilityAction*>())
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
bool UItemAction::Init(const FString name_, const FString discription_, const ACTIONTYPE action_, const  TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, TMap<FString, float> statMap_, const uint32 value_, const DAMAGETYPE damageType_, const TArray<UAbilityAction*> effectArray_)
{
	SetName(name_);
	SetDiscription(discription_);
	SetActionType(action_);
	SetTargetType(target_); 
	SetInteractionType(interaction_);
	SetActionID(actionID_);
	
	value = value_;
	effectList = effectArray_;
	if (&effectList && &statModMap)
		return true;
	else
		return false;
}
bool UItemAction::Init(const UItemAction* other_)
{
	SetName(other_->ReturnName());
	SetDiscription(other_->ReturnDiscription());
	SetActionType(other_ ->ReturnActionType());
	SetTargetType(other_->ReturnTargetType());
	SetInteractionType(other_->ReturnInteractionType());
	SetActionID(other_->ReturnActionID());
	SetValue(other_->ReturnValue());

	if (&effectList && &statModMap)
		return true;
	else
		return false;
}
bool UItemAction::Init(ItemData const data_)
{
	SetName(data_.name);
	SetDiscription(data_.discription);
	SetActionType(data_.actionType);
	SetTargetType(data_.targetType);
	SetInteractionType(data_.interactionType);
	SetActionID(data_.actionID);
	SetValue(data_.value);
	//Note: This part it where we instantiate/find all the id actions to the 
	//resource class.
	for (uint32 i : data_.effectIDList)
	{
		if (ResourceLoader::CheckAction(i))
		{
			UAbilityAction* tmp = dynamic_cast<UAbilityAction*>(ResourceLoader::ReturnAction(i));
			AddEffect(tmp);
		}
		else
		{
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("Action is not found or does not exist.", "UItemAction.cpp", __LINE__);
		}
	}

	if (&effectList && &statModMap)
		return true;
	else
		return false;
}
void UItemAction::SetValue(const uint32 value_)
{
	value = value_;
}
void UItemAction::SetDamageType(const DAMAGETYPE type_)
{
	damageType = type_;
}
void UItemAction::SetType(const ITEMTYPE type_)
{
	type = type_;
}
void UItemAction::AddEffect(UAbilityAction* const ability_)
{
	effectList.Add(ability_);
}
ITEMTYPE UItemAction::ReturnItemType() const
{
	return type;
}
uint32 UItemAction::ReturnValue() const 
{
	return value;
}
DAMAGETYPE UItemAction::ReturnDamageType() const
{
	return damageType;
}
TMap<FString, float> UItemAction::ReturnStatMap() const
{
	return statModMap;
}
TArray<UAbilityAction*> UItemAction::ReturnEffectList() const 
{
	return effectList;
}
void UItemAction::OnDestroy()
{
	//Clean up method
}
UItemAction::~UItemAction()
{
	OnDestroy();
}
