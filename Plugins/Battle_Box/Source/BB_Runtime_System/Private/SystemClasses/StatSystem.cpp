// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "StatSystem.h"
#include "Containers/Map.h"
#include "../Battle_Box/Private/StatSheetObject.h"
#include "../SystemClasses/DamageDeltSystem.h"
#include "../Battle_Box/Private/ActionClasses/ItemAction.h"
#include "../Battle_Box/Private/ActionClasses/AbilityAction.h"
#include "../Battle_Box/Private/ActionClasses/BaseAction.h"

StatSystem::StatSystem()
{

}
void StatSystem::BaseCalculate(const bool IsSingledTarget_, BaseAction* const action_)
{
	if (!IsSingledTarget_)
	{
		
	}
	else if (!IsSingledTarget_)
	{
		for (auto& target : targets)
		{
			
		}
	}
}
void StatSystem::ModifiyStat(const float value, const FString name_)
{
	if (target->ReturnStatMap().Contains(name_))
	{
		target->ReturnStatMap()[name_] += value;
	}
	else
	{
		Debugger::SetSeverity(MessageType::E_WARNING);
		Debugger::Warrning(name_ + " is not found in the stat sheet.", "StatSystem.cpp", __LINE__);
	}
}
void StatSystem::AddStatModifier(BaseAction* const action_)
{
	if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
	{
		ItemAction* item = dynamic_cast<ItemAction*>(action_);
		if (item->ReturnItemType() == ITEMTYPE::E_CONSUMABLE)
		{
			for (auto& effect : item->ReturnEffectList())
			{
				if (effect->ReturnAbilityType() == ABILITYTYPE::E_MODIFIYER)
				{
					for (auto& statMod : effect->ReturnModStatMap())
					{
						ModifiyStat(statMod.Value, statMod.Key);
					}
				}
				else if (effect->ReturnAbilityType() == ABILITYTYPE::E_TMP_MODIFIYER)
				{
					//This will go throught the modifyer process 
					//TO DO: Finish the proccess code for the tmp modifiyer.
				}
				else if (effect->ReturnAbilityType() == ABILITYTYPE::E_DAMAGE_MODIFYER)
				{
					//TO DO: turn systems to static classes.
				}

			}
		}
		else if (item->ReturnItemType() == ITEMTYPE::E_ARMOR || item->ReturnItemType() == ITEMTYPE::E_WEAPON)
		{
			for (auto& effect : item->ReturnEffectList())
			{	
				for(auto& statMod : effect->ReturnModStatMap())
				{ 
					ModifiyStat(statMod.Value, statMod.Key);
				}
			}
		}
	}
	else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
	{
		AbilityAction* ability = dynamic_cast<AbilityAction*>(action_);
		for(auto& statMod : ability->ReturnModStatMap())
		{
			ModifiyStat(statMod.Value, statMod.Key);
		}
	}
	else
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error(action_->ReturnName() + " does not have an modification in this action.", "StatSystem.cpp", __LINE__);
		return;
	}
}
void StatSystem::RemoveModifier(BaseAction* const action_)
{
	if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
	{
		ItemAction* item = dynamic_cast<ItemAction*>(action_);
		for (auto& effect : item->ReturnEffectList())
		{
			for (auto& statMod : effect->ReturnModStatMap())
			{
				ModifiyStat(-statMod.Value, statMod.Key);
			}
		}
	}
	else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
	{
		AbilityAction* ability = dynamic_cast<AbilityAction*>(action_);
		for (auto& statMod : ability->ReturnModStatMap())
		{
			ModifiyStat(-statMod.Value, statMod.Key);
		}
	}
	else
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error(action_->ReturnName() + " does not have an modification in this action.", "StatSystem.cpp", __LINE__);
		return;
	}
}
void StatSystem::AddTmpModifier(BaseAction* action_, const float duration_)
{
	//This will basiclly add a modifier then remove it in a timer.
}
void StatSystem::SetTarget(StatSheetObject* const target_)
{
	target = target_;
}
void StatSystem::SetTargetAction(BaseAction* const action_)
{
	targetAction = action_;
}
void StatSystem::Addtarget(StatSheetObject* const target_)
{
	targets.Add(target_);
}
void StatSystem::OnDestroy()
{
	///This will clearout any function data.
}
StatSystem::~StatSystem()
{
	OnDestroy();

}