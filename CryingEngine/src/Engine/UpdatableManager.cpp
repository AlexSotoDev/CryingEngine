#include "UpdatableManager.h"
#include "Updatable.h"

#include "AzulCore.h"

UpdatableManager::~UpdatableManager()
{
	UpdatableList.clear();
}

void UpdatableManager::Register(Updatable * up)
{
	ref = UpdatableList.insert(UpdatableList.end(), up);
	up->SetIterator(ref);
}

void UpdatableManager::Deregister(Updatable * up)
{
	UpdatableList.erase(up->GetIterator());
}

void UpdatableManager::ProcessElements()
{
	std::list<Updatable*>::iterator it = UpdatableList.begin();

	while (it != UpdatableList.end())
	{
		(*it)->Update();
		it++;
	}
}
