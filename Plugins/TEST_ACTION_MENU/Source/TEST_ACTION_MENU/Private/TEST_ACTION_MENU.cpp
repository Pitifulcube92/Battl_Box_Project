// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TEST_ACTION_MENU.h"
#include "TEST_ACTION_MENUStyle.h"
#include "TEST_ACTION_MENUCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SNumericDropDown.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"



static const FName TEST_ACTION_MENUTabName("TEST_ACTION_MENU");

#define LOCTEXT_NAMESPACE "FTEST_ACTION_MENUModule"

//Start up Moduel
void FTEST_ACTION_MENUModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	FTEST_ACTION_MENUStyle::Initialize();
	FTEST_ACTION_MENUStyle::ReloadTextures();

	FTEST_ACTION_MENUCommands::Register();

	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FTEST_ACTION_MENUCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FTEST_ACTION_MENUModule::PluginButtonClicked),
		FCanExecuteAction());

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FTEST_ACTION_MENUModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}

	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FTEST_ACTION_MENUModule::AddToolbarExtension));

		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(TEST_ACTION_MENUTabName, FOnSpawnTab::CreateRaw(this, &FTEST_ACTION_MENUModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FTEST_ACTION_MENUTabTitle", "TEST_ACTION_MENU"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	//SAssignNew(this->testTextArray, STextBlock);
	//testTextArray.Add()
	/*SAssignNew(ActionButtonText, STextBlock).Text(LOCTEXT("ACTIONSADF", "THIS IS TEXT"));
	testTextArray.Add(ActionButtonText);*/
	actionTypeArray.Add(MakeShareable(new FString("E_NONE")));
	actionTypeArray.Add(MakeShareable(new FString("E_ABILTY")));
	actionTypeArray.Add(MakeShareable(new FString("E_COMMAND")));
	actionTypeArray.Add(MakeShareable(new FString("E_ITEM")));
	currentActionType = actionTypeArray[0];

	// target Type
	targetTypeArray.Add(MakeShareable(new FString("E_NONE")));
	targetTypeArray.Add(MakeShareable(new FString("E_TARGET_ENEMY")));
	targetTypeArray.Add(MakeShareable(new FString("E_ALL_ENEMIES")));
	targetTypeArray.Add(MakeShareable(new FString("E_RANDOM_ENEMY")));
	targetTypeArray.Add(MakeShareable(new FString("E_ALLY")));
	targetTypeArray.Add(MakeShareable(new FString("E_ALL_ALLY")));
	targetTypeArray.Add(MakeShareable(new FString("E_ALLY_KO")));
	targetTypeArray.Add(MakeShareable(new FString("E_USER")));
	currentTargetType = targetTypeArray[0];

	/*E_NONE,
	E_PHYSICAL,
	E_ABILITY,
	E_PHYSICAL_AND_ABILITY*/
	// interaction Type
	interactionTypeArray.Add(MakeShareable(new FString("E_NONE")));
	interactionTypeArray.Add(MakeShareable(new FString("E_ABILITY")));
	interactionTypeArray.Add(MakeShareable(new FString("E_PHYSICAL_AND_ABILITY")));
	currentinteractionType = interactionTypeArray[0];
}
//Shutdown Moduel
void FTEST_ACTION_MENUModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FTEST_ACTION_MENUStyle::Shutdown();

	FTEST_ACTION_MENUCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(TEST_ACTION_MENUTabName);
}
//Stat window
TSharedRef<SDockTab> FTEST_ACTION_MENUModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FTEST_ACTION_MENUModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("TEST_ACTION_MENU.cpp"))
	);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
			//.Padding(1.0f, 1.0f)
			[
				SNew(SHorizontalBox)
				+SHorizontalBox::Slot()
				+SHorizontalBox::Slot()
				.Padding(10,0,10,10)
				[
					SNew(SVerticalBox)

					+SVerticalBox::Slot()
					.Padding(0,0,0,10)
					//.FillHeight()
						[
						SAssignNew(ActionButton, SButton) // Action Button
						.OnClicked_Raw(this,  &FTEST_ACTION_MENUModule::OpenActionTab)
							[
							SNew(SBorder)
							.Padding(FMargin(3))
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Content()
								[
								SAssignNew(ActionButtonText, STextBlock)
								.Text(LOCTEXT("Action", "Create Action Menu"))
								.AutoWrapText(true)
								] // Border content end

							]// Button end

						]// vertical box slot end
					+ SVerticalBox::Slot()
					.Padding(0, 0, 0, 10)
						[
						SAssignNew(StatSheetButton, SButton)
						.OnClicked_Raw(this, &FTEST_ACTION_MENUModule::OpenStatSheetTab)
							[
							SNew(SBorder)
							.Padding(FMargin(3))
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Content()
								[
								SAssignNew(StatSheetButtonText, STextBlock)
								.Text(LOCTEXT("StatSheet", "Create StatSheet Menu"))
								.AutoWrapText(true)
								] // Border content end

							]// Button end
						]// Vertical Box Slot
					+SVerticalBox::Slot()
						[
						SAssignNew(ManageButton, SButton)
							[
							SNew(SBorder)
							.Padding(FMargin(3))
							.HAlign(HAlign_Center)
							.VAlign(VAlign_Center)
							.Content()
								[
								SAssignNew(ManageButtonText, STextBlock)
								.Text(LOCTEXT("Manage", "Manage Actions and StatSheets"))
								.AutoWrapText(true)
								] // Border content end

							]// Button end
						]
				]// horisontal box end
				+ SHorizontalBox::Slot()
			]// Horisontal Box end
		];
}
// if the plugin button is click open modlue window
void FTEST_ACTION_MENUModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->InvokeTab(TEST_ACTION_MENUTabName);
}
// Builds the First window used in Start up
void FTEST_ACTION_MENUModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FTEST_ACTION_MENUCommands::Get().OpenActionWindow);
//	Builder.()
}
//toolBar extion call Used in start up
void FTEST_ACTION_MENUModule::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FTEST_ACTION_MENUCommands::Get().OpenPluginWindow);
}

