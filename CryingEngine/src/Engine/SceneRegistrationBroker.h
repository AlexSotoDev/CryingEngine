#ifndef _SceneRegistrationBroker
#define _SceneRegistrationBroker

#include <list>

class CommandBase;

/**********************************************************************************************//**
 * \class	SceneRegistrationBroker
 *
 * \brief	A scene registration broker for adding/maintaining a list of commands and executing them
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class SceneRegistrationBroker
{
public: 

	SceneRegistrationBroker();
	SceneRegistrationBroker(const SceneRegistrationBroker&) = delete;
	SceneRegistrationBroker& operator = (const SceneRegistrationBroker&) = delete;
	~SceneRegistrationBroker();

	/**********************************************************************************************//**
	 * \fn	void SceneRegistrationBroker::AddCommand(CommandBase* command);
	 *
	 * \brief	Adds a command.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	command	If non-null, the command.
	 **************************************************************************************************/

	void AddCommand(CommandBase* command);

	/**********************************************************************************************//**
	 * \fn	void SceneRegistrationBroker::ExecuteCommands();
	 *
	 * \brief	Executes the commands operation.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void ExecuteCommands();


private:

	/** \brief	List of commands */
	std::list<CommandBase*> commandList;

};


#endif