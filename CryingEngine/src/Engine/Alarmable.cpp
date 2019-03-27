#include "Alarmable.h"

#include "SceneManager.h"

#include "AlarmRegistrationCommand.h"
#include "AlarmDeregistrationCommand.h"

#include "EnumAlarm.h"
#include "EnumRegistrationState.h"


Alarmable::Alarmable()
{
	for (int i = 0; i < numberOfAlarms; i++)
	{
		RegData[i].registrationCommand = new AlarmRegistrationCommand(this, (AlarmID)i);
		RegData[i].deregistrationCommand = new AlarmDeregistrationCommand(this, (AlarmID)i);
		RegData[i].currentState = RegistrationState::CURRENTLY_DEREGISTERED;
		RegData[i].myAlarmID = (AlarmID)i;
	}
}

Alarmable::~Alarmable()
{
	for (int i = 0; i < numberOfAlarms; i++)
	{
		delete RegData[i].registrationCommand;
		delete RegData[i].deregistrationCommand;
	}
}

void Alarmable::SceneRegistration(float timer, AlarmID alarmID)
{
	assert(RegData[(int)alarmID].currentState == RegistrationState::PENDING_REGISTRATION);
	SceneManager::GetCurrentScene()->Register(timer, this, alarmID);
	RegData[(int)alarmID].currentState = RegistrationState::CURRENTLY_REGISTERED;
}

void Alarmable::SceneDeregistration(AlarmID alarmID)
{
	assert(RegData[(int)alarmID].currentState == RegistrationState::PENDING_DEREGISTRATION);
	SceneManager::GetCurrentScene()->Deregister(this, alarmID);
	RegData[(int)alarmID].currentState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Alarmable::SubmitAlarmRegistration(float timer, AlarmID alarmID)
{
	assert(RegData[(int)alarmID].currentState == RegistrationState::CURRENTLY_DEREGISTERED);
	RegData[(int)alarmID].time = timer;
	SceneManager::GetCurrentScene()->SubmitCommand(RegData[(int)alarmID].registrationCommand);
	RegData[(int)alarmID].currentState = RegistrationState::PENDING_REGISTRATION;

}

void Alarmable ::SubmitAlarmDeregistration(AlarmID alarmID)
{
	if (RegData[(int)alarmID].currentState == RegistrationState::CURRENTLY_DEREGISTERED) return;
	assert(RegData[(int)alarmID].currentState == RegistrationState::CURRENTLY_REGISTERED);
	SceneManager::GetCurrentScene()->SubmitCommand(RegData[(int)alarmID].registrationCommand);
	RegData[(int)alarmID].currentState = RegistrationState::PENDING_DEREGISTRATION;
}

float Alarmable::GetTime(AlarmID alarmID)
{
	return RegData[(int)alarmID].time;
}

void Alarmable::SetIterator(AlarmableManager::AlarmableListRef ref, AlarmID alarmID)
{
	RegData[(int)alarmID].myRef = ref;
}

AlarmableManager::AlarmableListRef Alarmable::GetIterator(AlarmID alarmID)
{
	return RegData[(int)alarmID].myRef;
}

void Alarmable::TriggerAlarm(AlarmID alarmID)
{
	switch (alarmID)
	{
		case(AlarmID::ALARM_0):
			RegData[(int)alarmID].currentState = RegistrationState::CURRENTLY_DEREGISTERED;
 			this->Alarm0();
			break;

		case(AlarmID::ALARM_1):
			RegData[(int)alarmID].currentState = RegistrationState::CURRENTLY_DEREGISTERED;
			this->Alarm1();
			break;

		case(AlarmID::ALARM_2):
			RegData[(int)alarmID].currentState = RegistrationState::CURRENTLY_DEREGISTERED;
			this->Alarm2();
			break;

		case(AlarmID::ALARM_3):
			RegData[(int)alarmID].currentState = RegistrationState::CURRENTLY_DEREGISTERED;
			this->Alarm3();
			break;

		default:
			break;
	}

}

