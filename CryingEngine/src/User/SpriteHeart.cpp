#include "SpriteHeart.h"
#include "../Engine/CryingEngine.h"

#include "../Engine/SceneManager.h"
#include "../Engine/Scene.h"
#include "../Engine/CameraManager.h"

#include "Frigate.h"

SpriteHeart::SpriteHeart(Frigate* player)
{
	playerCopy = player;

	SubmitDrawRegistration();
	SubmitUpdateRegistration();

	currentNumberOfHearts = totalNumberOfHearts;

	for (int i = 0; i < totalNumberOfHearts; i++)
	{
		HeartsArray[i] = new Sprite("Sprite_Megaman");
		HeartsArray[i]->SetPosition(50.0f + xOffset, 50.0f);
		HeartsArray[i]->SetAngle(0.0f, ANGLE_MEASURE_TYPE::RADIAN);
		HeartsArray[i]->SetScalePixel(50.0f, 50.0f);
		HeartsArray[i]->SetCenter(0.0f, 0.0f);

		xOffset += 100.0f;
	}
	
	//pSpriteHeart = new Sprite("Sprite_Megaman");
	//pSpriteHeart->SetPosition(50.0f + xOffset, 100.0f);
	//pSpriteHeart->SetScalePixel(100.0f, 100.0f);
}

SpriteHeart::~SpriteHeart()
{
	for (int i = 0; i < currentNumberOfHearts; i++)
	{
		delete HeartsArray[i];
	}

	SubmitDrawDeregistration();
	SubmitUpdateDeregistration();

}

void SpriteHeart::Draw2D()
{
	for (int i = 0; i < playerCopy->GetHealth(); i++)
	{
		HeartsArray[i]->Render();

	}
	

	//pSpriteHeart->Render();
}

void SpriteHeart::Update()
{
	SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent2DCamera()->updateCamera();
}
