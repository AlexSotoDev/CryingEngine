#include "BulletFactory.h"
#include "Bullet.h"
#include "DebugOut.h"
#include "Frigate.h"

BulletFactory* BulletFactory::ptrInstance = NULL;


void BulletFactory::privCreateBullet(Frigate* rotation)
{
	Bullet* b;

	if (recycledItems.empty())
	{
		//ConsoleMsg::WriteLine("New Bullet"); // For illustration purposes

		b = new Bullet();

		// Declares that this object should be returned here (rather than deleted) when destroyed
		//b->SetExternalManagement(RecycleBullet);
		DebugMsg::out("NEW BULLET CREATED\n");

	}
	else
	{
		//ConsoleMsg::WriteLine("Recycled Bullet"); // For illustration purposes

		b = recycledItems.top();
		recycledItems.pop();	// Remember: top doesn't pop and pop returns void...

								// Tell the object to register itself to the scene
								//b->RegisterToCurrentScene();
		DebugMsg::out("OLD BULLET USED\n");
	}

	b->Initialize(rotation);
	b->GameObject::SubmitEntry();
}

void BulletFactory::privRecycleBullet(Bullet* b)
{
	recycledItems.push(b);

	// For illustration purposes
	//ConsoleMsg::WriteLine("Recycled Stack Size: " + Tools::ToString(recycledItems.size()));
	DebugMsg::out("Recycled stack size: %d\n", recycledItems.size());
}

void BulletFactory::privTerminate()
{
	delete Instance().ptrInstance;
	Instance().ptrInstance = nullptr;	// important habit for Singleton. Why?
}


// Why is this necessary?
BulletFactory::~BulletFactory()
{
	// forcefully delele all recycled gameobjects
	while (!recycledItems.empty())
	{
		delete recycledItems.top();
		recycledItems.pop();
		DebugMsg::out("Recycled stack size: %d\n", recycledItems.size());
	}
}