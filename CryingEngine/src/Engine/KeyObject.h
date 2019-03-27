#ifndef _KeyObject
#define _KeyObject

#include "AzulCore.h"
#include <list>

class Inputable;
enum class EVENT_TYPE;

/**********************************************************************************************//**
 * \class	KeyObject
 *
 * \brief	A key object created through an inputable,a key, and a type, with functions for registering/deregistering inputables and maintaining lists of keys/keystates
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class KeyObject
{
public:

	/**********************************************************************************************//**
	 * \fn	KeyObject::KeyObject(Inputable* in, AZUL_KEY k, EVENT_TYPE type);
	 *
	 * \brief	Constructor that gives a Key Object its unique key and registers the inputable
	 * 			
	 * \sa		KeyObject::RegisterInputable
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	in  	If non-null, the inputable.
	 * \param 		  	k   	The AZUL_KEY to process.
	 * \param 		  	type	The type.
	 **************************************************************************************************/

	KeyObject(Inputable* in, AZUL_KEY k, EVENT_TYPE type);
	~KeyObject();
	KeyObject(const KeyObject&) = delete;
	KeyObject& operator=(const KeyObject&) = delete;

	/**********************************************************************************************//**
	 * \fn	AZUL_KEY KeyObject::GetKey()
	 *
	 * \brief	Returns the keyObject's azul key.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \return	The key.
	 **************************************************************************************************/

	AZUL_KEY GetKey() { return key; }

	/**********************************************************************************************//**
	 * \fn	void KeyObject::RegisterInputable(Inputable* in, EVENT_TYPE type);
	 *
	 * \brief	Registers the @Inputable. Called by constructor. Adds inputable to the list of keyPresses or keyReleases depending on the event type.
	 * 			
	 * \sa		KeyObject::KeyObject
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	in  	If non-null, the in.
	 * \param 		  	type	The type.
	 **************************************************************************************************/

	void RegisterInputable(Inputable* in, EVENT_TYPE type);

	/**********************************************************************************************//**
	 * \fn	void KeyObject::DeregisterInputable(Inputable* in, EVENT_TYPE type);
	 *
	 * \brief	Deregisters the @Inputable, removing it from the list of keyPresses or keyReleases depending on the event type.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	in  	If non-null, the inputable.
	 * \param 		  	type	The type.
	 **************************************************************************************************/

	void DeregisterInputable(Inputable* in, EVENT_TYPE type);

	/**********************************************************************************************//**
	 * \fn	void KeyObject::CheckStatus();
	 *
	 * \brief	Checks the status of a given key and appropriately calls the OnKeyPress/OnKeyRelease on the @Inputable if the key state has changed by finding it within the keyPresses/keyReleases list.
	 * 			
	 * \sa		Inputable::OnKeyPress
	 * \sa		Inputable::OnKeyRelease
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void CheckStatus();

private:


	/** \brief	The key */
	AZUL_KEY key;


	/** \brief	The key presses held in an STL List */
	std::list<Inputable*> keyPresses;

	/** \brief	The key releases held in an STL List*/
	std::list<Inputable*> keyReleases;


	/** \brief	Current state of key */
	bool currentState;

	/** \brief	Previous state of key */
	bool previousState;

	


};

#endif // !_KeyObject
