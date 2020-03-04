// Fill out your copyright notice in the Description page of Project Settings.


#include "StatSheetObject.h"
#include "ActionClasses/CommandAction.h"
#include "ActionClasses/ItemAction.h"
#include "ActionClasses/AbilityAction.h"
#include "Debugger.h"

StatSheetObject::StatSheetObject() : commandMap(TMap<FString, CommandAction*>()), itemMap(TMap<FString, ItemAction*>()), abilityMap(TMap<FString, AbilityAction*>()), statMap(TMap<FString, float>()), equipmentMap(TMap<FString, ItemAction*>())
{
	name = "";
	tag = "";
}
StatSheetObject::StatSheetObject(const FString name_, const FString tag_, const TMap<FString, CommandAction*>  commandMap_, const TMap<FString, ItemAction*>  itemMap_, const TMap<FString, AbilityAction*>  abilityMap_, const TMap<FString, float> statMap_, const TMap<FString, ItemAction*>  equipmentMap_)
{
	name = name_;
	tag = tag_;
	commandMap = commandMap_;
	itemMap = itemMap_;
	abilityMap = abilityMap_;
	equipmentMap = equipmentMap_;
}
StatSheetObject::StatSheetObject(StatSheetObject* const other_)
{
	name = other_->ReturnName();
	tag = other_->ReturnTag();
	commandMap = other_->ReturnCommandMap();
	itemMap = other_->ReturnItemMap();
	abilityMap = other_->ReturnAbilityMap();
	equipmentMap = other_->ReturnEquipmentMap();
	statMap = other_->ReturnStatMap();

}
void StatSheetObject::SetName(const FString name_)
{
	name = name_;
}
void StatSheetObject::SetTag(const FString tag_)
{
	tag = tag_;
}
FString StatSheetObject::ReturnName() const
{
	return name;
}
FString StatSheetObject::ReturnTag() const 
{
	return tag;
}
void StatSheetObject::AddCommandAction(CommandAction* const command_)
{
	commandMap.Add(command_->ReturnName(), command_);
}
void StatSheetObject::AddItemAction(ItemAction* const item_)
{
	itemMap.Add(item_->ReturnName(), item_);
}
void StatSheetObject::AddAbilityAction(AbilityAction* const ability_)
{
	abilityMap.Add(ability_->ReturnName(), ability_);
}
void StatSheetObject::AddEquipment(ItemAction* const equipment_)
{
	equipmentMap.Add(equipment_->ReturnName(), equipment_);
}
void StatSheetObject::RemoveCommandAction(const FString name_)
{
	commandMap.Remove(name_);
}
void StatSheetObject::RemoveItemAction(const FString name_)
{
	itemMap.Remove(name_);
}
void StatSheetObject::RemoveAbilityAction(const FString name_)
{
	abilityMap.Remove(name_);
}
void StatSheetObject::RemoveEquipment(const FString name_)
{
	equipmentMap.Remove(name);
}
CommandAction* StatSheetObject::ReturnCommand(FString name_) const
{
	if (!commandMap.Find(name_))
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Command action " + name_ + " could not be found", "StatSheetObject.cpp", __LINE__);
		return nullptr;
	}
		return commandMap[name_];
}
ItemAction* StatSheetObject::ReturnItem(const FString name_) const
{
	if (!itemMap.Find(name_))
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Item action " + name_ + " could not be found", "StatSheetObject.cpp", __LINE__);
		return nullptr;
	}
		return itemMap[name_];
}
AbilityAction* StatSheetObject::ReturnAbility(const FString name_) const
{
	if (!abilityMap.Find(name_))
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Ability action " + name_ + " could not be found", "StatSheetObject.cpp", __LINE__);
		return nullptr;
	}
	
	return abilityMap[name_];
}
ItemAction* StatSheetObject::ReturnEquipment(const FString name_) const
{
	if (!equipmentMap.Find(name_))
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Equipment action " + name_ + " could not be found", "StatSheetObject.cpp", __LINE__);
		return nullptr;
	}
		return equipmentMap[name_];
}
TMap<FString, CommandAction*> StatSheetObject::ReturnCommandMap() const
{
	return commandMap;
}
TMap<FString, ItemAction*> StatSheetObject::ReturnItemMap() const
{
	return itemMap;
}
TMap<FString, AbilityAction*> StatSheetObject::ReturnAbilityMap() const
{
	return abilityMap;
}
TMap<FString, float> StatSheetObject::ReturnStatMap() const
{
	return statMap;
}
TMap<FString, ItemAction*> StatSheetObject::ReturnEquipmentMap() const
{
	return equipmentMap;
}
void StatSheetObject::OnDestroy()
{
	//Clear out all pointer within the maps
	if (commandMap.Num() > 0)
	{
		for(auto command : commandMap)
		{
			delete command.Value;
		}
		commandMap.Empty();
	}
}
StatSheetObject::~StatSheetObject()
{
	OnDestroy();
}
