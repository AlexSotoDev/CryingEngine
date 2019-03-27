#include "Enemy.h"

#include "../Engine/ModelManager.h"
#include "../Engine/ShaderManager.h"
#include "../Engine/TextureManager.h"
#include "../Engine/CameraManager.h"
#include "../Engine/SceneManager.h"

#include "Frigate.h"

#include "../Engine/Visualizer.h"
#include "../Engine/ColorLibrary.h"

#include "EnemyBulletFactory.h"

Enemy::Enemy()
{
	SubmitUpdateRegistration();
	SubmitDrawRegistration();
	SubmitAlarmRegistration(switchDirtimer, AlarmID::ALARM_0);
	SubmitAlarmRegistration(fireRate, AlarmID::ALARM_1);

	// Light
	Vect LightColor(1.0f, 1.0f, 1.0f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	gObjTL = new GraphicsObject_TextureLight(ModelManager::GetModel("CRYpModelSpaceFrigate"), ShaderManager::GetShader("CRYtextureLightRender"), TextureManager::GetTexture("CRYpSpaceFrigateTex"), LightColor, LightPos);

	Vect Red(1.0f, 0.0f, 0.0f, 1.0f);
	gObjWF = new GraphicsObject_WireframeConstantColor(ModelManager::GetModel("CRYpModelSphere"), ShaderManager::GetShader("CRYcolorConstantRender"), Red);

	// Spaceship
	ShipScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	ShipRot.set(IDENTITY);
	ShipPos.set(-200, 10, -100);
	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	gObjTL->SetWorld(world);

	Collidable::SubmitCollisionRegistration<Enemy>(this);
	SetColliderModel(gObjTL->getModel(), CollisionVolumeType::AABB);
}

Enemy::Enemy(Vect& pos)
{
	SubmitUpdateRegistration();
	SubmitDrawRegistration();
	SubmitAlarmRegistration(switchDirtimer, AlarmID::ALARM_0);
	SubmitAlarmRegistration(fireRate, AlarmID::ALARM_1);

	// Light
	Vect LightColor(1.0f, 1.0f, 1.0f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	gObjTL = new GraphicsObject_TextureLight(ModelManager::GetModel("CRYpModelSpaceFrigate"), ShaderManager::GetShader("CRYtextureLightRender"), TextureManager::GetTexture("CRYpSpaceFrigateTex"), LightColor, LightPos);

	Vect Red(1.0f, 0.0f, 0.0f, 1.0f);
	gObjWF = new GraphicsObject_WireframeConstantColor(ModelManager::GetModel("CRYpModelSphere"), ShaderManager::GetShader("CRYcolorConstantRender"), Red);

	// Spaceship
	ShipScale.set(SCALE, 0.5f, 0.5f, 0.5f);
	ShipRot.set(IDENTITY);
	ShipPos.set(pos);
	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	gObjTL->SetWorld(world);

	Collidable::SubmitCollisionRegistration<Enemy>(this);
	SetColliderModel(gObjTL->getModel(), CollisionVolumeType::AABB);
}

Enemy::~Enemy()
{
	delete gObjTL;
	delete gObjWF;



	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	SubmitAlarmDeregistration(AlarmID::ALARM_0);

	Collidable::SubmitCollisionDeregistration<Enemy>(this);
}

void Enemy::Update()
{
	ShipPos += Vect(speed, 0, 0) * ShipRot * ShipTransSpeed;

	// Spaceship adjust matrix
	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	gObjTL->SetWorld(world);

	// Adjusting the spaceship's bounding sphere
	Vect vBSSize = gObjTL->getModel()->getRadius() * Vect(1, 1, 1);
	Vect vBSPos = gObjTL->getModel()->getCenter();

	gObjWF->SetWorld(world);


	UpdateCollisionData(world);
}

void Enemy::Draw()
{
	gObjTL->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());

	if (debugCollision)
	{
		//Visualizer::ShowCollisionVolume(this, Colors::Red);
	}

	else
	{
		//Visualizer::ShowCollisionVolume(this, Colors::Green);

	}

	debugCollision = false;
}

void Enemy::Alarm0()
{
	speed *= -1;
	SubmitAlarmRegistration(switchDirtimer, AlarmID::ALARM_0);
}

void Enemy::Alarm1()
{
	EnemyBulletFactory::CreateBullet(this);
	SubmitAlarmRegistration(fireRate, AlarmID::ALARM_1);
}

void Enemy::Collision(Collidable *)
{
	DebugMsg::out("Colliding with collidable\n");
}

void Enemy::Collision(Frigate *)
{
	DebugMsg::out("Colliding with Tank\n");

	debugCollision = true;
}

void Enemy::Collision(Enemy *)
{
	DebugMsg::out("Colliding with other Enemy\n");

	debugCollision = true;
}
