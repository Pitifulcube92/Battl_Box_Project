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
	////Generate widgets 
	TSharedRef<SWidget> generateDropDownWidget(FComboItemType inOption);


	//// the Action Type ComboBox  
	TSharedPtr<SComboBox<FComboItemType>> actionTypeComboBox;
	//// options in the Action Type sarray
	TArray<FComboItemType> actionTypeArray;
	//// Current Action Type
	FComboItemType currentActionType;
	////changes selection 
	void ActionTypeOnSelectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo);
	//// 
	FText GetCurrentActionTypeLabel() const;

	//// Target Type ComboBox
	TSharedPtr<SComboBox<FComboItemType>> targetTypeComboBox;
	//// options in the Target Type Array;
	TArray<FComboItemType> targetTypeArray;
	//// Current Target Type 
	FComboItemType currentTargetType;
	//// Changes selection
	void TargetTypeOnSectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo);
	//// Updates Lable
	FText GetCurrentTargetTypeLabel() const;

	//// interaction Type ComboBox
	TSharedPtr<SComboBox<FComboItemType>> interactionTypeComboBox;
	//// options in the interaction Type Array;
	TArray<FComboItemType> interactionTypeArray;
	//// Current interaction Type 
	FComboItemType currentinteractionType;
	//// Changes selection
	void InteractionTypeOnSectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo);
	//// Updates Lable
	FText GetCurrentInteractionTypeLabel() const;

	TSharedRef<SWindow> generateWidow();
private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
