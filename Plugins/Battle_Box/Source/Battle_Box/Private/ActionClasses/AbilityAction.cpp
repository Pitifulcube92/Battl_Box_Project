// Fill out your copyright notice in the Description page of Project Settings.
#include "ActionClasses/AbilityAction.h"
#include "Equation.h"
#include "JsonParse.h"

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
	const float duration_, const ABILITYTYPE type_, const EquationData data_)
{
	SetName(name_);
	SetDiscription(discription_);
	SetActionType(action_);
	SetTargetType(target_);
	SetInteractionType(interaction_);
	SetActionID(actionID_);
	duration = duration_;
	equationObject = new Equation(data_.generalScalar, data_.rise, data_.run, data_.xIntercept, data_.equationType);
}
AbilityAction::AbilityAction(AbilityAction* const other_)
{
	SetName(other_->ReturnName());
	SetDiscription(other_->ReturnDiscription());
	SetActionType(other_->ReturnActionType());
	SetTargetType(other_->ReturnTargetType());
	SetInteractionType(other_->ReturnInteractionType());
	SetActionID(other_->ReturnActionID());
	duration = other_->ReturnDuration();
	abilityValue = other_->ReturnAbilityValue();
	equationObject = other_->ReturnEquationObject();

}
AbilityAction::AbilityAction(AbilityData const data_)
{
	SetName(data_.name);
	SetDiscription(data_.discription);
	SetActionType(data_.actionType);
	SetActionID(data_.actionID);
	SetInteractionType(data_.interactionType);
	SetTargetType(data_.targetType);
	duration = data_.duration;
	abilityValue = data_.abilityValue;
	equationObject = new Equation(data_.generalScaler, data_.rise, data_.run, data_.xIntercept, data_.equationType);
}
float AbilityAction::CalculateAbilityValue()
{
	//TO DO: implement an equation class.
	return equationObject->DetermineEquation(abilityValue);
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
void AbilityAction::SetAbilityValue(const float value_)
{
	abilityValue = value_;
}
float AbilityAction::ReturnAbilityValue() const
{
	return abilityValue;
}
void AbilityAction::OnDestroy()
{
	//This will clear out any data.
}
Equation* AbilityAction::ReturnEquationObject() const
{
	return equationObject;
}
AbilityAction::~AbilityAction()
{
	OnDestroy();
}
