#ifndef _EndScene
#define _EndScene

#include "../Engine/Scene.h"

class SpriteBackground;

class EndScene : public Scene
{
private:
	SpriteBackground* mySprite;

public:

	void Initialize() override;
	void Terminate() override;

};


#endif

