
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

	// Will Add action based on name
	static void AddAction( BaseAction* const action_);
	// will add a statsheet based on name
	static void AddStatSheet(StatSheetObject* conststatSheet_);
	
	// Deletes action by name 
	static void DeleteAction(const FString name_); 
	 // deletes statsheet by name
	static void DeleteStatSheet(const FString name_);
	// deletes action by it's ID
	static void DeleteAction(const uint32 id_); 

	// Returns Object if inside 
	static BaseAction* ReturnAction(const FString name_);
	// returns object by id
	static BaseAction* ReturnAction(const uint32 id_); 
	 // returns object by name
	static StatSheetObject* ReturnStatSheet(const FString name_);

	// this will check if object is in the map and return bool;
	static bool CheckAction(const FString name_); 
	// this will check if object is in the map by ID and return bool
	static bool CheckAction(const uint32 id_);
	// this will check if object is in the map and return bool
	static bool CheckStatSheet(const FString name_);

	void OnCreate(); 
	void OnDestroy();

private:
	ResourceLoader();
	~ResourceLoader();
	static TMap<const FString, BaseAction* const> actionMap;
	static TMap<const FString, StatSheetObject* const> statSheetMap;
	static uint32 GetActionID(const std::string& key_);
	static std::unique_ptr<ResourceLoader> resourceInstance;
};

#endif
