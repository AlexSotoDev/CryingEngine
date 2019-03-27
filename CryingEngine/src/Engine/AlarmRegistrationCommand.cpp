#include "AlarmRegistrationCommand.h"

#include "EnumAlarm.h"

#include "Alarmable.h"

AlarmRegistrationCommand::AlarmRegistrationCommand(Alarmable * alarm, AlarmID alarmID)
{
	ptrAlarm = alarm;
	currentAlarmID = alarmID;
}

AlarmRegistrationCommand::~AlarmRegistrationCommand()
{
	ptrAlarm = nullptr;
}

void AlarmRegistrationCommand::Execute()
{
	ptrAlarm->SceneRegistration(ptrAlarm->GetTime(currentAlarmID), currentAlarmID);
}
