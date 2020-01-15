// Fill out your copyright notice in the Description page of Project Settings.

#ifndef ITEMACTION_H
#define ITEMACTION_H
#include "CoreMinimal.h"
#include "BaseAction.h"
#include "Containers/Array.h"
class AbilityAction;
/**
 * 
 */
class ItemAction : public BaseAction 
{
private:
	uint32 value;
	TArray<AbilityAction*> effectList;
	DAMAGETYPE damageType;
public:
	ItemAction();
	ItemAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const  TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, const uint32 value_, const DAMAGETYPE damageType_, const TArray<AbilityAction*> effectArray_);
	ItemAction(const ItemAction* other_);
	void SetValue(const uint32 value_);
	void AddEffect(const AbilityAction* ability_);
	uint32 ReturnValue();
	TArray<AbilityAction*> ReturnEffectList();
	~ItemAction();
};

#endif // !1

