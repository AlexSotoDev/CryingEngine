#include "Updatable.h"

#include "SceneManager.h"
#include "Scene.h"

#include "UpdateRegistrationCommand.h"
#include "UpdateDeregistrationCommand.h"

#include "EnumRegistrationState.h"

Updatable::Updatable()
{
	registrationCommand = new UpdateRegistrationCommand(this);
	deregistrationCommand = new UpdateDeregistrationCommand(this);
	currentState = RegistrationState::CURRENTLY_DEREGISTERED;
}

Updatable::~Updatable()
{
	delete registrationCommand;
	delete deregistrationCommand;
}

void Updatable::SceneRegistration()
{
	assert(currentState == RegistrationState::PENDING_REGISTRATION);
	SceneManager::GetCurrentScene()->Register(this);
	currentState = RegistrationState::CURRENTLY_REGISTERED;
}

void Updatable::SceneDeregistration()
{
	assert(currentState == RegistrationState::PENDING_DEREGISTRATION);
	SceneManager::GetCurrentScene()->Deregister(this);
	currentState = RegistrationState::CURRENTLY_DEREGISTERED;
}


void Updatable::SubmitUpdateRegistration()
{
	assert(currentState == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneManager::GetCurrentScene()->SubmitCommand(registrationCommand);
	currentState = RegistrationState::PENDING_REGISTRATION;
}

void Updatable::SubmitUpdateDeregistration()
{
	assert(currentState == RegistrationState::CURRENTLY_REGISTERED);
	SceneManager::GetCurrentScene()->SubmitCommand(deregistrationCommand);
	currentState = RegistrationState::PENDING_DEREGISTRATION;
}

void Updatable::SetIterator(UpdatableManager::UpdatableListRef ref)
{
	myRef = ref;
}

UpdatableManager::UpdatableListRef Updatable::GetIterator()
{
	return myRef;
}
