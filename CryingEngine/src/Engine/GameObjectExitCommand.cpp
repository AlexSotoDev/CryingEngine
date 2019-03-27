#include "GameObjectExitCommand.h"

#include "GameObject.h"

GameObjectExitCommand::GameObjectExitCommand(GameObject * GO)
{
	ptrGO = GO;
}

GameObjectExitCommand::~GameObjectExitCommand()
{
	ptrGO = nullptr;
}

void GameObjectExitCommand::Execute()
{
	ptrGO->DisconnectFromScene();
}
