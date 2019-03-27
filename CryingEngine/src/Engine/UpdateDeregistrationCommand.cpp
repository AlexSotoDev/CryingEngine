#include "UpdateDeregistrationCommand.h"

#include "Updatable.h"

UpdateDeregistrationCommand::UpdateDeregistrationCommand(Updatable * up)
{
	ptrUp = up;
}

UpdateDeregistrationCommand::~UpdateDeregistrationCommand()
{
	ptrUp = nullptr;
}

void UpdateDeregistrationCommand::Execute()
{
	ptrUp->SceneDeregistration();
}
