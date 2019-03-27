#ifndef _Axis
#define _Axis

#include "AzulCore.h"
#include "../Engine/Drawable.h"
#include "Align16.h"



class Axis : public Drawable, public Align16
{
public:
	Axis();
	virtual ~Axis();
	Axis& operator=(const Axis&) = delete;
	Axis(const Axis&) = delete;
	void Draw();

private:
	GraphicsObject_ColorNoTexture *gObjAxis;
	Matrix world;
};

#endif

