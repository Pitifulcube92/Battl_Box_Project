// Fill out your copyright notice in the Description page of Project Settings.

#ifndef ABILITYACTION_H		
#define ABILITYACTION_H
#include "CoreMinimal.h"
#include "BaseAction.h"

/****/
class AbilityAction : public BaseAction
{
private: 
	float duration;
	float abilityValue;
public:
	AbilityAction();
	AbilityAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_,
				  TMap<FString, float> statMap_, const float duration_);
	AbilityAction(AbilityAction* const other_);
	void SetDuration(const float duration_);
	float ReturnDuration() const;
	float CalculateAbilityValue();
	~AbilityAction();
};
#endif // !1
