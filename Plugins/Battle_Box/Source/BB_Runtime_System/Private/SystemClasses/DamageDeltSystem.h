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

	//Claculates the damage of a weapon item.
	float CalculateWeaponDamage(ItemAction* const target_);
	//Calculates the damage of a ability item.
	float CalculateAbilityDamage(AbilityAction* const targetAbility_);
	//Calculates the damage of an item.
	float CalculateItemDamage(ItemAction* const targetItem_);
	//Calculates the physical defence of the target. 
	float CalculatePhysicalDefence(StatSheetObject* const target_);
	//Calculates the magical defence of the target.
	float CalculateMagicalDefence(StatSheetObject* const target_);
public:
	DamageDeltSystem();
	//System calculation
	void BaseCalculate(const bool IsSingledTarget_, BaseAction* const action_);
	//Sets who the owner of the damage.
	void SetOwner(StatSheetObject* const owner_);
	//Sets the target who is being damaged.
	void SetTarget(StatSheetObject* const target_);
	//Adds another target to the array.
	void AddTargetToArray(StatSheetObject* const target_);
	void OnDestroy();
	//returns the damage value.
	float ReturnTotalDamageValue() const;
	//returns the damage value array.
	TArray<float> ReturnDamageValues() const;
	~DamageDeltSystem();
};

#endif // !DAMAGEDELTSYSTEM_H

