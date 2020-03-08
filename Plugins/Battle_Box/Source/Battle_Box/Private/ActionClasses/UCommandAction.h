// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UBaseAction.h"
struct CommandData;


enum class WEAPONTYPE
{
	E_NONE = 1,
	E_BLADE,
	E_RANGE,
	E_BLUNT_WEAP
};

class BATTLE_BOX_API UCommandAction : public UBaseAction
{
private:
	bool isActionCommand;
	WEAPONTYPE currentweapon;
	UBaseAction* command;
public:
	UCommandAction();
	bool Init(const FString name_, const FString discription_, const ACTIONTYPE action_,const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, TMap<FString, float> statMap_,
				  const WEAPONTYPE currentWeap_,  UBaseAction* const command_);
	bool Init(UCommandAction* const other_);
	bool Init(CommandData const data);
	///Sets the weapon type the item is.
	void SetWeaponType(WEAPONTYPE type_);
	///Sets the command object.
	void SetCommand(UBaseAction* action_);
	//TO DO: Make a method thta can execute a blueprint script
	///Return weapon type.
	WEAPONTYPE ReturnWeaponType() const;
	///Return acton.
	UBaseAction* ReturnAction() const;
	void OnDestroy();
	~UCommandAction();
};
