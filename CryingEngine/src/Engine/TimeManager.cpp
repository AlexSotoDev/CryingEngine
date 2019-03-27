#include "TimeManager.h"
#include "CryingEngine.h"

#include "FreezeTime.h"

TimeManager* TimeManager::self = NULL;

TimeManager::TimeManager()
{
	frozenTime = new FreezeTime();
}

float TimeManager::PrivateGetCurrentTime()
{
	return currentTime;
}

float TimeManager::PrivateGetFrameTime()
{
	return frameTime;
}

void TimeManager::PrivateProcessTime(float sys_time)
{
	previousTime = currentTime;

	currentTime = frozenTime->GetTimeInSeconds(sys_time);

	frameTime = currentTime - previousTime;
}


