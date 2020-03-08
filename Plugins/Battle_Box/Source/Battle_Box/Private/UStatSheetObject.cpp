// Fill out your copyright notice in the Description page of Project Settings.


#include "UStatSheetObject.h"
#include "ActionClasses/UCommandAction.h"
#include "ActionClasses/UItemAction.h"
#include "ActionClasses/UAbilityAction.h"
#include "ResourceLoader.h"
#include "Debugger.h"

UStatSheetObject::UStatSheetObject() : commandMap(TMap<FString, UCommandAction*>()), itemMap(TMap<FString, UItemAction*>()), abilityMap(TMap<FString, UAbilityAction*>()), statMap(TMap<FString, float>()), equipmentMap(TMap<FString, UItemAction*>())
{
	name = "";
	tag = "";
}
bool UStatSheetObject::Init(const FString name_, const FString tag_, const TMap<FString, UCommandAction*>  commandMap_, const TMap<FString, UItemAction*>  itemMap_, const TMap<FString, UAbilityAction*>  abilityMap_, const TMap<FString, float> statMap_, const TMap<FString, UItemAction*>  equipmentMap_)
{
	name = name_;
	tag = tag_;
	commandMap = commandMap_;
	itemMap = itemMap_;
	abilityMap = abilityMap_;
	equipmentMap = equipmentMap_;
	if (&commandMap || &itemMap || &abilityMap || &equipmentMap)
		return true;
	else
		return false;
}
bool UStatSheetObject::Init(UStatSheetObject* const other_)
{
	name = other_->ReturnName();
	tag = other_->ReturnTag();
	commandMap = other_->ReturnCommandMap();
	itemMap = other_->ReturnItemMap();
	abilityMap = other_->ReturnAbilityMap();
	equipmentMap = other_->ReturnEquipmentMap();
	statMap = other_->ReturnStatMap();
	if (&commandMap || &itemMap || &abilityMap || &equipmentMap)
		return true;
	else
		return false;
}
bool UStatSheetObject::Init(StatSheetData const data_)
{
	name = data_.name;
	tag = data_.tag;
	statMap = data_.statMap;
	for(uint32 ID : data_.commandMapID)
	{
		if (ResourceLoader::GetInstance()->CheckAction(ID))
		{
			if(ResourceLoader::GetInstance()->ReturnAction(ID)->ReturnActionType() == ACTIONTYPE::E_COMMAND)
			{
				UCommandAction* command = dynamic_cast<UCommandAction*>(ResourceLoader::GetInstance()->ReturnAction(ID));
				commandMap.Add(command->ReturnName(), command);
			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("Action command was not Added to the map.", "UStatSheetObject.cpp", __LINE__);
			}
		}
		else
		{
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("No Action command was found with this ID.", "UStatSheetObject.cpp", __LINE__);
		}
	}

	for (uint32 ID : data_.itemMapID)
	{
		if (ResourceLoader::GetInstance()->CheckAction(ID))
		{
			if (ResourceLoader::GetInstance()->ReturnAction(ID)->ReturnActionType() == ACTIONTYPE::E_ITEM)
			{
				UItemAction* item = dynamic_cast<UItemAction*>(ResourceLoader::GetInstance()->ReturnAction(ID));
				itemMap.Add(item->ReturnName(), item);
			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("Action Item was not Added to the map.", "UStatSheetObject.cpp", __LINE__);
			}
		}
		else
		{
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("No Action Item was found with this ID.", "UStatSheetObject.cpp", __LINE__);
		}
	}
	for (uint32 ID : data_.abilityMapID)
	{
		if (ResourceLoader::GetInstance()->CheckAction(ID))
		{
			if (ResourceLoader::GetInstance()->ReturnAction(ID)->ReturnActionType() == ACTIONTYPE::E_ABILITY)
			{
				UAbilityAction* ability = dynamic_cast<UAbilityAction*>(ResourceLoader::GetInstance()->ReturnAction(ID));
				abilityMap.Add(ability->ReturnName(), ability);
			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("Action Ability was not Added to the map.", "UStatSheetObject.cpp", __LINE__);
			}
		}
		else
		{
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("No Action Ability was found with this ID.", "UStatSheetObject.cpp", __LINE__);
		}
	}
	for (uint32 ID : data_.equipmentMapID)
	{

		if (ResourceLoader::GetInstance()->CheckAction(ID))
		{
			if (ResourceLoader::GetInstance()->ReturnAction(ID)->ReturnActionType() == ACTIONTYPE::E_ITEM)
			{
				UItemAction* equipment = dynamic_cast<UItemAction*>(ResourceLoader::GetInstance()->ReturnAction(ID));
				equipmentMap.Add(equipment->ReturnName(), equipment);
			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("Action Equipment was not Added to the map.", "UStatSheetObject.cpp", __LINE__);
			}
		}
		else
		{
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("No Action Item was found with this ID.", "UStatSheetObject.cpp", __LINE__);
		}
	}
	//Note: This part is where you search through the id list 
	//and find the action in the resource class
	//data.commandIDs
	//data.ItemIDs
	//data.abilityIDs
	//data.equipmentIDs
	if (&commandMap || &itemMap || &abilityMap || &equipmentMap)
		return true;
	else
		return false;
	
}
void UStatSheetObject::SetName(const FString name_)
{
	name = name_;
}
void UStatSheetObject::SetTag(const FString tag_)
{
	tag = tag_;
}
FString UStatSheetObject::ReturnName() const
{
	return name;
}
FString UStatSheetObject::ReturnTag() const 
{
	return tag;
}
void UStatSheetObject::AddCommandAction(UCommandAction* const command_)
{
	commandMap.Add(command_->ReturnName(), command_);
}
void UStatSheetObject::AddItemAction(UItemAction* const item_)
{
	itemMap.Add(item_->ReturnName(), item_);
}
void UStatSheetObject::AddAbilityAction(UAbilityAction* const ability_)
{
	abilityMap.Add(ability_->ReturnName(), ability_);
}
void UStatSheetObject::AddEquipment(UItemAction* const equipment_)
{
	equipmentMap.Add(equipment_->ReturnName(), equipment_);
}
void UStatSheetObject::RemoveCommandAction(const FString name_)
{
	commandMap.Remove(name_);
}
void UStatSheetObject::RemoveItemAction(const FString name_)
{
	itemMap.Remove(name_);
}
void UStatSheetObject::RemoveAbilityAction(const FString name_)
{
	abilityMap.Remove(name_);
}
void UStatSheetObject::RemoveEquipment(const FString name_)
{
	equipmentMap.Remove(name);
}
UCommandAction* UStatSheetObject::ReturnCommand(FString name_) const
{
	if (!commandMap.Find(name_))
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Command action " + name_ + " could not be found", "UStatSheetObject.cpp", __LINE__);
		return nullptr;
	}
		return commandMap[name_];
}
UItemAction* UStatSheetObject::ReturnItem(const FString name_) const
{
	if (!itemMap.Find(name_))
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Item action " + name_ + " could not be found", "UStatSheetObject.cpp", __LINE__);
		return nullptr;
	}
		return itemMap[name_];
}
UAbilityAction* UStatSheetObject::ReturnAbility(const FString name_) const
{
	if (!abilityMap.Find(name_))
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Ability action " + name_ + " could not be found", "UStatSheetObject.cpp", __LINE__);
		return nullptr;
	}
	
	return abilityMap[name_];
}
UItemAction* UStatSheetObject::ReturnEquipment(const FString name_) const
{
	if (!equipmentMap.Find(name_))
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Equipment action " + name_ + " could not be found", "UStatSheetObject.cpp", __LINE__);
		return nullptr;
	}
		return equipmentMap[name_];
}
TMap<FString, UCommandAction*> UStatSheetObject::ReturnCommandMap() const
{
	return commandMap;
}
TMap<FString, UItemAction*> UStatSheetObject::ReturnItemMap() const
{
	return itemMap;
}
TMap<FString, UAbilityAction*> UStatSheetObject::ReturnAbilityMap() const
{
	return abilityMap;
}
TMap<FString, float> UStatSheetObject::ReturnStatMap() const
{
	return statMap;
}
TMap<FString, UItemAction*> UStatSheetObject::ReturnEquipmentMap() const
{
	return equipmentMap;
}
void UStatSheetObject::OnDestroy()
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
UStatSheetObject::~UStatSheetObject()
{
	OnDestroy();
}
