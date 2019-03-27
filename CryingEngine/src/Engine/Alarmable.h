#ifndef _Alarmable
#define _Alarmable

#include "GameObject.h"
#include "AlarmableManager.h"


class AlarmRegistrationCommand;
class AlarmDeregistrationCommand;

enum class RegistrationState;
enum class AlarmID;

/**********************************************************************************************//**
 * \class	Alarmable
 *
 * \brief	An alarmable class to be put on desired game objects (through virtual inheritance) that use alarms. Uses command pattern for registration/deregistration(@AlarmRegistrationCommand , @AlarmDeregistrationCommand).
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class Alarmable : public virtual GameObject
{
	friend class AlarmableManager;
	friend class AlarmRegistrationCommand;
	friend class AlarmDeregistrationCommand;

public:

	/**********************************************************************************************//**
	 * \fn	Alarmable::Alarmable();
	 *
	 * \brief	Default constructor, which takes our number of alarms and creates a struct of RegistrationData for each, allowing us to use x number of alarms on an alarmable game object.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	Alarmable();
	virtual ~Alarmable();
	Alarmable(const Alarmable&) = delete; //overload copy constructor
	Alarmable& operator=(const Alarmable&) = delete;

	/**********************************************************************************************//**
	 * \fn	void Alarmable::SubmitAlarmRegistration(float timer, AlarmID alarmID);
	 *
	 * \brief	Submit alarm registration. Will check to make sure the alarm is currently in the correct Registration state before updating the corresponding RegData[i] using the ID and updating the timer.Then calls the Submit command on the scene using the ID to register to current scene.
	 *
	 * \sa		Scene::Register 
	 * 
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	timer  	The timer.
	 * \param	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	void SubmitAlarmRegistration(float timer, AlarmID alarmID);

	/**********************************************************************************************//**
	 * \fn	void Alarmable::SubmitAlarmDeregistration(AlarmID alarmID);
	 *
	 * \brief	Submit alarm registration. Will check to make sure the alarm is currently in the correct Registration state before updating the corresponding RegData[i] using the ID.Then calls the Submit command on the scene using the ID to deregister from current scene.
	 *
	 * \sa		Scene::Deregister
	 * 
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	void SubmitAlarmDeregistration(AlarmID alarmID);

	/**********************************************************************************************//**
	 * \fn	float Alarmable::GetTime(AlarmID alarmID);
	 *
	 * \brief	Gets the timer (as a float in seconds) from a given alarm using its ID as parameters.
	 *
	 * 
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	alarmID	Identifier for the alarm.
	 *
	 * \return	The time.
	 **************************************************************************************************/

	float GetTime(AlarmID alarmID);





private:

	/**********************************************************************************************//**
	 * \fn	void Alarmable::SetIterator(AlarmableManager::AlarmableListRef ref, AlarmID alarmID);
	 *
	 * \brief	Sets an iterator within the regData for @AlarmableManager to use when calling its manager functions the @Alarmable list (reg, dereg, process) so that it doesn't have to iterate through entire list to find correct @Alarmable and update its list.
	 *
	 * \sa		Alarmable::GetIterator
	 * 
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	ref	   	The reference.
	 * \param	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	void SetIterator(AlarmableManager::AlarmableListRef ref, AlarmID alarmID);

	/**********************************************************************************************//**
	 * \fn	AlarmableManager::AlarmableListRef Alarmable::GetIterator(AlarmID alarmID);
	 *
	 * \brief	Gets the iterator from regData for @AlarmableManager to use for its manager functions on the @Alarmable list (reg, dereg, process) saving on searching through the entire list.
	 * 			
	 * \sa		Alarmable::SetIterator
	 * 
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	alarmID	Identifier for the alarm.
	 *
	 * \return	The iterator.
	 **************************************************************************************************/

	AlarmableManager::AlarmableListRef GetIterator(AlarmID alarmID);

	/**********************************************************************************************//**
	 * \fn	virtual void Alarmable::TriggerAlarm(AlarmID alarmID);
	 *
	 * \brief	Virtual function for user to override for what happens when the corresponding alarm is triggered on a @GameObject. Called when timer coniditon is met when processing elements in @AlarmableManager.
	 * 			
	 * \sa		AlarmableManager::ProcessElements
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	virtual void TriggerAlarm(AlarmID alarmID);

	/**********************************************************************************************//**
	 * \struct	RegistrationData
	 *
	 * \brief	Holds data members for each alarm, including a listref (iterator), registration state, reg/dereg commands, alarmID, and a time/timer.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	struct RegistrationData
	{
		AlarmableManager::AlarmableListRef myRef;
		RegistrationState currentState;

		AlarmRegistrationCommand* registrationCommand;
		AlarmDeregistrationCommand* deregistrationCommand;

		AlarmID myAlarmID;
		float time;
	};



	/** \brief	Number of alarms per game object. Can be changed if we wish to have more alarms available per @GameObject, but extra virtual functions required for user to override/make the extra alarms usable Alarm*/
	static const int numberOfAlarms = 4;


	/** \brief	The number of register data[number of alarms] needed, using an array of size number of alarms*/
	RegistrationData RegData[numberOfAlarms];

	/**********************************************************************************************//**
	 * \fn	virtual void Alarmable::Alarm0()
	 *
	 * \brief	Alarm 0 for the given alarmable object (@GameObject). One per each alarm available on a @GameObject (void Alarm0, Alarm1, Alarm2, etc)
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	virtual void Alarm0() {};
	virtual void Alarm1() {};
	virtual void Alarm2() {};
	virtual void Alarm3() {};

	/**********************************************************************************************//**
	 * \fn	void Alarmable::SceneRegistration(float timer, AlarmID alarmID);
	 *
	 * \brief	Registers an alarm to the scene using its timer and ID. Calls the corresponding overloaded Register() function within @Scene. View @Scene 's Update() to see how @AlarmableManager and @SceneRegistrationBroker handle submission/registration/deregistration.
	 * 			
	 * \sa		Alarmable::SubmitSceneRegistration
	 * 			
	 * \sa		Scene::Register
	 * \sa		Scene::Update
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	timer  	The timer.
	 * \param	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	void SceneRegistration(float timer, AlarmID alarmID);

	/**********************************************************************************************//**
	 * \fn	void Alarmable::SceneDeregistration(AlarmID alarmID);
	 *
	 * \brief	Deregisters an alarm from the scene using its ID. Calls the corresponding overloaded Deregister() function within @Scene. View @Scene 's Update() to see how @AlarmableManager and @SceneRegistrationBroker handle submission/registration/deregistration.
	 *
	 * \sa		Scene::Deregister
	 * \sa		Scene::Update
	 * 
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	void SceneDeregistration(AlarmID alarmID);
};

#endif // !Updatable

