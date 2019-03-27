#include "SpriteBackground.h"

#include "..\Engine\Sprite.h"
#include "..\Engine\SceneManager.h"
#include "..\Engine\CryingEngine.h"

#include "..\Engine\SceneManager.h"
#include "..\User\DemoScene.h"
#include "..\User\DemoScene2.h"

SpriteBackground::SpriteBackground(std::string sprite)
{
	//Submit Registrations
	SubmitDrawRegistration();
	SubmitUpdateRegistration();

	//Set the sprite
	pBackgroundSprite = new Sprite(sprite);

	//Adjust sprite 
	pBackgroundSprite->SetPosition(CryingEngine::GetWidth() / 2.0f, CryingEngine::GetHeight() / 2.0f);
	pBackgroundSprite->SetAngle(0.0f, ANGLE_MEASURE_TYPE::RADIAN);
	pBackgroundSprite->SetCenter(0.0f, 0.0f);
	pBackgroundSprite->SetScalePixel((float)CryingEngine::GetWidth(), (float)CryingEngine::GetHeight());

}

SpriteBackground::~SpriteBackground()
{
	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();
	delete pBackgroundSprite;
}

void SpriteBackground::Update()
{
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_SPACE) || Keyboard::GetKeyState(AZUL_KEY::KEY_ENTER))
	{
		SceneManager::SetNextScene(new DemoScene2());
	}

}

void SpriteBackground::Draw2D()
{
	pBackgroundSprite->Render();
}
