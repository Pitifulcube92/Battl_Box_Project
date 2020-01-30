// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#ifndef STATSYSTEM_H
#define STATSYSTEM_H
#include "Containers/Array.h"
class BaseAction;
class StatSheetObject;

class StatSystem
{
private:
	static StatSheetObject* target;
	static TArray<StatSheetObject*> targets;

	static void BaseCalculate(const bool IsSingleTarget_, BaseAction* const action_);
	///Adds the specific modification by the baseaction.
	static void AddStatModifier(StatSheetObject* const target_, BaseAction* const action_);
	///Removes the specific modification by the baseaction.
	static void RemoveModifier(StatSheetObject* const target_, BaseAction* const action_);
	///Adds a modificationtemporarly.
	static void AddTmpModifier(StatSheetObject* const target_, BaseAction* const action_, const float duration_);
	///Removes a modification temporarly.
	static void RemoveTmpModifier(StatSheetObject* const target_, BaseAction*  action_, const float duration_);
public:
	StatSystem(const StatSystem&) = delete;
	StatSystem(StatSystem&&) = delete;
	StatSystem& operator =(const StatSystem&) = delete;
	StatSystem& operator =(StatSystem&&) = delete;
	StatSystem() = delete;

	static void CalculateStat(const bool IsSingleTarget_, BaseAction* const action_);
	///This updates the stats based on the name. 
	static void ModifiyStat(StatSheetObject* const target_, const float value, const FString name_);
	///Sets target.
	static void SetTarget(StatSheetObject* const target_);
	///Adds another target to the target array.
	static void Addtarget(StatSheetObject* const target_);
	static void OnDestroy();
	~StatSystem();
};

#endif // !STATSYSTEM_H
