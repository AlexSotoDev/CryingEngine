#ifndef _EnemyBulletFactory
#define _EnemyBulletFactory

#include <stack>
#include "EnemyBullet.h"

class Enemy;

class EnemyBulletFactory
{
private:

	static EnemyBulletFactory* ptrInstance;			// Game set up as a singleton

	EnemyBulletFactory() = default;												// Private constructor
	EnemyBulletFactory(const EnemyBulletFactory&) = delete;				// Prevent copy-construction
	EnemyBulletFactory& operator=(const EnemyBulletFactory&) = delete;	// Prevent assignment
	~EnemyBulletFactory();														// Only this class can delete

	static EnemyBulletFactory& Instance()	    // Access reference (all public methods will be static)
	{
		if (!ptrInstance)
			ptrInstance = new EnemyBulletFactory;
		return *ptrInstance;
	};

	std::stack<EnemyBullet*> recycledItems;  // Back to be a non-static member
	std::stack<EnemyBullet*> activeItems;

	// Note: Some facctory designs also keep a list of 'currently active' objects
	// Often useful at cleanup time. Not needed for this demo however

	// Private methods to perform actual work on member var
	void privCreateBullet(Enemy* ship);
	void privRecycleBullet(EnemyBullet* b);
	void privTerminate();


public:

	// Services/API
	static void CreateBullet(Enemy* ship) { Instance().privCreateBullet(ship); };
	static void RecycleBullet(EnemyBullet* b) { Instance().privRecycleBullet(b); };

	static void Terminate() { Instance().privTerminate(); };
};


#endif _EnemyBulletFactory

