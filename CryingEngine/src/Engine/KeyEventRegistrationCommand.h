#ifndef _KeyEventRegistrationCommand
#define _KeyEventRegistrationCommand

#include "AzulCore.h"


#include "CommandBase.h"


class Inputable;
enum class EVENT_TYPE;

/**********************************************************************************************//**
 * \class	KeyEventRegistrationCommand
 *
 * \brief	A key event registration command (Command Pattern) inhering from @CommandBase
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class KeyEventRegistrationCommand : public CommandBase
{

public:

	/**********************************************************************************************//**
	 * \fn	KeyEventRegistrationCommand::KeyEventRegistrationCommand(Inputable * in, AZUL_KEY key, EVENT_TYPE type);
	 *
	 * \brief	Constructor that takes an inputable with a key and type for use in Execute()
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	in  	If non-null, the inputable.
	 * \param 		  	key 	The key.
	 * \param 		  	type	The type.
	 **************************************************************************************************/

	KeyEventRegistrationCommand(Inputable * in, AZUL_KEY key, EVENT_TYPE type);
	~KeyEventRegistrationCommand();
	KeyEventRegistrationCommand(const KeyEventRegistrationCommand&) = delete;
	KeyEventRegistrationCommand& operator=(const KeyEventRegistrationCommand&) = delete;

	/**********************************************************************************************//**
	 * \fn	void KeyEventRegistrationCommand::Execute() override;
	 *
	 * \brief	Executes this object, calling the @Inputable 's KeyEventRegistration
	 * 			
	 * \sa		Inputable::KeyEventRegistration
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void Execute() override;


private:

	Inputable* ptrIn;
	AZUL_KEY myKey;
	EVENT_TYPE myType;
};

#endif // !_KeyEventRegistrationCommand