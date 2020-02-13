#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <sstream>
class ResourceLoader
{
public:
	ResourceLoader();
	~ResourceLoader();
	void DetermineLoadType(); // determine what data from a file will take in

private:
	void LoadActionSheet(const std::string& filename_); // once file type is determined will load a Action
	void LoadStatSheet(const std::string& filename_); // once file type is determined will load a StatSheet
};

#endif
