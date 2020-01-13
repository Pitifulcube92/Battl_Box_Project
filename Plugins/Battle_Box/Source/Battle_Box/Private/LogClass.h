// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Logging/LogCategory.h"

DECLARE_LOG_CATEGORY_EXTERN(ClassLog, Log, All)
/**
 * 
 */
class LogClass
{
public:
	LogClass();
	static void MessageLog(const FString constext_);
	~LogClass();
};
