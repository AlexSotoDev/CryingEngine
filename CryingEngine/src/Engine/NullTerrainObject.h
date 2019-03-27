#ifndef _NullTerrainObject
#define _NullTerrainObject

#include "AzulCore.h"
#include "Align16.h"
#include "TerrainObject.h"



class NullTerrainObject : public TerrainObject
{
public:
	NullTerrainObject() = default;
	~NullTerrainObject() = default;
	NullTerrainObject(NullTerrainObject&other) = delete;
	NullTerrainObject & operator=(NullTerrainObject&other) = delete;

	virtual void Render() override
	{};


private:

};

#endif // !_TerrainObject