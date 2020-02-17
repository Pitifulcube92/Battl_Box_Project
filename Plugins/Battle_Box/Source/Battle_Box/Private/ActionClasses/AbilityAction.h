// Fill out your copyright notice in the Description page of Project Settings.

#ifndef ABILITYACTION_H		
#define ABILITYACTION_H
#include "CoreMinimal.h"
#include "BaseAction.h"
struct AbilityData;
/****/

enum class ABILITYTYPE
{
	E_MODIFIYER = 1,
	E_TMP_MODIFIYER,
	E_DAMAGE_MODIFYER 
};
class BATTLE_BOX_API AbilityAction : public BaseAction
{
private: 
	float duration;
	float abilityValue;
	ABILITYTYPE abilityType;
	TMap<FString, float> modStatMap;
	float CalculateAbilityValue();

public:
	AbilityAction();
	AbilityAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_,
				  TMap<FString, float> statMap_, const float duration_, const ABILITYTYPE type_, const float abilityValue_);
	AbilityAction(AbilityAction* const other_);
	AbilityAction(AbilityData const data_);
	void SetAbilityType(const ABILITYTYPE type_);
	void SetAbilityValue(const float value_);
	void SetDuration(const float duration_);
	float ReturnDuration() const;
	float ReturnAbilityValue() const;
	TMap<FString, float> ReturnModStatMap();
	ABILITYTYPE ReturnAbilityType() const;
	void OnDestroy();
	~AbilityAction();
};
#endif // !1
