// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#ifndef JSONRECEIVER_H
#define JSONRECEIVER_H
#include "CoreMinimal.h"
#include "Equation.h"
#include "Templates/SharedPointer.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonReader.h"
#include "Battle_Box/Private/ActionClasses/UAbilityAction.h"
#include "Battle_Box/Private/ActionClasses/UCommandAction.h"
#include "Battle_Box/Private/ActionClasses/UItemAction.h"
#include "Containers/Array.h"			   

class UStatSheetObject;
class UBaseAction;
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

	TArray<TSharedPtr<FJsonValue>> MakeIDJsonArray(UStatSheetObject* const sheet_, const FString Name_);
public:
	JsonParse();
	bool ResetJsonObject();
	bool InitiateClass();
	UStatSheetObject* ReadStatSheetObject(const FString fileName_);
	UBaseAction* ReadActionObject(const FString& fileName_);
	void WriteStatSheetObject(UStatSheetObject* const sheet_);
	void WriteActionObject(UBaseAction* const action_);
	~JsonParse();
};

#endif // !

