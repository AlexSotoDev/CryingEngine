#ifndef _EnemyBullet
#define _EnemyBullet

#include "AzulCore.h"

#include "../Engine/Updatable.h"
#include "../Engine/Drawable.h"
#include "../Engine/Alarmable.h"
#include "../Engine/Collidable.h"

#include "Align16.h"

#include "../Engine/ModelManager.h"
#include "../Engine/ShaderManager.h"
#include "../Engine/TextureManager.h"
#include "../Engine/CameraManager.h"

class Enemy;
class Frigate;

class EnemyBullet : public Updatable, public Drawable, public Alarmable, public Collidable, public Align16
{

public:
	EnemyBullet();
	virtual ~EnemyBullet();

	void SceneEntry() override;
	void SceneExit() override;

	void Update() override;
	void Draw() override;
	void Alarm0() override;

	void Initialize(Enemy* ship);

	void Collision(Frigate*);

private:

	GraphicsObject_TextureFlat* pGObj_Bullet;

	Matrix world;
	Matrix bulletScale;
	Vect bulletPos;
	Matrix bulletRot;
	float bulletSpeed = 1.0f;
	float bulletRotAng = .05f;
	float bulletYOffset = -5.0f;
	bool debugCollision = false;

	float bulletLifeSpan = 5.0f;

};

#endif // _!EnemyBullet

