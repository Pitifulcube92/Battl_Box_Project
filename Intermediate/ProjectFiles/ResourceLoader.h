
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
	static void DetermineLoadType(BaseAction* action_); 
	static void DetermineLoadType(StatSheetObject* statSheet_);
	static BaseAction* GetAction(FString key_);
	static StatSheetObject* GetStatSheetObject(FString key_);
	void OnCreate();
	void OnDestroy();

private:
	ResourceLoader();
	~ResourceLoader();
	static void LoadActionSheet(BaseAction* action_); // 
	static void LoadStatSheet(StatSheetObject* statSheet_); // 
	static TMap<FString, BaseAction*> actionMap;
	static TMap<FString, StatSheetObject*> statSheetMap;
	static uint32 GetActionID(const std::string& key_);

};

#endif
