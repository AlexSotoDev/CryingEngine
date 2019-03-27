#include "EndScene.h"
#include "SpriteBackground.h"
#include "../Engine/SoundEngine.h"

void EndScene::Initialize()
{
	mySprite = new SpriteBackground("Sprite_TreeBackground");
	SoundEngine::PlaySound("song", "Master");
	
}

void EndScene::Terminate()
{
	delete mySprite;
}
