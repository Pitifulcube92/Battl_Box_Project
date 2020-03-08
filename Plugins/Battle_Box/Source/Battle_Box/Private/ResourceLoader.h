#pragma once
#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <sstream>
#include "ActionClasses/UBaseAction.h"
#include "BattleBoxFileManager.h"
#include "Containers/Map.h"
#include "Debugger.h"
#include "JsonParse.h"
#include "UStatSheetObject.h"

class UBaseAction;
class UStatSheetObject;

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
	static void AddAction( UBaseAction* const action_);
	// will add a statsheet based on name
	static void AddStatSheet(UStatSheetObject* conststatSheet_);
	
	// Deletes action by name 
	static void DeleteAction(const FString name_); 
	 // deletes statsheet by name
	static void DeleteStatSheet(const FString name_);
	// deletes action by it's ID
	static void DeleteAction(const uint32 id_); 

	// Returns Object if inside 
	static UBaseAction* ReturnAction(const FString name_);
	// returns object by id
	static UBaseAction* ReturnAction(const uint32 id_); 
	 // returns object by name
	static UStatSheetObject* ReturnStatSheet(const FString name_);

	// this will check if object is in the map and return bool;
	static bool CheckAction(const FString name_); 
	// this will check if object is in the map by ID and return bool
	static bool CheckAction(const uint32 id_);
	// this will check if object is in the map and return bool
	static bool CheckStatSheet(const FString name_);

	void OnCreate(); 
	void OnDestroy();
	~ResourceLoader();
private:
	ResourceLoader();

	static TMap<const FString, UBaseAction* const> actionMap;
	static TMap<const FString, UStatSheetObject* const> statSheetMap;
	static uint32 GetActionID(const std::string& key_);
	static std::unique_ptr<ResourceLoader> resourceInstance;
};

#endif
