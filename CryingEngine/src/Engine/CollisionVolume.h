#ifndef _CollisionVolume
#define _CollisionVolume

#include "AzulCore.h"

class CollisionVolumeBSphere;
class CollisionVolumeAABB;
class CollisionVolumeOBB;

class Collidable;

/**********************************************************************************************//**
 * \class	CollisionVolume
 *
 * \brief	A collision volume. Base collision volume all collision volumes inherit from for smooth collision testing/organization between all volume types.
 *
 * \author	Alex
 * \date	3/8/2017
 **************************************************************************************************/

class CollisionVolume
{



public:
	CollisionVolume() {};
	virtual ~CollisionVolume() {};
	CollisionVolume(const CollisionVolume&) = delete;
	CollisionVolume& operator=(const CollisionVolume&) = delete;

	/**********************************************************************************************//**
	 * \fn	virtual void CollisionVolume::ComputeData(Model* mod, Matrix& mat);
	 *
	 * \brief	Virtual function to compute the required collision data using a model and matrix. Virtual function so volumes can override/use it
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	mod	If non-null, the model.
	 * \param [in,out]	mat	The matrix.
	 **************************************************************************************************/

	virtual void ComputeData(Model* mod, Matrix& mat);

	/**********************************************************************************************//**
	 * \fn	virtual bool CollisionVolume::Intersect(CollisionVolume& other);
	 *
	 * \brief	Virtual function for intersecting with another collision volume. Overridden by inherited collision volumes for checking other generic volumes.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	other	The other collision volume.
	 *
	 * \return	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	virtual bool Intersect(CollisionVolume& other);

	/**********************************************************************************************//**
	 * \fn	virtual bool CollisionVolume::Intersect(CollisionVolumeBSphere& other);
	 *
	 * \brief	Virtual function for intersecting with another B-SPHERE collision volume. Overridden by inherited collision volumes for calculating intersection with b-sphere
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	other	The other.
	 *
	 * \return	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	virtual bool Intersect(CollisionVolumeBSphere& other);

	virtual bool Intersect(CollisionVolumeAABB& other);

	virtual bool Intersect(CollisionVolumeOBB& other);

	virtual void DebugView(const Vect& color);


};


#endif // !_CollisionVolume




