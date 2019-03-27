#include "Drawable.h"

#include "SceneManager.h"

#include "DrawRegistrationCommand.h"
#include "DrawDeregistrationCommand.h"

#include "EnumRegistrationState.h"

Drawable::Drawable()
{
	registrationCommand = new DrawRegistrationCommand(this);
	deregistrationCommand = new DrawDeregistrationCommand(this);
	currentState = RegistrationState::CURRENTLY_DEREGISTERED;
}

Drawable::~Drawable()
{
	delete registrationCommand;
	delete deregistrationCommand;
}

void Drawable::SceneRegistration()
{
	assert(currentState == RegistrationState::PENDING_REGISTRATION);
	SceneManager::GetCurrentScene()->Register(this);
	currentState = RegistrationState::CURRENTLY_REGISTERED;
}

void Drawable::SceneDeregistration()
{
	assert(currentState == RegistrationState::PENDING_DEREGISTRATION);
	SceneManager::GetCurrentScene()->Deregister(this);
	currentState = RegistrationState::CURRENTLY_DEREGISTERED;
}

void Drawable::SubmitDrawRegistration()
{
	assert(currentState == RegistrationState::CURRENTLY_DEREGISTERED);
	SceneManager::GetCurrentScene()->SubmitCommand(registrationCommand);
	currentState = RegistrationState::PENDING_REGISTRATION;
	
}

void Drawable::SubmitDrawDeregistration()
{
	assert(currentState == RegistrationState::CURRENTLY_REGISTERED);
	SceneManager::GetCurrentScene()->SubmitCommand(deregistrationCommand);
	currentState = RegistrationState::PENDING_DEREGISTRATION;
}

void Drawable::SetIterator(DrawableManager::DrawableListRef ref)
{
	myRef = ref;
}

DrawableManager::DrawableListRef Drawable::GetIterator()
{
	return myRef;
}
