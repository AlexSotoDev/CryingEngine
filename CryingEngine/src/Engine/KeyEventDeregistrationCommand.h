#ifndef _KeyEventDeregistrationCommand
#define _KeyEventDeregistrationCommand

#include "CommandBase.h"
#include "AzulCore.h"

enum class EVENT_TYPE;
class Inputable;

/**********************************************************************************************//**
 * \class	KeyEventDeregistrationCommand
 *
 * \brief	A key event deregistration command (Command Pattern) inhering from @CommandBase
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class KeyEventDeregistrationCommand : public CommandBase
{
public:

	/**********************************************************************************************//**
	 * \fn	KeyEventDeregistrationCommand::KeyEventDeregistrationCommand(Inputable * in, AZUL_KEY key, EVENT_TYPE type);
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

	KeyEventDeregistrationCommand(Inputable * in, AZUL_KEY key, EVENT_TYPE type);
	~KeyEventDeregistrationCommand();
	KeyEventDeregistrationCommand(const KeyEventDeregistrationCommand&) = delete;
	KeyEventDeregistrationCommand& operator=(const KeyEventDeregistrationCommand&) = delete;

	/**********************************************************************************************//**
	 * \fn	void KeyEventDeregistrationCommand::Execute() override;
	 *
	 * \brief	Executes this object, calling the @Inputable 's KeyEventDeregistration
	 * 			
	 * \sa		Inputable::KeyEventDeregistration
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

#endif // !_KeyEventDeregistrationCommand
