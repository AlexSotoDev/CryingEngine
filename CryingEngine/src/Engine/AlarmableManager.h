#ifndef _AlarmableManager
#define _AlarmableManager

#include <map>

class Alarmable;
class Scene;

enum class AlarmID;

/**********************************************************************************************//**
 * \class	AlarmableManager
 *
 * \brief	Manager for alarmables, one per @Scene. Handles registering, deregistering and processing elements within our AlarmableList for appropriate iterator spot for a given @Alarmable so that the manager can ProcessElements() (iterate through list and call alarm triggers when timer is up).
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class AlarmableManager
{

	friend class Scene;

public:
	AlarmableManager() = default;
	AlarmableManager(const AlarmableManager&) = delete;
	AlarmableManager& operator = (const AlarmableManager&) = delete;
	~AlarmableManager();

	/**********************************************************************************************//**
	 * \fn	void AlarmableManager::Register(float time, Alarmable* alarm, AlarmID alarmID);
	 *
	 * \brief	Registers an AlarmEvent and inserts into our Alarmable List.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param 		  	time   	The timer for alarm.
	 * \param [in,out]	alarm  	If non-null, the alarm.
	 * \param 		  	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	void Register(float time, Alarmable* alarm, AlarmID alarmID);

	/**********************************************************************************************//**
	 * \fn	void AlarmableManager::Deregister(Alarmable* alarm, AlarmID alarmID);
	 *
	 * \brief	Deregisters an AlarmEvent and erases from our Alarmable List.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	alarm  	If non-null, the alarm.
	 * \param 		  	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	void Deregister(Alarmable* alarm, AlarmID alarmID);

	/**********************************************************************************************//**
	 * \fn	float AlarmableManager::GetRemainingTime(Alarmable* al, AlarmID ID);
	 *
	 * \brief	Gets remaining time on an alarm. Called by a @Scene 's @AlarmableManager.
	 * 			
	 *
	 * \author	Alex
	 * \date	3/13/2017
	 *
	 * \param [in,out]	al	If non-null, the alarmable.
	 * \param 		  	ID	The identifier.
	 *
	 * \return	The remaining time.
	 **************************************************************************************************/

	float GetRemainingTime(Alarmable* al, AlarmID ID);


	/** \brief	The alarm event. Create a pair for an alarm event, which has an integer for its id, the the alarmable itself */
	using AlarmEvent = std::pair<AlarmID, Alarmable*>;


	/** \brief	An multimap iterator for alarmable list reference (which our alarmable list can use), using a map to hold a float for an alarm's timer and an AlarmEvent (ID, Alarmable pointer) */
	using AlarmableListRef = std::multimap<float, AlarmEvent>::iterator;

private:

	/** \brief	Multimap for our of alarms, using their float timer and alarm event to hold data manager needs to perform functions on corresponding alarm*/
	std::multimap<float, AlarmEvent> AlarmableList;

	/**********************************************************************************************//**
	 * \property	AlarmableListRef ref
	 *
	 * \brief	Gets the alarmable list reference.
	 *
	 * \return	The reference.
	 **************************************************************************************************/

	AlarmableListRef ref;

	/**********************************************************************************************//**
	 * \fn	void AlarmableManager::ProcessElements();
	 *
	 * \brief	Iterates through Alarmable List, checking if a given AlarmEvent's timer is up, triggering the current alarm and erasing it from our list.
	 * 			
	 * \sa		Alarmable::TriggerAlarm
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void ProcessElements();

};


#endif // !_AlarmableManager
