// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#ifndef EFFECTSYSTEM_H
#define EFFECTSYSTEM_H
#include "Containers/Array.h"
class UStatSheetObject;
class UBaseAction;

class EffectSystem 
{
private:
	static UStatSheetObject* target;
	static TArray<UStatSheetObject*> targets;
	static UBaseAction* targetAction;
public:
	EffectSystem(const EffectSystem&) = delete;
	EffectSystem(EffectSystem&&) = delete;
	EffectSystem& operator = (const EffectSystem&) = delete;
	EffectSystem& operator = (EffectSystem&&) = delete;
	EffectSystem() = delete;

	static void BaseCalculate(const bool IsSingleTarget_, UBaseAction* const action_);
	///Calculates the effect	
	static void CallculateEffect(UBaseAction* action_);
	///Removes the effect by the action.
	static void RemoveEffect(UBaseAction* action_);
	///Sets target
	static void SetTarget(UStatSheetObject* target_);
	///Add target to the target array
	static void Addtarget(UStatSheetObject* target_);
	static void OnDestroy();
	~EffectSystem();
};
#endif // !EFFECTSYSTEM_H
