#include "KeyObject.h"

#include "EnumEventType.h"	
#include "Inputable.h"

KeyObject::KeyObject(Inputable * in, AZUL_KEY k, EVENT_TYPE type) 
{
	key = k;
	RegisterInputable(in, type);
}

KeyObject::~KeyObject()
{

}

void KeyObject::RegisterInputable(Inputable * in, EVENT_TYPE type)
{
	switch (type)
	{
	case(EVENT_TYPE::KEY_PRESS):
		keyPresses.push_back(in);
		break;

	case(EVENT_TYPE::KEY_RELEASE):
		keyReleases.push_back(in);
		break;

	default:
		break;
	}
}

void KeyObject::DeregisterInputable(Inputable * in, EVENT_TYPE type)
{
	switch (type)
	{
	case(EVENT_TYPE::KEY_PRESS):
		keyPresses.remove(in);
		break;
	case(EVENT_TYPE::KEY_RELEASE):
		keyReleases.remove(in);
		break;
	default:
		break;
	}
}

void KeyObject::CheckStatus()
{
	currentState = Keyboard::GetKeyState(key);

	if (currentState == true && previousState == false)
	{
		//Key press is happening
		//Last frame no key press

		std::list<Inputable*>::iterator it;
		it = keyPresses.begin();
		while (it != keyPresses.end())
		{
			(*it)->OnKeyPress(key);
			it++;
		}
	}
	else if (currentState == false && previousState == true)
	{
		std::list<Inputable*>::iterator it;
		it = keyReleases.begin();
		while (it != keyReleases.end())
		{
			(*it)->OnKeyRelease(key);
			it++;
		}
	}

	previousState = currentState;
}