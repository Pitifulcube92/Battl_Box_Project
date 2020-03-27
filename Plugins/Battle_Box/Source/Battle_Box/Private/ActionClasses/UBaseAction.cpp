// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "../Public/ActionClasses/UBaseAction.h"
#include "../Public/UStatSheetObject.h"
#include "../Public/UBaseActionAlgorithm.h"

FBaseAction_Info UBaseAction::GetBaseInfo() const
{
	return baseInfo;
}
void UBaseAction::ExecuteAlgorithm(FString algorithmName_, UStatSheetObject* target_)
{
	if (baseInfo.actionAlgorithms.Contains(algorithmName_))
	{
		baseInfo.actionAlgorithms[algorithmName_]->Init(target_);
		baseInfo.actionAlgorithms[algorithmName_]->CallAlgorithm(); 
	}
}
