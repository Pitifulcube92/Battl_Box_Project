// Fill out your copyright notice in the Description page of Project Settings.


#include "LogClass.h"

DEFINE_LOG_CATEGORY(ClassLog)
LogClass::LogClass()
{
}
void LogClass::MessageLog(const FString content_)
{
	UE_LOG(ClassLog, Log, TEXT("%s"), content_.GetCharArray())
}
LogClass::~LogClass()
{
}
