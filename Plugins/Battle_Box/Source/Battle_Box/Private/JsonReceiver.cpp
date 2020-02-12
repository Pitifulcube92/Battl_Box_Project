// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JsonReceiver.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "Misc/Paths.h"
#include "Templates/Casts.h"
#include "BattleBoxFileManager.h"
#include "Serialization/JsonSerializer.h"

#include "../Battle_Box/Private/StatSheetObject.h"
#include "../Battle_Box/Private/ActionClasses/BaseAction.h"
#include "../Battle_Box/Private/ActionClasses/CommandAction.h"
#include "../Battle_Box/Private/ActionClasses/ItemAction.h"
#include "../Battle_Box/Private/ActionClasses/AbilityAction.h"


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
void JsonReceiver::ReadStatSheetObject(const FString fileName_)
{		
	//This will read from a json file for statsheetobject
	//TODO:: 
	readFileString = BattleBoxFileManager::ReadFile(Directory + "/StatSheets", fileName_);
	JsonReader = TJsonReaderFactory<>::Create(readFileString);
	if (FJsonSerializer::Deserialize(JsonReader.ToSharedRef(), JsonObject))
	{
		JsonObject.Get()->GetStringField("Name");
		JsonObject.Get()->GetStringField("Tag");
	}

}
void JsonReceiver::ReadActionObject(const FString& fileName_)
{
	//This will read from a json file for action object
	//TODO::
	readFileString = BattleBoxFileManager::ReadFile(Directory + "/ActionSheets", fileName_);
	JsonReader = TJsonReaderFactory<>::Create(readFileString);
	if (FJsonSerializer::Deserialize(JsonReader.ToSharedRef(), JsonObject))
	{
		ACTIONTYPE action =  static_cast<ACTIONTYPE>((int)JsonObject.Get()->GetNumberField("ActionType"));
		if (action == ACTIONTYPE::E_COMMAND)
		{

		}
		if (action == ACTIONTYPE::E_ITEM)
		{

		}
		if (action == ACTIONTYPE::E_ABILITY)
		{

		}

	}
}
void JsonReceiver::ReadEquationObject(const FString& fileName_)
{
	//This will read from a json file for equation object
	//TODO::
}
void JsonReceiver::WriteStatSheetObject(StatSheetObject* const sheet_)
{
	//This will write to a json file for a statsheetobject
	//TODO:: Write the object, serialize, save it to a file

	JsonObject.Get()->SetStringField("Name", sheet_->ReturnName());
	JsonObject.Get()->SetStringField("Tag", sheet_->ReturnTag());
	JsonObject.Get()->SetArrayField("Commands", MakeIDJsonArray(sheet_, "commands"));
	JsonObject.Get()->SetArrayField("Items", MakeIDJsonArray(sheet_, "items"));
	JsonObject.Get()->SetArrayField("abilities", MakeIDJsonArray(sheet_, "abilites"));
	JsonObject.Get()->SetArrayField("equipment", MakeIDJsonArray(sheet_, "equipment"));
	TSharedPtr<FJsonObject> StatObject;
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
	TArray<TSharedPtr<FJsonValue>> Array;
	TSharedPtr<FJsonObject> statObject;

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
		JsonObject.Get()->SetNumberField("StatAction", static_cast<double>(Ability->ReturnStatActionType()));

		for (auto& i : Ability->ReturnModStatMap())
		{
			statObject.Get()->SetNumberField(i.Key,i.Value);
		}
		JsonObject.Get()->SetObjectField("StatObject", statObject);
	}
	JsonWriter = TJsonWriterFactory<>::Create(&writeFileString);
	BattleBoxFileManager::WriteTextFile(Directory, writeFileString, action_->ReturnName() + ".json", false);
	statObject.Reset();
	Array.Reset();
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
