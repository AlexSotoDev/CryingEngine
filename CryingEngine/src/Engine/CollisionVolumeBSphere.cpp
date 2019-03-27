#include "CollisionVolumeBSphere.h"
#include "MathTools.h"
#include "Visualizer.h"

void CollisionVolumeBSphere::ComputeData(Model * mod, Matrix & mat)
{
	center = Vect(world.M12(), world.M13(), world.M14(), world.M15());
	//Location/center in world space by getting the translation of world
	
	radius = (Vect(1, 0, 0, 0) * world).mag();
	//get the magnitude in one axis because it's a sphere so x scale should = y scale and = z scale.

	Vect vBSSize = mod->getRadius() * Vect(1, 1, 1, 0);
	//Use a vector of (1,1,1,0) as a base unit vect and multiply by the model's radius (float) to get the radius of the model
	Vect vBSPos = mod->getCenter();
	//Get center is in model space
	world = Matrix(SCALE, vBSSize) * Matrix(TRANS, vBSPos) * mat;
	//the world mat of our bsphere, SRT, Scale of bsphere * no rotation b/c we use the same rot as our graphics obj * translation, then move that to world space by multiplying by world mat of collidable's graphics object

	minAABB = Vect(center.X() - radius, center.Y() - radius, center.Z() - radius);
	maxAABB = Vect(center.X() + radius, center.Y() + radius, center.Z() + radius);
}

bool CollisionVolumeBSphere::Intersect(CollisionVolume & other)
{
	return other.Intersect(*this);
}

void CollisionVolumeBSphere::DebugView(const Vect& color)
{
	Visualizer::ShowSphere(*this, color);
}

bool CollisionVolumeBSphere::Intersect(CollisionVolumeAABB & other)
{
	return MathTools::Intersect(other, *this);
}

bool CollisionVolumeBSphere::Intersect(CollisionVolumeOBB & other)
{
	return MathTools::Intersect(other, *this);
}

bool CollisionVolumeBSphere::Intersect(CollisionVolumeBSphere & other)
{
	return MathTools::Intersect(*this, other);
}


float& CollisionVolumeBSphere::GetRadius()
{
	return radius;
}

Vect& CollisionVolumeBSphere::GetCenter()
{
	return center;
}

Matrix& CollisionVolumeBSphere::GetWorld()
{
	return world;
}

Vect & CollisionVolumeBSphere::GetMinAABB()
{
	return minAABB;
}

Vect & CollisionVolumeBSphere::GetMaxAABB()
{
	return maxAABB;
}
