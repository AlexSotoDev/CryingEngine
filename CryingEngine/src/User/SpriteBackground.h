#ifndef _SpriteBackground
#define _SpriteBackground

#include "AzulCore.h"

#include "../Engine/Updatable.h"
#include "../Engine/Drawable.h"

#include "Align16.h"


class Sprite;

class SpriteBackground : public Updatable, public Drawable, public Align16
{
private:

	Sprite* pBackgroundSprite;

public:
	SpriteBackground() = delete;
	SpriteBackground(std::string sprite);
	~SpriteBackground();
	SpriteBackground& operator=(const SpriteBackground&) = delete;
	SpriteBackground(const SpriteBackground&) = delete;
	void Update();
	void Draw2D() override;

};


#endif // !_SpriteBackground
