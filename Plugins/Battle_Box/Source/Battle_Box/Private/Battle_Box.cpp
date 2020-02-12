// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Battle_Box.h"
#include "../Private/Debugger.h"
#include "BattleBoxFileManager.h"
#include "Misc/Paths.h"

#define LOCTEXT_NAMESPACE "FBattle_BoxModule"

void FBattle_BoxModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	Debugger::InitDebug();
	Debugger::SetSeverity(MessageType::E_INFO);
	if (BattleBoxFileManager::VerifyOnCreateDirectory(FPaths::ProjectPluginsDir() + "/Battle_Box/FileResource") ||
		BattleBoxFileManager::VerifyOnCreateDirectory(FPaths::ProjectPluginsDir() + "/Battle_Box/FileResource/StatSheets") ||
		BattleBoxFileManager::VerifyOnCreateDirectory(FPaths::ProjectPluginsDir() + "/Battle_Box/FileResource/ActionSheets"))
	{
		Debugger::SetSeverity(MessageType::E_ERROR);
		Debugger::Error("One of the Directories did not work or make!", "Battle_Box.cpp", __LINE__);
	}

}

void FBattle_BoxModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBattle_BoxModule, Battle_Box)