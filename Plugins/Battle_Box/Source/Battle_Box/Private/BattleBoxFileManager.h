// Fill out your copyright notice in the Description page of Project Settings.

#ifndef BATTLEBOXFILEMANAGER_H
#define BATTLEBOXFILEMANAGER_H

#include "CoreMinimal.h"

/**
 * 
 */
class BattleBoxFileManager
{
public:
	BattleBoxFileManager(const BattleBoxFileManager&) = delete;
	BattleBoxFileManager(BattleBoxFileManager&&) = delete;
	BattleBoxFileManager& operator=(const BattleBoxFileManager&) = delete;
	BattleBoxFileManager& operator=(BattleBoxFileManager&&) = delete;
	BattleBoxFileManager() = delete;

	static bool VerifyOnCreateDirectory(const FString& testDir_);
	static void GetFileSize(const FString& sourcePath_);
	static void DeleteFile(const FString& sourcePath_);
	static void WriteTextFile(const FString& saveDirectory_, const FString context_, const FString& FileName_, const int32 line_, bool const IsOverWrite_);
};
#endif // !
