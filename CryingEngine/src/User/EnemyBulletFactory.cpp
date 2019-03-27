#include "EnemyBulletFactory.h"
#include "EnemyBullet.h"
#include "DebugOut.h"
#include "Enemy.h"

EnemyBulletFactory* EnemyBulletFactory::ptrInstance = NULL;


void EnemyBulletFactory::privCreateBullet(Enemy* rotation)
{
	EnemyBullet* b;

	if (recycledItems.empty())
	{
		//ConsoleMsg::WriteLine("New Bullet"); // For illustration purposes

		b = new EnemyBullet();

		// Declares that this object should be returned here (rather than deleted) when destroyed
		//b->SetExternalManagement(RecycleBullet);
		//DebugMsg::out("NEW ENEMY BULLET CREATED\n");

	}
	else
	{
		//ConsoleMsg::WriteLine("Recycled Bullet"); // For illustration purposes

		b = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

								// Tell the object to register itself to the scene
								//b->RegisterToCurrentScene();
		//DebugMsg::out("OLD ENEMY BULLET USED\n");
	}

	b->Initialize(rotation);
	b->GameObject::SubmitEntry();
}

void EnemyBulletFactory::privRecycleBullet(EnemyBullet* b)
{
	recycledItems.push(b);

	// For illustration purposes
	//ConsoleMsg::WriteLine("Recycled Stack Size: " + Tools::ToString(recycledItems.size()));
	DebugMsg::out("Recycled stack size(enemy): %d\n", recycledItems.size());
}

void EnemyBulletFactory::privTerminate()
{
	delete Instance().ptrInstance;
	Instance().ptrInstance = nullptr;	// important habit for Singleton. Why?
}


EnemyBulletFactory::~EnemyBulletFactory()
{
	// forcefully delele all recycled gameobjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
		DebugMsg::out("Recycled stack size(enemy): %d\n", recycledItems.size());
	}
}