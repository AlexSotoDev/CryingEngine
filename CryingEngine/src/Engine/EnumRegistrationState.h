#ifndef _RegistrationState
#define _RegistrationState

/**********************************************************************************************//**
 * \enum	RegistrationState
 *
 * \brief	Values that represent registration states.
 **************************************************************************************************/

enum class RegistrationState
{
	CURRENTLY_DEREGISTERED,
	PENDING_REGISTRATION,
	CURRENTLY_REGISTERED,
	PENDING_DEREGISTRATION
};

#endif