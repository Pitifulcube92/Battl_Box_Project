// Fill out your copyright notice in the Description page of Project Settings.
#include "ActionClasses/AbilityAction.h"

AbilityAction::AbilityAction()
{
	SetName("");
	SetDiscription("");
	SetActionType(ACTIONTYPE::E_NONE);
	SetTargetType(TARGETTYPE::E_NONE);
	SetInteractionType(INTERACTIONTYPE::E_NONE);
	SetActionID(00);
	duration = 0.0f;
}
AbilityAction::AbilityAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, TMap<FString, float> statMap_,
	const float duration_, ABILITYTYPE type_)
{
	SetName(name_);
	SetDiscription(discription_);
	SetActionType(action_);
	SetTargetType(target_);
	SetInteractionType(interaction_);
	SetActionID(actionID_);
	duration = duration_;
}
AbilityAction::AbilityAction(AbilityAction* const other_)
{
	SetName(other_->ReturnName());
	SetDiscription(other_->ReturnDiscription());
	SetActionType(other_->ReturnActionType());
	SetInteractionType(other_->ReturnInteractionType());
	SetActionID(other_->ReturnActionID());
	duration = other_->ReturnDuration();

}
float AbilityAction::CalculateAbilityValue()
{
	//TO DO: implement an equation class.
	float tmp = 0.0f;
	return tmp;
}
void AbilityAction::SetDuration(const float duration_)
{
	duration = duration_;
}
float AbilityAction::ReturnDuration() const
{
	return duration;
}
TMap<FString, float> AbilityAction::ReturnModStatMap()
{
	return modStatMap;
}
void AbilityAction::SetAbilityType(const ABILITYTYPE type_)
{
	abilityType = type_;
}
ABILITYTYPE AbilityAction::ReturnAbilityType() const
{
	return abilityType;
}
float AbilityAction::ReturnAbilityValue() const
{
	return abilityValue;
}
void AbilityAction::OnDestroy()
{
	//This will clear out any data.
}
AbilityAction::~AbilityAction()
{
	OnDestroy();
}
