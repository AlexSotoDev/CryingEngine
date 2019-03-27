#ifndef _AlarmRegistrationCommand
#define _AlarmRegistrationCommand

#include "CommandBase.h"

class Alarmable;

enum class AlarmID;

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	AlarmRegistrationCommand
 *
 * \brief	An alarm registration command (Command Pattern) inheriting from @CommandBase
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class AlarmRegistrationCommand : public CommandBase
{


public:

	/**********************************************************************************************//**
	 * \fn	AlarmRegistrationCommand::AlarmRegistrationCommand(Alarmable* alarm, AlarmID alarmID);
	 *
	 * \brief	Constructor that takes an @Alarmable and an ID for use in executing the scene registration command.
	 *
	 * \sa		AlarmRegistrationCommand::Execute
	 *    
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	alarm  	If non-null, the alarm.
	 * \param 		  	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	AlarmRegistrationCommand(Alarmable* alarm, AlarmID alarmID);
	AlarmRegistrationCommand(const AlarmRegistrationCommand&) = delete;
	AlarmRegistrationCommand& operator= (const AlarmRegistrationCommand&) = delete;
	~AlarmRegistrationCommand();

	/**********************************************************************************************//**
	 * \fn	void AlarmRegistrationCommand::Execute() override;
	 *
	 * \brief	Executes the command on the Alarmable, registering it to the scene using the Alarmable's SceneRegistration() function, which registers using a timer (float) and a an AlarmID.
	 * 
	 * \sa		Alarmable::SceneRegistration
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void Execute() override;


private:


	/** \brief	The pointer to an alarmable */
	Alarmable* ptrAlarm;


	/** \brief	Identifier for the current alarm */
	AlarmID currentAlarmID;
};

#endif // !_UpdateRegistrationCommand
