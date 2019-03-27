#include "EnemySpawner.h"
#include "Enemy.h"

#include "../Engine/SceneManager.h"

void EnemySpawner::Alarm0()
{
	SubmitAlarmRegistration(spawnRate, AlarmID::ALARM_0);
	if (enemyCount < 1)
	{
		SpawnEnemy();
		enemyCount++;
	}

}

void EnemySpawner::SpawnEnemy()
{
	new Enemy();
}

EnemySpawner::EnemySpawner()
{
	SubmitAlarmRegistration(spawnRate, AlarmID::ALARM_0);
}

EnemySpawner::~EnemySpawner()
{
	SubmitAlarmDeregistration(AlarmID::ALARM_0);
}
