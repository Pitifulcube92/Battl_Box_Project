// Fill out your copyright notice in the Description page of Project Settings.

#ifndef STATSHEETOBJECT_H
#define STATSHEETOBJECT_H
#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
class ItemAction;
class CommandAction;
class AbilityAction;
/**
 * 
 */
class StatSheetObject
{
private:
	FString name;
	FString tag;
	TMap<FString, CommandAction*> commandMap;
	TMap<FString, ItemAction*> itemMap;
	TMap<FString, AbilityAction*> abilityMap;
	TMap<FString, float> statMap;
	TMap<FString, ItemAction*> equipmentMap;
	
public:
	StatSheetObject();
	StatSheetObject(const FString name_, const FString tag_, const TMap<FString, CommandAction*> commandMap_, const TMap<FString, ItemAction*> itemMap_, const TMap<FString, AbilityAction*> abilityMap_, const TMap<FString, float> statMap_, const TMap<FString, ItemAction*> equipmentMap_);
	StatSheetObject(StatSheetObject* const other_);
	void SetName(const FString name_);
	void SetTag(const FString tag_);
	FString ReturnName() const;
	FString ReturnTag() const;
	void AddCommandAction(CommandAction* const command_);
	void AddItemAction(ItemAction* const item_);
	void AddAbilityAction(AbilityAction* const ability_);
	void AddEquipment(ItemAction* const equipment_);
	void RemoveCommandAction(const FString name_);
	void RemoveItemAction(const FString name_);
	void RemoveAbilityAction(const FString name_);
	void RemoveEquipment(const FString name_);
	TMap<FString, CommandAction*> ReturnCommandMap() const;
	TMap<FString, ItemAction*> ReturnItemMap() const;
	TMap<FString, AbilityAction*> ReturnAbilityMap() const;
	TMap<FString, float> ReturnStatMap() const;
	TMap<FString, ItemAction*> ReturnEquipmentMap() const;
	CommandAction* ReturnCommand(FString name_) const;
	ItemAction* ReturnItem(const FString name_) const;
	AbilityAction* ReturnAbility(const FString name_) const;
	ItemAction* ReturnEquipment(const FString name_) const;
	void OnDestroy();
	~StatSheetObject();
};
#endif // !1
