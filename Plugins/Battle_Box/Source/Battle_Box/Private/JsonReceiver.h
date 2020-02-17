// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#ifndef JSONRECEIVER_H
#define JSONRECEIVER_H
#include "CoreMinimal.h"
#include "Templates/SharedPointer.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonReader.h"
#include "Containers/Array.h"
class StatSheetObject;
class BaseAction;
class Equation;
class FJsonObject;
class FJsonValue;
/**
 * 
 */
struct StatSheetData
{
	FString name;
	FString tag;
	TMap<FString, uint32> commandMapID;
	TMap<FString, uint32> itemMapID;
	TMap<FString, uint32> abilityMapID;
	TMap<FString, uint32> equipmentMapID;
	TMap<FString, float> statMap;
};
struct CommandData
{
	FString name;
	FString discription;
	uint32 actionID;
	ACTIONTYPE actionType;
	TARGETTYPE targetType;
	STATACTION statAction;
	INTERACTIONTYPE interactionType;
	WEAPONTYPE currentWeapon;
	uint32 commandActionID;
};
struct ItemData
{
	FString name;
	FString discription;
	uint32 actionID;
	ACTIONTYPE actionType;
	TARGETTYPE targetType;
	STATACTION statAction;
	INTERACTIONTYPE interactionType;
	ITEMTYPE itemType;
	DAMAGETYPE damageType;
	uint32 value;
	TArray<uint32> effectIDList;

};
struct AbilityData
{
	FString name;
	FString discription;
	uint32 actionID;
	ACTIONTYPE actionType;
	TARGETTYPE targetType;
	STATACTION statAction;
	INTERACTIONTYPE interactionType;
	float duration;
	float abilityValue;
	ABILITYTYPE abilityType;
};

class JsonReceiver
{
private:
	TSharedPtr<FJsonObject> JsonObject;
	TSharedPtr<TJsonWriter<>> JsonWriter;
	TSharedPtr<TJsonReader<>> JsonReader;
	FString Directory;
	FString readFileString;
	FString writeFileString;

	TArray<TSharedPtr<FJsonValue>> MakeIDJsonArray(StatSheetObject* const sheet_, const FString Name_);
public:
	JsonReceiver();
	bool ResetJsonObject();
	void InitiateClass();
	StatSheetObject* ReadStatSheetObject(const FString fileName_);
	BaseAction* ReadActionObject(const FString& fileName_);
	Equation* ReadEquationObject(const FString& fileName_);
	void WriteStatSheetObject(StatSheetObject* const sheet_);
	void WriteActionObject(BaseAction* const action_);
	void WriteEquationObject();
	~JsonReceiver();
};

#endif // !

