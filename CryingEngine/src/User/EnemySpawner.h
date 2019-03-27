#ifndef _EnemySpawner
#define _EnemySpawner

#include "AzulCore.h"
#include "Align16.h"

#include "../Engine/Alarmable.h"


class EnemySpawner : public Alarmable, public Align16
{

public:


	EnemySpawner();
	virtual ~EnemySpawner();
	EnemySpawner& operator=(const EnemySpawner&) = delete;
	EnemySpawner(const EnemySpawner&) = delete;

	void Alarm0() override;
	void SpawnEnemy();


private:

	float spawnRate = 3.0f;
	int enemyCount = 0;

};



#endif // !_EnemySpawner

