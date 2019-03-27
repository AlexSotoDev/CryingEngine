#ifndef _CollisionVolumeAABB
#define _CollisionVolumeAABB

#include "AzulCore.h"
#include "CollisionVolume.h"
#include "Align16.h"

/**********************************************************************************************//**
* \class	CollisionVolumeBSphere
*
* \brief	A collision volume b sphere constructed using a model and a matrix to place the model at the world origin and create the sphere data (center, radius). Inherits from @CollisionVolume for integrated use with later more complex/precise collision volumes.
*
* \author	Alex
* \date	3/8/2017
**************************************************************************************************/

class CollisionVolumeAABB : public CollisionVolume, public Align16
{
private:
	Vect center;
	Vect cornerMin;
	Vect cornerMax;

	//To treat like OBB
	Vect localCornerMin;
	Vect localCornerMax;
	Vect localCenter;
	Vect halfDiagonal;

	Matrix world;
	Matrix trueWorld;

	float scaleSquared;

	float bSphereRadius;

public:

	CollisionVolumeAABB();

	CollisionVolumeAABB(Model* collisionModel);

	CollisionVolumeAABB(CollisionVolumeBSphere& bSphere);

	//CollisionVolumeAABB(Vect& bSphereCenter, float bSphereRadius);
	~CollisionVolumeAABB() {};
	CollisionVolumeAABB(const CollisionVolumeAABB&) = delete;
	CollisionVolumeAABB& operator=(const CollisionVolumeAABB&) = delete;

	
	void ComputeData(Model* mod, Matrix& mat) override;

	void ComputeData(CollisionVolumeBSphere& bSphere);

	void ComputeData(Vect& min, Vect& max);


	bool Intersect(CollisionVolumeBSphere& other) override;

	bool Intersect(CollisionVolumeAABB& other) override;

	bool Intersect(CollisionVolumeOBB& other) override;


	bool Intersect(CollisionVolume& other) override;

	void DebugView(const Vect& color) override;

	Vect& GetCenter();

	Matrix& GetWorld();

	Vect& GetCornerMin();

	Vect& GetCornerMax();

	Vect& GetLocalCornerMin();

	Vect& GetLocalCornerMax();

	Vect& GetLocalCenter();

	Matrix& GetTrueWorld();

	float& GetScaleSquared();

};


#endif // !_CollisionVolume

