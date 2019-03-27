#ifndef _TerrainManager
#define _TerrainManager

#include <string>

class TerrainObject;
class NullTerrainObject;

class TerrainManager
{
public:
	TerrainManager();
	virtual ~TerrainManager();

	TerrainManager(const TerrainManager&) = delete;
	TerrainManager& operator=(const TerrainManager&) = delete;

	void SetTerrain(std::string terrainName);
	TerrainObject* GetTerrain();

	void RenderTerrain();


private:

	TerrainObject* terrain;
	NullTerrainObject* nullTerrain;


};

#endif // !_TerrainManager
