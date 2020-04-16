// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "../Public/ActionClasses/UBaseAction.h"
#include "../Public/UStatSheetObject.h"
#include "../Public/ActionAlgorithmComponent.h"

FBaseAction_Info UBaseAction::GetBaseInfo() const
{
	return baseInfo;
}
void UBaseAction::SetBaseInfo(FBaseAction_Info other_) 
{
	baseInfo = other_;
}