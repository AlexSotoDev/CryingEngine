#include "CollisionManager.h"

CollisionManager::~CollisionManager()
{
	for (auto it = CollisionGroups.begin(); it != CollisionGroups.end(); it++)
	{
		//delete (*it);
		(*it)->Terminate();

	}
 	CollisionGroups.clear();


	for (auto it = CollisionTestCommands.begin(); it != CollisionTestCommands.end(); it++)
	{
		delete (*it);

	}
	CollisionTestCommands.clear();
}

void CollisionManager::ProcessCollisionTest()
{
	for (auto it = CollisionTestCommands.begin(); it != CollisionTestCommands.end(); it++)
	{
		(*it)->Execute();
	}
}
