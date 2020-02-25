// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#ifndef JSONRECEIVER_H
#define JSONRECEIVER_H
#include "CoreMinimal.h"
#include "Equation.h"
#include "Templates/SharedPointer.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonReader.h"
#include "Battle_Box/Private/ActionClasses/AbilityAction.h"
#include "Battle_Box/Private/ActionClasses/CommandAction.h"
#include "Battle_Box/Private/ActionClasses/ItemAction.h"
#include "Containers/Array.h"

class StatSheetObject;
class BaseAction;
class FJsonObject;
class FJsonValue;

struct StatSheetData
{
	FString name;
	FString tag;
	TArray<uint32> commandMapID;
	TArray<uint32> itemMapID;
	TArray<uint32> abilityMapID;
	TArray<uint32> equipmentMapID;
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
	ABILITYTYPE abilityType;
	EQUATION_TYPE equationType;
	float abilityValue;
	float duration;
	float generalScaler;
	float rise;
	float run;
	float xIntercept;
};

class JsonParse
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
	JsonParse();
	bool ResetJsonObject();
	void InitiateClass();
	StatSheetObject* ReadStatSheetObject(const FString fileName_);
	BaseAction* ReadActionObject(const FString& fileName_);
	void WriteStatSheetObject(StatSheetObject* const sheet_);
	void WriteActionObject(BaseAction* const action_);
	~JsonParse();
};

#endif // !

