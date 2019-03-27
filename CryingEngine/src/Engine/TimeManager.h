#ifndef _TimeManager
#define _TimeManager

// Singleton timer manager

#include "AzulCore.h"

class FreezeTime;

/**********************************************************************************************//**
 * \class	TimeManager
 *
 * \brief	Singleton manager for time keeping within our game engine. Has private methods with public accessors for getting the current time, frame time and processing time between frames
 *
 * \author	Alex
 * \date	3/6/2017
 **************************************************************************************************/

class TimeManager
{
private:

	static TimeManager *self; //pointer to itself

	TimeManager();

	TimeManager(const TimeManager&) {};
	TimeManager& operator = (const TimeManager&) {};

	~TimeManager() {}; //destructor

						 //Instance Creation
	static TimeManager& Instance()
	{
		if (!self)
		{
			self = new TimeManager();
		}

		return *self;
	}

	/**********************************************************************************************//**
	 * \fn	float TimeManager::PrivateGetCurrentTime();
	 *
	 * \brief	Private function for geting/returning the current time as a float. Called by public accessor function.
	 * 			
	 * \sa		TimeManager::GetCurrentTime
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \return	A float (the time in seconds).
	 **************************************************************************************************/

	float PrivateGetCurrentTime();

	/**********************************************************************************************//**
	 * \fn	float TimeManager::PrivateGetFrameTime();
	 *
	 * \brief	Private function for geting/returning the frame time as a float. Called by public accessor function.
	 * 			
	 * \sa		TimeManager::GetFrameTime
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \return	A float (the time in seconds).
	 **************************************************************************************************/

	float PrivateGetFrameTime();

	/**********************************************************************************************//**
	 * \fn	void TimeManager::PrivateProcessTime(float sys_time);
	 *
	 * \brief	Private function for processing time by getting the time in seconds with the system time. 
	 * 			1. Sets previous time to the current time  
	 * 			2. Gets/Updates the Time in seconds using sys_time  
	 * 			3. Updates the frame time (time between frames) using difference of currentTime - previousTime
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	sys_time	The system time.
	 **************************************************************************************************/

	void PrivateProcessTime(float sys_time);


	/** \brief	The current time (of curr frame) */
	float currentTime = 0;

	/** \brief	The previous time (of prev frame) */
	float previousTime = 0;

	/** \brief	The frame time */
	float frameTime = 0;

	FreezeTime* frozenTime;


public:

	/**********************************************************************************************//**
	 * \fn	static float TimeManager::GetCurrTime()
	 *
	 * \brief	Gets/returns current time as float by calling private equivalent function.
	 * 			
	 * \sa		TimeManager::PrivateGetCurrentTime
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \return	The curr time.
	 **************************************************************************************************/

	static float GetCurrTime() { return Instance().PrivateGetCurrentTime(); }

	/**********************************************************************************************//**
	 * \fn	static void TimeManager::ProcessTime(float sys_time)
	 *
	 * \brief	Process the time described by sys_time by calling private equivalent function
	 * 	
	 * \sa		TimeManager::PrivateProcessTime					
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	sys_time	The system time.
	 **************************************************************************************************/

	static void ProcessTime(float sys_time) { Instance().PrivateProcessTime(sys_time); }

	/**********************************************************************************************//**
	 * \fn	static float TimeManager::GetFrameTime()
	 *
	 * \brief	Calculate the frame time (curr - prev difference) by calling private equivalent function
	 * 
	 * \sa		TimeManager::PrivateGetFrameTime			
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \return	The frame time.
	 **************************************************************************************************/

	static float GetFrameTime() { return Instance().PrivateGetFrameTime(); }
	

};

#endif