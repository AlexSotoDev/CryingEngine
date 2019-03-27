#include "Collidable.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeOBB.h"



Collidable::~Collidable()
{
	delete colVol;

	delete registrationCommand;
	delete deregistrationCommand;
}

void Collidable::Collision(Collidable * co)
{
	(void)co;
}


void Collidable::SetColliderModel(Model * mod, CollisionVolumeType type)
{
	collisionModel = mod;

	switch (type)
	{

	case(CollisionVolumeType::BSphere):
		defaultBSphere = new CollisionVolumeBSphere();
		colVol = defaultBSphere;
		break;

	case(CollisionVolumeType::AABB):
		colVol = new CollisionVolumeAABB(collisionModel);
		defaultBSphere = new CollisionVolumeBSphere();
		break;

	case(CollisionVolumeType::OBB):
		colVol = new CollisionVolumeOBB(collisionModel);
		defaultBSphere = new CollisionVolumeBSphere();
		break;

	default:
		break;

	}
}

void Collidable::UpdateCollisionData(Matrix & mat)
{
	colVol->ComputeData(collisionModel, mat);
	defaultBSphere->ComputeData(collisionModel, mat);
	
}

CollisionVolume & Collidable::GetCollisionVolume()
{
	return *colVol;
}

CollisionVolumeBSphere* Collidable::GetDefaultBSphere()
{
	return defaultBSphere;
}

void Collidable::TerrainCollision()
{
}


