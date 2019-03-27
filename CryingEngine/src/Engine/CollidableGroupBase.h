#ifndef _CollidableGroupBase
#define _CollidableGroupBase

/**********************************************************************************************//**
 * \class	CollidableGroupBase
 *
 * \brief	A collidable group base class serving to completely isolate/minimize the templatization of collision system, particularly @CollidableGroup class. 
 *
 * \author	Alex
 * \date	3/8/2017
 **************************************************************************************************/

#include "CollisionVolume.h"

class CollidableGroupBase
{
public:


	CollidableGroupBase() {};
	virtual ~CollidableGroupBase() {};
	virtual void Terminate() {};

protected:
	CollisionVolumeAABB* collidableGroupAABB;

private:

	
};


#endif
