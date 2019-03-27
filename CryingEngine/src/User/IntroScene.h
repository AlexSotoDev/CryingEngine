#ifndef _IntroScene
#define _IntroScene

#include "../Engine/Scene.h"

class SpriteBackground;

class IntroScene : public Scene
{
private:
	SpriteBackground* mySprite;

public:

	void Initialize() override;
	void Terminate() override;

};


#endif
