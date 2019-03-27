#include "CollisionVolumeOBB.h"
#include "Visualizer.h"
#include "MathTools.h"

CollisionVolumeOBB::CollisionVolumeOBB(Model *collisionModel)
{
	//Local
	//Calculate once
	cornerMin = collisionModel->getMinAABB();
	cornerMax = collisionModel->getMaxAABB();
	center = (cornerMin + cornerMax) * .5f;
	halfDiagonal = .5f * (cornerMax - cornerMin);
	scale = Matrix(SCALE, (cornerMin - cornerMax));

	translation = Matrix(TRANS, center);


}

void CollisionVolumeOBB::ComputeData(Model * mod, Matrix & mat)
{
	(void)mod;

	
	trueWorld = mat;

	world = scale * translation * mat;
	
	scaleSquared = trueWorld.get(ROW_0).magSqr();

	centerWorld = (cornerMin + halfDiagonal) * mat;

}

bool CollisionVolumeOBB::Intersect(CollisionVolumeOBB & other)
{
	return MathTools::Intersect(*this, other);
}

bool CollisionVolumeOBB::Intersect(CollisionVolumeAABB & other)
{
	return (MathTools::Intersect(other,*this));
}

bool CollisionVolumeOBB::Intersect(CollisionVolumeBSphere & other)
{
	return (MathTools::Intersect(*this, other));
}

bool CollisionVolumeOBB::Intersect(CollisionVolume & other)
{
	return other.Intersect(*this);
}

void CollisionVolumeOBB::DebugView(const Vect & color)
{
	Visualizer::ShowOBB(*this, color);
}

Vect & CollisionVolumeOBB::GetCenter()
{
	return center;
}

Matrix & CollisionVolumeOBB::GetWorld()
{
	return world;
}

Vect & CollisionVolumeOBB::GetCornerMin()
{
	return cornerMin;
}

Vect & CollisionVolumeOBB::GetCornerMax()
{
	return cornerMax;
}

Matrix & CollisionVolumeOBB::GetTrueWorld()
{
	return trueWorld;
}

float & CollisionVolumeOBB::GetScaleSquared()
{
	return scaleSquared;
}

Vect & CollisionVolumeOBB::GetCenterWorld()
{
	return centerWorld;
}

