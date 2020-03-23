#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

class BB_RUNTIME_SYSTEM_API ISystemCommand : public UObject
{
public:
	virtual void Execute() = 0;
};