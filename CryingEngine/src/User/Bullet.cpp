#include "Bullet.h"

#include "../Engine/SceneManager.h"
#include "../Engine/CryingEngine.h"

#include "BulletFactory.h"

#include "DebugOut.h"
#include <string>

#include "Frigate.h"

Bullet::Bullet()
{
	pGObj_Bullet = new GraphicsObject_TextureFlat(ModelManager::GetModel("CRYpModelSphere"), ShaderManager::GetShader("CRYtextureFlatRender"), TextureManager::GetTexture("Texture_Blue"));
	
}

Bullet::~Bullet()
{
	//SubmitAlarmDeregistration(AlarmID::ALARM_0);

	delete pGObj_Bullet;

	DebugMsg::out("BULLET DESTROYED\n");
}

void Bullet::SceneEntry()
{
	SubmitUpdateRegistration();
	SubmitDrawRegistration();
	SubmitAlarmRegistration(bulletLifeSpan, AlarmID::ALARM_0);
	SubmitCollisionRegistration<Bullet>(this);
	SetColliderModel(pGObj_Bullet->getModel(), CollisionVolumeType::BSphere);
	
}

void Bullet::SceneExit()
{

	SubmitUpdateDeregistration();
	SubmitDrawDeregistration();
	SubmitCollisionDeregistration<Bullet>(this);
	BulletFactory::RecycleBullet(this);



}

void Bullet::Update()
{

	bulletPos += Vect(0, 0, 1) * bulletRot * bulletSpeed;

	world = bulletScale * bulletRot * Matrix(TRANS, bulletPos);
	pGObj_Bullet->SetWorld(world);
	UpdateCollisionData(world);
}

void Bullet::Draw()
{
	pGObj_Bullet->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());

}

void Bullet::Alarm0()
{
	GameObject::SubmitExit();
}

void Bullet::Initialize(Frigate * ship)
{
	bulletScale.set(SCALE, 3.0f, 3.0f, 3.0f);
	bulletRot = ship->GetRotation();
	bulletPos = ship->GetTranslation();
	bulletPos = Vect(bulletPos.X(), bulletPos.Y() + bulletYOffset, bulletPos.Z());
	world = bulletScale * bulletRot * Matrix(TRANS, bulletPos);
	pGObj_Bullet->SetWorld(world);
}


