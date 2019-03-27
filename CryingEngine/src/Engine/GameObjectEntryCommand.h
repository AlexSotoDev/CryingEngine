#ifndef _GameObjectEntryCommand
#define _GameObjectEntryCommand

#include "CommandBase.h"

class GameObject;

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	GameObjectEntryCommand
 *
 * \brief	A game object entry command inheriting from @CommandBase (Command Pattern).
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class GameObjectEntryCommand : public CommandBase
{
	

public:

	/**********************************************************************************************//**
	 * \fn	GameObjectEntryCommand::GameObjectEntryCommand(GameObject* GO);
	 *
	 * \brief	Constructor that takes a gameObject pointer for use in Execute()
	 * 			
	 * \sa		GameObjectEntryCommand::Execute
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	GO	If non-null, the game object.
	 **************************************************************************************************/

	GameObjectEntryCommand(GameObject* GO);
	GameObjectEntryCommand(const GameObjectEntryCommand&) = delete;
	GameObjectEntryCommand& operator= (const GameObjectEntryCommand&) = delete;
	~GameObjectEntryCommand();

	/**********************************************************************************************//**
	 * \fn	void GameObjectEntryCommand::Execute() override;
	 *
	 * \brief	Executes this object, calling the ConnectToScene() function from @GameObject so that the object can register to the current scene.
	 * 			
	 * \sa		GameObject::ConnectToScene
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void Execute() override;


private:

	GameObject* ptrGO;
};

#endif // !_GameObjectEntryCommand
