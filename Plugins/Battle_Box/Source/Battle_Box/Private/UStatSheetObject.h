// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Array.h"
#include "Containers/Map.h"
#include "Engine/DataAsset.h"
#include "UStatSheetObject.generated.h"

class UItemAction;
class UCommandAction;
class UAbilityAction;
struct StatSheetData;
/**
 * 
 */
UCLASS(Blueprintable, ClassGroup = "Battle_Box")
class BATTLE_BOX_API UStatSheetObject : public UDataAsset
{
	GENERATED_BODY()
private:
	FString name;
	FString tag;
	TMap<FString, UCommandAction*> commandMap;
	TMap<FString, UItemAction*> itemMap;
	TMap<FString, UAbilityAction*> abilityMap;
	TMap<FString, float> statMap;
	TMap<FString, UItemAction*> equipmentMap;
	
public:
	UStatSheetObject();
	bool Init(const FString name_, const FString tag_, const TMap<FString, UCommandAction*> commandMap_, const TMap<FString, UItemAction*> itemMap_, const TMap<FString, UAbilityAction*> abilityMap_, const TMap<FString, float> statMap_, const TMap<FString, UItemAction*> equipmentMap_);
	bool Init(UStatSheetObject* const other_);
	bool Init(StatSheetData const data_);
	///Sets name 
	void SetName(const FString name_);
	///Sets tag
	void SetTag(const FString tag_);
	///Returns name
	FString ReturnName() const;
	///Returns tag
	FString ReturnTag() const;
	///Adds a command action the command map
	void AddCommandAction(UCommandAction* const command_);
	///Adds a item action to the item map
	void AddItemAction(UItemAction* const item_);
	///Adds a ability action to the ability map
	void AddAbilityAction(UAbilityAction* const ability_);
	///Adds a eqquipment-item action  to the equipmnet map
	void AddEquipment(UItemAction* const equipment_);
	///Removes a command action if there is one in the map
	void RemoveCommandAction(const FString name_);
	///Removes a item action if there is one in the map
	void RemoveItemAction(const FString name_);
	///Removes  a ability action if there is one in the map
	void RemoveAbilityAction(const FString name_);
	///Removes a equipment-type action if there is one in the map
	void RemoveEquipment(const FString name_);
	///Returns the commmand map 
	TMap<FString, UCommandAction*> ReturnCommandMap() const;
	///Returns the item map
	TMap<FString, UItemAction*> ReturnItemMap() const;
	///Returns the ability map
	TMap<FString, UAbilityAction*> ReturnAbilityMap() const;
	///Returns the statMap
	TMap<FString, float> ReturnStatMap() const;
	///Returns the equipment map
	TMap<FString, UItemAction*> ReturnEquipmentMap() const;
	///Returns a command action by its name from the command map 
	UCommandAction* ReturnCommand(FString name_) const;
	///Returns a item action by its name from the item map
	UItemAction* ReturnItem(const FString name_) const;
	///Returns a ability action by its name from the ability map
	UAbilityAction* ReturnAbility(const FString name_) const;
	///Returns a equipment-item action by its name from the equipment map
	UItemAction* ReturnEquipment(const FString name_) const;
	void OnDestroy();
	~UStatSheetObject();
};
