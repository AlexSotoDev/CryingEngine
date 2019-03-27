#include "TerrainObject.h"
#include "GpuVertTypes.h"
#include "TextureTGA.h"

#include "SceneManager.h"
#include "CameraManager.h"
#include "ShaderManager.h"
#include "TextureManager.h"

#include "Collidable.h"
#include "MathTools.h"
#include "Visualizer.h"

TerrainObject::TerrainObject(const char * heightmapFile, std::string texKey, int RepeatU, int RepeatV, int width, int height, int scale, float xOff, float yOff, float zOff)
{
	int icomp;
	unsigned int dtype;
	GLbyte* imgData = gltReadTGABits(heightmapFile, &imgWidth, &imgHeight, &icomp, &dtype);
	assert(imgWidth == imgHeight && imgWidth != 0); // We need square images for heightmaps

	int nverts = width * width;
	pVerts = new VertexStride_VUN[nverts];

	int ntri = ((width - 1) * (width - 1)) * 2;
	pTriList = new TriangleIndex[ntri];

	float h_val;

	rowCells = width - 1;
	rowCols = width - 1;

	xOffset = -rowCols * xOff;
	yOffset = yOff;
	zOffset = rowCells * zOff;

	cellSizeX = scale;
	cellSizeZ = scale;

	float du = 1.0f / (width - 1);
	float dv = 1.0f / (width - 1);

	int k = 0;
	for (float i = 0; i < width; ++i) {

		for (float j = 0; j < width; ++j)
		{
			size_t myI = (size_t)i;
			size_t myJ = (size_t)j;

			h_val = static_cast<unsigned char>(imgData[4 * (myJ * imgHeight + myI)]);

			float yVal = (float)h_val;
			// Offset y-value by R value in RGB pixel
			pVerts[k].set(j * cellSizeX + xOffset, (yVal / 255.0f) * height + yOffset, -i * cellSizeZ + zOffset, i * du * RepeatU, j * dv * RepeatV, 1.0f, 1.0f, 1.0f);

			++k;
		}
	}

	k = 0;
	for (DWORD i = 0; i < (DWORD)rowCells; ++i)
	{
		for (DWORD j = 0; j < (DWORD)rowCols; ++j)
		{
			pTriList[k].set(i * width + j, i * width + j + 1, (i + 1) * width + j);
			pTriList[k + 1].set((i + 1) * width + j, i * width + j + 1, (i + 1) * width + j + 1);
			k += 2;
		}
	}

	for (int i = 0; i < ntri; i++)
	{
		int index1 = pTriList[i].v0;
		int index2 = pTriList[i].v1;
		int index3 = pTriList[i].v2;

		Vect side1 = Vect(pVerts[index1].x - pVerts[index3].x, pVerts[index1].y - pVerts[index3].y, pVerts[index1].z - pVerts[index3].z);
		Vect side2 = Vect(pVerts[index1].x - pVerts[index2].x, pVerts[index1].y - pVerts[index2].y, pVerts[index1].z - pVerts[index2].z);
		Vect mynormal = side2.cross(side1);

		pVerts[index1].nx = 0;
		pVerts[index2].ny = 0;
		pVerts[index3].nz = 0;

		pVerts[index1].nx += mynormal.X();
		pVerts[index2].ny += mynormal.Y();
		pVerts[index3].nz += mynormal.Z();
	}

	lightColor = Vect(1, 1, 1);
	lightPos = Vect(0, 1000, 0);

	pModel = new Model(pVerts, nverts, pTriList, ntri);

	pTerrain = new GraphicsObject_TextureLight(pModel, ShaderManager::GetShader("CRYtextureLightRender"), TextureManager::GetTexture(texKey), lightColor, lightPos);

	CreateCellMinMax();
}

TerrainObject::~TerrainObject()
{
	delete pModel;
}


void TerrainObject::CreateCellMinMax()
{
	for (int i = 0; i < imgWidth - 1; i++)
	{
		for (int j = 0; j < imgHeight - 1; j++)
		{
			Vect min = GetCellMinFromVert(i, j);
			Vect max = GetCellMaxFromVert(i, j);

			terrainCell cell;
			cell.cellMax = max;
			cell.cellMin = min;

			cellsVector.push_back(cell);
		}
	}
}

