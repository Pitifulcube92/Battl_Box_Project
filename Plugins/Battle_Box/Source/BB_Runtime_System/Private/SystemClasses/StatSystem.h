// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#ifndef STATSYSTEM_H
#define STATSYSTEM_H
#include "BaseSystem.h"
#include "Containers/Array.h"
class BaseAction;
class StatSheetObject;

class StatSystem : public BaseSystem
{
private:
	StatSheetObject* target;
	BaseAction* targetAction;
	TArray<StatSheetObject*> targets;
public:
	StatSystem();
	void BaseCalculate(const bool IsSingleTarget_, BaseAction* const action_);
	///Adds the specific modification by the baseaction.
	void AddStatModifier(BaseAction* const action_);
	///Removes the specific modification by the baseaction.
	void RemoveModifier(BaseAction* const action_);
	///Adds a temporary modifierby the base action.
	void AddTmpModifier(BaseAction* action_, const float duration_);
	///Sets target.
	void SetTarget(StatSheetObject* const target_);
	///Sets target action.
	void SetTargetAction(BaseAction* const action_);
	///Adds another target to the target array.
	void Addtarget(StatSheetObject* const target_);
	void OnDestroy();
	~StatSystem();
};

#endif // !STATSYSTEM_H
