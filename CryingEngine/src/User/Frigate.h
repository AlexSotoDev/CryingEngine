#ifndef _Frigate
#define _Frigate

#include "AzulCore.h"

#include "../Engine/Updatable.h"
#include "../Engine/Drawable.h"
#include "../Engine/Alarmable.h"
#include "../Engine/Inputable.h"
#include "../Engine/Collidable.h"

#include "Align16.h"

class Enemy;
class EnemyBullet;

class Frigate: public Updatable, public Drawable, public Alarmable, public Inputable, public Collidable, public Align16
{
public:
	Frigate();
	virtual ~Frigate();
	Frigate& operator=(const Frigate&) = delete;
	Frigate(const Frigate&) = delete;
	void Update();
	void Draw();

	void Alarm0() override;
	void Alarm1() override;
	void Alarm2() override;

	Matrix GetRotation() { return ShipRot; };
	Vect GetTranslation() { return ShipPos; }

	void OnKeyPress(AZUL_KEY key);
	void OnKeyRelease(AZUL_KEY key);

	virtual void Collision(Collidable*);
	virtual void Collision(Enemy*);

	virtual void Collision(EnemyBullet*);

	int GetHealth();

private:

	GraphicsObject_TextureLight* gObjTL;
	GraphicsObject_TextureLight* gObjTL2;
	GraphicsObject_WireframeConstantColor* gObjWF;

	// Spaceship vars
	Matrix ShipScale;
	Vect ShipPos;
	Matrix ShipRot;
	const float ShipTransSpeed = 1;
	const float ShipRotAng = .05f;
	bool BsphereToggle = false;

	Matrix world;

	bool debugCollision = false;

	int health = 5;

	const float sceneSwitchDelay = 1.0f;
	



};
#endif