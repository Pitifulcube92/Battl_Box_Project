
#include "ResourceLoader.h"
std::unique_ptr<ResourceLoader> ResourceLoader::resourceInstance = nullptr;

ResourceLoader::ResourceLoader()
{
	OnCreate();
}

ResourceLoader::~ResourceLoader()
{
	OnDestroy();
}

const BaseAction * ResourceLoader::GetAction(FString key_)
{
	if (actionMap.Contains(key_)) {
		return *actionMap.Find(key_);
	}
	Debugger::Error("Key not found. Action not returned, returning nullptr", "ResourceLoader.cpp", __LINE__);
	return nullptr;
}

const StatSheetObject * ResourceLoader::GetStatSheetObject(FString key_)
{
	if (statSheetMap.Contains(key_)) {
		return *statSheetMap.Find(key_);
	}
	Debugger::Error("Key not found. Statsheet not returned, returning nullptr", "ResourceLoader.cpp", __LINE__);
	return nullptr;
}

void ResourceLoader::OnCreate()
{
}

void ResourceLoader::OnDestroy()
{
	if (actionMap.Num > 0) {
		for (auto actions : actionMap) {
			delete actions.Value;
			actions.Value = nullptr;
		}
	}
	if (statSheetMap.Num > 0) {
		for (auto statSheet : statSheetMap) {
			delete statSheet.Value;
			statSheet.Value = nullptr;
		}
	}
}

ResourceLoader * ResourceLoader::GetInstance()
{
	if (resourceInstance == nullptr) {
		resourceInstance.reset(new ResourceLoader);
	}
	return resourceInstance.get();
}

void ResourceLoader::LoadActionSheet(BaseAction* action_){
	if (action_->ReturnName() == "") {// if the name is emtpy create name 
		FString newName = "action " + actionMap.Num();
		action_->SetName(newName);
		actionMap.Add(action_->ReturnName(), action_);
	}
	else if (!actionMap.Contains(action_->ReturnName())) { // if new action is first of it's name
		actionMap.Add(action_->ReturnName(), action_);
	}
	else {
		Debugger::Error("Action Object exists with name " + action_->ReturnName(), "ResourceLoader.cpp", __LINE__);
		FString newName = "action " + statSheetMap.Num();
		action_->SetName(newName);
		actionMap.Add(action_->ReturnName(), action_);
	}
}

void ResourceLoader::LoadStatSheet(StatSheetObject* statSheet_){
	if (statSheet_->ReturnName() == "") { // if the Name is empty create name based on the amount in map
		FString newName = "statSheet " + statSheetMap.Num();
		statSheet_->SetName(newName);
		statSheetMap.Add(statSheet_->ReturnName(), statSheet_);
	}
	else if (!statSheetMap.Contains(statSheet_->ReturnName())) { // statsheet name is not empty and does not contain the current name
		statSheetMap.Add(statSheet_->ReturnName(), statSheet_); // add to the statsheetmap
	}
	else { // if the name is in the map 
		Debugger::Error("Statsheet Object exists with name " + statSheet_->ReturnName(), "ResourceLoader.cpp", __LINE__);
		FString newName = "statSheet " + statSheetMap.Num();
		statSheet_->SetName(newName);
		statSheetMap.Add(statSheet_->ReturnName(), statSheet_);
	}
	
}

uint32 ResourceLoader::GetActionID(const std::string& key_)
{
	FString key = key_.c_str();//because the map is Fstring conversion must occur
	const BaseAction* base;
	if((base = *actionMap.Find(key)) != nullptr){ // object is found at key 
		return base->ReturnActionID(); // Return Action Key is call by the object then returned
	}
	else {
		Debugger::Error("Key returning Null Object", "ResourceLoader.cpp", __LINE__);
		return uint32();
	}
}
