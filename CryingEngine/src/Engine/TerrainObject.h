#ifndef _TerrainObject
#define _TerrainObject

#include "AzulCore.h"
#include <string>
#include "Align16.h"

#include <vector>
#include <list>

class Collidable;

class TerrainObject : public Align16
{
public:
	TerrainObject() = default;
	TerrainObject(const char * heightmapFile, std::string texKey, int RepeatU, int RepeatV, int width, int height, int scale = 1, float xOff = 0.5f, float yOff = 0.5f , float zOff = 0.5f);
	~TerrainObject();
	TerrainObject(TerrainObject&other) = default;
	TerrainObject & operator=(TerrainObject&other) = default;

	void CreateCellMinMax();

	int GetVertFromIndex(int i, int j);

	Vect GetCellMinFromVert(int i, int j);

	Vect GetCellMaxFromVert(int i, int j);

	struct terrainCell
	{
		Vect cellMin;
		Vect cellMax;
	};

	std::list<terrainCell> DetectCellsFromCollidable(Collidable* collidableObject);

	virtual void Render();

private:

	GraphicsObject_TextureLight* pTerrain;

	Model* pModel;

	Vect lightColor;
	Vect lightPos;

	std::vector<terrainCell> cellsVector;

	int imgWidth;
	int imgHeight;

	VertexStride_VUN* pVerts;
	TriangleIndex* pTriList;

	int cellSizeX;
	int cellSizeZ;

	float xOffset;
	float yOffset;
	float zOffset;

	int rowCells;
	int rowCols;


};

#endif // !_TerrainObject
