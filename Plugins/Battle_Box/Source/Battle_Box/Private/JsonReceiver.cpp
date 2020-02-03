// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JsonReceiver.h"
#include "Dom/JsonObject.h"
#include "BattleBoxFileManager.h"
#include "../Battle_Box/Private/StatSheetObject.h"
#include "../Battle_Box/Private/ActionClasses/BaseAction.h"
#include "../Battle_Box/Private/ActionClasses/CommandAction.h"
#include "../Battle_Box/Private/ActionClasses/ItemAction.h"
#include "../Battle_Box/Private/ActionClasses/AbilityAction.h"
#include "Misc/Paths.h"


JsonReceiver::JsonReceiver()
{
}
void JsonReceiver::InitiateClass()
{
	JsonObject = MakeShareable(new FJsonObject);
	Directory = FPaths::ProjectPluginsDir() + "/Battle_Box/FileResource";
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
	//TODO:: Write the object, serialize, save it to a file.

	JsonWriter = TJsonWriterFactory<>::Create(&JsonFileString);
	BattleBoxFileManager::WriteTextFile(Directory, JsonFileString, sheet_->ReturnName() + ".json", false);
}
void JsonReceiver::WriteActionObject(BaseAction* const action_)
{
	//This will write to a json file for a action object
	//TODO:: Write the object, serialize, save it to a file.
	JsonWriter = TJsonWriterFactory<>::Create(&JsonFileString);
	BattleBoxFileManager::WriteTextFile(Directory, JsonFileString, action_->ReturnName() + ".json", false);
}
void JsonReceiver::WriteEquationObject()
{
	//This will write to a json file for a equation object.
	//TODO:: Write the object, serialize, save it to a file.
}
JsonReceiver::~JsonReceiver()
{
}
