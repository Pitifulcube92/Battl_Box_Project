
#include "ResourceLoader.h"
#include "Misc/Paths.h"
#include "FileManager.h" // remove if not needed
std::unique_ptr<ResourceLoader> ResourceLoader::resourceInstance = nullptr;
TMap<const FString, BaseAction *const> ResourceLoader::actionMap = TMap<const FString, BaseAction *const>();
TMap<const FString, StatSheetObject* const> ResourceLoader::statSheetMap = TMap<const FString, StatSheetObject* const>();
ResourceLoader::ResourceLoader()
{
	OnCreate();
}

ResourceLoader::~ResourceLoader() {
	OnDestroy();
}

BaseAction * ResourceLoader::ReturnAction(const FString name_)
{
	if (actionMap.Contains(name_)) {
		BaseAction* baseAction = new BaseAction(actionMap[name_]->ReturnName(), actionMap[name_]->ReturnDiscription(), actionMap[name_]->ReturnActionType(), actionMap[name_]->ReturnTargetType(), actionMap[name_]->ReturnInteractionType(), actionMap[name_]->ReturnStatActionType(), actionMap[name_]->ReturnActionID(), false);
		return baseAction;
	}
	Debugger::SetSeverity(MessageType::E_ERROR);
	Debugger::Error("Action not found in Resources returning Nullptr", "ResourceLoader.cpp", __LINE__);
	return nullptr;
}

BaseAction * ResourceLoader::ReturnAction(const uint32 id_)
{
	for (auto actions : actionMap) {
		if (actions.Value->ReturnActionID() == id_) {
			BaseAction * baseAction = new BaseAction(actions.Value);
			return baseAction;
		}
	}
	Debugger::SetSeverity(MessageType::E_ERROR);
	Debugger::Error("Action not found in Resources returning Nullptr", "ResourceLoader.cpp", __LINE__);
	return nullptr;
}

StatSheetObject * ResourceLoader::ReturnStatSheet(const FString name_)
{
	if (statSheetMap.Contains(name_)) {
		StatSheetObject* statSheet = new StatSheetObject(statSheetMap[name_]->ReturnName(), statSheetMap[name_]->ReturnTag(),statSheetMap[name_]->ReturnCommandMap(), statSheetMap[name_]->ReturnItemMap(), statSheetMap[name_]->ReturnAbilityMap(), statSheetMap[name_]->ReturnStatMap(), statSheetMap[name_]->ReturnEquipmentMap());
		return statSheet;
	}
	Debugger::SetSeverity(MessageType::E_ERROR);
	Debugger::Error("StatSheet object not found in Resources", "ResourceLoader.cpp", __LINE__);
	return nullptr;
}

bool ResourceLoader::CheckAction(const FString name_)
{
	if (actionMap.Contains(name_)) {
		return true;
	}
	Debugger::SetSeverity(MessageType::E_INFO);
	Debugger::Info("Action of name: " + name_ + "does not exist in resoruces", "ResourceLoader.cpp", __LINE__);
	return false;
}

bool ResourceLoader::CheckAction(const uint32 id_)
{
	for (auto actions : actionMap) {
		if (actions.Value->ReturnActionID() == id_) {
			return true;
		}
	}
	Debugger::SetSeverity(MessageType::E_INFO);
	Debugger::Info("Action of ID: " + FString::FromInt(id_) +  "does not exist in resoruces", "ResourceLoader.cpp", __LINE__);
	return false;
}

bool ResourceLoader::CheckStatSheet(const FString name_)
{
	if (statSheetMap.Contains(name_)) {
		return true;
	}
	Debugger::SetSeverity(MessageType::E_INFO);
	Debugger::Info("StatSheet of name: " + name_ + "does not exist in resoruces", "ResourceLoader.cpp", __LINE__);
	return false;
}


