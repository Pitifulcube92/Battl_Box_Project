// Fill out your copyright notice in the Description page of Project Settings.
#ifndef BASEACTION_H
#define BASEACTION_H
#include "CoreMinimal.h"
enum class ACTIONTYPE
{
	E_NONE,
	E_COMMAND,
	E_ITEM,
	E_ABILITY
};

enum class TARGETTYPE
{
	E_NONE,
	E_TARGET_ENEMY,
	E_ALL_ENEMIES,
	E_RANDOM_ENEMY,
	E_ALLY,
	E_ALL_ALLY,
	E_ALLY_KO,
	E_ALL_ALLY_KO,
	E_USER
};

enum class INTERACTIONTYPE
{
	E_NONE,
	E_BASIC_ACTION,
	E_PHYSICAL_ACTION,
	E_ABILITY_ACTION
};

enum class DAMAGETYPE
{
	E_NONE,
	E_HP_DAMAGE,
	E_MP_DAMAGE,
	E_HP_RECOVER,
	E_MP_RECOVER
};

enum class ELEMENTTYPE
{
	E_NONE,
	E_FLAME,
	E_WATER,
	E_EARTH,
	E_ICE,
	E_THUNDER,
	E_WIND,
	E_LIGHT,
	E_DARK
};

class BaseAction
{
private:
	FString name;
	FString discription;
	ACTIONTYPE action;
	TARGETTYPE target;
	INTERACTIONTYPE interaction;
	uint32 actionID;
public:
	BaseAction();
	//Base Construction
	BaseAction(FString name_, FString discription_, ACTIONTYPE action_, TARGETTYPE target_, INTERACTIONTYPE interaction_, const uint32 actionID_);
	BaseAction(const BaseAction* other_);
	void SetName(const FString name_);
	void SetDiscription(const FString discription_);
	void SetAction(const ACTIONTYPE type_);
	void SetTarget(const TARGETTYPE type_);
	void SetInteraction(const INTERACTIONTYPE type_);
	void SetActionID(const uint32 actionID_);
	void OnDestroy();

	FString ReturnName() const;
	FString ReturnDiscription() const;
	ACTIONTYPE ReturnActionType() const;
	TARGETTYPE ReturnTargetType() const;
	INTERACTIONTYPE ReturnInteractionType() const;
	uint32 ReturnActionID() const;
	virtual ~BaseAction();
};


#endif // !1

