#include "StatSheetWindow.h"
#include "SlateBasics.h"
//Widgets
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SComboBox.h"
#include "Widgets/Input/SNumericDropDown.h"
#include "Widgets/Input/SSpinbox.h"
#include "Widgets/Layout/SScrollBox.h"
#include "Widgets/SOverlay.h"
//#include "Editor/EditorWidgets/Public/SDropTarget.h"
#include "AssetRegistryModule.h"
#include "../UStatSheetObject.h"
#include "UStatSheetFactory.h"


TSharedRef<SWindow> StatSheetWindow::generateWidow()
{
	return  SNew(SWindow)
		.ClientSize(FVector2D(640, 640))
		.IsEnabled(true)
		.bDragAnywhere(true)
		.Title(FText::FromString("StatSheet Creation Menu"))
		.Content()
		[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(FText::FromString("Name: "))
		.AutoWrapText(true)
		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SAssignNew(StatSheetName,SEditableTextBox)

		]
		]
	+ SVerticalBox::Slot()
		[
			SNew(SHorizontalBox)
			+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
			.Text(FText::FromString("Tag: "))
		.AutoWrapText(true)

		]
	+ SHorizontalBox::Slot()
		.VAlign(VAlign_Center)
		[
			SAssignNew(StatSheetTag, SEditableTextBox)
		]
		]
	+ SVerticalBox::Slot()
		[
			SAssignNew(StatSheetStatInfo, SVerticalBox)
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
					.VAlign(VAlign_Center)
					[
						SNew(STextBlock).Text(FText::FromString("Stat Map"))
					]
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
					[
						SNew(SButton).Text(FText::FromString("Add Stat")).OnClicked_Raw(this, &StatSheetWindow::CreateNewEntry)
					]
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
					[
						SNew(SButton).Text(FText::FromString("Reset Map")).OnClicked_Raw(this, &StatSheetWindow::ResetStatMap)
					]
			]
			+SVerticalBox::Slot()
			[
				SAssignNew(ItemPanel, SScrollBox)
			]
			+SVerticalBox::Slot().HAlign(HAlign_Right).VAlign(VAlign_Center)
			[
				SNew(SButton).OnClicked_Raw(this,&StatSheetWindow::createObject)
				[
					SNew(STextBlock).Text(FText::FromString("Create"))
				]
			]
		]
		];
	UE_LOG(LogTemp, Log, TEXT("Stat Window Open"));
}

FReply StatSheetWindow::CreateNewEntry() {
	ItemPanel.Get()->AddSlot().AttachWidget(StatSheetWindow::genreateStatMapline());
	return FReply::Handled();
}

TSharedRef<SWidget> StatSheetWindow::generateDropDownWidget(FStatSheetItemType inOption)
{
	auto test = SNew(STextBlock).Text(FText::FromString(*inOption));
	return test;
}

TSharedRef<SWidget> StatSheetWindow::genreateStatMapline() {
	auto text = SNew(SEditableTextBox);
	auto spinner = SNew(SSpinBox<float>).MaxValue(10000000000);
	StatNames.Add(text);
	StatValues.Add(spinner);

	auto sendWidget = SNew(SHorizontalBox)
		+SHorizontalBox::Slot()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			[
				SNew(STextBlock).Text(FText::FromString("StatName"))
			]
			+SHorizontalBox::Slot()
			[
				text
			]
		]
		+SHorizontalBox::Slot()
		[
			SNew(SHorizontalBox)
			+SHorizontalBox::Slot()
			[
				SNew(STextBlock).Text(FText::FromString("Stat Value"))
			]
			+SHorizontalBox::Slot()
			[
				spinner
			]
		];
		return sendWidget;
} 

void StatSheetWindow::StatMapOnSecctionChanged(FStatSheetItemType NewValue, ESelectInfo::Type selectionInfo)
{
	currentStatMapItem = NewValue;
}

// create stat sheet object
FReply StatSheetWindow::createObject() {
	FString Filename = StatSheetName.Get()->GetText().ToString();
	FString PackageName = "/Game/";
	PackageName += Filename;
	UPackage* Package = CreatePackage(NULL, *PackageName);
	auto UDataAssetFactory = NewObject<UStatSheetFactory>();
	UStatSheetObject* newDataAssetObject = (UStatSheetObject*)UDataAssetFactory->FactoryCreateNew(UStatSheetObject::StaticClass(), Package, *Filename, RF_Standalone | RF_Public, NULL, GWarn);
	FAssetRegistryModule::AssetCreated(newDataAssetObject);

	Package->FullyLoad();
	Package->SetDirtyFlag(true);

	newDataAssetObject->generalnInfo.name = StatSheetName.Get()->GetText().ToString();
	newDataAssetObject->generalnInfo.tag = StatSheetTag.Get()->GetText().ToString();

	if (StatNames.Num() == StatValues.Num()) { }
	int counter = StatNames.Num();
	UE_LOG(LogTemp, Log, TEXT("Numbers %d"), counter);
	for (int i = 0; i < counter; i++) {
		FString fill = StatNames[i].Get().GetText().ToString();
		float amount = StatValues[i].Get().GetValue();
		newDataAssetObject->generalnInfo.additionlStats.Add(fill ,amount);

		UE_LOG(LogTemp, Log, TEXT("Value Name %s"), *fill);
		UE_LOG(LogTemp, Log, TEXT("Value %d"), amount);
	}
	StatNames.Empty();
	StatValues.Empty();
	ItemPanel.Get()->ClearChildren();
	UE_LOG(LogTemp, Log, TEXT("Create Object"));
	return FReply::Handled();
}
// Clears the Array
FReply StatSheetWindow::ResetStatMap() {
	StatNames.Empty();
	StatValues.Empty();
	ItemPanel.Get()->ClearChildren();
	return FReply::Handled();
}