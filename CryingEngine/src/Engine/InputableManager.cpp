#include "InputableManager.h"

#include "KeyObject.h"

InputableManager::~InputableManager()
{
	for (auto it = keyObjectList.begin(); it != keyObjectList.end(); ++it)
	{
		delete *it;
	}

	keyObjectList.clear();
}

void InputableManager::Register(Inputable * in, AZUL_KEY k, EVENT_TYPE type)
{
	KeyObject* obj = GetKeyObject(k);
	if (obj == nullptr)
	{
		obj = new KeyObject(in, k, type);
		keyObjectList.push_back(obj);
	}
	else
	{
		obj->RegisterInputable(in, type);
	}
}

void InputableManager::Deregister(Inputable * in, AZUL_KEY k, EVENT_TYPE type)
{
	if (GetKeyObject(k) != nullptr)
	{
		GetKeyObject(k)->DeregisterInputable(in, type);
	}
}

KeyObject * InputableManager::GetKeyObject(AZUL_KEY k)
{
	for (auto it = keyObjectList.begin(); it != keyObjectList.end(); ++it)
	{
		if ((*it)->GetKey() == k)
		{
			return *it;
		}
	}
	return nullptr;
}

void InputableManager::ProcessElements()
{
	for (auto it = keyObjectList.begin(); it != keyObjectList.end(); ++it)
	{
		(*it)->CheckStatus();
	}
}