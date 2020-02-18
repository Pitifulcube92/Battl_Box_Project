
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
public:// Singleton stuff
	ResourceLoader(const ResourceLoader&) = delete;
	ResourceLoader(ResourceLoader&&) = delete;
	ResourceLoader& operator=(const ResourceLoader&) = delete;
	ResourceLoader& operator=(ResourceLoader&&) = delete;
	// Singleton 
	static ResourceLoader* GetInstance(); // The Instance of Resrouce Loader

	static void LoadActionSheet(BaseAction* action_); // Will load a action into the action map
	static void LoadStatSheet(StatSheetObject* statSheet_); // will load a statsheet in to the statsheet map
	static const BaseAction* GetAction(FString key_); // will get an action from the action map 
	static const StatSheetObject* GetStatSheetObject(FString key_); // will get a statsheet from the statsheepmap 
	void OnCreate(); 
	void OnDestroy();

private:
	ResourceLoader();
	~ResourceLoader();
	static TMap<FString,const BaseAction*> actionMap;
	static TMap<FString,const StatSheetObject*> statSheetMap;
	static uint32 GetActionID(const std::string& key_);
	static std::unique_ptr<ResourceLoader> resourceInstance;
};

#endif
