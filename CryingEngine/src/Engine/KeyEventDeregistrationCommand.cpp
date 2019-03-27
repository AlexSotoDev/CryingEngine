#include "KeyEventDeregistrationCommand.h"

#include "Inputable.h"

KeyEventDeregistrationCommand::KeyEventDeregistrationCommand(Inputable * in, AZUL_KEY key, EVENT_TYPE type)
{
	ptrIn = in;
	myKey = key;
	myType = type;
}

KeyEventDeregistrationCommand::~KeyEventDeregistrationCommand()
{
	ptrIn = nullptr;
}

void KeyEventDeregistrationCommand::Execute()
{
	ptrIn->KeyEventDeregistration(myKey, myType);
}
