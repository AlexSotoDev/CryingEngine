#include "DemoScene.h"

#include "Frigate.h"
#include "Plane.h"
#include "Axis.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "../Engine/GodCamera.h"

#include "TestSpriteObject.h"
#include "SpriteHeart.h"

#include "EnemyBullet.h"
#include "Bullet.h"



void DemoScene::Initialize()
{
	myFrigate = new Frigate();

	myPlane = new Plane();

	myAxis = new Axis();

	//myEnemy = new Enemy();

	myEnemySpawner = new EnemySpawner();

	sceneCollisionManager->SetCollisionPair<Frigate, Enemy>();
	sceneCollisionManager->SetCollisionSelf<Frigate>();
	sceneCollisionManager->SetCollisionSelf<Enemy>();

	sceneCollisionManager->SetCollisionPair<Frigate, EnemyBullet>();
	sceneCollisionManager->SetCollisionPair<Enemy, Bullet>();

	myGodCam = new GodCamera();

	myTestSpriteObject = new TestSpriteObject();

	mySpriteHeart = new SpriteHeart(myFrigate);
}


void DemoScene::Terminate()
{
	delete myAxis;
	delete myPlane;
	delete myFrigate;
	//delete myEnemy;

	delete myEnemySpawner;

	delete myGodCam;

	delete myTestSpriteObject;

	delete mySpriteHeart;

}
