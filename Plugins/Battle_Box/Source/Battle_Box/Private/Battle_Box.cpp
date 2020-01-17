// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Battle_Box.h"
#include "../Private/Debuger.h"

#define LOCTEXT_NAMESPACE "FBattle_BoxModule"

void FBattle_BoxModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	Debuger::InitDebug();
	Debuger::SetSeverity(MessageType::E_INFO);
	Debuger::Info("Info is working.", "Battle_Box.cpp", __LINE__);

	Debuger::SetSeverity(MessageType::E_ERROR);
	Debuger::Error("Error is working.", "Battle_Box.cpp", __LINE__);

	Debuger::SetSeverity(MessageType::E_WARNING);
	Debuger::Warrning("Warning is Working.", "Battle_Box.cpp", __LINE__);

	Debuger::SetSeverity(MessageType::E_FATAL_ERROR);
	Debuger::FatalError("FatalError is working.", "Battle_Box.cpp", __LINE__);
}

void FBattle_BoxModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBattle_BoxModule, Battle_Box)