#ifndef _DemoScene2
#define _DemoScene2

#include "../Engine/Scene.h"

class Frigate;
class Axis;
class Plane;
class Enemy;
class EnemySpawner;
class GodCamera;
class TestSpriteObject;
class SpriteHeart;

class DemoScene2 : public Scene
{
private:
	Frigate *myFrigate;

	Axis *myAxis;

	Enemy *myEnemy;
	Enemy *myEnemy2;
	Enemy *myEnemy3;

	GodCamera *myGodCam;
	TestSpriteObject *myTestSpriteObject;
	SpriteHeart *mySpriteHeart;

public:

	void Initialize() override;
	void Terminate();

};


#endif