void ResourceLoader::OnCreate(){
	// create in order command, abilty, items, then load into map.  
	// use file manager
	/// Get the Path for each Directory
	FString ActionDirectory = FPaths::ProjectPluginsDir() + "/Battle_Box/FileResource/ActionSheets";
	TCHAR* fileEnd = _T(".json");	
	/// Verifiy that these Directories exist
	BattleBoxFileManager::VerifyOnCreateDirectory(ActionDirectory);
	// Use the paths with the Json Receiver to get each object
	// find the amount of files in the directory then call jsonRecevier to then add into the maps
	JsonParse* json = new JsonParse(); // create Json parser 
	json->InitiateClass(); // initate class
	TArray<FString> foundFiles;
	IFileManager* DirectoryCheck =  &IFileManager::Get(); // IFilemanger
	DirectoryCheck->FindFiles(foundFiles, *ActionDirectory, fileEnd); // found files will hold all the .json files in directory;
	for (auto files : foundFiles) {
		BaseAction* action = json->ReadActionObject(files);
		if (action != nullptr) {
			AddAction(action);
			Debugger::SetSeverity(MessageType::E_INFO);
			Debugger::Info("Action File with name: " + action->ReturnName() + " loaded", "ResourceLoader.cpp", __LINE__);
		}
		else {
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("Action File with name: " + files + " cannont be loaded", "ResourceLoader.cpp", __LINE__);
		}
	}
	foundFiles.Empty();
	 
	// create stat sheet objects
	FString StatSheetDirectory = FPaths::ProjectPluginsDir() + "/Battle_Box/FileResource/StatSheets";

	/// Verifiy that these Directories exist
	BattleBoxFileManager::VerifyOnCreateDirectory(StatSheetDirectory);
	DirectoryCheck->FindFiles(foundFiles, *StatSheetDirectory, fileEnd); // found files will hold all the .json files in directory;
	for (auto files : foundFiles) {
		StatSheetObject* statSheet = json->ReadStatSheetObject(files);
		if (statSheet != nullptr) {
			AddStatSheet(statSheet);
			Debugger::SetSeverity(MessageType::E_INFO);
			Debugger::Info("StatSheet File with name: " + statSheet->ReturnName() + " loaded", "ResourceLoader.cpp", __LINE__);
		}
		else {
			Debugger::SetSeverity(MessageType::E_ERROR);
			Debugger::Error("StatSheet File with name: " + statSheet->ReturnName() + " cannont be loaded", "ResourceLoader.cpp", __LINE__);
		}
	}
	// 
}

void ResourceLoader::OnDestroy()
{
	if (actionMap.Num() > 0) {
		for (auto actions : actionMap) {
			delete actions.Value;
			//actions.Value = nullptr;
		}
	}
	actionMap.Empty();
	if (statSheetMap.Num() > 0) {
		for (auto statSheet : statSheetMap) {
			delete statSheet.Value;
			//statSheet.Value = nullptr;
		}
	}
	statSheetMap.Empty();
}

ResourceLoader * ResourceLoader::GetInstance()
{
	if (resourceInstance == nullptr) {
		resourceInstance.reset(new ResourceLoader);
	}
	return resourceInstance.get();
}

void ResourceLoader::AddAction(BaseAction * const action_)
{
	actionMap.Add(action_->ReturnName(), action_);
}

void ResourceLoader::AddStatSheet(StatSheetObject * const statSheet_)
{
	statSheetMap.Add(statSheet_->ReturnName(), statSheet_);
}

void ResourceLoader::DeleteAction(const FString name_)
{
	if (actionMap.Contains(name_)) {
		actionMap.Remove(name_);
	}
	else {
		Debugger::Info("action Object doesn't exist by name", "ResourceLoader.cpp", __LINE__);
	}
}

void ResourceLoader::DeleteStatSheet(const FString name_)
{
	if (statSheetMap.Contains(name_)) {
		statSheetMap.Remove(name_);
	}
	else {
		Debugger::Info("statSheet Object doesn't exist by name", "ResourceLoader.cpp", __LINE__);
	}
}

void ResourceLoader::DeleteAction(const uint32 id_)
{
	for (auto actions : actionMap) {
		if (actions.Value->ReturnActionID() == id_) {
			actionMap.Remove(actions.Key);
			break;
		}
	}
	Debugger::Info("Action ID is not found in Action map", "ResrouceLoader.cpp", __LINE__);
}

//void ResourceLoader::AddAction(const FString name_)
//{
//	BaseAction* baseAction;// = /////// Will pull info from the Json Parser
//
//
//
//	if (baseAction->ReturnName() == "") { // if the Name is empty create name based on the amount in map
//		FString newName = "action " + actionMap.Num();
//		baseAction->SetName(newName);
//		actionMap.Add(baseAction->ReturnName(), baseAction);
//	}
//	else if (!actionMap.Contains(baseAction->ReturnName())) { // statsheet name is not empty and does not contain the current name
//		actionMap.Add(baseAction->ReturnName(), baseAction); // add to the statsheetmap
//	}
//	else { // if the name is in the map 
//		Debugger::Error("Action Object exists with name " + baseAction->ReturnName(), "ResourceLoader.cpp", __LINE__);
//		FString newName = "Action " + statSheetMap.Num();
//		baseAction->SetName(newName);
//		actionMap.Add(baseAction->ReturnName(), baseAction);
//	}
//}

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
