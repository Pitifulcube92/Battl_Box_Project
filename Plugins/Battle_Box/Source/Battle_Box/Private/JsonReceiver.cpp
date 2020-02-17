// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JsonReceiver.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "Misc/Paths.h"
#include "Equation.h"
#include "Templates/Casts.h"
#include "BattleBoxFileManager.h"
#include "Serialization/JsonSerializer.h"
#include "../Battle_Box/Private/StatSheetObject.h"
#include "../Battle_Box/Private/ActionClasses/BaseAction.h"
#include "../Battle_Box/Private/ActionClasses/CommandAction.h"
#include "../Battle_Box/Private/ActionClasses/ItemAction.h"
#include "../Battle_Box/Private/ActionClasses/AbilityAction.h"

///////////////////////////////////////////////////////
//	*STAT_SHEET_INFO*
//NAME 
//TAG
//COMMAND_ID_LIST
//ITEM_ID_LIST
//ABILITY_ID_LIST
//STAT_ID_LIST
//EQUIPMENT_ID_LIST
//////////////////////////////////////////////////////
//		*COMMAND_ACTION_INFO*
//	NAME 
//	DISCRIPTION
//	ACTIONTYPE
//	TARGETTYPE
//	STATTYPE
//	INTERACTIONTYPE
//	ACTION_ID
//	WEAPONTYPE
//	COMMAND
//////////////////////////////////////////////////////
//		*ITEM_ACTION_INFO*
//	NAME 
//	DISCRIPTION
//	ACTIONTYPE
//	TARGETTYPE
//	STATTYPE
//	INTERACTIONTYPE
//	ACTION_ID
//	ITEMTYPE 
//	VALUE
//	EFFECT_ID_LIST 
//	STAT_MOD_LIST
//	DAMAGETYPE
//////////////////////////////////////////////////////
//		*ABILITY_ACTION_INFO*
//	NAME 
//	DISCRIPTION
//	ACTIONTYPE
//	TARGETTYPE
//	STATTYPE
//	INTERACTIONTYPE
//	ACTION_ID
//	DURATION
//	ABILITY_VALUE
//	MODSTAT_LIST
//////////////////////////////////////////////////////



