// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JsonReceiver.h"
#include "Dom/JsonObject.h"
#include "BattleBoxFileManager.h"

JsonReceiver::JsonReceiver()
{
}
void JsonReceiver::initJsonObject()
{
	JsonObject = MakeShareable(new FJsonObject);
	JsonWriter = TJsonWriterFactory<>::Create(&JsonFileString); 
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
	JsonObject.Get()->SetStringField();
	JsonObject.Get()->SetStringField();


	BattleBoxFileManager::WriteTextFile();
}
void JsonReceiver::WriteActionObject(BaseAction* const action_)
{
	//This will write to a json file for a action object
	//TODO:: Write the object, serialize, save it to a file.
}
void JsonReceiver::WriteEquationObject()
{
	//This will write to a json file for a equation object.
	//TODO:: Write the object, serialize, save it to a file.
}
void JsonReceiver::OnDestroy()
{
	//TODO:: clear any private data variables.
}
JsonReceiver::~JsonReceiver()
{
	OnDestroy();
}
