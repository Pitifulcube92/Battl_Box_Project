// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TEST_ACTION_MENUCommands.h"

#define LOCTEXT_NAMESPACE "FTEST_ACTION_MENUModule"

void FTEST_ACTION_MENUCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "TEST_ACTION_MENU", "Bring up TEST_ACTION_MENU window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
