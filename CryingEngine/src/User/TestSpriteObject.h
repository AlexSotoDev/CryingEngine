#ifndef _TestSpriteObject
#define _TestSpriteObject

#include "AzulCore.h"

#include "../Engine/Updatable.h"
#include "../Engine/Drawable.h"

#include "Align16.h"

class Sprite;

class TestSpriteObject : public Updatable, public Drawable, public Align16
{
private:

	Sprite* pMegamanSprite;

public:

	TestSpriteObject();
	~TestSpriteObject();
	TestSpriteObject& operator=(const TestSpriteObject&) = delete;
	TestSpriteObject(const TestSpriteObject&) = delete;
	void Update();
	void Draw2D() override;

};


#endif // !_TestSpriteObject

