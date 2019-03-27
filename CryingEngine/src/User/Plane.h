#ifndef _Plane
#define _Plane

#include "AzulCore.h"
#include "../Engine/Drawable.h"
#include "Align16.h"



class Plane : public Drawable, public Align16
{
public:
	Plane();
	virtual ~Plane();
	Plane& operator=(const Plane&) = delete;
	Plane(const Plane&) = delete;
	void Draw();

private:
	GraphicsObject_TextureLight* gObjTL;
	Matrix world;

	Vect color;
	Vect position;
};


#endif 
