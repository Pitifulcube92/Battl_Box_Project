// Fill out your copyright notice in the Description page of Project Settings.

#ifndef DEBUGER_H
#define DEBUGER_H
#include "CoreMinimal.h"
/**
 * 
 */
enum class MessageType
{
	E_NONE = 0,
	E_INFO,
	E_WARNING,
	E_ERROR,
	E_FATAL_ERROR
};
class Debugger 
{
private:
	static void Log(const MessageType type_, const FString& message_, const FString& fileName_, const int32 line_);
	static TArray<FString> LogArray;
	static MessageType currentType;
	static FString DebugDirectory;
public:
	Debugger(const Debugger&) = delete;
	Debugger(Debugger&&) = delete;
	Debugger& operator =(const Debugger&) = delete;
	Debugger& operator =(Debugger&&) = delete;
	Debugger() = delete;

	static void InitDebug();
	static void SetSeverity(const MessageType type_);
	static void Info(const FString& message_, const FString& fileName_, const int32 line_);
	static void Error(const FString& message_, const FString& fileName_, const int32 line_);
	static void Warrning(const FString& message_, const FString& fileName_, const int32 line_);
	static void FatalError(const FString& message_, const FString& fileName_, const int32 line_);
};
#endif // !1
