#ifndef _FreezeTime
#define _FreezeTime

#include "AzulCore.h"

/**********************************************************************************************//**
 * \class	FreezeTime
 *
 * \brief	A freeze time class for a "hacked" freeze operation in our game engine. Debugging tool for users. Use F10 to pause/unpause and F9 to step through frame by frame.
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class FreezeTime
{
private:

	/** \brief	The freeze key used for temporarily pausing entire game engine/game processes */
	static const AZUL_KEY FREEZE_KEY = AZUL_KEY::KEY_F10;


	/** \brief	The single frame key for stepping through game/game engine at runtime moving one frame per key press */
	static const AZUL_KEY SINGLE_FRAME_KEY = AZUL_KEY::KEY_F9;


	/** \brief	The total frozen time */
	float totalFrozenTime;


	/** \brief	True to freeze mode active */
	bool freeze_mode_active;

	/**********************************************************************************************//**
	 * \fn	float FreezeTime::WaitAndReturnFrozenTime(float activetime);
	 *
	 * \brief	Wait and return frozen time.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	activetime	The activetime.
	 *
	 * \return	A float.
	 **************************************************************************************************/

	float WaitAndReturnFrozenTime(float activetime);

	/**********************************************************************************************//**
	 * \fn	bool FreezeTime::HackedKeyRelease(AZUL_KEY k);
	 *
	 * \brief	Hacked key release.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	k	The AZUL_KEY to process.
	 *
	 * \return	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	bool HackedKeyRelease(AZUL_KEY k);

public:

	/**********************************************************************************************//**
	 * \fn	FreezeTime::FreezeTime();
	 *
	 * \brief	Default constructor, initializing our game to not frozen and freeze time to 0.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	FreezeTime();
	~FreezeTime() {};
	FreezeTime(const FreezeTime&) = delete;
	FreezeTime& operator=(const FreezeTime&) = delete;

	/**********************************************************************************************//**
	 * \fn	float FreezeTime::GetTimeInSeconds(float sys_time);
	 *
	 * \brief	Gets time in seconds.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	sys_time	The system time.
	 *
	 * \return	The time in seconds.
	 **************************************************************************************************/

	float GetTimeInSeconds(float sys_time);
};

#endif _FreezeTime
