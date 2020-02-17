
#include "ResourceLoader.h"

ResourceLoader::ResourceLoader()
{
	OnCreate();
}

ResourceLoader::~ResourceLoader()
{
	OnDestroy();
}

void ResourceLoader::DetermineLoadType(BaseAction* action_){
	LoadActionSheet(action_);
}

BaseAction * ResourceLoader::GetAction(FString key_)
{
	if (actionMap.Contains(key_)) {
		return *actionMap.Find(key_);
	}
	Debugger::Error("Key not found. Action not returned, returning nullptr", "ResourceLoader.cpp", __LINE__);
	return nullptr;
}

StatSheetObject * ResourceLoader::GetStatSheetObject(FString key_)
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

void ResourceLoader::LoadActionSheet(BaseAction* action_){
	actionMap.Add(action_->ReturnName(), action_);
}

void ResourceLoader::LoadStatSheet(StatSheetObject* statSheet_){
	statSheetMap.Add(statSheet_->ReturnName(), statSheet_);
}

uint32 ResourceLoader::GetActionID(const std::string& key_)
{
	FString key = key_.c_str();//because the map is Fstring conversion must occur
	BaseAction* base;
	if((base = *actionMap.Find(key)) != nullptr){ // object is found at key 
		return base->ReturnActionID(); // Return Action Key is call by the object then returned
	}
	else {
		Debugger::Error("Key returning Null Object", "ResourceLoader.cpp", __LINE__);
		return uint32();
	}
}
