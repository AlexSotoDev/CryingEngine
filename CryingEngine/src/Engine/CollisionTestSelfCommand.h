#ifndef _CollisionTestSelfCommand
#define _CollisionTestSelfCommand

#include "CommandBase.h"
#include "CollidableGroup.h"

/**********************************************************************************************//**
 * \class	CollisionTestSelfCommand
 *
 * \brief	A collision test self command inheriting from @CommandBase and used by @CollisionManager. Takes a collidable collection of a group and executes bSphere collision between every collidable within the collection, making sure not to do duplicate checks/check itself by making the inner loop iterator start at the next object rather than also at the start
 *
 * \author	Alex
 * \date	3/8/2017
 *
 * \tparam	C1	Type of the collidable group.
 **************************************************************************************************/

template<class C1>
class CollisionTestSelfCommand : public CommandBase, public Align16
{
private:

	typename CollidableGroup<C1>::CollidableCollection& Collection1;

public:

	/**********************************************************************************************//**
	 * \fn	CollisionTestSelfCommand::CollisionTestSelfCommand() : Collection1(CollidableGroup<C1>::GetColliderCollection())
	 *
	 * \brief	Default constructor that gets the collider collection from the group type.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	CollisionTestSelfCommand()
		: Collection1(CollidableGroup<C1>::GetColliderCollection())
	{

	}

	/**********************************************************************************************//**
	 * \fn	virtual void CollisionTestSelfCommand::Execute()
	 *
	 * \brief	Executes the command to check for B sphere intersection between each item from the collection and checking it with each other one without checking itself/avoiding duplicates by making the inner loop only check the next items - end. If test is positive/true, calls C1 obj Collision function with the C2 and vice versa so each collidable object's collision function is properly called.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	virtual void Execute()
	{
		CollidableGroup<C1>::CollidableCollection::iterator it1;
		CollidableGroup<C1>::CollidableCollection::iterator it2;
		for (it1 = Collection1.begin(); it1 != Collection1.end(); ++it1)
		{
			for (it2 = next(it1); it2 != Collection1.end(); ++it2)
			{
				//B sphere level
				bool test_result = MathTools::Intersect(*(*it1)->GetDefaultBSphere(), *(*it2)->GetDefaultBSphere());

				//Now test actual user defined volumes
				if (test_result)
				{

					test_result = MathTools::Intersect(*it1, *it2);

					if (test_result && it1 != Collection1.end() && it2 != Collection1.end())
					{
						(*it1)->Collision(*it2);
						(*it2)->Collision(*it1);
					}
				}

			}
		}
	}
};

#endif // !_CollisionTestSelfCommand