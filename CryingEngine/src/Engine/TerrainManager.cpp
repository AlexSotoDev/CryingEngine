#include "TerrainManager.h"
#include "TerrainObjectManager.h"
#include "TerrainObject.h"
#include "NullTerrainObject.h"

TerrainManager::TerrainManager()
{
	nullTerrain = new NullTerrainObject();
	terrain = nullTerrain;
}

TerrainManager::~TerrainManager()
{
	delete nullTerrain;
}

void TerrainManager::SetTerrain(std::string terrainName)
{
	terrain = TerrainObjectManager::GetTerrain(terrainName);
}

TerrainObject * TerrainManager::GetTerrain()
{
	return terrain;
}

void TerrainManager::RenderTerrain()
{
	terrain->Render();

}
