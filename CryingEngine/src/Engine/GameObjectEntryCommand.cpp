#include "GameObjectEntryCommand.h"

#include "GameObject.h"

GameObjectEntryCommand::GameObjectEntryCommand(GameObject * GO)
{
	ptrGO = GO;
}

GameObjectEntryCommand::~GameObjectEntryCommand()
{
	ptrGO = nullptr;
}

void GameObjectEntryCommand::Execute()
{
	ptrGO->ConnectToScene();
}
