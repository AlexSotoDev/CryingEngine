#include "DrawDeregistrationCommand.h"

#include "Drawable.h"

DrawDeregistrationCommand::DrawDeregistrationCommand(Drawable * draw)
{
	ptrDraw = draw;
}

DrawDeregistrationCommand::~DrawDeregistrationCommand()
{
	ptrDraw = nullptr;
}

void DrawDeregistrationCommand::Execute()
{
	ptrDraw->SceneDeregistration();
}
