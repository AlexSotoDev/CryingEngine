#ifndef _CollisionTestPairCommand
#define _CollisionTestPairCommand

#include "CommandBase.h"
#include "CollidableGroup.h"
#include "MathTools.h"

#include "Visualizer.h"
#include "ColorLibrary.h"
/**********************************************************************************************//**
 * \class	CollisionTestPairCommand
 *
 * \brief	A collision test pair command inheriting from @CommandBase and used by @CollisionManager. Takes two collidable collections of two groups and executes bSphere collision test between corresponding collidable objects by using the test result to call Collision on each object with the other object.
 *
 * \author	Alex
 * \date	3/8/2017
 *
 * \tparam	C1	Type of the collidable group 1.
 * \tparam	C2	Type of the collidable group 2.
 **************************************************************************************************/

template<typename C1, typename C2>
class CollisionTestPairCommand : public CommandBase, public Align16
{
private:

	typename CollidableGroup<C1>::CollidableCollection& Collection1;
	typename CollidableGroup<C2>::CollidableCollection& Collection2;

	typename CollidableGroup<C1> ColGroup1;
	typename CollidableGroup<C2> ColGroup2;

public:

	/**********************************************************************************************//**
	 * \fn	CollisionTestPairCommand::CollisionTestPairCommand() : Collection1(CollidableGroup<C1>::GetColliderCollection()), Collection2(CollidableGroup<C2>::GetColliderCollection())
	 *
	 * \brief	Default constructor that gets the collider collections from two templated group type.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	CollisionTestPairCommand()
		: Collection1(CollidableGroup<C1>::GetColliderCollection()),
		Collection2(CollidableGroup<C2>::GetColliderCollection())
	{

	}

	/**********************************************************************************************//**
	 * \fn	virtual void CollisionTestPairCommand::Execute()
	 *
	 * \brief	Executes the command to check all possible BSphere collection through nested for loop that iterates through the first collection and checks every item against every item of the second collection, using pointers to for each item of each collection to check the pair until every check is complete. All true tests result in a collision, calling the corresponding Collision functions for each collidable object on the other.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	virtual void Execute()
	{

		CollidableGroup<C1>::CollidableCollection::iterator it1;
		CollidableGroup<C2>::CollidableCollection::iterator it2;

		ColGroup1.UpdateAABB();
		ColGroup2.UpdateAABB();



		bool test_result = MathTools::Intersect(*ColGroup1.GetAABB(), *ColGroup2.GetAABB());

		if (test_result)
		{
			for (it1 = Collection1.begin(); it1 != Collection1.end(); it1++)
			{
				test_result = MathTools::Intersect(*ColGroup2.GetAABB(), *((*it1)->GetDefaultBSphere()));

				if (test_result)
				{
					for (it2 = Collection2.begin(); it2 != Collection2.end(); it2++)
					{
						test_result = MathTools::Intersect(*((*it1)->GetDefaultBSphere()), *((*it2)->GetDefaultBSphere()));

						if (test_result)
						{
							test_result = MathTools::Intersect((*it1), (*it2));

							if (test_result)
							{
								(*it1)->Collision(*it2);
								(*it2)->Collision(*it1);
							}

							else
							{
								Visualizer::ShowCollisionVolume(*it1, Colors::DeepPink);
								Visualizer::ShowCollisionVolume(*it2, Colors::DeepPink);
							}
						}

						else
						{
							Visualizer::ShowSphere(*((*it1)->GetDefaultBSphere()), Colors::DeepSkyBlue);
							Visualizer::ShowSphere(*((*it2)->GetDefaultBSphere()), Colors::DeepSkyBlue);
						}
					}
				}

				else
				{
					Visualizer::ShowAABB(*(ColGroup1.GetAABB()), Colors::SkyBlue);
					Visualizer::ShowAABB(*(ColGroup2.GetAABB()), Colors::SkyBlue);
				}
			}


		}

		else
		{
			Visualizer::ShowAABB(*(ColGroup1.GetAABB()), Colors::LightSkyBlue);
			Visualizer::ShowAABB(*(ColGroup2.GetAABB()), Colors::LightSkyBlue);
		}


		


	}
};

#endif // !_CollisionTestPairCommand
