#ifndef _Inputable
#define _Inputable

#include "AzulCore.h"

#include "GameObject.h"

enum class EVENT_TYPE;

class KeyEventRegistrationCommand;
class KeyEventDeregistrationCommand;

/**********************************************************************************************//**
 * \class	Inputable
 *
 * \brief	An inputable class to be put on desired game objects (through virtual inheritance) that use inputs. Uses command pattern for registration/deregistration((@KeyEventRegistrationCommand , @KeyEventDeregistrationCommand).
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class Inputable : public GameObject
{
	friend class KeyEventRegistrationCommand;
	friend class KeyEventDeregistrationCommand;

public:

	Inputable() {};
	virtual ~Inputable();
	Inputable(const Inputable&) = delete;
	Inputable& operator=(const Inputable&) = delete;

	/**********************************************************************************************//**
	 * \fn	virtual void Inputable::SubmitKeyEventRegistration(AZUL_KEY k, EVENT_TYPE type);
	 *
	 * \brief	Submit key event registration for a given key with an event type. To be overridden by user on a @GameObject that is @Inputable to register inputs. Calls equivalent private dereg function.
	 *
	 * \sa		Inputable::KeyEventRegistration
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	k   	The AZUL_KEY to process.
	 * \param	type	The type of key event.
	 **************************************************************************************************/

	virtual void SubmitKeyEventRegistration(AZUL_KEY k, EVENT_TYPE type);

	/**********************************************************************************************//**
	 * \fn	virtual void Inputable::SubmitKeyEventDeregistration(AZUL_KEY k, EVENT_TYPE type);
	 *
	 * \brief	Submit key event deregistration for a given key with an event type. To be overridden by user on a @GameObject that is @Inputable to deregister inputs. Calls equivalent private dereg function.
	 *
	 * \sa		Inputable::KeyEventDeregistration 
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	k   	The AZUL_KEY to process.
	 * \param	type	The type.
	 **************************************************************************************************/

	virtual void SubmitKeyEventDeregistration(AZUL_KEY k, EVENT_TYPE type);

	/**********************************************************************************************//**
	 * \fn	virtual void Inputable::OnKeyPress(AZUL_KEY k);
	 *
	 * \brief	Executes the key press action. User overrides function for desired functionality.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	k	The AZUL_KEY to process.
	 **************************************************************************************************/

	virtual void OnKeyPress(AZUL_KEY k);

	/**********************************************************************************************//**
	 * \fn	virtual void Inputable::OnKeyRelease(AZUL_KEY k);
	 *
	 * \brief	Executes the key release action. User overrides function for desired functionality.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	k	The AZUL_KEY to process.
	 **************************************************************************************************/

	virtual void OnKeyRelease(AZUL_KEY k);

private:

	/**********************************************************************************************//**
	 * \fn	virtual void Inputable::KeyEventRegistration(AZUL_KEY k, EVENT_TYPE type);
	 *
	 * \brief	Key event registration. Called by equivalent submit function.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	k   	The AZUL_KEY to process.
	 * \param	type	The event type.
	 **************************************************************************************************/

	virtual void KeyEventRegistration(AZUL_KEY k, EVENT_TYPE type);

	/**********************************************************************************************//**
	 * \fn	virtual void Inputable::KeyEventDeregistration(AZUL_KEY k, EVENT_TYPE type);
	 *
	 * \brief	Key event deregistration. Called by equivalent submit function
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	k   	The AZUL_KEY to process.
	 * \param	type	The event type.
	 **************************************************************************************************/

	virtual void KeyEventDeregistration(AZUL_KEY k, EVENT_TYPE type);

	KeyEventRegistrationCommand* registrationCommand;
	KeyEventDeregistrationCommand* deregistrationCommand;


};

#endif // !_Inputable
