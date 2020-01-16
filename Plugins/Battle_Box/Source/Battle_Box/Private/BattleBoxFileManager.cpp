// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleBoxFileManager.h"
#include "HAL/PlatformFilemanager.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "Misc/FileHelper.h"

bool BattleBoxFileManager::VerifyOnCreateDirectory(const FString& testDir_)
{
	IPlatformFile& PlatFromFile = FPlatformFileManager::Get().GetPlatformFile();

	if (!PlatFromFile.DirectoryExists(*testDir_))
	{
		PlatFromFile.CreateDirectory(*testDir_);
		if(!PlatFromFile.DirectoryExists(*testDir_))
		{
			return false;
		}
	}
	return true;
}
void  BattleBoxFileManager::GetFileSize(const FString& sourcePath_)
{
	if(!FPlatformFileManager::Get().GetPlatformFile().FileSize(*sourcePath_)) 
	{
		UE_LOG(LogTemp, Warning, TEXT("File not Found!"));
		return;
	}
	const int32 FileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*sourcePath_);

	FString Message = FString::Printf(TEXT("File size is: %d"), FileSize);
	UE_LOG(LogTemp, Log, TEXT("%s"), *Message);

}
void  BattleBoxFileManager::DeleteFile(const FString& sourcePath_)
{
	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*sourcePath_))
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not find File!"));
		return;
	}
}
void  BattleBoxFileManager::WriteTextFile(const FString& saveDirectory_, const FString context_, const FString& FileName_, const int32 line_,  bool const IsOverWrite_)
{
	IPlatformFile& PlateFormFile = FPlatformFileManager::Get().GetPlatformFile();

	if(PlateFormFile.CreateDirectory(*saveDirectory_))
	{
		FString absoluteFilePath = saveDirectory_ + "/" + FileName_;
		if (IsOverWrite_|| !PlateFormFile.FileExists(*absoluteFilePath))
		{
			FFileHelper::SaveStringToFile(*context_ + line_, *absoluteFilePath);
		}
	}
}

