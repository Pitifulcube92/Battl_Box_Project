// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Input/SComboBox.h"
//#include "Battle_Box_Enums.h"


class FToolBarBuilder;
class FMenuBuilder;
typedef TSharedPtr <FString>  FComboItemType;

class FTEST_ACTION_MENUModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command (by default it will bring up plugin window) */
	void PluginButtonClicked();

private:

	void AddToolbarExtension(FToolBarBuilder& Builder);
	void AddMenuExtension(FMenuBuilder& Builder);
	FReply CreateObject();

	TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);

	FReply OpenStatSheetTab();
	FReply OpenActionTab();
	//
	TSharedPtr<FUICommandList> CommandList;
	TSharedPtr<const FExtender> Extender;
	ISlateStyle* slateStyle;
	// Buttons
	TSharedPtr<SButton> ActionButton;
	TSharedPtr<SButton> StatSheetButton;
	TSharedPtr<SButton> ManageButton;
	//Button Text
	TSharedPtr<STextBlock> ActionButtonText;
	TSharedPtr<STextBlock> StatSheetButtonText;
	TSharedPtr<STextBlock> ManageButtonText;
	//Horisontal Box
	TSharedPtr<SHorizontalBox> ContentBox;
	TSharedPtr<SHorizontalBox> FillBox1;
	TSharedPtr<SHorizontalBox> FillBox2;
	
	//SComboBox 
	//TSharedRef<STextBlock> textRef;
	////Generate widgets 
	TSharedRef<SWidget> generateWidgetTest(FComboItemType inOption); 
	////changes selection 
	void OnSelectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo);
	//// gets current Item name
	FText GetCurrentItemLabel() const;
	//// the combobox 
	TSharedPtr<SComboBox<FComboItemType>> testBox;
	//// options in the combobox array
	TArray<FComboItemType> testTextArray;
	//// current Item
	FComboItemType CurrentItem;
	//Button Text
	TSharedPtr<STextBlock> comboBoxText;

	TSharedRef<SWindow> generateWidow();
private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
