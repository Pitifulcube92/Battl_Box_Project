// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "DamageDeltSystem.h"
#include "../Battle_Box/Private/StatSheetObject.h"
#include "../Battle_Box/Private/ActionClasses/ItemAction.h"

DamageDeltSystem::DamageDeltSystem() : singleTarget(nullptr), owner(nullptr), targets(TArray<StatSheetObject*>()), totalDamageValues(TArray<float>())
{
	totalDamageValue = 0.0f;
}
void DamageDeltSystem::BaseCalculate(const bool IsSingledTarget_)
{
	if(IsSingledTarget_)
	{
	}
	else if (IsSingledTarget_)
	{

	}
}
float DamageDeltSystem::CalculateWeaponDamage(StatSheetObject* const target_)
{
	float totalDamage = 0.0f;
	if (target_->ReturnEquipmentMap().Contains("Weapon_1"))
	{
		totalDamage += target_->ReturnEquipmentMap()["Weapon_1"]->ReturnStatMap["Atk"];
	}
	if (target_->ReturnEquipmentMap().Contains("Weapon_2"))
	{
		totalDamage += target_->ReturnEquipmentMap()["Weapon_2"]->ReturnStatMap["Atk"];
	}
	totalDamage += target_->ReturnStatMap()["Atk"];
	return totalDamage;
}
float  DamageDeltSystem::CalculateCommandDamage(CommandAction* const targetCommand_)
{
	//Get the target action and get the damage value;
}
float  DamageDeltSystem::CalculateAbilityDamage(AbilityAction* const targetAbility_)
{
	//Get the target action and get the damage value;
}
float DamageDeltSystem::ClaculateItemDamage(ItemAction* const targetItem_)
{
	//Get the target and get the damage Value;
}
float DamageDeltSystem::CalculateMagicDamage(StatSheetObject* const target_)
{
	float magicDamage = 0.0f;
	return magicDamage;
}
float DamageDeltSystem::CalculatePhysicalDefence(StatSheetObject* const target_)
{
	float physicalDefence = 0.0f;
	if(target_->ReturnEquipmentMap().Contains("Helment"))
	{
		physicalDefence += target_->ReturnEquipmentMap()["Helment"]->ReturnStatMap()["Def"];
	}
	if(target_->ReturnEquipmentMap().Contains("Chest_Armor"))
	{
		physicalDefence += target_->ReturnEquipmentMap()["Chest_Armor"]->ReturnStatMap()["Def"];
	}
	if(target_->ReturnEquipmentMap().Contains("Leg_Armor"))
	{
		physicalDefence += target_->ReturnEquipmentMap()["Leg_Armor"]->ReturnStatMap()["Def"];
	}
	if(target_->ReturnEquipmentMap().Contains("Boots"))
	{
		physicalDefence += target_->ReturnEquipmentMap()["Boots"]->ReturnStatMap()["Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Accessory_1"))
	{
		physicalDefence += target_->ReturnEquipmentMap()["Accessory_1"]->ReturnStatMap()["Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Accesory_2"))
	{
		physicalDefence += target_->ReturnEquipmentMap()["Accesory_2"]->ReturnStatMap()["Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Weapon_1"))
	{
		physicalDefence += target_->ReturnEquipmentMap()["Weapon_1"]->ReturnStatMap()["Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Weapon_2"))
	{
		physicalDefence += target_->ReturnEquipmentMap()["Weapon_2"]->ReturnStatMap()["Def"];
	}
	physicalDefence += target_->ReturnStatMap()["Def"];
	return physicalDefence;
}
float DamageDeltSystem::CalculateMagicalDefence(StatSheetObject* const target_)
{
	float magicDefence = 0.0f;
	if (target_->ReturnEquipmentMap().Contains("Helment"))
	{
		magicDefence += target_->ReturnEquipmentMap()["Helment"]->ReturnStatMap()["M_Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Chest_Armor"))
	{
		magicDefence += target_->ReturnEquipmentMap()["Chest_Armor"]->ReturnStatMap()["M_Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Leg_Armor"))
	{
		magicDefence += target_->ReturnEquipmentMap()["Leg_Armor"]->ReturnStatMap()["M_Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Boots"))
	{
		magicDefence += target_->ReturnEquipmentMap()["Boots"]->ReturnStatMap()["M_Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Accessory_1"))
	{
		magicDefence += target_->ReturnEquipmentMap()["Accessory_1"]->ReturnStatMap()["M_Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Accesory_2"))
	{
		magicDefence += target_->ReturnEquipmentMap()["Accesory_2"]->ReturnStatMap()["M_Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Weapon_1"))
	{
		magicDefence += target_->ReturnEquipmentMap()["Weapon_1"]->ReturnStatMap()["M_Def"];
	}
	if (target_->ReturnEquipmentMap().Contains("Weapon_2"))
	{
		magicDefence += target_->ReturnEquipmentMap()["Weapon_2"]->ReturnStatMap()["M_Def"];
	}
	magicDefence += target_->ReturnStatMap()["M_Def"];
	return magicDefence;
}
void DamageDeltSystem::SetOwner(StatSheetObject* const owner_)
{
	owner = owner_;
}
void DamageDeltSystem::SetTarget(StatSheetObject* const target_)
{
	singleTarget = target_;
}
void DamageDeltSystem::AddTargetToArray(StatSheetObject* const target_)
{
	targets.Add(target_);
}
void DamageDeltSystem::OnDestroy()
{
	//clean up any pointers
}
float DamageDeltSystem::ReturnTotalDamageValue() const
{
	return totalDamageValue;
}
TArray<float> DamageDeltSystem::ReturnDamageValues() const
{
	return totalDamageValues;
}
DamageDeltSystem::~DamageDeltSystem()
{
	OnDestroy();
}