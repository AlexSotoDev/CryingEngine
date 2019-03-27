#include "Frigate.h"

#include "../Engine/ModelManager.h"
#include "../Engine/ShaderManager.h"
#include "../Engine/TextureManager.h"
#include "../Engine/CameraManager.h"
#include "../Engine/SceneManager.h"
#include "BulletFactory.h"

#include "DemoScene.h"

#include "Enemy.h"

#include "../Engine/Visualizer.h"
#include "../Engine/ColorLibrary.h"

#include "EnemyBullet.h"

#include "EndScene.h"

Frigate::Frigate()
{


	SubmitUpdateRegistration();
	SubmitDrawRegistration();
	//SubmitAlarmRegistration(1.0f, AlarmID::ALARM_0);
	//SubmitAlarmRegistration(4.0f, AlarmID::ALARM_1);

	SubmitKeyEventRegistration(AZUL_KEY::KEY_Q, EVENT_TYPE::KEY_PRESS);
	SubmitKeyEventRegistration(AZUL_KEY::KEY_E, EVENT_TYPE::KEY_RELEASE);
	SubmitKeyEventRegistration(AZUL_KEY::KEY_SPACE, EVENT_TYPE::KEY_PRESS);

	//For scene changing test
	SubmitKeyEventRegistration(AZUL_KEY::KEY_R, EVENT_TYPE::KEY_PRESS);


	// Light
	Vect LightColor(1.50f, 1.50f, 1.50f, 1.0f);
	Vect LightPos(1.0f, 1.0f, 1.0f, 1.0f);
	gObjTL = new GraphicsObject_TextureLight(ModelManager::GetModel("Model_TankBottom"), ShaderManager::GetShader("CRYtextureLightRender"), TextureManager::GetTexture("Texture_TankBody"), LightColor, LightPos);

	gObjTL2 = new GraphicsObject_TextureLight(ModelManager::GetModel("Model_TankTop"), ShaderManager::GetShader("CRYtextureLightRender"), TextureManager::GetTexture("Texture_TankBody"), LightColor, LightPos);


	Vect Blue(0.0f, 0.0f, 1.0f, 1.0f);
	gObjWF = new GraphicsObject_WireframeConstantColor(ModelManager::GetModel("CRYpModelSphere"), ShaderManager::GetShader("CRYcolorConstantRender"), Blue);

	// Spaceship
	ShipScale.set(SCALE, 3.0f, 3.0f, 3.0f);
	ShipRot.set(IDENTITY);
	ShipPos.set(0, -5, 0);
	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	gObjTL->SetWorld(world);
	gObjTL2->SetWorld(world);


	SubmitCollisionRegistration<Frigate>(this);

	SetColliderModel(gObjTL->getModel(), CollisionVolumeType::AABB);
	
}

Frigate::~Frigate()
{
	delete gObjTL;
	delete gObjWF;
	
	

	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	//SubmitAlarmDeregistration(AlarmID::ALARM_0);
	//SubmitAlarmDeregistration(AlarmID::ALARM_1);
	//SubmitAlarmDeregistration(AlarmID::ALARM_2);

	BulletFactory::Terminate();

	SubmitKeyEventDeregistration(AZUL_KEY::KEY_Q, EVENT_TYPE::KEY_PRESS);
	SubmitKeyEventDeregistration(AZUL_KEY::KEY_E, EVENT_TYPE::KEY_RELEASE);

	//For scene changing test
	SubmitKeyEventDeregistration(AZUL_KEY::KEY_R, EVENT_TYPE::KEY_PRESS);
	SubmitKeyEventDeregistration(AZUL_KEY::KEY_SPACE, EVENT_TYPE::KEY_PRESS);

	SubmitCollisionDeregistration<Frigate>(this);

}

void Frigate::Update()
{
	//SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera()->setOrientAndPosition(Vect(0, 1, 0), ShipPos, Vect(50.0f, 150.0f, 250.0f) + ShipPos);
	//SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera()->updateCamera();

	// Ship translation movement (not using time-based values for simplicity)
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_W))
	{
		ShipPos += Vect(0, 0, 1) * ShipRot * ShipTransSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_S))
	{
		ShipPos += Vect(0, 0, 1) * ShipRot * -ShipTransSpeed;
	}

	// Ship Rotation movement (not using time-based values for simplicity)
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_A))
	{
		ShipRot *= Matrix(ROT_Y, ShipRotAng);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_D))
	{
		ShipRot *= Matrix(ROT_Y, -ShipRotAng);
	}

	// Spaceship adjust matrix
	world = ShipScale * ShipRot * Matrix(TRANS, ShipPos);
	gObjTL->SetWorld(world);
	gObjTL2->SetWorld(world);

	gObjWF->SetWorld(world);
	UpdateCollisionData(world);

	//DebugMsg::out("Remaining time on Alarm 1: %2f\n", SceneManager::GetCurrentScene()->GetRemainingTime(this, AlarmID::ALARM_1));
}

void Frigate::Draw()
{
	gObjTL->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());
	gObjTL2->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());


	//if (debugCollision)
	//{
	//	//Visualizer::ShowCollisionVolume(this, Colors::Red);
	//}

	//else
	//{
	//	//Visualizer::ShowCollisionVolume(this, Colors::Green);

	//}

	////if (BsphereToggle)
	////{
	////	gObjWF->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());
	////}

	debugCollision = false;
}

void Frigate::Alarm0()
{
	ShipPos += Vect(0, 0, 1) * ShipRot * ShipTransSpeed;
	SubmitAlarmRegistration(1.0f, AlarmID::ALARM_0);
}

void Frigate::Alarm1()
{
	ShipPos += Vect(1, 0, 0) * ShipRot * ShipTransSpeed;
	SubmitAlarmRegistration(4.0f, AlarmID::ALARM_1);
}

void Frigate::Alarm2()
{
	SceneManager::SetNextScene(new EndScene());
}

void Frigate::OnKeyPress(AZUL_KEY key)
{
	switch (key)
	{
		case(AZUL_KEY::KEY_SPACE):
			BulletFactory::CreateBullet(this);
			break;

		case(AZUL_KEY::KEY_R):
			SceneManager::SetNextScene(new DemoScene());
			break;
		default:
			break;
	}
}

void Frigate::OnKeyRelease(AZUL_KEY key)
{
	switch (key)
	{
	case(AZUL_KEY::KEY_E):
		BulletFactory::CreateBullet(this);
		break;

	default:
		break;
	}

}

void Frigate::Collision(Collidable *)
{
	DebugMsg::out("Colliding with collidable\n");
}

void Frigate::Collision(Enemy *)
{
	DebugMsg::out("Colliding with enemy\n");
	debugCollision = true;
}

void Frigate::Collision(EnemyBullet *)
{
	health--;
	if (health == 0)
	{
		SubmitAlarmRegistration(sceneSwitchDelay, AlarmID::ALARM_2);
	}
}

int Frigate::GetHealth()
{
	return health;
}
