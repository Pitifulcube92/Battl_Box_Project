// Fill out your copyright notice in the Description page of Project Settings.

#ifndef ITEMACTION_H
#define ITEMACTION_H
#include "CoreMinimal.h"
#include "BaseAction.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
class AbilityAction;
/**
 * 
 */
enum class SITUATIONTYPE
{
	E_NONE,
	E_BATTLE,
	E_UI
};
enum class ITEMTYPE
{
	E_NONE,
	E_CONSUMABLE,
	E_ARMOR,
	E_WEAPON,
	E_KEY_ITEM
};
class ItemAction : public BaseAction 
{
private:
	ITEMTYPE type;
	uint32 value;
	TArray<AbilityAction*> effectList;
	DAMAGETYPE damageType;
	TMap<FString, float> statMap;
public:
	ItemAction();
	ItemAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const  TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, const uint32 value_, const DAMAGETYPE damageType_, const TArray<AbilityAction*> effectArray_);
	ItemAction(const ItemAction* other_);
	void SetType(const ITEMTYPE type_);
	void SetValue(const uint32 value_);
	void SetDamageType(const DAMAGETYPE type_);
	void AddEffect(AbilityAction* const ability_);
	ITEMTYPE ReturnItemType() const;
	uint32 ReturnValue() const;
	DAMAGETYPE ReturnDamageType() const;
	TArray<AbilityAction*> ReturnEffectList() const;
	TMap<FString, float> ReturnStatMap() const;
	void OnDestroy();
	~ItemAction();
};

#endif // !1

