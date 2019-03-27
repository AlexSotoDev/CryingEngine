#include "KeyEventRegistrationCommand.h"

#include "Inputable.h"

KeyEventRegistrationCommand::KeyEventRegistrationCommand(Inputable * in, AZUL_KEY key, EVENT_TYPE type)
{
	ptrIn = in;
	myKey = key;
	myType = type;
}

KeyEventRegistrationCommand::~KeyEventRegistrationCommand()
{
	ptrIn = nullptr;
}

void KeyEventRegistrationCommand::Execute()
{
	ptrIn->KeyEventRegistration(myKey, myType);
}
