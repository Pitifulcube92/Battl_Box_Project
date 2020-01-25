// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#ifndef EFFECTSYSTEM_H
#define EFFECTSYSTEM_H
#include "BaseSystem.h"
#include "Containers/Array.h"
class StatSheetObject;
class BaseAction;

class EffectSystem : public BaseSystem
{
private:
	StatSheetObject* target;
	TArray<StatSheetObject*> targets;
	BaseAction* targetAction;
public:
	EffectSystem();
	void BaseCalculate(const bool IsSingleTarget_, BaseAction* const action_); \
	///Calculates the effect	
	void CallculateEffect(BaseAction* action_);	
	///Removes the effect by the action.
	void RemoveEffect(BaseAction* action_);
	///Sets target
	void SetTarget(StatSheetObject* target_);
	///Add target to the target array
	void Addtarget(StatSheetObject* target_);
	void OnDestroy();
	~EffectSystem();
};
#endif // !EFFECTSYSTEM_H
