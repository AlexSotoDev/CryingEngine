#ifndef _SpriteHeart
#define _SpriteHeart

#include "AzulCore.h"

#include "../Engine/Drawable.h"
#include "../Engine/Updatable.h"

#include "../Engine/Sprite.h"

#include "Align16.h"

class Frigate;

class SpriteHeart : public Drawable, public Updatable, public Align16
{
private:

	float xOffset = 0.0f;

	static const int totalNumberOfHearts = 5;
	int currentNumberOfHearts;

	Sprite* HeartsArray[totalNumberOfHearts];

	Sprite* pSpriteHeart;

	Frigate* playerCopy;

public:

	SpriteHeart(Frigate* player);
	~SpriteHeart();
	SpriteHeart& operator=(const SpriteHeart&) = delete;
	SpriteHeart(const SpriteHeart&) = delete;
	void Draw2D() override;
	void Update() override;
};


#endif // !_SpriteHeart
