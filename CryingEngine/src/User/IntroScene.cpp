#include "IntroScene.h"
#include "SpriteBackground.h"
#include "../Engine/SoundEngine.h"


void IntroScene::Initialize()
{
	mySprite = new SpriteBackground("Sprite_TankBackground");
	Vect myVect = Vect(0, 0, 0);
	SoundEngine::PlaySound("song", "Master", myVect, 1.0f);
	SoundEngine::StopAllSounds();
}

void IntroScene::Terminate()
{
	delete mySprite;
}
