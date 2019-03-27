#ifndef _AlarmDeregistrationCommand
#define _AlarmDeregistrationCommand

#include "CommandBase.h"

class Alarmable;

enum class AlarmID;

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	AlarmDeregistrationCommand
 *
 * \brief	An alarm deregistration command (Command Pattern).
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class AlarmDeregistrationCommand : public CommandBase
{
public:

	/**********************************************************************************************//**
	 * \fn	AlarmDeregistrationCommand::AlarmDeregistrationCommand(Alarmable* alarm, AlarmID alarmID);
	 *
	 * \brief	Constructor that takes an alarmable and an ID for use in executing the scene deregistration command..
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	alarm  	If non-null, the alarm.
	 * \param 		  	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	AlarmDeregistrationCommand(Alarmable* alarm, AlarmID alarmID);
	AlarmDeregistrationCommand(const AlarmDeregistrationCommand&) = delete;
	AlarmDeregistrationCommand& operator= (const AlarmDeregistrationCommand&) = delete;
	~AlarmDeregistrationCommand();

	/**********************************************************************************************//**
	 * \fn	void AlarmDeregistrationCommand::Execute() override;
	 *
	 * \brief	Executes the command on the Alarmable, deregistering it from the scene using the Alarmable's SceneDeregistration() function, which uses alarmable and its ID. 
	 * 			
	 * \sa		Alarmable::SceneDeregistration
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void Execute() override;


private:

	Alarmable* ptrAlarm;
	AlarmID currentAlarmID;
};

#endif // !_UpdateRegistrationCommand
