// Fill out your copyright notice in the Description page of Project Settings.
#ifndef DAMAGEDELTSYSTEM_H
#define DAMAGEDELTSYSTEM_H
#include "CoreMinimal.h"
#include "Containers/Queue.h"
class StatSheetObject;
/**
 * 
 */
class DamageDeltSystem
{
private:
	StatSheetObject* target;
	StatSheetObject* owner;
	TQueue<StatSheetObject*> targets;
	float totalDamageValue;
	TQueue<float> damageValues;
	float physicalDefenceValue;
	float magicDefenceValue;
public:
	DamageDeltSystem(const DamageDeltSystem&) = delete;
	DamageDeltSystem(DamageDeltSystem&&) = delete;
	DamageDeltSystem& operator=(const DamageDeltSystem&) = delete;
	DamageDeltSystem& operator=(DamageDeltSystem&&) = delete;
	~DamageDeltSystem();
};
#endif // !1
