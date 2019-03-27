#include "TestSpriteObject.h"

#include "..\Engine\Sprite.h"

#include "..\Engine\SceneManager.h"
#include "..\Engine\CameraManager.h"

#include "..\Engine\CryingEngine.h"


TestSpriteObject::TestSpriteObject()
{
	SubmitDrawRegistration();
	SubmitUpdateRegistration();
	pMegamanSprite = new Sprite("Sprite_Megaman");
	pMegamanSprite->SetPosition(CryingEngine::GetWidth()/2.0f, CryingEngine::GetHeight()/2.0f);
	//pMegamanSprite->SetPosition(0.0f, 0.0f);
	pMegamanSprite->SetAngle(0.0f, ANGLE_MEASURE_TYPE::RADIAN);
	//pMegamanSprite->SetScaleFactor(3.0f, 3.0f);
	pMegamanSprite->SetScalePixel(200.0f, 200.0f);
	pMegamanSprite->SetCenter(0.0f, 0.0f);
	

	float currAngle = pMegamanSprite->GetAngle(ANGLE_MEASURE_TYPE::DEGREE);
	DebugMsg::out("%f\n", currAngle);
}

TestSpriteObject::~TestSpriteObject()
{
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	delete pMegamanSprite;
}

void TestSpriteObject::Update()
{

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_Z))
	{
		float deltaAng = pMegamanSprite->GetAngle(ANGLE_MEASURE_TYPE::DEGREE) + 1.0f;
		DebugMsg::out("%f\n", deltaAng);
		pMegamanSprite->SetAngle(deltaAng, ANGLE_MEASURE_TYPE::DEGREE);

		float currAngle = pMegamanSprite->GetAngle(ANGLE_MEASURE_TYPE::DEGREE);
		DebugMsg::out("%f\n",currAngle);
	}

	SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent2DCamera()->updateCamera();

}

void TestSpriteObject::Draw2D()
{
	//pMegamanSprite->Render();
}
