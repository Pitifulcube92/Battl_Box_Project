
#include "ResourceLoader.h"

ResourceLoader::ResourceLoader()
{
	OnCreate();
}

ResourceLoader::~ResourceLoader()
{
	OnDestroy();
}

void ResourceLoader::DetermineLoadType()
{
}

void ResourceLoader::OnCreate()
{
}

void ResourceLoader::OnDestroy()
{
}

void ResourceLoader::LoadActionSheet(const std::string & filename_)
{
}

void ResourceLoader::LoadStatSheet(const std::string & filename_)
{
}
