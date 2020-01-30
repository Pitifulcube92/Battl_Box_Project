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
	static StatSheetObject* singleTarget;
	static StatSheetObject* owner;
	static TArray<StatSheetObject*> targets;
	static float totalDamageValue;
	static TArray<float> totalDamageValues;

	///System calculation.
	static void BaseCalculate(const bool IsSingledTarget_, BaseAction* const action_);
	///Claculates the damage of a weapon item.
	static float CalculateWeaponDamage(ItemAction* const target_);
	///Calculates the damage of a ability item.
	static float CalculateAbilityDamage(AbilityAction* const targetAbility_);
	///Calculates the damage of an item.
	static float CalculateItemDamage(ItemAction* const targetItem_);
	///Calculates the physical defence of the target. 
	static float CalculatePhysicalDefence(StatSheetObject* const target_);
	///Calculates the magical defence of the target.
	static float CalculateMagicalDefence(StatSheetObject* const target_);
public:
	DamageDeltSystem(const DamageDeltSystem&) = delete;
	DamageDeltSystem(DamageDeltSystem&&) = delete;
	DamageDeltSystem& operator =(const DamageDeltSystem&) = delete;
	DamageDeltSystem& operator =(DamageDeltSystem&&) = delete;
	DamageDeltSystem() = delete;

	///Static moethod for the base function
	static void CalculateDamage(const bool IsSingledTarget_, BaseAction* const action_);
	///Sets who the owner of the damage.
	static void SetOwner(StatSheetObject* const owner_);
	///Sets the target who is being damaged.
	static void SetTarget(StatSheetObject* const target_);
	///Adds another target to the array.
	static void AddTargetToArray(StatSheetObject* const target_);
	static void OnDestroy();
	///Returns the damage value.
	static const float ReturnTotalDamageValue() ;
	///Returns the damage value array.
	static const TArray<float> ReturnDamageValues() ;
	~DamageDeltSystem();
};

#endif // !DAMAGEDELTSYSTEM_H

