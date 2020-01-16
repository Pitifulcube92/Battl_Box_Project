// Fill out your copyright notice in the Description page of Project Settings.


#include "Debuger.h"
#include "BattleBoxFileManager.h"
#include "Misc/Paths.h"
MessageType Debuger::currentType = MessageType::E_NONE;
FString Debuger::DebugDirectory = "";

void Debuger::InitDebug()
{
	DebugDirectory = FPaths::ProjectPluginsDir() + "/Battle_Box/Debug";
	if (!BattleBoxFileManager::VerifyOnCreateDirectory(DebugDirectory))
	{
		UE_LOG(LogTemp, Warning, TEXT("Something went wrong with the directory!"));
		return;
	}
	UE_LOG(LogTemp, Log, TEXT("Debug Directory has been made!"));
}
void Debuger::Log(const MessageType type_, const FString& message_, const FString& fileName_, const int32 line_)
{
	UE_LOG(LogTemp, Log, TEXT("This Works!"));
	if (type_ <= currentType && currentType > MessageType::E_NONE)
	{
		UE_LOG(LogTemp, Log, TEXT("This Works!"));
		BattleBoxFileManager::WriteTextFile(DebugDirectory, message_, fileName_, line_, false);		
	}
}
void Debuger::SetSeverity(const MessageType type_)
{
	currentType = type_;
}
void Debuger::Info(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_INFO, message_, fileName_, line_);
}
void Debuger::Error(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_ERROR, message_, fileName_, line_);
}
void Debuger::Warrning(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_WARNING, message_, fileName_, line_);
}
void Debuger::FatalError(const FString& message_, const FString& fileName_, const int32 line_)
{
	Log(MessageType::E_FATAL_ERROR, message_, fileName_, line_);
}
