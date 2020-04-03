// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SSpinBox.h"
//#include "Battle_Box_Enums.h"


class FToolBarBuilder;
class FMenuBuilder;
typedef TSharedPtr <FString>  FComboItemType;
typedef TSharedPtr <FString>  FStatSheetItemType;

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

	/// Main Menu
	// Buttons
	TSharedPtr<SButton> ActionButton;
	TSharedPtr<SButton> StatSheetButton;
	//Button Text
	TSharedPtr<STextBlock> ActionButtonText;
	TSharedPtr<STextBlock> StatSheetButtonText;
	//Horisontal Box
	TSharedPtr<SHorizontalBox> ContentBox;
	TSharedPtr<SHorizontalBox> FillBox1;
	TSharedPtr<SHorizontalBox> FillBox2;
	/// </Main Menu
	


	//SComboBox 
	////Generate widgets 
	TSharedRef<SWidget> generateDropDownWidget(FComboItemType inOption);

	/// Action Menu
	// SEditable Name
	TSharedPtr<SEditableTextBox> actionName;
	// SEditable Desciption
	TSharedPtr<SEditableTextBox> actionDescription;

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

	//// Stataction type ComboBox
	TSharedPtr<SComboBox<FComboItemType>> statActionTypeComboBox;
	//// options in the stataction type array
	TArray<FComboItemType> statActionTypeArray;
	//// Current statActionType Array
	FComboItemType currentStatActionType;
	//// changes current selection 
	void StatActionTypeOnSelectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo);
	//// Updates Label
	FText GetCurrentStatActionTypeLabel() const;

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

	// SEditable 
	TSharedPtr<SSpinBox<float>> actionID;
	/// </Action Menu
	
	
	
	/// StatSheet Widgets
	//Stat Map Variables;
	///Slate Stat name
	TSharedPtr<SEditableText> StatName;
	///Slate Stat VAlue
	TSharedPtr<SSpinBox<float>> StatValue;
	///Slate widget Combo Box;
	TSharedPtr<SComboBox<FStatSheetItemType>> StatMapWidget;
	/// ComboBox Array;
	TArray<FStatSheetItemType> StatMapArray;
	///StatMap Current Selection;
	FStatSheetItemType currentStatMapItem; 
	///Stat Map On selection Change
	void StatMapOnSecctionChanged(FStatSheetItemType NewValue, ESelectInfo::Type selectionInfo);
	/// C++ Stat Map
	TMap<FString, float> StatMap;
	
	
	
	
	TSharedRef<SWindow> generateWidow();

	FReply CreateNewEntry();
	FReply CreateStatObject();
private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
