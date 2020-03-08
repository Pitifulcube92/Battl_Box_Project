// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
class UAbilityAction;
struct ItemData;
/**
 * 
 */
enum class ITEMTYPE
{
	E_NONE = 1,
	E_CONSUMABLE,
	E_ARMOR,
	E_WEAPON,
	E_KEY_ITEM
};

class BATTLE_BOX_API UItemAction : public UBaseAction
{
private:
	ITEMTYPE type;
	uint32 value;
	TArray<UAbilityAction*> effectList;
	TMap<FString, float> statModMap;
	DAMAGETYPE damageType;	
public:
	UItemAction();
	bool Init(const FString name_, const FString discription_, const ACTIONTYPE action_, const  TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, TMap<FString, float> statMap_, const uint32 value_, const DAMAGETYPE damageType_, const TArray<UAbilityAction*> effectArray_);
	bool Init(const UItemAction* other_);
	bool Init(ItemData const data_);
	///Set Item type
	void SetType(const ITEMTYPE type_);
	///Set item Value 
	void SetValue(const uint32 value_);
	///Set Damage type
	void SetDamageType(const DAMAGETYPE type_);
	///Adds an effect to the items effects array
	void AddEffect(UAbilityAction* const ability_);
	///Returns itemType
	ITEMTYPE ReturnItemType() const;
	///Returnsitem value. 
	uint32 ReturnValue() const;
	///Returns Damage type.
	DAMAGETYPE ReturnDamageType() const;
	///Returns Effect array.
	TArray<UAbilityAction*> ReturnEffectList() const;
	///Return statModMap
	TMap<FString, float> ReturnStatMap() const;
	void OnDestroy();
	~UItemAction();
	//Note: when creating item make the ability be calculated and store in the statsheet.
};