int TerrainObject::GetVertFromIndex(int i, int j)
{
	return i * imgHeight + j;
}

Vect TerrainObject::GetCellMinFromVert(int i, int j)
{
	Vect min;
	Vect topLeft, topRight, bottomLeft, bottomRight;

	topLeft = Vect(pVerts[GetVertFromIndex(i, j)].x, pVerts[GetVertFromIndex(i, j)].y, pVerts[GetVertFromIndex(i, j)].z);
	topRight = Vect(pVerts[GetVertFromIndex(i+1, j)].x, pVerts[GetVertFromIndex(i+1, j)].y, pVerts[GetVertFromIndex(i+1, j)].z);
	bottomLeft = Vect(pVerts[GetVertFromIndex(i, j+1)].x, pVerts[GetVertFromIndex(i, j+1)].y, pVerts[GetVertFromIndex(i, j+1)].z);
	bottomRight = Vect(pVerts[GetVertFromIndex(i+1, j+1)].x, pVerts[GetVertFromIndex(i+1, j+1)].y, pVerts[GetVertFromIndex(i+1, j+1)].z);

	min = topLeft;
	min = MathTools::CalculateMinVect(min, topRight);
	min = MathTools::CalculateMinVect(min, bottomLeft);
	min = MathTools::CalculateMinVect(min, bottomRight);

	return min;
}

Vect TerrainObject::GetCellMaxFromVert(int i, int j)
{
	Vect max;
	Vect topLeft, topRight, bottomLeft, bottomRight;

	topLeft = Vect(pVerts[GetVertFromIndex(i, j)].x, pVerts[GetVertFromIndex(i, j)].y, pVerts[GetVertFromIndex(i, j)].z);
	topRight = Vect(pVerts[GetVertFromIndex(i + 1, j)].x, pVerts[GetVertFromIndex(i + 1, j)].y, pVerts[GetVertFromIndex(i + 1, j)].z);
	bottomLeft = Vect(pVerts[GetVertFromIndex(i, j + 1)].x, pVerts[GetVertFromIndex(i, j + 1)].y, pVerts[GetVertFromIndex(i, j + 1)].z);
	bottomRight = Vect(pVerts[GetVertFromIndex(i + 1, j + 1)].x, pVerts[GetVertFromIndex(i + 1, j + 1)].y, pVerts[GetVertFromIndex(i + 1, j + 1)].z);

	max = topLeft;
	max = MathTools::CalculateMaxVect(max, topRight);
	max = MathTools::CalculateMaxVect(max, bottomLeft);
	max = MathTools::CalculateMaxVect(max, bottomRight);

	return max;
}


std::list<TerrainObject::terrainCell> TerrainObject::DetectCellsFromCollidable(Collidable* collidableObject)
{
	std::list<TerrainObject::terrainCell> terrainCellList;

	Vect AABBmin, AABBmax;
	AABBmin = collidableObject->GetDefaultBSphere()->GetMinAABB();
	AABBmax = collidableObject->GetDefaultBSphere()->GetMaxAABB();

	Vect sphereMin, sphereMax;
	sphereMin = Vect(AABBmin.X() - cellSizeX - xOffset, AABBmin.Y(), AABBmin.Z() - cellSizeZ - zOffset);
	sphereMax = Vect(AABBmax.X() - cellSizeX - xOffset, AABBmax.Y(), AABBmax.Z() - cellSizeZ - zOffset);

	int iMin, iMax, jMin, jMax;
	
	iMin = (int)((((-sphereMax.Z()) / cellSizeZ) - zOffset / rowCells));
	iMax = (int)((((-sphereMin.Z()) / cellSizeZ) - zOffset / rowCells));

	jMin = (int)((((sphereMin.X()) / cellSizeX) - xOffset / rowCols));
	jMax = (int)((((sphereMax.X()) / cellSizeX) - xOffset / rowCols));

	Vect min, max;

	for (int i = iMin; i < iMax; i++)
	{
		for (int j = jMin; j < jMax; j++)
		{
			min = GetCellMinFromVert(i, j);
			max = GetCellMaxFromVert(i, j);
			terrainCell cell;
			cell.cellMax = max;
			cell.cellMin = min;
			terrainCellList.push_back(cell);
		}
	}

	return terrainCellList;
}

void TerrainObject::Render()
{
	
	pTerrain->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());
}
