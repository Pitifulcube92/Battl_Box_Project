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
	///Sets name 
	void SetName(const FString name_);
	///Sets tag
	void SetTag(const FString tag_);
	///Returns name
	FString ReturnName() const;
	///Returns tag
	FString ReturnTag() const;
	///Adds a command action the command map
	void AddCommandAction(CommandAction* const command_);
	///Adds a item action to the item map
	void AddItemAction(ItemAction* const item_);
	///Adds a ability action to the ability map
	void AddAbilityAction(AbilityAction* const ability_);
	///Adds a eqquipment-item action  to the equipmnet map
	void AddEquipment(ItemAction* const equipment_);
	///Removes a command action if there is one in the map
	void RemoveCommandAction(const FString name_);
	///Removes a item action if there is one in the map
	void RemoveItemAction(const FString name_);
	///Removes  a ability action if there is one in the map
	void RemoveAbilityAction(const FString name_);
	///Removes a equipment-type action if there is one in the map
	void RemoveEquipment(const FString name_);
	///Returns the commmand map 
	TMap<FString, CommandAction*> ReturnCommandMap() const;
	///Returns the item map
	TMap<FString, ItemAction*> ReturnItemMap() const;
	///Returns the ability map
	TMap<FString, AbilityAction*> ReturnAbilityMap() const;
	///Returns the statMap
	TMap<FString, float> ReturnStatMap() const;
	///Returns the equipment map
	TMap<FString, ItemAction*> ReturnEquipmentMap() const;
	///Returns a command action by its name from the command map 
	CommandAction* ReturnCommand(FString name_) const;
	///Returns a item action by its name from the item map
	ItemAction* ReturnItem(const FString name_) const;
	///Returns a ability action by its name from the ability map
	AbilityAction* ReturnAbility(const FString name_) const;
	///Returns a equipment-item action by its name from the equipment map
	ItemAction* ReturnEquipment(const FString name_) const;
	void OnDestroy();
	~StatSheetObject();
};
#endif // !1
