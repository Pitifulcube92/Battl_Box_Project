// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle_Box_Actor_Windows.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SEditableTextBox.h"


//Asset Registry 
#include "AssetRegistryModule.h"
//creation classes
#include "ActorFactories/ActorFactory.h"
#include "UBattle_Box_Character_Factory.h"
#include "../Battle_Box_Character.h"
#include "UBattle_Box_Actor_Factory.h"
#include "../Battle_Box_Actor.h"
#include "UBattle_Box_Pawn_Factory.h"
#include "../Battle_Box_Pawn.h"
#include "..\Public\Battle_Box_Actor_Windows.h"

TSharedRef<SWindow> Battle_Box_Actor_Windows::generateWidow()
{
	return  SNew(SWindow)
		.ClientSize(FVector2D(640, 640))
		//.IsPopupWindow(true)
		.IsEnabled(true)
		.bDragAnywhere(true)
		.Content()
		[
			SNew(SVerticalBox)
			// Create Name 
			+ SVerticalBox::Slot()
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
				[
					SNew(STextBlock).Text(FText::FromString("Name: "))
				]
				+ SHorizontalBox::Slot().VAlign(VAlign_Center)
				[
					SAssignNew(actorName, SEditableTextBox)
				]
			]
			// Button Create Actor
			+ SVerticalBox::Slot().VAlign(VAlign_Center)
			[
				SNew(SButton).OnClicked_Raw(this, &Battle_Box_Actor_Windows::CreateActorObject)
				[
					SNew(STextBlock).Text(FText::FromString("Create Actor"))
				]
			]
			// Button Create Character
			+ SVerticalBox::Slot().VAlign(VAlign_Center)
			[
				SNew(SButton).OnClicked_Raw(this, &Battle_Box_Actor_Windows::CreateCharacterObject)
				[
					SNew(STextBlock).Text(FText::FromString("Create Character"))
				]
			]
			// Button Create Pawn
			+ SVerticalBox::Slot().VAlign(VAlign_Center)
			[
				SNew(SButton).OnClicked_Raw(this, &Battle_Box_Actor_Windows::CreatePawnObject)
				[
					SNew(STextBlock).Text(FText::FromString("Create Pawn"))
				]
			]
		];
}

FReply Battle_Box_Actor_Windows::CreateCharacterObject() {
	FindFiles();
	FString Filename = actorName.Get()->GetText().ToString();
 	if (!contentFiles.Contains((Filename + ".uasset"))) {
		UE_LOG(LogTemp, Log, TEXT("Test1"));
		FString PackageName = "/Game/";
		PackageName += Filename;
		UPackage* Package = CreatePackage(NULL, *PackageName);
		Package->FullyLoad();
		auto Factory = NewObject<UBattle_Box_Character_Factory>();
		ABattle_Box_Character* newAssetObject = (ABattle_Box_Character*)Factory->CreateBlueprint(ABattle_Box_Character::StaticClass(), Package, *Filename, FName("NAME_NONE"));

		Package->MarkPackageDirty();
		FAssetRegistryModule::AssetCreated(newAssetObject);


		Package->SetDirtyFlag(true);

		//Save The Package
		FString PackageFileName = FPackageName::LongPackageNameToFilename(PackageName, FPackageName::GetAssetPackageExtension());
		Package->SavePackage(Package, newAssetObject, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone, *PackageFileName, GError, nullptr, true, true, SAVE_NoError);
	//	Package->Save(Package,newAssetObject, EObjectFlags::RF_Public | EObjectFlags::RF_Standalone,)

		newAssetObject->PreEditChange(NULL);
		newAssetObject->PostEditChange();
	}
	if (!contentFiles.Contains(Filename+".uasset")) {
		UE_LOG(LogTemp, Log, TEXT("Test2"));
	}

	UE_LOG(LogTemp, Log, TEXT("Create Character Object"));
	return FReply::Handled();
}

FReply Battle_Box_Actor_Windows::CreatePawnObject()
{
	FString Filename = actorName.Get()->GetText().ToString();
	FString PackageName = "/Game/";
	PackageName += Filename;
	UPackage* Package = CreatePackage(NULL, *PackageName);
	auto Factory = NewObject<UBattle_Box_Pawn_Factory>();
	ABattle_Box_Pawn* newAssetObject = (ABattle_Box_Pawn*)Factory->CreateBlueprint(ABattle_Box_Pawn::StaticClass(), Package, *Filename, FName("NAME_NONE"));
	FAssetRegistryModule::AssetCreated(newAssetObject);

	Package->FullyLoad();
	Package->SetDirtyFlag(true);
	UE_LOG(LogTemp, Log, TEXT("Create Pawn Object"));
	return FReply::Handled();
}

FReply Battle_Box_Actor_Windows::CreateActorObject()
{
	FString Filename = actorName.Get()->GetText().ToString();
	FString PackageName = "/Game/";
	PackageName += Filename;
	UPackage* Package = CreatePackage(NULL, *PackageName);
	auto Factory = NewObject<UBattle_Box_Actor_Factory>();
	ABattle_Box_Actor* newAssetObject = (ABattle_Box_Actor*)Factory->CreateBlueprint(ABattle_Box_Actor::StaticClass(), Package, *Filename, FName("NAME_NONE"));
	FAssetRegistryModule::AssetCreated(newAssetObject);

	Package->FullyLoad();
	Package->SetDirtyFlag(true);
	UE_LOG(LogTemp, Log, TEXT("Create Actor Object"));
	return FReply::Handled();
}

void Battle_Box_Actor_Windows::FindFiles()
{
	IFileManager& FileManager = IFileManager::Get();
	FString FilePath = FPaths::ProjectContentDir() + "*.uasset";
	FileManager.FindFiles(contentFiles, *FilePath, true, false);
}


