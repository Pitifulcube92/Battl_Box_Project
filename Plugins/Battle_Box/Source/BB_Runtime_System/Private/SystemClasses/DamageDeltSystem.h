// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#ifndef DAMAGEDELTSYSTEM_H
#define DAMAGEDELTSYSTEM_H
#include "CoreMinimal.h"
#include "BaseSystem.h"
#include "Containers/Queue.h"
class StatSheetObject;

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
	void CalculateTotalDamage(const StatSheetObject* target_);
	float CalculateMagicDamage(const StatSheetObject* target_);
	float CalculatePhysicalDefence(const StatSheetObject* target_);
	float CalculateMagicalDefence(const StatSheetObject* target_);
	void SetOwner(StatSheetObject* const owner_);
	void SetTarget(StatSheetObject* const target_);
	void AddTargetToArray(StatSheetObject* const target_);
	void OnDestroy();
	float ReturnTotalDamageValue() const;
	TArray<float> ReturnDamageValues() const;
	~DamageDeltSystem();
};

#endif // !DAMAGEDELTSYSTEM_H

