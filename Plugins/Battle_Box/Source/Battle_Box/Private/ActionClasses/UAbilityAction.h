// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "Equation.h"

class Equation;
struct AbilityData;
/****/

struct EquationData
{
	EQUATION_TYPE equationType;
	float generalScalar;
	float rise;
	float run;
	float xIntercept;
};
enum class ABILITYTYPE
{
	E_MODIFIYER = 1,
	E_TMP_MODIFIYER,
	E_DAMAGE_MODIFYER 
};
class BATTLE_BOX_API UAbilityAction : public UBaseAction
{
private: 
	float duration;
	float abilityValue;
	ABILITYTYPE abilityType;
	TMap<FString, float> modStatMap;
	Equation* equationObject;
	float CalculateAbilityValue();

public:
	UAbilityAction();
	bool Init(const FString name_, const FString discription_, const ACTIONTYPE action_, const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_,
				  TMap<FString, float> statMap_, const float duration_, const ABILITYTYPE type_, const EquationData data_);
	bool Init(UAbilityAction* const other_);
	bool Init(AbilityData const data_);

	void SetAbilityType(const ABILITYTYPE type_);
	void SetAbilityValue(const float value_);
	void SetDuration(const float duration_);
	Equation* ReturnEquationObject() const;
	float ReturnDuration() const;
	float ReturnAbilityValue() const;
	TMap<FString, float> ReturnModStatMap();
	ABILITYTYPE ReturnAbilityType() const;
	void OnDestroy();
	~UAbilityAction();
};
