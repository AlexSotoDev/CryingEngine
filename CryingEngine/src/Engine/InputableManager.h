#ifndef _InputableManager
#define _InputableManager

#include "AzulCore.h"

#include <list>

class KeyObject;
class Inputable;
enum class EVENT_TYPE;

/**********************************************************************************************//**
 * \class	InputableManager
 *
 * \brief	Manager for inputables. One per @Scene. Handles registering, deregistering, and ProcessElements() (iterates through list of @KeyObject checks their current status).
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class InputableManager
{
	friend class Scene;

public:
	InputableManager() = default;
	virtual ~InputableManager();
	InputableManager(const InputableManager&) = delete;
	InputableManager& operator=(const InputableManager&) = delete;

	/**********************************************************************************************//**
	 * \fn	void InputableManager::Register(Inputable* in, AZUL_KEY k, EVENT_TYPE type);
	 *
	 * \brief	Creates a @KeyObject if one doesn't already exist for that key and updates the list of key objects, else (it already exists) it registers the inputable along with its type through the @KeyObject
	 *
	 * \sa		KeyObject::RegisterInputable 
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	in  	If non-null, the in.
	 * \param 		  	k   	The AZUL_KEY to process.
	 * \param 		  	type	The type.
	 **************************************************************************************************/

	void Register(Inputable* in, AZUL_KEY k, EVENT_TYPE type);

	/**********************************************************************************************//**
	 * \fn	void InputableManager::Deregister(Inputable* in, AZUL_KEY k, EVENT_TYPE type);
	 *
	 * \brief	Deregisters this object if a @KeyObject exists for the given by calling DeregisterInputable() from the @KeyObject class.
	 *
	 * \sa		KeyObject::DeregisterInputable 
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	in  	If non-null, the in.
	 * \param 		  	k   	The AZUL_KEY to process.
	 * \param 		  	type	The type.
	 **************************************************************************************************/

	void Deregister(Inputable* in, AZUL_KEY k, EVENT_TYPE type);

private:

	/**********************************************************************************************//**
	 * \typedef	std::list<KeyObject*> KeyObjectList
	 *
	 * \brief	Defines an alias representing list of key objects.
	 **************************************************************************************************/
	typedef std::list<KeyObject*> KeyObjectList;

	/** \brief	List of key objects */
	KeyObjectList keyObjectList;


	/** \brief	The storage list reference */
	using StorageListRef = std::list<KeyObject*>::iterator;

	/**********************************************************************************************//**
	 * \property	StorageListRef ref
	 *
	 * \brief	Gets the reference.
	 *
	 * \return	The reference.
	 **************************************************************************************************/

	StorageListRef ref;

	/**********************************************************************************************//**
	 * \fn	KeyObject* InputableManager::GetKeyObject(AZUL_KEY k);
	 *
	 * \brief	Gets key object.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	k	The AZUL_KEY to process.
	 *
	 * \return	Null if it fails, else the key object.
	 **************************************************************************************************/

	KeyObject* GetKeyObject(AZUL_KEY k);

	/**********************************************************************************************//**
	 * \fn	void InputableManager::ProcessElements();
	 *
	 * \brief	Process the elements, calling CheckStatus() on every @KeyObject in the KeyObjectList to see if it is pressed/released or changed its status
	 *
	 * \sa		KeyObject::CheckStatus 
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void ProcessElements();
};

#endif // !_InputableManager