///

//Creation of the other two windows

///
//StatSheetWindow Creation
FReply FTEST_ACTION_MENUModule::OpenStatSheetTab()
{
	auto MyWindow = SNew(SWindow)
		.ClientSize(FVector2D(640, 640))
		//.IsPopupWindow(true)
		.IsEnabled(true)
		.bDragAnywhere(true)
		.Content()
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
		[
			SNew(STextBlock)
			.Text(LOCTEXT("Menu Name Stat", "Create StatSheet"))
		]
	+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("StatName", "Name: "))
		.AutoWrapText(true)
		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(SEditableTextBox)

		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("StatTag", "Tag: "))
		.AutoWrapText(true)

		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(SEditableTextBox)
		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(LOCTEXT("StatActionMap", "Action Maps"))
		]
		]
		];
	UE_LOG(LogTemp, Log, TEXT("Stat Window Open"));
	FSlateApplication::Get().AddWindow(MyWindow, true);
	return FReply::Handled();
}
//actionwindow creation calls Generate Window Transfer code from genrate window to this function call once completed dropDowns
FReply FTEST_ACTION_MENUModule::OpenActionTab() {

	auto myWindow = generateWidow();
	UE_LOG(LogTemp, Log, TEXT("Action Window Open"));
	FSlateApplication::Get().AddWindow(myWindow, true);
	return FReply::Handled();
}
//Genreates a STextBlock based on a FComboItemType array
TSharedRef<SWidget> FTEST_ACTION_MENUModule::generateDropDownWidget(FComboItemType inOption)
{
	auto test = SNew(STextBlock).Text(FText::FromString(*inOption));
	return test;
}
// gets the action type name
FText FTEST_ACTION_MENUModule::GetCurrentActionTypeLabel() const
{
	if (currentActionType.IsValid()) {
		return FText::FromString(**currentActionType);
	}
	else {
		return FText::FromString("Failed");
	}
}
//Section changes the current Action Type once a slection is changed
void FTEST_ACTION_MENUModule::ActionTypeOnSelectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo)
{
	currentActionType = NewValue;
	UE_LOG(LogTemp, Warning, TEXT("Current Item is: %s"), **currentActionType);
}
void FTEST_ACTION_MENUModule::TargetTypeOnSectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo)
{
	currentTargetType = NewValue;
	UE_LOG(LogTemp, Warning, TEXT("Current Item is: %s"), **currentActionType);
}
FText FTEST_ACTION_MENUModule::GetCurrentTargetTypeLabel() const
{
	if (currentTargetType.IsValid()) {
		return FText::FromString(**currentTargetType);
	}
	return FText::FromString("Failed");
}
void FTEST_ACTION_MENUModule::InteractionTypeOnSectionChanged(FComboItemType NewValue, ESelectInfo::Type selectionInfo)
{
	currentinteractionType = NewValue;
}
FText FTEST_ACTION_MENUModule::GetCurrentInteractionTypeLabel() const
{
	if (currentinteractionType.IsValid()) {
		return FText::FromString(**currentinteractionType);
	}
	return FText::FromString("Failed");
}
//Genrates the Action Creation Menu Move code to actionTab
TSharedRef<SWindow> FTEST_ACTION_MENUModule::generateWidow()
{
	return SNew(SWindow)
		.ClientSize(FVector2D(640, 640))
		.IsEnabled(true)
		.bDragAnywhere(true)
		.Content()[
			SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				.VAlign(VAlign_Top)
				.HAlign(HAlign_Left)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Action Title Text", "Action Creation Menu"))
				]
				]
			+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Action type", "Choose Action Type"))
				]
			+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SAssignNew(actionTypeComboBox, SComboBox<FComboItemType>)
					.OptionsSource(&actionTypeArray)
				.OnGenerateWidget_Raw(this, &FTEST_ACTION_MENUModule::generateDropDownWidget)
				.OnSelectionChanged_Raw(this, &FTEST_ACTION_MENUModule::ActionTypeOnSelectionChanged)
				.InitiallySelectedItem(currentActionType)
				[
					SNew(STextBlock).Text_Raw(this, &FTEST_ACTION_MENUModule::GetCurrentActionTypeLabel)
					//.Text(FText::FromString("Failed"))

				]
				]
				]
			+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock).Text(FText::FromString("Target Type:"))
					]
					+ SHorizontalBox::Slot()
					.VAlign(VAlign_Center)
					[
						SAssignNew(targetTypeComboBox, SComboBox<FComboItemType>)
						.OptionsSource(&targetTypeArray)
						.OnGenerateWidget_Raw(this, &FTEST_ACTION_MENUModule::generateDropDownWidget)
						.OnSelectionChanged_Raw(this, &FTEST_ACTION_MENUModule::TargetTypeOnSectionChanged)
						.InitiallySelectedItem(currentTargetType)
						[
						SNew(STextBlock).Text_Raw(this, &FTEST_ACTION_MENUModule::GetCurrentTargetTypeLabel)
						]
					]
				]
			+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("Interaction type", "Choose Interaction Type"))
				]
				+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SAssignNew(interactionTypeComboBox, SComboBox<FComboItemType>)
					.OptionsSource(&interactionTypeArray)
					.OnGenerateWidget_Raw(this, &FTEST_ACTION_MENUModule::generateDropDownWidget)
					.OnSelectionChanged_Raw(this, &FTEST_ACTION_MENUModule::InteractionTypeOnSectionChanged)
					.InitiallySelectedItem(currentinteractionType)
					[
						SNew(STextBlock).Text_Raw(this, &FTEST_ACTION_MENUModule::GetCurrentInteractionTypeLabel)
					]
				]
				]
			+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SNew(STextBlock)
					.Text(LOCTEXT("ActionID  type", "Choose ActionID Type"))
				]
			+ SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				[
					SNew(SEditableText)
				]
				]
			+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()
				.VAlign(VAlign_Bottom)
				.HAlign(HAlign_Right)
				[
					SNew(SButton)
					.Text(LOCTEXT("Action Creation Button Text", "Create"))
				.OnClicked_Raw(this, &FTEST_ACTION_MENUModule::CreateObject)
				]
				]
		];

}
//Test call
FReply FTEST_ACTION_MENUModule::CreateObject()
{
	UE_LOG(LogTemp, Log, TEXT("Create Object"));
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FTEST_ACTION_MENUModule, TEST_ACTION_MENU)
