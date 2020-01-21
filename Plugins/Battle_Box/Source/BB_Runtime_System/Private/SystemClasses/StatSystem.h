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
	void BaseCalculate(const bool IsSingleTarget_);
	void AddStatModifier(BaseAction* const action_);
	void RemoveModifier(BaseAction* const action_);
	void AddTmpModifier(BaseAction* action_, const float duration_);
	void SetTarget(StatSheetObject* const target_);
	void SetTargetAction(BaseAction* const action_);
	void Addtarget(StatSheetObject* const target_);
	void OnDestroy();
	~StatSystem();
};

#endif // !STATSYSTEM_H
