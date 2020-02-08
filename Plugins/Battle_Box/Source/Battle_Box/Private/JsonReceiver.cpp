// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JsonReceiver.h"
#include "Dom/JsonObject.h"
#include "Dom/JsonValue.h"
#include "Misc/Paths.h"
#include "BattleBoxFileManager.h"
#include "Serialization/JsonSerializer.h"
#include "Templates/Casts.h"
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
	JsonWriter = TJsonWriterFactory<>::Create(&JsonFileString);
	BattleBoxFileManager::VerifyOnCreateDirectory(Directory);
}
void JsonReceiver::ReadStatSheetObject()
{		
	//This will read from a json file for statsheetobject
	//TODO:: 
}
void JsonReceiver::ReadActionObject()
{
	//This will read from a json file for action object
	//TODO::
}
void JsonReceiver::ReadEquationObject()
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
	BattleBoxFileManager::WriteTextFile(Directory, JsonFileString, sheet_->ReturnName() + ".json", false);
	ResetJsonObject();
}
void JsonReceiver::WriteActionObject(BaseAction* const action_)
{
	//This will write to a json file for a action object
	//TODO:: Write the object, serialize, save it to a file.
	switch (action_->ReturnActionType())
	{
	case ACTIONTYPE::E_COMMAND:
		CommandAction* command = dynamic_cast<CommandAction*>(action_);


			break;
	case ACTIONTYPE::E_ITEM:
		ItemAction* Item = dynamic_cast<ItemAction*>(action_);


			break;
	case ACTIONTYPE::E_ABILITY: 
		AbilityAction* Ability = dynamic_cast<AbilityAction*>(action_);


			break;
	}

	JsonWriter = TJsonWriterFactory<>::Create(&JsonFileString);
	BattleBoxFileManager::WriteTextFile(Directory, JsonFileString, action_->ReturnName() + ".json", false);
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
			TSharedPtr<FJsonValue> value = MakeShareable(new FJsonValueNumber((double) i.Value->ReturnActionID()));
			Array.Add(value);
		}
	}
	if (Name_ == "items")
	{
		for (auto& i : sheet_->ReturnItemMap())
		{
			TSharedPtr<FJsonValue> value = MakeShareable(new FJsonValueNumber((double)i.Value->ReturnActionID()));
			Array.Add(value);
		}
	}
	if (Name_ == "abilities")
	{
		for (auto& i : sheet_->ReturnAbilityMap())
		{
			TSharedPtr<FJsonValue> value = MakeShareable(new FJsonValueNumber((double)i.Value->ReturnActionID()));
			Array.Add(value);
		}
	}
	if (Name_ == "equipmint")
	{
		for (auto& i : sheet_->ReturnEquipmentMap())
		{
			TSharedPtr<FJsonValue> value = MakeShareable(new FJsonValueNumber((double)i.Value->ReturnActionID()));
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
	}
}
JsonReceiver::~JsonReceiver()
{
}
