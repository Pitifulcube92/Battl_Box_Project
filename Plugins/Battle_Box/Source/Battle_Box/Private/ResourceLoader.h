
#pragma once
#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <sstream>
#include "ActionClasses/BaseAction.h"
#include "Containers/Map.h"
#include "Debugger.h"
#include "StatSheetObject.h"

class BaseAction;
class StatSheetObject;

class ResourceLoader
{
public:
	static void LoadActionSheet(BaseAction* action_); // 
	static void LoadStatSheet(StatSheetObject* statSheet_); // 
	static const BaseAction* GetAction(FString key_);
	static const StatSheetObject* GetStatSheetObject(FString key_);
	void OnCreate();
	void OnDestroy();

private:
	ResourceLoader();
	~ResourceLoader();

	static TMap<FString,const BaseAction*> actionMap;
	static TMap<FString,const StatSheetObject*> statSheetMap;
	static uint32 GetActionID(const std::string& key_);

};

#endif
