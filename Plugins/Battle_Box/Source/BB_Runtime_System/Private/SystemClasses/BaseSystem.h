// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
#ifndef BASESYSTEM_H
#define BASESYSTEM_H

class BaseSystem
{
public:
	virtual void BaseCalculate(const bool IsSingledTarget);
	virtual ~BaseSystem();
};

#endif // !BASESYSTEM_H

