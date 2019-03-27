#include "TerrainObjectManager.h"
#include <assert.h>
#include "TerrainObject.h"

TerrainObjectManager* TerrainObjectManager::self = NULL;

void TerrainObjectManager::PrivateLoadTerrain(std::string terrainName, std::string heightMapFilePath, std::string texKey, int RepeatU, int RepeatV, int width, int height, int scale, float xOff, float yOff, float zOff)
{
	//Check if string is empty str
	assert((terrainName != "" ) && "terrainName is not valid (empty string entered)!");
	assert(heightMapFilePath != "" && "heightMapFilePath is not valid (empty string entered)!");
	assert((texKey != "") && "texKey is not valid (empty string entered)!");

	//Check if it's already in map
	assert(Instance().terrainMap[terrainName] == NULL && "A terrain with that name already exists!");

	Instance().terrainMap[terrainName] = new TerrainObject(heightMapFilePath.c_str(), texKey, RepeatU, RepeatV, width, height, scale, xOff, yOff, zOff);
}

TerrainObject * TerrainObjectManager::PrivateGetTerrain(std::string terrainName)
{
	//Check if it's null
	assert(Instance().terrainMap[terrainName] != NULL && "Texture with that name cannot be found!");

	return Instance().terrainMap[terrainName];
}

void TerrainObjectManager::PrivateUnloadAllTerrain()
{
	std::map<std::string, TerrainObject*>::iterator it = Instance().terrainMap.begin(); //create an iterator to go through the textureMap
	while (it != Instance().terrainMap.end())
	{
		delete it->second;
		it->second = nullptr;
		it++;
	}

	delete self;
}
