// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*	
*/
#ifndef BASESYSTEM_H
#define BASESYSTEM_H
class BaseAction;
class BaseSystem
{
public:
	///Base calculation for any dirieved system classes. 
	virtual void BaseCalculate(const bool IsSingledTarget_, BaseAction* const action_) = 0;
	virtual ~BaseSystem() {};
};

#endif // !BASESYSTEM_H

