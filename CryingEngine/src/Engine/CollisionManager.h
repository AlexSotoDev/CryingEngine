#ifndef _CollisionManager
#define _CollisionManager

#include <list>
#include <set>

#include "CollisionTestSelfCommand.h"
#include "CollisionTestPairCommand.h"
#include "TerrainCollisionCommand.h"


class CollidableGroupBase;

/**********************************************************************************************//**
 * \class	CollisionManager
 *
 * \brief	Manager for collisions. One per scene. Manages all collision groups in a set and collision test commands. Can test collision pairs or collision with self.
 *
 * \author	Alex
 * \date	3/8/2017
 **************************************************************************************************/

class CollisionManager
{


public:
	CollisionManager() {};
	virtual ~CollisionManager();


	/** \brief	The collision test commands */
	std::list<CommandBase*> CollisionTestCommands;

	/** \brief	Groups the collision belongs to */
	std::set<CollidableGroupBase*> CollisionGroups;

	/**********************************************************************************************//**
	 * \fn	void CollisionManager::ProcessCollisionTest();
	 *
	 * \brief	Process the collision test by iterating through the list of collision test commands and calling execute on each item within list.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	void ProcessCollisionTest();

	/**********************************************************************************************//**
	 * \fn	template <typename C1, typename C2> void CollisionManager::SetCollisionPair()
	 *
	 * \brief	Sets collision pair by inserting the Instance of the two templated @CollidableGroups into the CollisionGroups set. Then, pushes back a new command into the collisionTestCommands list using those two groups as the parameter pair.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \tparam	C1	Type of the collidable 1.
	 * \tparam	C2	Type of the collidable 2.
	 **************************************************************************************************/

	template <typename C1, typename C2>
	void SetCollisionPair()
	{
		CollisionGroups.insert(&CollidableGroup<C1>::Instance());
		CollisionGroups.insert(&CollidableGroup<C2>::Instance());
		CollisionTestCommands.push_back(new CollisionTestPairCommand<C1, C2>());
	}

	/**********************************************************************************************//**
	 * \fn	template <typename C1> void CollisionManager::SetCollisionSelf()
	 *
	 * \brief	Sets collision with self by inserting the given templated collidable into the collision groups and pushing back a new collisionSelfTestCommand into the list using the single collidable group instance as a parameter. Self check collisions will apparently show their use in GAM 377.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \tparam	C1	Type of the collidable 1.
	 **************************************************************************************************/

	template <typename C1>
	void SetCollisionSelf()
	{
		CollisionGroups.insert(&CollidableGroup<C1>::Instance());
		CollisionTestCommands.push_back(new CollisionTestSelfCommand<C1>());
	}

	template <typename C1>
	void SetCollisionTerrain()
	{
		CollisionGroups.insert(&CollidableGroup<C1>::Instance());
		CollisionTestCommands.push_back(new TerrainCollisionCommand<C1>());
	}

private:

};

#endif // !_CollisionManager
