// Fill out your copyright notice in the Description page of Project Settings.



#include "CoreMinimal.h"
#include "../Public/ActionClasses/UBaseAction.h"
#include "UCommandAction.generated.h"

USTRUCT(BlueprintType, Category = "Battle_Box")
struct BATTLE_BOX_API FCommandAction_Info
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	bool isActionCommand;
	UPROPERTY(EditAnywhere)
	WEAPONTYPE currentweapon;
	UPROPERTY(EditAnywhere)
	UBaseAction* command;
};

UCLASS(Blueprintable, BlueprintType, Category="Battle_Box")
class BATTLE_BOX_API UCommandAction : public UBaseAction
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly)
		FCommandAction_Info commandInfo;
	UFUNCTION(BlueprintCallable)
		FCommandAction_Info GetCommandInfo() const;
};
