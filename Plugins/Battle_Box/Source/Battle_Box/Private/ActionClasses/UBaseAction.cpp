// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "../Public/ActionClasses/UBaseAction.h"
#include "../Public/UStatSheetObject.h"
#include "../Public/ActionAlgorithmComponent.h"

FBaseAction_Info UBaseAction::GetBaseInfo() const
{
	return baseInfo;
}
void UBaseAction::ExecuteAlgorithms(FString actionName_, UStatSheetObject* target_)
{

	for (auto u : baseInfo.actionAlgorithms)
	{
		UActionAlgorithmComponent* tmp = u.Value.GetDefaultObject();
		tmp->Init(actionName_, target_);
		tmp->CallAlgorithm();
	}
}
