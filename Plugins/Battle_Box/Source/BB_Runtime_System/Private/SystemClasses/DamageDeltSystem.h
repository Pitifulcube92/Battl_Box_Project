// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#ifndef DAMAGEDELTSYSTEM_H
#define DAMAGEDELTSYSTEM_H
#include "CoreMinimal.h"
#include "BaseSystem.h"
#include "Containers/Queue.h"
class StatSheetObject;
class ItemAction;
class AbilityAction;
class CommandAction;

class DamageDeltSystem : public BaseSystem
{
private:
	StatSheetObject* singleTarget;
	StatSheetObject* owner;
	TArray<StatSheetObject*> targets;
	float totalDamageValue;
	TArray<float> totalDamageValues;
public:
	DamageDeltSystem();
	void BaseCalculate(const bool IsSingledTarget_);
	float CalculateWeaponDamage(StatSheetObject* const target_);
	float CalculateMagicDamage(StatSheetObject* const target_);
	float CalculateCommandDamage(CommandAction* const targetCommand_);
	float CalculateAbilityDamage(AbilityAction* const targetAbility_);
	float ClaculateItemDamage(ItemAction* const targetItem_);
	float CalculatePhysicalDefence(StatSheetObject* const target_);
	float CalculateMagicalDefence(StatSheetObject* const target_);
	void SetOwner(StatSheetObject* const owner_);
	void SetTarget(StatSheetObject* const target_);
	void AddTargetToArray(StatSheetObject* const target_);
	void OnDestroy();
	float ReturnTotalDamageValue() const;
	TArray<float> ReturnDamageValues() const;
	~DamageDeltSystem();
};

#endif // !DAMAGEDELTSYSTEM_H

