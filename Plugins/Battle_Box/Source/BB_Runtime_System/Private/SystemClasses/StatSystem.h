//// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
//#ifndef STATSYSTEM_H
//#define STATSYSTEM_H
//#include "Containers/Array.h"
//class UBaseAction;
//class UStatSheetObject;
//
//class StatSystem
//{
//private:
//	static UStatSheetObject* target;
//	static TArray<UStatSheetObject*> targets;
//
//	static void BaseCalculate(const bool IsSingleTarget_, UBaseAction* const action_);
//	///Adds the specific modification by the UBaseAction.
//	static void AddStatModifier(UStatSheetObject* const target_, UBaseAction* const action_);
//	///Removes the specific modification by the UBaseAction.
//	static void RemoveModifier(UStatSheetObject* const target_, UBaseAction* const action_);
//	///Adds a modificationtemporarly.
//	static void AddTmpModifier(UStatSheetObject* const target_, UBaseAction* const action_, const float duration_);
//	///Removes a modification temporarly.
//	static void RemoveTmpModifier(UStatSheetObject* const target_, UBaseAction*  action_, const float duration_);
//public:
//	StatSystem(const StatSystem&) = delete;
//	StatSystem(StatSystem&&) = delete;
//	StatSystem& operator =(const StatSystem&) = delete;
//	StatSystem& operator =(StatSystem&&) = delete;
//	StatSystem() = delete;
//
//	static void CalculateStat(const bool IsSingleTarget_, UBaseAction* const action_);
//	///This updates the stats based on the name. 
//	static void ModifiyStat(UStatSheetObject* const target_, const float value, const FString name_);
//	///Sets target.
//	static void SetTarget(UStatSheetObject* const target_);
//	///Adds another target to the target array.
//	static void Addtarget(UStatSheetObject* const target_);
//	static void OnDestroy();
//	~StatSystem();
//};
//
//#endif // !STATSYSTEM_H
