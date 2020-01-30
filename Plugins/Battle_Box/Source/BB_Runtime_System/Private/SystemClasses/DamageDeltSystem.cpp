// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "DamageDeltSystem.h"
#include "StatSystem.h"
#include "../Battle_Box/Private/Debugger.h"
#include "../Battle_Box/Private/StatSheetObject.h"
#include "../Battle_Box/Private/ActionClasses/BaseAction.h"
#include "../Battle_Box/Private/ActionClasses/CommandAction.h"
#include "../Battle_Box/Private/ActionClasses/ItemAction.h"
#include "../Battle_Box/Private/ActionClasses/AbilityAction.h"

StatSheetObject* DamageDeltSystem::singleTarget = nullptr;
StatSheetObject* DamageDeltSystem::owner = nullptr;
TArray<StatSheetObject*> DamageDeltSystem::targets = TArray<StatSheetObject*>();
float DamageDeltSystem::totalDamageValue = 0.0f;
TArray<float> DamageDeltSystem::totalDamageValues = TArray<float>();

void DamageDeltSystem::BaseCalculate(const bool IsSingledTarget_, BaseAction* const action_)
{
	if(IsSingledTarget_)
	{
		if (singleTarget == nullptr)
		{
			//This will claculate any damage for a single target.
			if (action_->ReturnActionType() == ACTIONTYPE::E_COMMAND)
			{
				//Command will do basic act with basic stats
				//TO DO: Check if there is any damage in this command.
				CommandAction* command = dynamic_cast<CommandAction*>(action_);
			}
			else if(action_->ReturnActionType() == ACTIONTYPE::E_ITEM) 
			{
				//Item will be sorted to what type then calculated for total damage.
				ItemAction* item = dynamic_cast<ItemAction*>(action_);

				if (item->ReturnItemType() == ITEMTYPE::E_CONSUMABLE)
				{
					totalDamageValue = CalculateItemDamage(item) - CalculateMagicalDefence(singleTarget) + CalculatePhysicalDefence(singleTarget);
				}
				else if (item->ReturnItemType() == ITEMTYPE::E_WEAPON)
				{
					totalDamageValue = CalculateItemDamage(item) - CalculateMagicalDefence(singleTarget) + CalculatePhysicalDefence(singleTarget);
				}
				else
				{
					Debugger::SetSeverity(MessageType::E_ERROR);
					Debugger::Error("No Item to contain damage from: " + item->ReturnName(), "DamageDeltSystem.cpp", __LINE__);
					return;
				}
			}
			else if(action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
			{
				//ability will retreive the damage value if any.
				//TO DO: create an enum for what type of ability it is.
				AbilityAction* ability = dynamic_cast<AbilityAction*>(action_);
				CalculateAbilityDamage(ability);
			}
			//TO DO: modify targets HP on stat system.
			StatSystem::ModifiyStat(singleTarget, totalDamageValue, "HP");
		}
		else
		{
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("Target not avalable. Please set target if null", "DamageDeltSystem.cpp", __LINE__);
			return;
		}
	}
	else if (!IsSingledTarget_)
	{
		if (targets.Num() > 0)
		{
			//This will calculate any damage for multiple targets.
			if (action_->ReturnActionType() == ACTIONTYPE::E_COMMAND)
			{
				//Command will do basic act with basic stats
				//TO DO: Check if there is any damage in this command.
				CommandAction* command = dynamic_cast<CommandAction*>(action_);
			}
			else if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
			{

				//Item will be sorted to what type then calculated for total damage.
				ItemAction* item = dynamic_cast<ItemAction*>(action_);
				if (item->ReturnItemType() == ITEMTYPE::E_CONSUMABLE)
				{
					for (int i = 0; i < targets.Num(); i++)
					{
						totalDamageValues.Add(CalculateItemDamage(item) - CalculateMagicalDefence(targets[i]) + CalculatePhysicalDefence(targets[i]));
					}
				}
				else if (item->ReturnItemType() == ITEMTYPE::E_WEAPON)
				{
					for (int i = 0; i < targets.Num(); i++)
					{
						totalDamageValues.Add(CalculateItemDamage(item) - CalculateMagicalDefence(targets[i]) + CalculatePhysicalDefence(targets[i]));
					}
				}
				else
				{
					Debugger::SetSeverity(MessageType::E_ERROR);
					Debugger::Error("No Item to contain damage from: " + item->ReturnName(), "DamageDeltSystem.cpp", __LINE__);
					return;
				}
			}
			else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
			{

				//ability will retreive the damage value if any.
				//TO DO: create an enum for what type of ability it is.
				AbilityAction* ability = dynamic_cast<AbilityAction*>(action_);
				CalculateAbilityDamage(ability);
			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("No specified action was found!", "DamageDeltSystem.cpp", __LINE__);
				return;
			}
			//TO DO: Modify stats of HP in targets.
			for (int i = 0; i < targets.Num(); i++)
			{
				StatSystem::ModifiyStat(targets[i], totalDamageValues[i], "HP");
			}
		}
		else
		{
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("No targets avalable it the array. Please insert a target before calculating.", "DamageDeltSystem.cpp", __LINE__);
			return;
		}
	}
	//TO DO: After modification is done empty all information.
	OnDestroy();
}
void DamageDeltSystem::CalculateDamage(const bool IsSingledTarget_, BaseAction* const action_)
{
	BaseCalculate(IsSingledTarget_, action_);
}
float DamageDeltSystem::CalculateWeaponDamage(ItemAction* const targetWeapon_)
{
	//This will return either magic, physical or both as a damage value;
	if (targetWeapon_->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL)
	{
		return targetWeapon_->ReturnStatMap()["Atk"];
	}
	if (targetWeapon_->ReturnInteractionType() == INTERACTIONTYPE::E_ABILITY)
	{
		return targetWeapon_->ReturnStatMap()["M_Atk"];
	}
	if (targetWeapon_->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL_AND_ABILITY)
	{
		return targetWeapon_->ReturnStatMap()["Atk"] + targetWeapon_->ReturnStatMap()["M_Atk"];
	}
}
float  DamageDeltSystem::CalculateAbilityDamage(AbilityAction* const targetAbility_)
{
	//Get the target action and get the damage value;
	float tmp = 0.0f;
	return tmp;
	/*if (targetAbility_->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL)
	{
		target
	}
	if (targetAbility_->ReturnInteractionType() == INTERACTIONTYPE::E_ABILITY)
	{

	}
	if(targetAbility_->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL_AND_ABILITY)
	{

	}*/
}
float DamageDeltSystem::CalculateItemDamage(ItemAction* const targetItem_)
{
	//Get the target and get the damage Value;
	if (targetItem_->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL)
	{
		return targetItem_->ReturnStatMap()["Atk"];
	}
	if (targetItem_->ReturnInteractionType() == INTERACTIONTYPE::E_ABILITY)
	{
		return targetItem_->ReturnStatMap()["M_Atk"];
	}
	if (targetItem_->ReturnInteractionType() ==INTERACTIONTYPE::E_PHYSICAL_AND_ABILITY)
	{
		return targetItem_->ReturnStatMap()["Atk"] + targetItem_->ReturnStatMap()["M_Atk"];
	}
	//switch (targetItem_->ReturnDamageType())
	//{
	//case DAMAGETYPE::E_HP_DAMAGE:
	//	//This will get the damage from the stat map
	//	return targetItem_->ReturnStatMap()["Atk"];
	//case DAMAGETYPE::E_HP_RECOVER:
	//	return targetItem_->ReturnStatMap()["HP_REC"];
	//case DAMAGETYPE::E_MP_DAMAGE:
	//	return targetItem_->ReturnStatMap()["M_Atk"];
	//case DAMAGETYPE::E_MP_RECOVER:
	//	return targetItem_->ReturnStatMap()["M_REC"];
	//}
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
	if(singleTarget)
	{
		delete singleTarget;
		singleTarget = nullptr;
	}
	if(owner)
	{
		delete owner;
		owner = nullptr;
	}
	if(targets.Num() > 0)
	{
		for(auto& elem : targets)
		{
			delete elem;
			elem = nullptr;
		}
		targets.Empty();
	}
	totalDamageValue = 0.0f;
	if (totalDamageValues.Num() > 0)
	{
		for (auto n : totalDamageValues)
		{
			n = 0.0f;
		}
		targets.Empty();
	}
}
float const DamageDeltSystem::ReturnTotalDamageValue() 
{
	return totalDamageValue;
}
TArray<float> const DamageDeltSystem::ReturnDamageValues() 
{
	return totalDamageValues;
}
DamageDeltSystem::~DamageDeltSystem()
{
	OnDestroy();
}