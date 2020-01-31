// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "EffectSystem.h"
#include "../Battle_Box/Private/Debugger.h"
#include "../Battle_Box/Private/StatSheetObject.h"
#include "../Battle_Box/Private/ActionClasses/BaseAction.h"
#include "../Battle_Box/Private/ActionClasses/AbilityAction.h"
#include "../Battle_Box/Private/ActionClasses/ItemAction.h"

void EffectSystem::BaseCalculate(const bool IsSingledTarget_, BaseAction* const action_)
{
	if (IsSingledTarget_)
	{
		if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
		{
			ItemAction* item = dynamic_cast<ItemAction*>(action_);

			if (item->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL)
			{
				//calculate for physical attributes
			}
			else if (item->ReturnInteractionType() == INTERACTIONTYPE::E_ABILITY)
			{
				//calculate for ability attributes
			}
			else if(item->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL_AND_ABILITY)
			{
				//calculate for physical and ability attributes

			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("No interaction fits the criteria.", "EffectSystem.cpp", __LINE__);
				return;
			}
		}
		else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
		{
			AbilityAction* ability = dynamic_cast<AbilityAction*>(action_);
		}
		else
		{
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("action does not meet the effect criteria.", "EffectSystem.cpp", __LINE__);
			return;
		}
	}
	else if (IsSingledTarget_)
	{
		if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
		{
			ItemAction* item = dynamic_cast<ItemAction*>(action_);

			if (item->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL)
			{
				//calculate for physical attributes
			}
			else if (item->ReturnInteractionType() == INTERACTIONTYPE::E_ABILITY)
			{
				//calculate for ability attributes
			}
			else if (item->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL_AND_ABILITY)
			{
				//calculate for physical and ability attributes

			}
			else
			{
				Debugger::SetSeverity(MessageType::E_ERROR);
				Debugger::Error("No interaction fits the criteria.", "EffectSystem.cpp", __LINE__);
				return;
			}
		}
		else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
		{

		}
		else
		{
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("action does not meet the effect criteria.", "EffectSystem.cpp", __LINE__);
			return;
		}
	}
}
void EffectSystem::CallculateEffect(BaseAction* action_)
{
	//This will extract the equation class and calculate the values needed.
}
void EffectSystem::RemoveEffect(BaseAction* action_)
{
	//Same process as the equation and reverse calculate the value needed.
}
void EffectSystem::SetTarget(StatSheetObject* target_)
{
	target = target_;
}
void EffectSystem::Addtarget(StatSheetObject* target_)
{
	targets.Add(target_);
}
void EffectSystem::OnDestroy()
{
	//clear all variables.
	if (target)
	{
		delete target;
		target = nullptr;
	}
	if (targets.Num() > 0)
	{
		for(auto t : targets)
		{
			delete t;
			t = nullptr;
		}
		targets.Empty();
	}
}
EffectSystem::~EffectSystem()
{

}