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

/**
 * 
 */
class CommandAction : public BaseAction
{
private:
	WEAPONTYPE currentweapon;
	BaseAction* Command;
public:
	CommandAction();
	CommandAction(const FString name_, const FString discription_, const ACTIONTYPE action_,const TARGETTYPE target_, const INTERACTIONTYPE interaction_, const uint32 actionID_,
				  const WEAPONTYPE currentWeap_, const BaseAction* command_);
	void SetWeaponType(WEAPONTYPE type_);
	void SetCommand(BaseAction* action_);
	WEAPONTYPE ReturnWeaponType() const;
	BaseAction* ReturnAction() const;
	void OnDestroy();
	~CommandAction();
};
#endif // !1
