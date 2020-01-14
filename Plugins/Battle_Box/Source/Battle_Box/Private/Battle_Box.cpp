// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Battle_Box.h"

#define LOCTEXT_NAMESPACE "FBattle_BoxModule"

void FBattle_BoxModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	//UE_LOG(LogTemp, Warning, TEXT("This module works!"));
	//FString tmp = "This message shows that this class works!";
}

void FBattle_BoxModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FBattle_BoxModule, Battle_Box)