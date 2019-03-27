#include "DemoScene2.h"

#include "Plane.h"
#include "Axis.h"
#include "Enemy.h"
#include "EnemySpawner.h"
#include "../Engine/GodCamera.h"

#include "TestSpriteObject.h"
#include "SpriteHeart.h"

#include "EnemyBullet.h"
#include "Bullet.h"
#include "Frigate.h"



void DemoScene2::Initialize()
{
	myFrigate = new Frigate();

	myAxis = new Axis();

	Vect pos1 = Vect(-100.0f, 0.0f, 0.0f);
	Vect pos2 = Vect(100.0f, 0.0f, 0.0f);
	Vect pos3 = Vect(0.0f, 0.0f, 100.0f);


	myEnemy = new Enemy(pos1);
	myEnemy2 = new Enemy(pos2);
	myEnemy3 = new Enemy(pos3);


	sceneCollisionManager->SetCollisionPair<Frigate, Enemy>();
	//sceneCollisionManager->SetCollisionSelf<Frigate>();
	//sceneCollisionManager->SetCollisionSelf<Enemy>();

	sceneCollisionManager->SetCollisionPair<Frigate, EnemyBullet>();
	//sceneCollisionManager->SetCollisionPair<Enemy, Bullet>();

	myGodCam = new GodCamera();

	myTestSpriteObject = new TestSpriteObject();

	mySpriteHeart = new SpriteHeart(myFrigate);

	SetTerrain("Terrain_PrimaryTerrain");

	sceneCollisionManager->SetCollisionTerrain<Frigate>();
	
}


void DemoScene2::Terminate()
{
	delete myAxis;
	delete myFrigate;

	delete myEnemy;
	delete myEnemy2;
	delete myEnemy3;


	delete myGodCam;

	delete myTestSpriteObject;

	delete mySpriteHeart;

}