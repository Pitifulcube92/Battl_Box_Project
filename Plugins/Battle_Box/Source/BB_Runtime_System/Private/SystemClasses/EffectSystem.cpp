//// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
//#include "EffectSystem.h"
//#include "StatSystem.h"
//#include "DamageDeltSystem.h"
//#include "Templates/Casts.h"
//#include "../Battle_Box/Private/Debugger.h"
//#include "../Battle_Box/Private/UStatSheetObject.h"
//#include "../Battle_Box/Private/ActionClasses/UBaseAction.h"
//#include "../Battle_Box/Private/ActionClasses/UAbilityAction.h"
//#include "../Battle_Box/Private/ActionClasses/UItemAction.h"
//UStatSheetObject*  EffectSystem::target = nullptr;
//TArray<UStatSheetObject*> EffectSystem::targets = TArray<UStatSheetObject*>();
//UBaseAction* EffectSystem::targetAction = nullptr;
//
//void EffectSystem::BaseCalculate(const bool IsSingledTarget_, UBaseAction* const action_)
//{
//	if (IsSingledTarget_)
//	{
//		if (target)
//		{
//			if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
//			{
//				UItemAction* item = dynamic_cast<UItemAction*>(action_);
//				if (item->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL)
//				{
//					//calculate for physical attributes
//					if (item->ReturnEffectList().Num() > 0)
//					{
//						for (auto ability : item->ReturnEffectList())
//						{
//							if (ability->ReturnAbilityType() == ABILITYTYPE::E_MODIFIYER)
//							{
//								//Communicate with stat System
//							}
//							else if (ability->ReturnAbilityType() == ABILITYTYPE::E_TMP_MODIFIYER)
//							{
//								//Communicate with stat System
//							}
//							else if (ability->ReturnAbilityType() == ABILITYTYPE::E_DAMAGE_MODIFYER)
//							{
//								//Communicate with Damage System
//							}
//							else
//							{
//								Debugger::SetSeverity(MessageType::E_ERROR);
//								Debugger::Error("No ability type is found and cannot calculate.", "EffectSystem.cpp", __LINE__);
//								return;
//							}
//						}
//					}
//					else
//					{
//						Debugger::SetSeverity(MessageType::E_ERROR);
//						Debugger::Error("No ability found or is null.", "EffectSystem.cpp", __LINE__);
//						return;
//					}
//				}
//				else if (item->ReturnInteractionType() == INTERACTIONTYPE::E_ABILITY)
//				{
//					//calculate for ability attributes
//					if (item->ReturnEffectList().Num() > 0)
//					{
//						for (auto ability : item->ReturnEffectList())
//						{
//							if (ability->ReturnAbilityType() == ABILITYTYPE::E_MODIFIYER)
//							{
//								//Communicate with stat System
//							}
//							else if (ability->ReturnAbilityType() == ABILITYTYPE::E_TMP_MODIFIYER)
//							{
//								//Communicate with stat System
//							}
//							else if (ability->ReturnAbilityType() == ABILITYTYPE::E_DAMAGE_MODIFYER)
//							{
//								//Communicate with Damage System
//							}
//							else
//							{
//								Debugger::SetSeverity(MessageType::E_ERROR);
//								Debugger::Error("No ability type is found and cannot calculate.", "EffectSystem.cpp", __LINE__);
//								return;
//							}
//						}
//					}
//					else
//					{
//						Debugger::SetSeverity(MessageType::E_ERROR);
//						Debugger::Error("No ability found or is null.", "EffectSystem.cpp", __LINE__);
//						return;
//					}
//				}
//				else if (item->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL_AND_ABILITY)
//				{
//					//calculate for physical and ability attributes
//					if (item->ReturnEffectList().Num() > 0)
//					{
//
//						for (auto ability : item->ReturnEffectList())
//						{
//							if (ability->ReturnAbilityType() == ABILITYTYPE::E_MODIFIYER)
//							{
//								//Communicate with stat System
//							}
//							else if (ability->ReturnAbilityType() == ABILITYTYPE::E_TMP_MODIFIYER)
//							{
//								//Communicate with stat System
//							}
//							else if (ability->ReturnAbilityType() == ABILITYTYPE::E_DAMAGE_MODIFYER)
//							{
//								//Communicate with Damage System
//							}
//							else
//							{
//								Debugger::SetSeverity(MessageType::E_ERROR);
//								Debugger::Error("No ability type is found and cannot calculate.", "EffectSystem.cpp", __LINE__);
//								return;
//							}
//						}
//					}
//					else
//					{
//						Debugger::SetSeverity(MessageType::E_ERROR);
//						Debugger::Error("No ability found or is null.", "EffectSystem.cpp", __LINE__);
//						return;
//					}
//				}
//				else
//				{
//					Debugger::SetSeverity(MessageType::E_ERROR);
//					Debugger::Error("No interaction fits the criteria.", "EffectSystem.cpp", __LINE__);
//					return;
//				}
//			}
//			else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
//			{
//				UAbilityAction* ability = dynamic_cast<UAbilityAction*>(action_);
//
//				if (ability->ReturnAbilityType() == ABILITYTYPE::E_MODIFIYER)
//				{
//					//Communicate with stat System
//				}
//				else if (ability->ReturnAbilityType() == ABILITYTYPE::E_TMP_MODIFIYER)
//				{
//					//Communicate with stat System
//				}
//				else if (ability->ReturnAbilityType() == ABILITYTYPE::E_DAMAGE_MODIFYER)
//				{
//					//Communicate with Damage System
//				}
//				else
//				{
//					Debugger::SetSeverity(MessageType::E_ERROR);
//					Debugger::Error("No ability type is found and cannot calculate.", "EffectSystem.cpp", __LINE__);
//					return;
//				}
//			}
//			else
//			{
//				Debugger::SetSeverity(MessageType::E_ERROR);
//				Debugger::Error("action does not meet the effect criteria.", "EffectSystem.cpp", __LINE__);
//				return;
//			}
//		}
//		else
//		{
//			Debugger::SetSeverity(MessageType::E_ERROR);
//			Debugger::Error("target was not set.", "EffectSystem.cpp", __LINE__);
//			return;
//		}
//	}
//	else if (!IsSingledTarget_)
//	{
//		if (targets.Num() > 0)
//		{
//			for (auto target : targets)
//			{
//				if (action_->ReturnActionType() == ACTIONTYPE::E_ITEM)
//				{
//					UItemAction* item = dynamic_cast<UItemAction*>(action_);
//					if (item->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL)
//					{
//						//calculate for physical attributes
//						if (item->ReturnEffectList().Num() > 0)
//						{
//							for (auto ability : item->ReturnEffectList())
//							{
//								if (ability->ReturnAbilityType() == ABILITYTYPE::E_MODIFIYER)
//								{
//									//Communicate with stat System
//								}
//								else if (ability->ReturnAbilityType() == ABILITYTYPE::E_TMP_MODIFIYER)
//								{
//									//Communicate with stat System
//								}
//								else if (ability->ReturnAbilityType() == ABILITYTYPE::E_DAMAGE_MODIFYER)
//								{
//									//Communicate with Damage System
//								}
//								else
//								{
//									Debugger::SetSeverity(MessageType::E_ERROR);
//									Debugger::Error("No ability type is found and cannot calculate.", "EffectSystem.cpp", __LINE__);
//									return;
//								}
//							}
//						}
//						else
//						{
//							Debugger::SetSeverity(MessageType::E_ERROR);
//							Debugger::Error("No ability found or is null.", "EffectSystem.cpp", __LINE__);
//							return;
//						}
//					}
//					else if (item->ReturnInteractionType() == INTERACTIONTYPE::E_ABILITY)
//					{
//						//calculate for ability attributes
//						if (item->ReturnEffectList().Num() > 0)
//						{
//							for (auto ability : item->ReturnEffectList())
//							{
//								if (ability->ReturnAbilityType() == ABILITYTYPE::E_MODIFIYER)
//								{
//									//Communicate with stat System
//								}
//								else if (ability->ReturnAbilityType() == ABILITYTYPE::E_TMP_MODIFIYER)
//								{
//									//Communicate with stat System
//								}
//								else if (ability->ReturnAbilityType() == ABILITYTYPE::E_DAMAGE_MODIFYER)
//								{
//									//Communicate with Damage System
//								}
//								else
//								{
//									Debugger::SetSeverity(MessageType::E_ERROR);
//									Debugger::Error("No ability type is found and cannot calculate.", "EffectSystem.cpp", __LINE__);
//									return;
//								}
//							}
//						}
//						else
//						{
//							Debugger::SetSeverity(MessageType::E_ERROR);
//							Debugger::Error("No ability found or is null.", "EffectSystem.cpp", __LINE__);
//							return;
//						}
//					}
//					else if (item->ReturnInteractionType() == INTERACTIONTYPE::E_PHYSICAL_AND_ABILITY)
//					{
//						//calculate for physical and ability attributes
//						if (item->ReturnEffectList().Num() > 0)
//						{
//							for (auto ability : item->ReturnEffectList())
//							{
//								if (ability->ReturnAbilityType() == ABILITYTYPE::E_MODIFIYER)
//								{
//									//Communicate with stat System
//								}
//								else if (ability->ReturnAbilityType() == ABILITYTYPE::E_TMP_MODIFIYER)
//								{
//									//Communicate with stat System
//								}
//								else if (ability->ReturnAbilityType() == ABILITYTYPE::E_DAMAGE_MODIFYER)
//								{
//									//Communicate with Damage System
//								}
//								else
//								{
//									Debugger::SetSeverity(MessageType::E_ERROR);
//									Debugger::Error("No ability type is found and cannot calculate.", "EffectSystem.cpp", __LINE__);
//									return;
//								}
//							}
//						}
//						else
//						{
//							Debugger::SetSeverity(MessageType::E_ERROR);
//							Debugger::Error("No ability found or is null.", "EffectSystem.cpp", __LINE__);
//							return;
//						}
//					}
//					else
//					{
//						Debugger::SetSeverity(MessageType::E_ERROR);
//						Debugger::Error("No interaction fits the criteria.", "EffectSystem.cpp", __LINE__);
//						return;
//					}
//				}
//				else if (action_->ReturnActionType() == ACTIONTYPE::E_ABILITY)
//				{
//					UAbilityAction* ability = dynamic_cast<UAbilityAction*>(action_);
//
//					if (ability->ReturnAbilityType() == ABILITYTYPE::E_MODIFIYER)
//					{
//						//Communicate with stat System
//					}
//					else if (ability->ReturnAbilityType() == ABILITYTYPE::E_TMP_MODIFIYER)
//					{
//						//Communicate with stat System
//					}
//					else if (ability->ReturnAbilityType() == ABILITYTYPE::E_DAMAGE_MODIFYER)
//					{
//						//Communicate with Damage System
//					}
//					else
//					{
//						Debugger::SetSeverity(MessageType::E_ERROR);
//						Debugger::Error("No ability type is found and cannot calculate.", "EffectSystem.cpp", __LINE__);
//						return;
//					}
//				}
//				else
//				{
//					Debugger::SetSeverity(MessageType::E_ERROR);
//					Debugger::Error("action does not meet the effect criteria.", "EffectSystem.cpp", __LINE__);
//					return;
//				}
//			}
//		}
//		else
//		{
//			Debugger::SetSeverity(MessageType::E_ERROR);
//			Debugger::Error("target array is empty.", "EffectSystem.cpp", __LINE__);
//			return;
//		}
//	}
//	OnDestroy();
//}
//void EffectSystem::CallculateEffect(UBaseAction* action_)
//{
//	//This will extract the equation class and calculate the values needed.
//}
//void EffectSystem::RemoveEffect(UBaseAction* action_)
//{
//	//Same process as the equation and reverse calculate the value needed.
//}
//void EffectSystem::SetTarget(UStatSheetObject* target_)
//{
//	target = target_;
//}
//void EffectSystem::Addtarget(UStatSheetObject* target_)
//{
//	targets.Add(target_);
//}
//void EffectSystem::OnDestroy()
//{
//	//clear all variables.
//	if (target)
//	{
//		delete target;
//		target = nullptr;
//	}
//	if (targets.Num() > 0)
//	{
//		for(auto t : targets)
//		{
//			delete t;
//			t = nullptr;
//		}
//		targets.Empty();
//	}
//}
//EffectSystem::~EffectSystem()
//{
//	OnDestroy();
//}
