// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
enum class ACTIONTYPE
{
	E_NONE = 1,
	E_COMMAND ,
	E_ITEM,
	E_ABILITY
};

enum class TARGETTYPE
{
	E_NONE = 1,
	E_TARGET_ENEMY,
	E_ALL_ENEMIES,
	E_RANDOM_ENEMY,
	E_ALLY,
	E_ALL_ALLY,
	E_ALLY_KO,
	E_ALL_ALLY_KO ,
	E_USER
};

enum class INTERACTIONTYPE
{
	E_NONE = 1,
	E_PHYSICAL,
	E_ABILITY,
	E_PHYSICAL_AND_ABILITY
};

enum class DAMAGETYPE
{
	E_NONE = 1,
	E_HP_DAMAGE,
	E_MP_DAMAGE,
	E_HP_RECOVER,
	E_MP_RECOVER
};

enum class ELEMENTTYPE
{
	E_NONE = 1,
	E_FLAME,
	E_WATER,
	E_EARTH,
	E_ICE,
	E_THUNDER,
	E_WIND,
	E_LIGHT,
	E_DARK
};

enum class STATACTION
{
	E_NONE = 1,
	E_ADD,
	E_REMOVE,
	E_TMP_ADD,
	E_TMP_REMOVE
};

class BATTLE_BOX_API UBaseAction : public UDataAsset
{
private:
	FString name;
	FString discription;
	ACTIONTYPE action;
	TARGETTYPE target;
	STATACTION statAction;
	INTERACTIONTYPE interaction;
	uint32 actionID;
public:
	UBaseAction();
	///Base Construction
	bool Init(FString name_, FString discription_, ACTIONTYPE action_, TARGETTYPE target_, INTERACTIONTYPE interaction_, STATACTION statAction_, const uint32 actionID_, bool IsFirstInstance_);
	bool Init(const UBaseAction* other_);
	uint32 GenerateID();
	///Sets Name.
	void SetName(const FString name_);
	///Sets Discription.
	void SetDiscription(const FString discription_);
	///Sets Actiontype.
	void SetActionType(const ACTIONTYPE type_);
	///Sets target type.
	void SetTargetType(const TARGETTYPE type_);
	///Sets interaction type.
	void SetInteractionType(const INTERACTIONTYPE type_);
	///Set Stat Action type.
	void SetStatActionType(const STATACTION type_);
	///Sets action ID
	void SetActionID(const uint32 actionID_);
	void OnDestroy();
	///Return Name.
	FString ReturnName() const;
	///Return discription.
	FString ReturnDiscription() const;
	///Return action type.
	ACTIONTYPE ReturnActionType() const;
	///Return target type.
	TARGETTYPE ReturnTargetType() const;
	///Return Interaction type.
	INTERACTIONTYPE ReturnInteractionType() const;
	///Returns the stat action type.
	STATACTION ReturnStatActionType() const;
	///Return Action ID.
	uint32 ReturnActionID() const;
	virtual ~UBaseAction();
};
