#include "GameObject.h"

#include "GameObjectEntryCommand.h"
#include "GameObjectExitCommand.h"

#include "AzulCore.h"
#include "SceneManager.h"

#include "EnumRegistrationState.h"

GameObject::GameObject()
{
	registrationCommand = new GameObjectEntryCommand(this);
	deregistrationCommand = new GameObjectExitCommand(this);
	
	currentState = RegistrationState::CURRENTLY_DEREGISTERED;
}

GameObject::~GameObject()
{
	delete registrationCommand;
	delete deregistrationCommand;
}

void GameObject::SubmitEntry()
{
	assert(currentState == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneManager::GetCurrentScene()->SubmitCommand(registrationCommand);
	currentState = RegistrationState::PENDING_REGISTRATION;
}

void GameObject::SubmitExit()
{
	assert(currentState == RegistrationState::CURRENTLY_REGISTERED);
	SceneManager::GetCurrentScene()->SubmitCommand(deregistrationCommand);
	currentState = RegistrationState::PENDING_DEREGISTRATION;
}

void GameObject::ConnectToScene()
{
	assert(currentState == RegistrationState::PENDING_REGISTRATION);
	SceneManager::GetCurrentScene()->Register(this);
	currentState = RegistrationState::CURRENTLY_REGISTERED;
}

void GameObject::DisconnectFromScene()
{
	assert(currentState == RegistrationState::PENDING_DEREGISTRATION);
	SceneManager::GetCurrentScene()->Deregister(this);
	currentState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void GameObject::SceneEntry()
{
}

void GameObject::SceneExit()
{
}
