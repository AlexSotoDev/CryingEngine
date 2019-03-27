#include "SceneRegistrationBroker.h"

#include "CommandBase.h"

SceneRegistrationBroker::SceneRegistrationBroker()
{
}

SceneRegistrationBroker::~SceneRegistrationBroker()
{
}

void SceneRegistrationBroker::AddCommand(CommandBase * command)
{
	commandList.push_back(command);
}

void SceneRegistrationBroker::ExecuteCommands()
{
	auto it = commandList.begin();
	
	while (it != commandList.end())
	{
		(*it)->Execute();
		it++;
	}

	commandList.clear();
}
