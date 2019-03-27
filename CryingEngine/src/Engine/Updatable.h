#ifndef _Updatable
#define _Updatable

#include "GameObject.h"
#include "UpdatableManager.h"

class UpdateRegistrationCommand;
class UpdateDeregistrationCommand;

/**********************************************************************************************//**
 * \class	Updatable
 *
 * \brief	An @Updatable class to be put on desired game objects (through virtual inheritance) that need an Update() function. Uses command pattern for registration/deregistration (@UpdateRegistrationCommand , @UpdateDeregistrationCommand).
 * 			
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class Updatable : public virtual GameObject
{
	friend class UpdatableManager;
	friend class UpdateRegistrationCommand;
	friend class UpdateDeregistrationCommand;

public:

	/**********************************************************************************************//**
	 * \fn	Updatable::Updatable();
	 *
	 * \brief	Default constructor, which gives our @Updatable a registration and deregistration command
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	Updatable();
	virtual ~Updatable();
	Updatable(const Updatable&) = delete; //overload copy constructor
	Updatable& operator=(const Updatable&) = delete;

	// To be defined/overriden by user. 

	/**********************************************************************************************//**
	 * \fn	virtual void Updatable::Update()
	 *
	 * \brief	Updates this object. To be overridden/defined by the user for desired behavior
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	virtual void Update() {};

	/**********************************************************************************************//**
	 * \fn	void Updatable::SubmitUpdateRegistration();
	 *
	 * \brief	Public accessor function to submit update registration. Will check to make sure Reg State is in correct state before submitting the regCommand to the current scene and updating the state. 
	 *
	 * \sa		Updatable::UpdateRegistration
	 * 
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void SubmitUpdateRegistration();

	/**********************************************************************************************//**
	 * \fn	void Updatable::SubmitUpdateDeregistration();
	 *
	 * \brief	Public accessor function to submit update deregistration. Will check to make sure reg state is in correct state before submitting the deregCommand to the current scene and updating the state.
	 *
	 * \sa		Updatable::UpdateDeregistration
	 * 
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void SubmitUpdateDeregistration();


	/** \brief	my iterator reference */
	UpdatableManager::UpdatableListRef myRef;



private:

	/**********************************************************************************************//**
	 * \fn	void Updatable::SceneRegistration();
	 *
	 * \brief	Scene registration.  Calls the corresponding overloaded Register() function within @Scene. View @Scene 's Update() to see how @UpdatableManager and @SceneRegistrationBroker handle submission/registration/deregistration.
	 *
	 * \sa		Scene::Register
	 * \sa		Scene::Update
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void SceneRegistration();

	/**********************************************************************************************//**
	 * \fn	void Updatable::SceneDeregistration();
	 *
	 * \brief	Scene deregistration. Calls the corresponding overloaded Deregister() function within @Scene. View @Scene 's Update() to see how @UpdatableManager and @SceneRegistrationBroker handle submission/registration/deregistration.
	 *
	 * \sa		Scene::Deregister
	 * \sa		Scene::Update
	 * 
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void SceneDeregistration();


	/** \brief	The registration command */
	UpdateRegistrationCommand* registrationCommand;

	/** \brief	The deregistration command */
	UpdateDeregistrationCommand* deregistrationCommand;


	/** \brief	The current registration state */
	RegistrationState currentState;

	/**********************************************************************************************//**
	 * \fn	void Updatable::SetIterator(UpdatableManager::UpdatableListRef ref);
	 *
	 * \brief	Sets an iterator for. @UpdatableManager uses the GetIterator() when calling its manager functions on the @Updatable list (reg, dereg, process) so that it doesn't have to iterate through entire list each time to find correct element.
	 *
	 * \sa		Updatable::GetIterator
	 * 
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	ref	The reference.
	 **************************************************************************************************/

	void SetIterator(UpdatableManager::UpdatableListRef ref);

	/**********************************************************************************************//**
	 * \fn	UpdatableManager::UpdatableListRef Updatable::GetIterator();
	 *
	 * \brief	Gets the iterator for @UpdatableManager to use when calling its manager functions on the @Updatable list.
	 *
	 * \sa		Updatable::SetIterator
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \return	The iterator.
	 **************************************************************************************************/

	UpdatableManager::UpdatableListRef GetIterator();



};

#endif // !Updatable