JsonReceiver::JsonReceiver()
{
}
void JsonReceiver::InitiateClass()
{
	JsonObject = MakeShareable(new FJsonObject);
	Directory = FPaths::ProjectPluginsDir() + "/Battle_Box/FileResource";
	JsonWriter = TJsonWriterFactory<>::Create(&writeFileString);
	BattleBoxFileManager::VerifyOnCreateDirectory(Directory);
}
StatSheetObject* JsonReceiver::ReadStatSheetObject(const FString fileName_)
{		
	//This will read from a json file for statsheetobject
	//TODO:: 
	readFileString = BattleBoxFileManager::ReadFile(Directory + "/StatSheets", fileName_);
	JsonReader = TJsonReaderFactory<>::Create(readFileString);
	if (FJsonSerializer::Deserialize(JsonReader.ToSharedRef(), JsonObject))
	{
		StatSheetData data;
		data.name = JsonObject.Get()->GetStringField("Name");
		data.tag = JsonObject.Get()->GetStringField("Tag");

		TSharedPtr<FJsonObject> statObject = JsonObject.Get()->GetObjectField("StatObject");

		data.statMap.Add("HP", (float)statObject.Get()->GetNumberField("HP"));
		data.statMap.Add("HP", (float)statObject.Get()->GetNumberField("MP"));
		data.statMap.Add("Atk", (float)statObject.Get()->GetNumberField("Atk"));
		data.statMap.Add("MagicAttack", (float)statObject.Get()->GetNumberField("SpecialAttack"));
		data.statMap.Add("Defence", (float)statObject.Get()->GetNumberField("Defence"));
		data.statMap.Add("MagicDefence", (float)statObject.Get()->GetNumberField("MagicDefence"));
	}
	//Create the sheet then
	//Note:This function should return the StatSheetObject.
}
BaseAction* JsonReceiver::ReadActionObject(const FString& fileName_)
{
	//This will read from a json file for action object
	//TODO:: Get the Functiuon to return a base action.
	//Create the dirived class and return it as a base action.

	readFileString = BattleBoxFileManager::ReadFile(Directory + "/ActionSheets", fileName_);
	JsonReader = TJsonReaderFactory<>::Create(readFileString);
	if (FJsonSerializer::Deserialize(JsonReader.ToSharedRef(), JsonObject))
	{
		//RTTI to find what the dirived action is 
		ACTIONTYPE action =  static_cast<ACTIONTYPE>((int)JsonObject.Get()->GetNumberField("ActionType"));
		if (action == ACTIONTYPE::E_COMMAND)
		{
			CommandData data;
			data.name = JsonObject.Get()->GetStringField("Name");
			data.discription = JsonObject.Get()->GetStringField("Discription");
			data.actionID = static_cast<uint32>((int)JsonObject.Get()->GetNumberField("ActionID"));
			data.actionType = static_cast<ACTIONTYPE>((int)JsonObject.Get()->GetNumberField("ActionType"));
			data.targetType = static_cast<TARGETTYPE>((int)JsonObject.Get()->GetNumberField("TargetType"));
			
			double tmp;
			if (JsonObject.Get()->TryGetNumberField("StatAction", tmp))
				data.statAction = static_cast<STATACTION>((int)JsonObject.Get()->GetNumberField("StatAction"));
			else
				data.statAction = STATACTION::E_NONE;
			data.currentWeapon = static_cast<WEAPONTYPE>((int)JsonObject.Get()->GetNumberField("CurrentWeapon"));
			data.commandActionID = static_cast<uint32>(JsonObject.Get()->GetNumberField("BaseActionID"));

			//Instatiate CommandAction
			//Return CommandAction
		}
		if (action == ACTIONTYPE::E_ITEM)
		{
			ItemData data;
			data.name = JsonObject.Get()->GetStringField("Name");
			data.discription = JsonObject.Get()->GetStringField("Discription");
			data.actionID = static_cast<uint32>((int)JsonObject.Get()->GetNumberField("ActionID"));
			data.actionType = static_cast<ACTIONTYPE>((int)JsonObject.Get()->GetNumberField("ActionType"));
			data.targetType = static_cast<TARGETTYPE>((int)JsonObject.Get()->GetNumberField("TargetType"));

			double tmp;
			if (JsonObject.Get()->TryGetNumberField("StatAction", tmp))
				data.statAction = static_cast<STATACTION>((int)JsonObject.Get()->GetNumberField("StatAction"));
			else
				data.statAction = STATACTION::E_NONE;

			data.itemType = static_cast<ITEMTYPE>((int)JsonObject.Get()->GetIntegerField("ItemAction"));
			data.value = JsonObject.Get()->GetIntegerField("Value");
			data.effectIDList = TArray<uint32>(JsonObject.Get()->GetArrayField("EffectListID"));

			//Instantiate ItemAction
			//Return ItemAction
		}
		if (action == ACTIONTYPE::E_ABILITY)
		{
			AbilityData data;
			data.name = JsonObject.Get()->GetStringField("Name");
			data.discription = JsonObject.Get()->GetStringField("Discription");
			data.actionID = static_cast<uint32>((int)JsonObject.Get()->GetNumberField("ActionID"));
			data.actionType = static_cast<ACTIONTYPE>((int)JsonObject.Get()->GetNumberField("ActionType"));
			data.targetType = static_cast<TARGETTYPE>((int)JsonObject.Get()->GetNumberField("TargetType"));

			double tmp;
			if (JsonObject.Get()->TryGetNumberField("StatAction", tmp))
				data.statAction = static_cast<STATACTION>((int)JsonObject.Get()->GetNumberField("StatAction"));
			else
				data.statAction = STATACTION::E_NONE;
			data.abilityType = static_cast<ABILITYTYPE>((int)JsonObject.Get()->GetNumberField("AbilityType"));
			data.duration = static_cast<float>(JsonObject.Get()->GetNumberField("Duration"));
			data.abilityValue = static_cast<float>(JsonObject.Get()->GetNumberField("AbilityValue"));

			//Instatiate AbilityAction
			//return AbilityAction
		}
	}
}
Equation* JsonReceiver::ReadEquationObject(const FString& fileName_)
{
	//This will read from a json file for equation object
	//TODO::
}
void JsonReceiver::WriteStatSheetObject(StatSheetObject* const sheet_)
{
	//This will write to a json file for a statsheetobject
	//TODO: Write the object, serialize, save it to a file
	//Note: Make that takes in IDs instead of than actual maps.

	JsonObject.Get()->SetStringField("Name", sheet_->ReturnName());
	JsonObject.Get()->SetStringField("Tag", sheet_->ReturnTag());
	JsonObject.Get()->SetArrayField("Commands", MakeIDJsonArray(sheet_, "commands"));
	JsonObject.Get()->SetArrayField("Items", MakeIDJsonArray(sheet_, "items"));
	JsonObject.Get()->SetArrayField("abilities", MakeIDJsonArray(sheet_, "abilites"));
	JsonObject.Get()->SetArrayField("equipment", MakeIDJsonArray(sheet_, "equipment"));
	TSharedPtr<FJsonObject> StatObject;

	//This does not work when you re-enginer.
	for (auto& i : sheet_->ReturnStatMap())
	{
		StatObject.Get()->SetNumberField(i.Key, (double)i.Value);
	}
	JsonObject.Get()->SetObjectField("StatObject", StatObject);

	
	FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter.ToSharedRef());
	BattleBoxFileManager::WriteTextFile(Directory, writeFileString, sheet_->ReturnName() + ".json", false);
	ResetJsonObject();
}
void JsonReceiver::WriteActionObject(BaseAction* const action_)
{
	//This will write to a json file for a action object
	//TODO:: Write the object, serialize, save it to a file.
	

	if (action_->ReturnActionType() == ACTIONTYPE::E_COMMAND)
	{
		CommandAction* command = dynamic_cast<CommandAction*>(action_);

		JsonObject.Get()->SetStringField("Name", command->ReturnName());
		JsonObject.Get()->SetStringField("Discription", command->ReturnDiscription());
		JsonObject.Get()->SetNumberField("ActionID", static_cast<double>(command->ReturnActionID()));
		JsonObject.Get()->SetNumberField("ActionType", static_cast<double>(command->ReturnActionID()));
		JsonObject.Get()->SetNumberField("TargetType", static_cast<double>(command->ReturnTargetType()));
		JsonObject.Get()->SetNumberField("StatAction", static_cast<double>(command->ReturnStatActionType()));
		JsonObject.Get()->SetNumberField("InteractionType", static_cast<double>(command->ReturnInteractionType()));
		JsonObject.Get()->SetNumberField("CurrentWeapon", static_cast<double>(command->ReturnWeaponType()));
		JsonObject.Get()->SetNumberField("BaseActionID", static_cast<double>(command->ReturnAction()->ReturnActionID()));

		JsonWriter = TJsonWriterFactory<>::Create(&writeFileString);
		BattleBoxFileManager::WriteTextFile(Directory, writeFileString, action_->ReturnName() + ".json", false);
	}
	if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
	{
		ItemAction* Item = dynamic_cast<ItemAction*>(action_);

		JsonObject.Get()->SetStringField("Name", Item->ReturnName());
		JsonObject.Get()->SetStringField("Discription", Item->ReturnDiscription());
		JsonObject.Get()->SetNumberField("ActionID", static_cast<double>(Item->ReturnActionID()));
		JsonObject.Get()->SetNumberField("ActionType", static_cast<double>(Item->ReturnActionID()));
		JsonObject.Get()->SetNumberField("TargetType", static_cast<double>(Item->ReturnTargetType()));
		JsonObject.Get()->SetNumberField("StatAction", static_cast<double>(Item->ReturnStatActionType()));
		JsonObject.Get()->SetNumberField("InteractionType", static_cast<double>(Item->ReturnInteractionType()));
		JsonObject.Get()->SetNumberField("ItemType", static_cast<double>(Item->ReturnItemType()));
		JsonObject.Get()->SetNumberField("Value", static_cast<double>(Item->ReturnValue()));
		JsonObject.Get()->SetNumberField("DamageType", static_cast<double>(Item->ReturnDamageType()));

		TArray<TSharedPtr<FJsonValue>> Array;
		TSharedPtr<FJsonObject> statObject;
		
		for (auto& i : Item->ReturnEffectList())
		{
			TSharedPtr<FJsonValue> value = MakeShareable(new FJsonValueNumber(i->ReturnActionID()));
			Array.Add(value);
		}
		JsonObject.Get()->SetArrayField("EffectListID", Array);
		for (auto& i : Item->ReturnStatMap())
		{
			statObject.Get()->SetNumberField(i.Key, i.Value);
		}
		JsonWriter = TJsonWriterFactory<>::Create(&writeFileString);
		BattleBoxFileManager::WriteTextFile(Directory, writeFileString, action_->ReturnName() + ".json", false);
	}
	if(action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
	{
		AbilityAction* Ability = dynamic_cast<AbilityAction*>(action_);

		JsonObject.Get()->SetStringField("Name", Ability->ReturnName());
		JsonObject.Get()->SetStringField("Discription", Ability->ReturnDiscription());
		JsonObject.Get()->SetNumberField("ActionID", static_cast<double>(Ability->ReturnActionID()));
		JsonObject.Get()->SetNumberField("ActionType", static_cast<double>(Ability->ReturnActionID()));
		JsonObject.Get()->SetNumberField("TargetType", static_cast<double>(Ability->ReturnTargetType()));
		JsonObject.Get()->SetNumberField("StatAction", static_cast<double>(Ability->ReturnStatActionType()));
		JsonObject.Get()->SetNumberField("InteractionType", static_cast<double>(Ability->ReturnInteractionType()));
		JsonObject.Get()->SetNumberField("Duration", static_cast<double>(Ability->ReturnDuration()));
		JsonObject.Get()->SetNumberField("AbilityValue", static_cast<double>(Ability->ReturnAbilityValue()));
		JsonObject.Get()->SetNumberField("AbilityType", static_cast<double>(Ability->ReturnAbilityType()));
		TArray<TSharedPtr<FJsonValue>> Array;
		
	JsonWriter = TJsonWriterFactory<>::Create(&writeFileString);
	BattleBoxFileManager::WriteTextFile(Directory, writeFileString, action_->ReturnName() + ".json", false);
	}
	ResetJsonObject();
}
void JsonReceiver::WriteEquationObject()
{
	//This will write to a json file for a equation object.
	//TODO:: Write the object, serialize, save it to a file.
}
TArray<TSharedPtr<FJsonValue>> JsonReceiver::MakeIDJsonArray(StatSheetObject* const sheet_, const FString Name_)
{
	TArray<TSharedPtr<FJsonValue>> Array;
	
	if (Name_ == "commands")
	{
		for (auto& i : sheet_->ReturnCommandMap())
		{
			TSharedPtr<FJsonValue> value = MakeShareable(new FJsonValueNumber(static_cast<double>(i.Value->ReturnActionID())));
			Array.Add(value);
		}
	}
	if (Name_ == "items")
	{
		for (auto& i : sheet_->ReturnItemMap())
		{
			TSharedPtr<FJsonValue> value = MakeShareable(new FJsonValueNumber(static_cast<double>(i.Value->ReturnActionID())));
			Array.Add(value);
		}
	}
	if (Name_ == "abilities")
	{
		for (auto& i : sheet_->ReturnAbilityMap())
		{
			TSharedPtr<FJsonValue> value = MakeShareable(new FJsonValueNumber(static_cast<double>(i.Value->ReturnActionID())));
			Array.Add(value);
		}
	}
	if (Name_ == "equipmint")
	{
		for (auto& i : sheet_->ReturnEquipmentMap())
		{
			TSharedPtr<FJsonValue> value = MakeShareable(new FJsonValueNumber(static_cast<double>(i.Value->ReturnActionID())));
			Array.Add(value);
		}
	}
	return Array;
}
bool JsonReceiver::ResetJsonObject()
{
	if (JsonObject.Get())
	{
		JsonObject.Reset();
		return true;
	}
	return false;
}
JsonReceiver::~JsonReceiver()
{
}
