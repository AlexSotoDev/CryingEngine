#ifndef _CollisionVolumeOBB	
#define _CollisionVolumeOBB

#include "AzulCore.h"
#include "CollisionVolume.h"
#include "Align16.h"

class CollisionVolumeOBB : public CollisionVolume, public Align16
{
private:
	Vect center;
	Vect cornerMin;
	Vect cornerMax;
	Matrix world;

	Vect halfDiagonal;
	float scaleSquared;

	Matrix trueWorld;
	Matrix scale;
	Matrix translation;

	Vect centerWorld;

public:


	CollisionVolumeOBB(Model* collisionModel);
	~CollisionVolumeOBB() {};
	CollisionVolumeOBB(const CollisionVolumeOBB&) = delete;
	CollisionVolumeOBB& operator=(const CollisionVolumeOBB&) = delete;


	void ComputeData(Model* mod, Matrix& mat) override;

	bool Intersect(CollisionVolumeOBB& other) override;

	bool Intersect(CollisionVolumeBSphere& other) override;

	bool Intersect(CollisionVolumeAABB& other) override;

	bool Intersect(CollisionVolume& other) override;

	void DebugView(const Vect& color) override;

	Vect& GetCenter();

	Matrix& GetWorld();

	Vect& GetCornerMin();

	Vect& GetCornerMax();
	Matrix& GetTrueWorld();

	float& GetScaleSquared();

	Vect& GetCenterWorld();

};


#endif // !_CollisionVolumeOBB


