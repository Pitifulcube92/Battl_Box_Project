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
	TMap<FString, float> statModMap;
	DAMAGETYPE damageType;	
public:
	ItemAction();
	ItemAction(const FString name_, const FString discription_, const ACTIONTYPE action_, const  TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, TMap<FString, float> statMap_, const uint32 value_, const DAMAGETYPE damageType_, const TArray<AbilityAction*> effectArray_);
	ItemAction(const ItemAction* other_);
	///Set Item type
	void SetType(const ITEMTYPE type_);
	///Set item Value 
	void SetValue(const uint32 value_);
	///Set Damage type
	void SetDamageType(const DAMAGETYPE type_);
	///Adds an effect to the items effects array
	void AddEffect(AbilityAction* const ability_);
	///Returns itemType
	ITEMTYPE ReturnItemType() const;
	///Returnsitem value. 
	uint32 ReturnValue() const;
	///Returns Damage type.
	DAMAGETYPE ReturnDamageType() const;
	///Returns Effect array.
	TArray<AbilityAction*> ReturnEffectList() const;
	///Return statModMap
	TMap<FString, float> ReturnStatMap() const;
	void OnDestroy();
	~ItemAction();
	//Note: when creating item make the ability be calculated and store in the statsheet.
};

#endif // !1

