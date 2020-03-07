// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JsonParse.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "Misc/Paths.h"
#include "Equation.h"
#include "Templates/Casts.h"
#include "BattleBoxFileManager.h"
#include "ResourceLoader.h"
#include "Serialization/JsonSerializer.h"
#include "../Battle_Box/Private/UStatSheetObject.h"
#include "../Battle_Box/Private/ActionClasses/BaseAction.h"

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


JsonParse::JsonParse()
{
}
bool JsonParse::InitiateClass()
{
	JsonObject = MakeShareable(new FJsonObject);
	Directory = FPaths::ProjectPluginsDir() + "/Battle_Box/FileResource";
	JsonWriter = TJsonWriterFactory<>::Create(&writeFileString);
	JsonReader = TJsonReaderFactory<>::Create(readFileString);

	if (JsonObject && JsonWriter && JsonReader &&BattleBoxFileManager::VerifyOnCreateDirectory(Directory))
		return true;
	else
		return false;
}
UStatSheetObject* JsonParse::ReadStatSheetObject(const FString fileName_)
{		
	//This will read from a json file for UStatSheetObject
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
		data.statMap.Add("MagicAttack", (float)statObject.Get()->GetNumberField("MagicAttack"));
		data.statMap.Add("Defence", (float)statObject.Get()->GetNumberField("Defence"));
		data.statMap.Add("MagicDefence", (float)statObject.Get()->GetNumberField("MagicDefence"));

		UStatSheetObject* tmp = new UStatSheetObject(data);
		return tmp;
	}
	//Create the sheet then
	//Note:This function should return the UStatSheetObject.
	Debugger::SetSeverity(MessageType::E_ERROR);
	Debugger::Error("Json Parser Failed to parse UStatSheetObject", "JsonParse.cpp", __LINE__);
	return nullptr;
}
BaseAction* JsonParse::ReadActionObject(const FString& fileName_)
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
			
			CommandAction* temp = new CommandAction(data);
			return dynamic_cast<BaseAction*>(temp);
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
 
		//	data.effectIDList = (JsonObject.Get()->GetArrayField("EffectListID"));// this is causing a memory Conversion Error2440
			
			ItemAction* temp = new ItemAction(data);
			return dynamic_cast<BaseAction*>(temp);
		
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
			TSharedPtr<FJsonObject> equationObject = JsonObject.Get()->GetObjectField("EquationObject");
			data.equationType = static_cast<EQUATION_TYPE>(equationObject.Get()->GetIntegerField("EquationObject"));
			data.generalScaler = equationObject.Get()->GetNumberField("generalScale");
			data.rise = equationObject.Get()->GetNumberField("rise");
			data.run = equationObject.Get()->GetNumberField("run");
			data.xIntercept = equationObject.Get()->GetNumberField("xIntercept");

			AbilityAction* temp = new AbilityAction(data);
			return dynamic_cast<BaseAction*>(temp);
		
		}
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("Json Parser Failed to parse ActionObject ActionType", "JsonParse.cpp", __LINE__);
		return nullptr;
	}
	Debugger::SetSeverity(MessageType::E_ERROR);
	Debugger::Error("Json Parser Failed to parse ActionObject", "JsonParse.cpp", __LINE__);
	return nullptr;
}
void JsonParse::WriteStatSheetObject(UStatSheetObject* const sheet_)
{
	//This will write to a json file for a UStatSheetObject
	//TODO: Write the object, serialize, save it to a file
	//Note: Make that takes in IDs instead of than actual maps.
	Debugger::SetSeverity(MessageType::E_INFO);
	Debugger::Info(sheet_->ReturnName(), "JsonParser.cpp", __LINE__);

	JsonObject.Get()->SetStringField("Name",sheet_->ReturnName());
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
	BattleBoxFileManager::WriteTextFile(Directory + "/StatSheets", writeFileString,  sheet_->ReturnName()+".json", false);
	ResetJsonObject();
}
void JsonParse::WriteActionObject(BaseAction* const action_)
{
	//This will write to a json file for a action object
	//TODO:: Write the object, serialize, save it to a file.
	Debugger::SetSeverity(MessageType::E_INFO);
	
	if (action_->ReturnActionType() == ACTIONTYPE::E_COMMAND)
	{
		CommandAction* command = dynamic_cast<CommandAction*>(action_);

		JsonObject.Get()->SetStringField("Name", command->ReturnDiscription());
		JsonObject.Get()->SetStringField("Discription", command->ReturnDiscription());
		JsonObject.Get()->SetNumberField("ActionID", static_cast<double>(command->ReturnActionID()));
		JsonObject.Get()->SetNumberField("ActionType", static_cast<double>(command->ReturnActionID()));
		JsonObject.Get()->SetNumberField("TargetType", static_cast<double>(command->ReturnTargetType()));
		JsonObject.Get()->SetNumberField("StatAction", static_cast<double>(command->ReturnStatActionType()));
		JsonObject.Get()->SetNumberField("InteractionType", static_cast<double>(command->ReturnInteractionType()));
		JsonObject.Get()->SetNumberField("CurrentWeapon", static_cast<double>(command->ReturnWeaponType()));
		JsonObject.Get()->SetNumberField("BaseActionID", static_cast<double>(command->ReturnAction()->ReturnActionID()));

		JsonWriter = TJsonWriterFactory<>::Create(&writeFileString);

		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter.ToSharedRef());
		BattleBoxFileManager::WriteTextFile(Directory + "/ActionSheets", writeFileString, action_->ReturnName() + ".json", false);
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

		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter.ToSharedRef());
		BattleBoxFileManager::WriteTextFile(Directory + "/ActionSheets", writeFileString, action_->ReturnName() + ".json", false);
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
		TSharedPtr<FJsonObject> equationObject = MakeShareable(new FJsonObject);
		equationObject.Get()->SetNumberField("generalScaler", static_cast<double>(Ability->ReturnEquationObject()->ReturnGenrealScale()));
		equationObject.Get()->SetNumberField("rise", static_cast<double>(Ability->ReturnEquationObject()->ReturnRise()));
		equationObject.Get()->SetNumberField("run", static_cast<double>(Ability->ReturnEquationObject()->ReturnRun()));
		equationObject.Get()->SetNumberField("xIntercept", static_cast<double>(Ability->ReturnEquationObject()->ReturnXIntercept()));
		equationObject.Get()->SetNumberField("EquationType", static_cast<double>(Ability->ReturnEquationObject()->RetrunEquationType()));
		JsonObject.Get()->SetObjectField("EquationObject", equationObject);
		TArray<TSharedPtr<FJsonValue>> Array;
		
		JsonWriter = TJsonWriterFactory<>::Create(&writeFileString);

		FJsonSerializer::Serialize(JsonObject.ToSharedRef(), JsonWriter.ToSharedRef());
		BattleBoxFileManager::WriteTextFile(Directory + "/ActionSheets", writeFileString, action_->ReturnName() + ".json", false);
	}
	ResetJsonObject();
}
TArray<TSharedPtr<FJsonValue>> JsonParse::MakeIDJsonArray(UStatSheetObject* const sheet_, const FString Name_)
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
bool JsonParse::ResetJsonObject()
{
	if (JsonObject.Get())
	{
		JsonObject.Reset();
		return true;
	}
	return false;
}
JsonParse::~JsonParse()
{
}
