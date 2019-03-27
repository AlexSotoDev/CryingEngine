#ifndef _Drawable
#define _Drawable

#include "GameObject.h"

#include "DrawableManager.h"

class DrawRegistrationCommand;
class DrawDeregistrationCommand;

enum class RegistrationState;

/**********************************************************************************************//**
 * \class	Drawable
 *
 * \brief	A drawable class to be put on desired game objects (through virtual inheritance) that need to be drawn/have a draw function. Uses command pattern for registration/deregistration (@DrawRegistrationCommand , @DrawDeregistrationCommand).
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class Drawable : public virtual GameObject
{
	friend class DrawableManager;
	friend class DrawRegistrationCommand;
	friend class DrawDeregistrationCommand;

public:

	/**********************************************************************************************//**
	 * \fn	Drawable::Drawable();
	 *
	 * \brief	Default constructor that creates a reg/dereg command and registration state for the drawable
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	Drawable();
	virtual ~Drawable();
	Drawable(const Drawable&) = delete; //overload copy constructor
	Drawable& operator=(const Drawable&) = delete;

	//To be defined/overriden by user

	/**********************************************************************************************//**
	 * \fn	virtual void Drawable::Draw()
	 *
	 * \brief	Draws this object, overriden by user for drawing a 3D graphics object on their @GameObject Draw() function. 3D Draw called before 2D.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	virtual void Draw() {}

	/**********************************************************************************************//**
	 * \fn	virtual void Drawable::Draw2D()
	 *
	 * \brief	Draw 2D objects, overriden by user for drawing a 2D graphics object on their @GameObject. 2D Draw called after 3D.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	virtual void Draw2D() {}

	/**********************************************************************************************//**
	 * \fn	void Drawable::SubmitDrawRegistration();
	 *
	 * \brief	Submit draw registration. Will check to make sure the drawable is currently in the correct Registration state before calling the Submit command on the scene using the regCommand for the Drawable
	 * 		
	 * \sa		Drawable::SceneRegistration	
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void SubmitDrawRegistration();

	/**********************************************************************************************//**
	 * \fn	void Drawable::SubmitDrawDeregistration();
	 *
	 * \brief	Submit draw Deregistration. Will check to make sure the drawable is currently in the correct Registration state before calling the Submit command on the scene using the DeregCommand for the Drawable
	 *
	 * \sa		Drawable::SceneDeregistration
	 * 			
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void SubmitDrawDeregistration();


	/** \brief	my iterator reference within the DrawableList  */
	DrawableManager::DrawableListRef myRef;

private:

	/**********************************************************************************************//**
	 * \fn	void Drawable::SceneRegistration();
	 *
	 * \brief	Registers the drawable to the scene. Calls the corresponding overloaded Register() function within @Scene. View @Scene 's Update() to see how @DrawableManager and @SceneRegistrationBroker handle submission/registration/deregistration.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void SceneRegistration();

	/**********************************************************************************************//**
	 * \fn	void Drawable::SceneDeregistration();
	 *
	 * \brief	Deregisters the drawable to the scene. Calls the corresponding overloaded Deregister() function within @Scene. View @Scene 's Update() to see how @DrawableManager and @SceneRegistrationBroker handle submission/registration/deregistration.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void SceneDeregistration();


	/** \brief	The registration command */
	DrawRegistrationCommand* registrationCommand;

	/** \brief	The deregistration command */
	DrawDeregistrationCommand* deregistrationCommand;

	/**********************************************************************************************//**
	 * \fn	void Drawable::SetIterator(DrawableManager::DrawableListRef ref);
	 *
	 * \brief	Sets an iterator within the drawable list ref of the @DrawableManager
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	ref	The reference.
	 **************************************************************************************************/

	void SetIterator(DrawableManager::DrawableListRef ref);

	/**********************************************************************************************//**
	 * \fn	DrawableManager::DrawableListRef Drawable::GetIterator();
	 *
	 * \brief	Gets the iterator reference point from within the @DrawableManager
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \return	The iterator.
	 **************************************************************************************************/

	DrawableManager::DrawableListRef GetIterator();


	RegistrationState currentState;
};

#endif // !Drawable

