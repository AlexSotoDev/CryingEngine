#ifndef _Cottage
#define _Cottage

#include "AzulCore.h"

#include "../Engine/Drawable.h"
#include "../Engine/Updatable.h"

#include "Align16.h"



class Cottage : public Drawable, public Align16
{
public:
	Cottage();
	virtual ~Cottage();
	Cottage& operator=(const Cottage&) = delete;
	Cottage(const Cottage&) = delete;
	void Draw();

private:
	GraphicsObject_ColorNoTexture *gObjCottage;
	Matrix world;
};

#endif
