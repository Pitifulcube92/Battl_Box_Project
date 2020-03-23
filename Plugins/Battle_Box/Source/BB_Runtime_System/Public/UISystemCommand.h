#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UISystemCommand.generated.h"

UCLASS()
class BB_RUNTIME_SYSTEM_API UISystemCommand : public UObject
{
	GENERATED_BODY()
public:
	void Execute() PURE_VIRTUAL(UISystemCommand::Execute, ;);
};