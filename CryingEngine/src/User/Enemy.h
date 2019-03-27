#ifndef _Enemy
#define _Enemy

#include "AzulCore.h"

#include "../Engine/Updatable.h"
#include "../Engine/Drawable.h"
#include "../Engine/Alarmable.h"
#include "../Engine/Collidable.h"

#include "Align16.h"

class Frigate;

class Enemy : public Updatable, public Drawable, public Alarmable, public Collidable, public Align16
{
public:
	Enemy();
	Enemy(Vect& pos);

	virtual ~Enemy();
	Enemy& operator=(const Enemy&) = delete;
	Enemy(const Enemy&) = delete;
	void Update();
	void Draw();

	void Alarm0() override;
	void Alarm1() override;

	Matrix GetRotation() { return ShipRot; };
	Vect GetTranslation() { return ShipPos; }

	virtual void Collision(Collidable*);
	virtual void Collision(Frigate*);
	virtual void Collision(Enemy*);


private:

	GraphicsObject_TextureLight* gObjTL;
	GraphicsObject_WireframeConstantColor* gObjWF;

	// Spaceship vars
	Matrix ShipScale;
	Vect ShipPos;
	Matrix ShipRot;
	const float ShipTransSpeed = 1;
	const float ShipRotAng = .05f;

	Matrix world;

	float speed = 0.0f;
	float switchDirtimer = 2.5f;

	bool debugCollision = false;

	float fireRate = 1.0f;


};
#endif
