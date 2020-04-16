// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#include "../Battle_Box/Public/UStatSheetObject.h"
FGeneral_Info UStatSheetObject::GetGeneralInfo() const
{
	return generalInfo;
}

FAction_Info UStatSheetObject::GetActionInfo() const
{
	return actionInfo;
}
void UStatSheetObject::SetGeneralInfo(FGeneral_Info other_)
{
	generalInfo = other_;
}
void UStatSheetObject::SetActionInfo(FAction_Info other_)
{
	actionInfo = other_;
}
