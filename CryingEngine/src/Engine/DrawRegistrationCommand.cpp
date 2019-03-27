#include "DrawRegistrationCommand.h"

#include "Drawable.h"

DrawRegistrationCommand::DrawRegistrationCommand(Drawable * draw)
{
	ptrDraw = draw;
}

DrawRegistrationCommand::~DrawRegistrationCommand()
{
	ptrDraw = nullptr;
}

void DrawRegistrationCommand::Execute()
{
	ptrDraw->SceneRegistration();
}
