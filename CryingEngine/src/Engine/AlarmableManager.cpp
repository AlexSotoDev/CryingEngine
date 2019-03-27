#include "AlarmableManager.h"

#include "Alarmable.h"

#include "AzulCore.h"

#include "TimeManager.h"

//#include "EnumAlarm.h"



void AlarmableManager::Register(float time, Alarmable * alarm, AlarmID alarmID)
{
	AlarmEvent newEvent;
	newEvent.first = alarmID;
	newEvent.second = alarm;

	ref = AlarmableList.insert(std::pair<float, AlarmEvent>(TimeManager::GetCurrTime() + time, newEvent));
	alarm->SetIterator(ref, alarmID);
}

void AlarmableManager::Deregister(Alarmable * alarm, AlarmID alarmID)
{
	AlarmableList.erase(alarm->GetIterator(alarmID));
}

float AlarmableManager::GetRemainingTime(Alarmable * al, AlarmID ID)
{
	std::multimap<float, AlarmEvent>::iterator temp = AlarmableList.begin();

	std::multimap<float, AlarmEvent>::iterator it = AlarmableList.begin();

	while (it != AlarmableList.end())
	{
		if ((it->second).second == al && (it->second).first == ID)
		{
			return it->first - TimeManager::GetCurrTime();
		}
		it++;
	}
	return 0.0f;
}

void AlarmableManager::ProcessElements()
{
	std::multimap<float, AlarmEvent>::iterator temp = AlarmableList.begin();

	std::multimap<float, AlarmEvent>::iterator it = AlarmableList.begin();

	while (it != AlarmableList.end() && it->first <= TimeManager::GetCurrTime())
		//Check pair
		//Checking whether alarm time is <= our engine's current time in seconds, because that would mean it's time to trigger alarm
		//Checking it isn't at end so we can do for every alarm like we did for updatable and drawable
	{
		temp = it;
		++temp;
		(it->second).second->TriggerAlarm(it->second.first);
		AlarmableList.erase(it);
		it = temp;
	}
	

}

AlarmableManager::~AlarmableManager()
{
	AlarmableList.clear();
}