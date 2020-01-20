// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "DamageDeltSystem.h"
#include "../Battle_Box/Private/StatSheetObject.h"

DamageDeltSystem::DamageDeltSystem() : singleTarget(nullptr), owner(nullptr), targets(TArray<StatSheetObject*>()), totalDamageValues(TArray<float>())
{
	totalDamageValue = 0.0f;
}
void DamageDeltSystem::BaseCalculate(const bool IsSingledTarget)
{

}
void DamageDeltSystem::CalculateTotalDamage(const StatSheetObject* target_)
{

}
float DamageDeltSystem::CalculateMagicDamage(const StatSheetObject* target_)
{
	float tmp = 0.0f;
	return tmp;
}
float DamageDeltSystem::CalculatePhysicalDefence(const StatSheetObject* target_)
{
	float tmp = 0.0f;
	return tmp;
}
float DamageDeltSystem::CalculateMagicalDefence(const StatSheetObject* target_)
{
	float tmp = 0.0f;
	return tmp;
}
void DamageDeltSystem::SetOwner(StatSheetObject* const owner_)
{
	owner = owner_;
}
void DamageDeltSystem::SetTarget(StatSheetObject* const target_)
{
	singleTarget = target_;
}
void DamageDeltSystem::AddTargetToArray(StatSheetObject* const target_)
{
	targets.Add(target_);
}
void DamageDeltSystem::OnDestroy()
{
	//clean up any pointers
}
float DamageDeltSystem::ReturnTotalDamageValue() const
{
	return totalDamageValue;
}
TArray<float> DamageDeltSystem::ReturnDamageValues() const
{
	return totalDamageValues;
}
DamageDeltSystem::~DamageDeltSystem()
{
	OnDestroy();
}