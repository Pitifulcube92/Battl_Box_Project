// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#ifndef JSONRECEIVER_H
#define JSONRECEIVER_H
#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "Serialization/JsonWriter.h"
#include "Containers/Array.h"
class StatSheetObject;
class BaseAction;
class FJsonObject;
class FJsonValueNUmber;
/**
 * 
 */
class JsonReceiver
{
private:
	TSharedPtr<FJsonObject> JsonObject;
	TSharedPtr<TJsonWriter<>> JsonWriter;
	FString Directory;
	FString JsonFileString;

	TArray<TSharedPtr<FJsonValueNumber>> MakeIDJsonArray(StatSheetObject* const sheet_, FString Name_);
public:
	JsonReceiver();
	void InitiateClass();
	void ReadStatSheetObject();
	void ReadActionObject();
	void ReadEquationObject();
	void WriteStatSheetObject(StatSheetObject* const sheet_);
	void WriteActionObject(BaseAction* const action_);
	void WriteEquationObject();
	~JsonReceiver();
};

#endif // !

