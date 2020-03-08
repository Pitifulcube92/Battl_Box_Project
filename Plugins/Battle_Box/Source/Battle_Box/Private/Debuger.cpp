// Fill out your copyright notice in the Description page of Project Settings.


#include "Debugger.h"
#include "BattleBoxFileManager.h"
///destroy all this 
#include "ActionClasses/UBaseAction.h"
#include "UStatSheetObject.h"
#include "ActionClasses/UAbilityAction.h"
#include "ActionClasses/UItemAction.h"
#include "ActionClasses/UCommandAction.h"
#include "ResourceLoader.h"
#include <string>
#include "JsonParse.h"
///destroy all this
#include "Misc/Paths.h"

MessageType Debugger::currentType = MessageType::E_NONE;
FString Debugger::DebugDirectory = "";
TArray<FString> Debugger::LogArray = TArray<FString>();

void Debugger::InitDebug()
{
	DebugDirectory = FPaths::ProjectPluginsDir() + "/Battle_Box/Debug";
	if (!BattleBoxFileManager::VerifyOnCreateDirectory(DebugDirectory))
	{
		UE_LOG(LogTemp, Warning, TEXT("Something went wrong with the directory!"));
		return;
	}
	currentType = MessageType::E_FATAL_ERROR;
	UE_LOG(LogTemp, Log, TEXT("Debug Directory has been made!"));
	
}
void Debugger::Log(const MessageType type_, const FString& message_, const FString& fileName_, const int32 line_)
{
	UE_LOG(LogTemp, Log, TEXT("This Works!"));
	if (type_ <= currentType && currentType > MessageType::E_NONE)
	{
		UE_LOG(LogTemp, Log, TEXT("This Works!"));
		FString LogMessage = message_ + " in " + fileName_ + ". " + "Line: " + FString::FromInt(line_);
		FString LogFileName = "Logger.txt";
		LogArray.Add(LogMessage);
		BattleBoxFileManager::WriteTextArrayToFile(DebugDirectory, LogArray, LogFileName, true);
	}
}
void Debugger::SetSeverity(const MessageType type_)
{
	currentType = type_;
}
void Debugger::Info(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_INFO,"INFO: " + message_, fileName_, line_);
}
void Debugger::Error(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_ERROR,"ERROR: " + message_, fileName_, line_);
}
void Debugger::Warrning(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_WARNING,"WARNING: " + message_, fileName_, line_);
}
void Debugger::FatalError(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_FATAL_ERROR,"FATALERROR: " + message_, fileName_, line_);
}
//
//void Debugger::TESTALLCLASSES()
//{
//	TMap<FString, float> statMap;
//	statMap.Add("Attack", 66);
//	TArray<AbilityAction*> Tarray;
//	EquationData equation = EquationData();
//	BaseAction* test = new BaseAction();
//	
//	AbilityAction* abilty = 
//		new AbilityAction(FString("Name"), FString("DesciptionAbilty"), ACTIONTYPE::E_ABILITY,TARGETTYPE::E_ALL_ENEMIES,
//			INTERACTIONTYPE::E_ABILITY, 2.0f, statMap, 3.0f, ABILITYTYPE::E_DAMAGE_MODIFYER, equation);	
//
//	ItemAction* item = new ItemAction(FString("NameItem"),FString("ItemDesc"), ACTIONTYPE::E_ITEM,TARGETTYPE::E_ALLY_KO,
//		INTERACTIONTYPE::E_PHYSICAL_AND_ABILITY, 32, statMap,4,DAMAGETYPE::E_MP_DAMAGE,Tarray);
//	
//	CommandAction* command = new CommandAction(FString("CommandName"), FString("CommandDesc"), ACTIONTYPE::E_COMMAND,
//		TARGETTYPE::E_RANDOM_ENEMY, INTERACTIONTYPE::E_PHYSICAL, 42, statMap, WEAPONTYPE::E_BLADE,
//		test);
//
//	static ResourceLoader* resource;
//	resource->OnCreate();
//	resource->GetInstance()->OnCreate();
//	resource->GetInstance()->AddAction(abilty);
//
//
//	TMap<FString, AbilityAction*> abiltyMap;
//	TMap<FString, ItemAction*> itemMap;
//	TMap<FString, CommandAction*> commandMap;
//	TMap<FString, ItemAction*> equipMap;
//
//	/// StatSheet
//	StatSheetObject* statSheet = new StatSheetObject(FString("StatSheetName"), FString("Tag"),commandMap,
//		itemMap,abiltyMap,statMap,equipMap);
//
//	resource->GetInstance()->AddStatSheet(statSheet);
//	bool StatSheetCheck = resource->GetInstance()->CheckStatSheet(statSheet->ReturnName());
//	if(StatSheetCheck) { Debugger::Info("Resouce StatSheetObject Check done correctly", "Debugger.cpp", __LINE__);  }
//	StatSheetObject* ReturnStatSheetTest = resource->GetInstance()->ReturnStatSheet(statSheet->ReturnName());
//	Debugger::Info("ReturnStatSheetTest name is: " + ReturnStatSheetTest->ReturnName(), "Debugger.cpp", __LINE__);
//	resource->DeleteStatSheet(statSheet->ReturnName());
//	resource->CheckStatSheet(statSheet->ReturnName());
//
//	statSheet->AddAbilityAction(abilty);
//	statSheet->AddItemAction(item);
//	statSheet->AddItemAction(item);
//	statSheet->AddCommandAction(command);
//	statSheet->AddEquipment(item);
//	statSheet->AddAbilityAction(abilty);
//	/// StatSheet 
//	//command->GenerateID();
//	JsonParse* parse = new JsonParse();
//	parse->InitiateClass();
//
//}