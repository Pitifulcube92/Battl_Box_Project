// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Widgets/SWindow.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "HAL/FileManagerGeneric.h"
#include "Misc/Paths.h"


/**
 * 
 */
class TEST_ACTION_MENU_API Battle_Box_Actor_Windows : public IModuleInterface
{
public:
	TSharedPtr<SEditableTextBox>actorName;
	TArray<FString> contentFiles;
	TSharedRef<SWindow> generateWidow();
	FReply CreateCharacterObject();
	FReply CreatePawnObject();
	FReply CreateActorObject();
	//search function to find all the files in directory
	void FindFiles();
};
