#ifndef _GameObject
#define _GameObject

class GameObjectEntryCommand;
class GameObjectExitCommand;

enum class RegistrationState;

/**********************************************************************************************//**
 * \class	GameObject
 *
 * \brief	A game object class that serves as a base class for most objects in a game engine that have commonly desired functionality such as Alarms, Collision, Draw, Input, Update ( @Alarmable , @Collidable , @Drawable , @Inputable , @Updatable ).
 *			NOTE: Game Objects do not/should not be created as type @GameObject. Instead create your own class and make it inherit from the desired class you want functionality of (ex: class UserObject: public Drawable, public Updatable, public Align16). Align16 is to put obj aligned in memory.
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class GameObject
{

	friend class Scene;
	friend class GameObjectEntryCommand;
	friend class GameObjectExitCommand;

public:

	/**********************************************************************************************//**
	 * \fn	GameObject::GameObject();
	 *
	 * \brief	Default constructor, setting up the @GameObjectEntryCommand and @GameObjectExitCommand for this object.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	GameObject();
	virtual ~GameObject();
	GameObject(const GameObject&) = delete; //overload copy constructor
	GameObject& operator=(const GameObject&) = delete;

	/**********************************************************************************************//**
	 * \fn	void GameObject::SubmitEntry();
	 *
	 * \brief	Public accessor to submit command to register/enter scene using the object's @GameObjectEntryCommand
	 * 			
	 * \sa		Scene::SubmitCommand	
	 * \sa		GameObject::ConnectToScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void SubmitEntry();

	/**********************************************************************************************//**
	 * \fn	void GameObject::SubmitExit();
	 *
	 * \brief	Public accessor to submit command to deregister/disconnect from scene using the object's @GameObjectExitCommand
	 * 			
	 * \sa		Scene::SubmitCommand
	 * \sa		GameObject::DisconnectFromScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void SubmitExit();


private:


	/** \brief	The current registration state */
	RegistrationState currentState;

	/**********************************************************************************************//**
	 * \fn	void GameObject::ConnectToScene();
	 *
	 * \brief	Connect/registers this @GameObject to scene. Called by public accessor function
	 * 			
	 * \sa		GameObject::SubmitEntry
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void ConnectToScene();

	/**********************************************************************************************//**
	 * \fn	void GameObject::DisconnectFromScene();
	 *
	 * \brief	Disconnects/deregisters this @GameObject from scene. Called by public accessor function
	 * 			
	 * \sa		GameObject::SubmitExit
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void DisconnectFromScene();

	/**********************************************************************************************//**
	 * \fn	virtual void GameObject::SceneEntry();
	 *
	 * \brief	Defines behavior on object entering the scene. Overridden by user for desired behavior. Called in scene's register for @GameObject.
	 * 			
	 * \sa		Scene::Register
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	virtual void SceneEntry();

	/**********************************************************************************************//**
	 * \fn	virtual void GameObject::SceneExit();
	 *
	 * \brief	Defines behavior on object entering the scene. Overridden by user for desired behavior. Called in scene's deregister for @GameObject.
	 * 			
	 * \sa		Scene::Deregister
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	virtual void SceneExit();


	/** \brief	The registration command */
	GameObjectEntryCommand* registrationCommand;

	/** \brief	The deregistration command */
	GameObjectExitCommand* deregistrationCommand;

};

#endif
