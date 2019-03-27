#include "EnemyBullet.h"

#include "../Engine/SceneManager.h"
#include "../Engine/CryingEngine.h"

#include "EnemyBulletFactory.h"

#include "DebugOut.h"
#include <string>

#include "Enemy.h"
#include "Frigate.h"

#include "../Engine/Visualizer.h"
#include "../Engine/ColorLibrary.h"

EnemyBullet::EnemyBullet()
{

	pGObj_Bullet = new GraphicsObject_TextureFlat(ModelManager::GetModel("CRYpModelSphere"), ShaderManager::GetShader("CRYtextureFlatRender"), TextureManager::GetTexture("Texture_Red"));

	SetColliderModel(pGObj_Bullet->getModel(), CollisionVolumeType::BSphere);

	SubmitUpdateRegistration();
	SubmitDrawRegistration();
	//SubmitAlarmRegistration(bulletLifeSpan, AlarmID::ALARM_0);
	SubmitCollisionRegistration<EnemyBullet>(this);
}

EnemyBullet::~EnemyBullet()
{
	//SubmitAlarmDeregistration(AlarmID::ALARM_0);

	delete pGObj_Bullet;

	DebugMsg::out("ENEMY BULLET DESTROYED\n");
}

void EnemyBullet::SceneEntry()
{


}

void EnemyBullet::SceneExit()
{

	SubmitUpdateDeregistration();
	SubmitDrawDeregistration();
	EnemyBulletFactory::RecycleBullet(this);
	//SubmitAlarmDeregistration(AlarmID::ALARM_0);


}

void EnemyBullet::Update()
{

	bulletPos += Vect(0, 0, 1) * bulletRot * bulletSpeed;

	world = bulletScale * bulletRot * Matrix(TRANS, bulletPos);
	pGObj_Bullet->SetWorld(world);

	UpdateCollisionData(world);
}

void EnemyBullet::Draw()
{
	pGObj_Bullet->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());

	if (debugCollision)
	{
		Visualizer::ShowCollisionVolume(this, Colors::Green);
	}

	else
	{
		Visualizer::ShowCollisionVolume(this, Colors::Red);
	}


	debugCollision = false;
}

void EnemyBullet::Alarm0()
{
	GameObject::SubmitExit();
}

void EnemyBullet::Initialize(Enemy * ship)
{
	bulletScale.set(SCALE, 3.0f, 3.0f, 3.0f);
	bulletRot = ship->GetRotation();
	bulletPos = ship->GetTranslation();
	bulletPos = Vect(bulletPos.X(), bulletPos.Y() + bulletYOffset, bulletPos.Z());
	world = bulletScale * bulletRot * Matrix(TRANS, bulletPos);
	pGObj_Bullet->SetWorld(world);
}

void EnemyBullet::Collision(Frigate *)
{
	GameObject::SubmitExit();
	SubmitCollisionDeregistration<EnemyBullet>(this);
	//SubmitAlarmDeregistration(AlarmID::ALARM_0);

	debugCollision = true;
	
}
