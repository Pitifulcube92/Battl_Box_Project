// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "StatSystem.h"
#include "Containers/Map.h"
#include "Templates/Casts.h"
#include "../Battle_Box/Private/Debugger.h"
#include "../Battle_Box/Private/UStatSheetObject.h"
#include "../SystemClasses/DamageDeltSystem.h"
#include "../Battle_Box/Private/ActionClasses/ItemAction.h"
#include "../Battle_Box/Private/ActionClasses/AbilityAction.h"
#include "../Battle_Box/Private/ActionClasses/BaseAction.h"

UStatSheetObject* StatSystem::target = nullptr;
TArray<UStatSheetObject*> StatSystem::targets = TArray<UStatSheetObject*>();

void StatSystem::CalculateStat(const bool IsSingleTarget_, BaseAction* const action_)
{
	BaseCalculate(IsSingleTarget_, action_);
}
void StatSystem::BaseCalculate(const bool IsSingledTarget_, BaseAction* const action_)
{
	if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
	{
		ItemAction* item = dynamic_cast<ItemAction*>(action_);
		if (IsSingledTarget_)
		{
			if (target == nullptr)
			{
				for (auto& ability : item->ReturnEffectList())
				{
					if (ability->ReturnStatActionType() == STATACTION::E_ADD)
					{
						AddStatModifier(target, action_);
					}
					else if (ability->ReturnStatActionType() == STATACTION::E_REMOVE)
					{
						RemoveModifier(target, ability);
					}
					else if (ability->ReturnStatActionType() == STATACTION::E_TMP_ADD)
					{
						AddTmpModifier(target, ability, ability->ReturnDuration());
					}
					else if (ability->ReturnStatActionType() == STATACTION::E_TMP_REMOVE)
					{
						RemoveTmpModifier(target, ability, ability->ReturnDuration());
					}
					else
					{
						Debugger::SetSeverity(MessageType::E_ERROR);
						Debugger::Error(action_->ReturnName() + " Could not be modified", "StatSystem.cpp", __LINE__);
						return;
					}
				}
			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("Target not avalable. Please set target if null", "StatSystem.cpp", __LINE__);
				return;
			}
		}
		else if (!IsSingledTarget_)
		{
			if (targets.Num() > 0)
			{
				for (auto& i : targets)
				{
					for (auto& ability : item->ReturnEffectList())
					{
						if (ability->ReturnStatActionType() == STATACTION::E_ADD)
						{
							AddStatModifier(i, action_);
						}
						else if (ability->ReturnStatActionType() == STATACTION::E_REMOVE)
						{
							RemoveModifier(i, ability);
						}
						else if (ability->ReturnStatActionType() == STATACTION::E_TMP_ADD)
						{
							AddTmpModifier(i, ability, ability->ReturnDuration());
						}
						else if (ability->ReturnStatActionType() == STATACTION::E_TMP_REMOVE)
						{
							RemoveTmpModifier(i, ability, ability->ReturnDuration());
						}
						else
						{
							Debugger::SetSeverity(MessageType::E_ERROR);
							Debugger::Error(action_->ReturnName() + " Could not be modified", "StatSystem.cpp", __LINE__);
							return;
						}
					}
				}
			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("No targets avalable it the array. Please insert a target before calculating.", "StatSystem.cpp", __LINE__);
				return;
			}

		}
	}
	else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
	{
		AbilityAction* ability = dynamic_cast<AbilityAction*>(action_);
		if (IsSingledTarget_)
		{
			if (target == nullptr)
			{
				if (ability->ReturnStatActionType() == STATACTION::E_ADD)
				{
					AddStatModifier(target, action_);
				}
				else if (ability->ReturnStatActionType() == STATACTION::E_REMOVE)
				{
					RemoveModifier(target, ability);
				}
				else if (ability->ReturnStatActionType() == STATACTION::E_TMP_ADD)
				{
					AddTmpModifier(target, ability, ability->ReturnDuration());
				}
				else if (ability->ReturnStatActionType() == STATACTION::E_TMP_REMOVE)
				{
					RemoveTmpModifier(target, ability, ability->ReturnDuration());
				}
				else
				{
					Debugger::SetSeverity(MessageType::E_ERROR);
					Debugger::Error(action_->ReturnName() + " Could not be modified", "StatSystem.cpp", __LINE__);
					return;
				}
			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("Target not avalable. Please set target if null", "StatSystem.cpp", __LINE__);
				return;
			}
		}
		else if(!IsSingledTarget_) 
		{
			if (targets.Num() > 0)
			{
				for (auto& i : targets)
				{
					if (ability->ReturnStatActionType() == STATACTION::E_ADD)
					{
						AddStatModifier(i, action_);
					}
					else if (ability->ReturnStatActionType() == STATACTION::E_REMOVE)
					{
						RemoveModifier(i, ability);
					}
					else if (ability->ReturnStatActionType() == STATACTION::E_TMP_ADD)
					{
						AddTmpModifier(i, ability, ability->ReturnDuration());
					}
					else if (ability->ReturnStatActionType() == STATACTION::E_TMP_REMOVE)
					{
						RemoveTmpModifier(i, ability, ability->ReturnDuration());
					}
					else
					{
						Debugger::SetSeverity(MessageType::E_ERROR);
						Debugger::Error(action_->ReturnName() + " Could not be modified", "StatSystem.cpp", __LINE__);
						return;
					}
				}
			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("No targets avalable it the array. Please insert a target before calculating.", "StatSystem.cpp", __LINE__);
				return;
			}
		}
	}
	OnDestroy();
}

