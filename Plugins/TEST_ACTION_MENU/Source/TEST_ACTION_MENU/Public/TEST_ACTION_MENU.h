// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

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

	//Test For SListView
	FReply ButtonPressed();

	/* Adds a new textbox with the string to the list */
	TSharedRef<ITableRow> OnGenerateRowForList(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable);

	/* The list of strings */
	TArray<TSharedPtr<FString>> Items;

	/* The actual UI list */
	TSharedPtr< SListView< TSharedPtr<FString> > > ListViewWidget;
private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
