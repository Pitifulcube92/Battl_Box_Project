<<<<<<< Updated upstream
=======
#pragma once
>>>>>>> Stashed changes
#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <sstream>
<<<<<<< Updated upstream
class ResourceLoader
{
public:
	ResourceLoader();
	~ResourceLoader();
	void DetermineLoadType(); // determine what data from a file will take in
	void OnCreate();
	void OnDestroy();

private:
	void LoadActionSheet(const std::string& filename_); // once file type is determined will load a Action
	void LoadStatSheet(const std::string& filename_); // once file type is determined will load a StatSheet
=======
#include "ActionClasses/BaseAction.h"
#include "StatSheetObject.h"
#include "Debugger.h"
class ResourceLoader
{
public:
	static void DetermineLoadType(); // determine what data from a file will take in
	void OnCreate();
	void OnDestroy();

private:
	ResourceLoader();
	~ResourceLoader();
	static void LoadActionSheet(const std::string& filename_); // once file type is determined will load a Action
	static void LoadStatSheet(const std::string& filename_); // once file type is determined will load a StatSheet
>>>>>>> Stashed changes
};

#endif
