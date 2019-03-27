#ifndef _TerrainObjectManager
#define _TerrainObjectManager

// Singleton Terrain Object Manager
// include map
#include <map>

class TerrainObject;

class TerrainObjectManager
{
private:

	static TerrainObjectManager *self; //pointer to itself

	TerrainObjectManager() {}; //empty contructor
	TerrainObjectManager(const TerrainObjectManager&) {};
	TerrainObjectManager& operator = (const TerrainObjectManager&) {};

	~TerrainObjectManager() {}; //destructor

								//Instance Creation
	static TerrainObjectManager& Instance()
	{
		if (!self)
		{
			self = new TerrainObjectManager();
		}

		return *self;
	}


	/** \brief	to store all shader objs */
	std::map<std::string, TerrainObject*> terrainMap;

	void PrivateLoadTerrain(std::string terrainName, std::string heightMapFilePath, std::string texKey, int RepeatU, int RepeatV, int width, int height, int scale = 1, float xOff = 0.5f, float yOff = 0.5f, float zOff = 0.5f);


	TerrainObject* PrivateGetTerrain(std::string terrainName);



	void PrivateUnloadAllTerrain();

public:

	static void LoadTerrain(std::string terrainName, std::string filePath, std::string texKey, int RepeatU, int RepeatV, int width, int height, int scale = 1, float xOff = 0.5f, float yOff = 0.5f, float zOff = 0.5f) { Instance().PrivateLoadTerrain(terrainName, filePath, texKey, RepeatU, RepeatV, width, height, scale, xOff, yOff, zOff); }

	static TerrainObject* GetTerrain(std::string terrainName) {
		return Instance().PrivateGetTerrain(terrainName);
	}

	static void UnloadAllTextures() { Instance().PrivateUnloadAllTerrain(); }

};

#endif // !_TerrainObjectManager
