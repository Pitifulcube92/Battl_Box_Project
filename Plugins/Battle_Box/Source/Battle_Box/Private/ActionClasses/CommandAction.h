// Fill out your copyright notice in the Description page of Project Settings.

#ifndef COMMANDACTION_H
#define COMMANDACTION_H
#include "CoreMinimal.h"
#include "BaseAction.h"

enum class WEAPONTYPE
{
	E_NONE,
	E_BLADE,
	E_RANGE,
	E_BLUNT_WEAP
};

class BATTLE_BOX_API CommandAction : public BaseAction
{
private:
	bool isActionCommand;
	WEAPONTYPE currentweapon;
	BaseAction* command;
public:
	CommandAction();
	CommandAction(const FString name_, const FString discription_, const ACTIONTYPE action_,const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_, TMap<FString, float> statMap_,
				  const WEAPONTYPE currentWeap_,  BaseAction* const command_);
	CommandAction(CommandAction* const other_);
	///Sets the weapon type the item is.
	void SetWeaponType(WEAPONTYPE type_);
	///Sets the command object.
	void SetCommand(BaseAction* action_);
	//TO DO: Make a method thta can execute a blueprint script
	///Return weapon type.
	WEAPONTYPE ReturnWeaponType() const;
	///Return acton.
	BaseAction* ReturnAction() const;
	void OnDestroy();
	~CommandAction();
};
#endif // !1