void StatSystem::ModifiyStat(UStatSheetObject* const target_, const float value, const FString name_)
{
	if (target_->ReturnStatMap().Contains(name_))
	{
		target_->ReturnStatMap()[name_] += value;
	}
	else
	{
		Debugger::SetSeverity(MessageType::E_WARNING);
		Debugger::Warrning(name_ + " is not found in the stat sheet.", "StatSystem.cpp", __LINE__);
	}
}
void StatSystem::AddStatModifier(UStatSheetObject* const target_, BaseAction* const action_)
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
						ModifiyStat(target_, statMod.Value, statMod.Key);
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
					ModifiyStat(target_, statMod.Value, statMod.Key);
				}
			}
		}
	}
	else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
	{
		AbilityAction* ability = dynamic_cast<AbilityAction*>(action_);
		for(auto& statMod : ability->ReturnModStatMap())
		{
			ModifiyStat(target_, statMod.Value, statMod.Key);
		}
	}
	else
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error(action_->ReturnName() + " does not have an modification in this action.", "StatSystem.cpp", __LINE__);
		return;
	}
}
void StatSystem::RemoveModifier(UStatSheetObject* const target_, BaseAction* const action_)
{
	if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
	{
		ItemAction* item = dynamic_cast<ItemAction*>(action_);
		for (auto& effect : item->ReturnEffectList())
		{
			for (auto& statMod : effect->ReturnModStatMap())
			{
				ModifiyStat(target_,-statMod.Value, statMod.Key);
			}
		}
	}
	else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
	{
		AbilityAction* ability = dynamic_cast<AbilityAction*>(action_);
		for (auto& statMod : ability->ReturnModStatMap())
		{
			ModifiyStat(target_,-statMod.Value, statMod.Key);
		}
	}
	else
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error(action_->ReturnName() + " does not have an modification in this action.", "StatSystem.cpp", __LINE__);
		return;
	}
}
void StatSystem::AddTmpModifier(UStatSheetObject* const target_, BaseAction* const  action_, const float duration_)
{
	//This will add a modifier then remove it in a timer.
}
void StatSystem::RemoveTmpModifier(UStatSheetObject* const target_, BaseAction* action_, const float duration_)
{
	//This will remove a modifier then add it in a timer.
}
void StatSystem::SetTarget(UStatSheetObject* const target_)
{
	target = target_;
}
void StatSystem::Addtarget(UStatSheetObject* const target_)
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