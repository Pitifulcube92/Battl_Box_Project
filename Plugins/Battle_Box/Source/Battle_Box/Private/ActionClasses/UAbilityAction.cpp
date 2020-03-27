// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "../Public/ActionClasses/UAbilityAction.h"
#include "../Battle_Box/Public/UBaseStatusEffect.h"
FAbilityAction_Info UAbilityAction::GetAbilityInfo() const
{
	return abilityInfo;
}
void UAbilityAction::ActivateEffect() const
{
	for (auto e : abilityInfo.effects)
	{
		e->CallEffect();
	}
}