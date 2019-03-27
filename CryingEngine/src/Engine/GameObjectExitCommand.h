#ifndef _GameObjectExitCommand	
#define _GameObjectExitCommand

#include "CommandBase.h"

class GameObject;

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	GameObjectExitCommand
 *
 * \brief	A game object exit command inheriting from @CommandBase (Command Pattern).
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class GameObjectExitCommand : public CommandBase
{
public:

	/**********************************************************************************************//**
	 * \fn	GameObjectExitCommand::GameObjectExitCommand(GameObject* GO);
	 *
	 * \brief	Constructor that takes a gameObject pointer for use in Execute()
	 * 			
	 * \sa		GameObjectExitCommand::Execute
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	GO	If non-null, the go.
	 **************************************************************************************************/

	GameObjectExitCommand(GameObject* GO);
	GameObjectExitCommand(const GameObjectExitCommand&) = delete;
	GameObjectExitCommand& operator= (const GameObjectExitCommand&) = delete;
	~GameObjectExitCommand();

	/**********************************************************************************************//**
	 * \fn	void GameObjectExitCommand::Execute() override;
	 *
	 * \brief	Executes this object, calling the DisconnectFromScene() function from @GameObject so that the object can deregister from the current scene.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void Execute() override;


private:

	GameObject* ptrGO;
};

#endif // !_UpdateRegistrationCommand

