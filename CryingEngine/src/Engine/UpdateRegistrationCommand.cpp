#include "UpdateRegistrationCommand.h"

#include "Updatable.h"

UpdateRegistrationCommand::UpdateRegistrationCommand(Updatable * up)
{
	ptrUp = up;
}

UpdateRegistrationCommand::~UpdateRegistrationCommand()
{
	ptrUp = nullptr;
}

void UpdateRegistrationCommand::Execute()
{
	ptrUp->SceneRegistration();
}
