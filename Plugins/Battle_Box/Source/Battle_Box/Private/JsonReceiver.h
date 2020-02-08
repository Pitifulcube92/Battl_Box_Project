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
class FJsonValue;
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

	TArray<TSharedPtr<FJsonValue>> MakeIDJsonArray(StatSheetObject* const sheet_, const FString Name_);
public:
	JsonReceiver();
	bool ResetJsonObject();
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

