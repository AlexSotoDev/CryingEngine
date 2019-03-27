#ifndef _DemoScene
#define _DemoScene

#include "../Engine/Scene.h"

class Frigate;
class Axis;
class Plane;
class Enemy;
class EnemySpawner;
class GodCamera;
class TestSpriteObject;
class SpriteHeart;

class DemoScene : public Scene
{
private:
	Frigate *myFrigate;
	Plane *myPlane;
	Axis *myAxis;
	Enemy *myEnemy;
	EnemySpawner *myEnemySpawner;
	GodCamera *myGodCam;
	TestSpriteObject *myTestSpriteObject;
	SpriteHeart *mySpriteHeart;

public:

	void Initialize() override;
	void Terminate();

};


#endif