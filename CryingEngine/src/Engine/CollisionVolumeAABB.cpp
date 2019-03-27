#include "CollisionVolumeAABB.h"
#include "MathTools.h"
#include "Visualizer.h"

CollisionVolumeAABB::CollisionVolumeAABB()
{

}

CollisionVolumeAABB::CollisionVolumeAABB(Model* collisionModel)
{
	localCornerMin = collisionModel->getMinAABB();
	localCornerMax = collisionModel->getMaxAABB();
	localCenter = (localCornerMin + localCornerMax) * .5f;
	halfDiagonal = .5f * (cornerMax - cornerMin);
}

CollisionVolumeAABB::CollisionVolumeAABB(CollisionVolumeBSphere & bSphere)
{
	center = bSphere.GetCenter();

	trueWorld = bSphere.GetWorld();

	bSphereRadius = bSphere.GetRadius();

	Vect sphereToBoxMin = Vect(center.X() - bSphereRadius, center.Y() - bSphereRadius, center.Z() - bSphereRadius);
	Vect sphereToBoxMax = Vect(center.X() + bSphereRadius, center.Y() + bSphereRadius, center.Z() + bSphereRadius);
	
	cornerMin = sphereToBoxMin;
	cornerMax = sphereToBoxMax;
}

//CollisionVolumeAABB::CollisionVolumeAABB(Vect& bSphereCenter, float bSphereRadius)
//{
//	center = bSphereCenter;
//
//	Vect sphereToBoxMin = Vect(bSphereCenter.X() - bSphereRadius, bSphereCenter.Y() - bSphereRadius, bSphereCenter.Z() - bSphereRadius);
//	Vect sphereToBoxMax = Vect(bSphereCenter.X() + bSphereRadius, bSphereCenter.Y() + bSphereRadius, bSphereCenter.Z() + bSphereRadius);
//
//	cornerMin = sphereToBoxMin;
//	cornerMax = sphereToBoxMax;
//
//}

void CollisionVolumeAABB::ComputeData(Model * mod, Matrix & mat)
{
	trueWorld = mat;

	cornerMin = MathTools::CalculateCornerMin(mod, mat);
	cornerMax = MathTools::CalculateCornerMax(mod, mat);

	center = MathTools::CalculateCenter(cornerMin, cornerMax);

	Matrix scale = Matrix(SCALE, (cornerMin - cornerMax));
	Matrix translation = Matrix(TRANS, center);
	world = scale * translation;

	scaleSquared = trueWorld.get(ROW_0).magSqr();

	//centerWorld = (cornerMin + halfDiagonal) * mat;

}

void CollisionVolumeAABB::ComputeData(CollisionVolumeBSphere& bSphere)
{
	trueWorld = bSphere.GetWorld();
	center = bSphere.GetCenter();
	scaleSquared = trueWorld.get(ROW_0).magSqr();

	cornerMin = Vect(center.X() - bSphereRadius, center.Y() - bSphereRadius, center.Z() - bSphereRadius);
	cornerMax = Vect(center.X() + bSphereRadius, center.Y() + bSphereRadius, center.Z() + bSphereRadius);

	//Matrix scale = Matrix(SCALE, (cornerMin - cornerMax));
	//Matrix translation = Matrix(TRANS, center);
	//world = scale * translation;

	world = bSphere.GetWorld();
}

void CollisionVolumeAABB::ComputeData(Vect & min, Vect & max)
{
	cornerMin = min;
	cornerMax = max;

	center = MathTools::CalculateCenter(cornerMin, cornerMax);

	halfDiagonal = .5f * (cornerMax - cornerMin);

	Matrix scale = Matrix(SCALE, (cornerMin - cornerMax));
	Matrix translation = Matrix(TRANS, center);
	world = scale * translation;


}

bool CollisionVolumeAABB::Intersect(CollisionVolumeBSphere & other)
{
	return (MathTools::Intersect(*this, other));
}

bool CollisionVolumeAABB::Intersect(CollisionVolumeAABB & other)
{
	return (MathTools::Intersect(*this, other));
}

bool CollisionVolumeAABB::Intersect(CollisionVolumeOBB & other)
{
	return (MathTools::Intersect(*this, other));
}

bool CollisionVolumeAABB::Intersect(CollisionVolume & other)
{
	return other.Intersect(*this);
}

void CollisionVolumeAABB::DebugView(const Vect & color)
{
	Visualizer::ShowAABB(*this, color);
}

Vect & CollisionVolumeAABB::GetCenter()
{
	return center;
}

Matrix & CollisionVolumeAABB::GetWorld()
{
	return world;
}

Vect & CollisionVolumeAABB::GetCornerMin()
{
	return cornerMin;
}

Vect & CollisionVolumeAABB::GetCornerMax()
{
	return cornerMax;
}

Vect & CollisionVolumeAABB::GetLocalCornerMin()
{
	return localCornerMin;
}

Vect & CollisionVolumeAABB::GetLocalCornerMax()
{
	return localCornerMax;
}

Vect & CollisionVolumeAABB::GetLocalCenter()
{
	return localCenter;
}

Matrix & CollisionVolumeAABB::GetTrueWorld()
{
	return trueWorld;
}

float & CollisionVolumeAABB::GetScaleSquared()
{
	return scaleSquared;
}
