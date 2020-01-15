// Fill out your copyright notice in the Description page of Project Settings.

#ifndef ABILITYACTION_H		
#define ABILITYACTION_H
#include "CoreMinimal.h"
#include "BaseAction.h"

/**
 * 
 */
class AbilityAction : public BaseAction
{
private: 
	float duration;
public:
	AbilityAction();
	AbilityAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_,
				  const float duration_);
	AbilityAction(AbilityAction* other_);
	~AbilityAction();
};
#endif // !1
