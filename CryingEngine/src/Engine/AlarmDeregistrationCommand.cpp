#include "AlarmDeregistrationCommand.h"

#include "Alarmable.h"

AlarmDeregistrationCommand::AlarmDeregistrationCommand(Alarmable * alarm, AlarmID alarmID)
{
	ptrAlarm = alarm;
	currentAlarmID = alarmID;
}

AlarmDeregistrationCommand::~AlarmDeregistrationCommand()
{
	ptrAlarm = nullptr;
}

void AlarmDeregistrationCommand::Execute()
{
	ptrAlarm->SceneDeregistration(currentAlarmID);
}
