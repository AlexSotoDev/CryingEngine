#ifndef _CollisionVolumeBSphere
#define _CollisionVolumeBSphere

#include "AzulCore.h"
#include "CollisionVolume.h"
#include "Align16.h"

class CollisionVolumeAABB;

/**********************************************************************************************//**
 * \class	CollisionVolumeBSphere
 *
 * \brief	A collision volume b sphere constructed using a model and a matrix to place the model at the world origin and create the sphere data (center, radius). Inherits from @CollisionVolume for integrated use with later more complex/precise collision volumes.
 *
 * \author	Alex
 * \date	3/8/2017
 **************************************************************************************************/

class CollisionVolumeBSphere : public CollisionVolume, public Align16
{
private:
	Vect center;
	float radius;

	Matrix world;

	Vect minAABB;
	Vect maxAABB;

public:


	CollisionVolumeBSphere() {};
	~CollisionVolumeBSphere() {};
	CollisionVolumeBSphere(const CollisionVolumeBSphere&) = delete;
	CollisionVolumeBSphere& operator=(const CollisionVolumeBSphere&) = delete;

	/**********************************************************************************************//**
	 * \fn	virtual void CollisionVolumeBSphere::ComputeData(Model* mod, Matrix& mat) override;
	 *
	 * \brief	Calculates the necessary data for the sphere (radius, center)
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	mod	If non-null, the model.
	 * \param [in,out]	mat	The matrix.
	 **************************************************************************************************/

	void ComputeData(Model* mod, Matrix& mat) override;

	/**********************************************************************************************//**
	 * \fn	virtual bool CollisionVolumeBSphere::Intersect(CollisionVolumeBSphere& other) override;
	 *
	 * \brief	Checks for intersection between this sphere and another.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	other	The other b sphere.
	 *
	 * \return	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool Intersect( CollisionVolumeBSphere& other) override;

	/**********************************************************************************************//**
	 * \fn	virtual bool CollisionVolumeBSphere::Intersect(CollisionVolume& other) override;
	 *
	 * \brief	For checking b sphere collision with other collision volume types (will flesh out in the future).
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	other	The other.
	 *
	 * \return	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool Intersect(CollisionVolume& other) override;

	void DebugView(const Vect& color) override;

	bool Intersect(CollisionVolumeAABB& other) override;

	bool Intersect(CollisionVolumeOBB& other) override;


	float& GetRadius();
	Vect& GetCenter();
	Matrix& GetWorld();

	Vect& GetMinAABB();
	Vect& GetMaxAABB();
};


#endif // !_CollisionVolume
