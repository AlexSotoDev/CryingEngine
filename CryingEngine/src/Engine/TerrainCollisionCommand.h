#ifndef _TerrainCollisionCommand
#define _TerrainCollisionCommand

#include "CommandBase.h"
#include "CollidableGroup.h"

#include "SceneManager.h"
#include "Scene.h"

#include "TerrainManager.h"
#include "TerrainObject.h"

#include "Visualizer.h"
#include "MathTools.h"
#include "ColorLibrary.h"
#include "CollisionVolumeAABB.h"

template<class C1>
class TerrainCollisionCommand : public CommandBase, public Align16
{
private:

	typename CollidableGroup<C1>::CollidableCollection& Collection1;
	std::list<TerrainObject::terrainCell> commandCellList;

public:

	TerrainCollisionCommand()
		: Collection1(CollidableGroup<C1>::GetColliderCollection())
	{

	}

	virtual void Execute()
	{
		bool testResult;

		CollidableGroup<C1>::CollidableCollection::iterator it1;
		for (it1 = Collection1.begin(); it1 != Collection1.end(); ++it1)
		{
			commandCellList = SceneManager::GetCurrentScene()->GetTerrain()->DetectCellsFromCollidable(*it1);

			std::list<TerrainObject::terrainCell>::iterator it = commandCellList.begin();
			while (it != commandCellList.end())
			{
				CollisionVolumeAABB cellAABB;
				cellAABB.ComputeData(it->cellMin, it->cellMax);

				testResult = MathTools::Intersect(cellAABB, *((*it1)->GetDefaultBSphere()));

				if (testResult)
				{
					Visualizer::ShowAABB(cellAABB, Colors::Yellow);
					Visualizer::ShowSphere(*((*it1)->GetDefaultBSphere()), Colors::Yellow);


					testResult = (*it1)->GetCollisionVolume().Intersect(cellAABB);
					(*it1)->TerrainCollision();

					if (testResult)
					{
						Visualizer::ShowAABB(cellAABB, Colors::Red);
						Visualizer::ShowCollisionVolume((*it1), Colors::Red);
					}
				}

				else
				{
					Visualizer::ShowAABB(cellAABB, Colors::Green);
					Visualizer::ShowSphere(*((*it1)->GetDefaultBSphere()), Colors::Green);
				}
				
				it++;
			}
		}
	}
};

#endif // !_TerrainCollisionCommand
