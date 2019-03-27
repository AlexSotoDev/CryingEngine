#ifndef _UpdatableManager
#define _UpdatableManager

#include <list>

class Updatable;
class Scene;

/**********************************************************************************************//**
 * \class	UpdatableManager
 *
 * \brief	Manager for updatables, one per @Scene. Handles registering, deregistering and processing elements within our UpdatableList for appropriate iterator spot for a given @Updatable so that the manager can ProcessElements() (iterate through list and call Update() on each @GameObject that has it).
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class UpdatableManager
{

	friend class Scene;

public:
	UpdatableManager() = default;
	UpdatableManager(const UpdatableManager&) = delete;
	UpdatableManager& operator = (const UpdatableManager&) = delete;
	~UpdatableManager();

	/**********************************************************************************************//**
	 * \fn	void UpdatableManager::Register(Updatable* draw);
	 *
	 * \brief	Registers the @Updatable to our UpdatableList and sets the iterator at the corresponding place to reference it within the list.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	draw	If non-null, the drawable.
	 **************************************************************************************************/
	void Register(Updatable* draw);

	/**********************************************************************************************//**
	 * \fn	void UpdatableManager::Deregister(Updatable* draw);
	 *
	 * \brief	Deregisters the @Updatable to our UpdatableList and erases it from our UpdatableList
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	draw	If non-null, the draw.
	 **************************************************************************************************/

	void Deregister(Updatable* draw);


	/** \brief	The iterator updatable list reference */
	using UpdatableListRef = std::list<Updatable*>::iterator;

private:

	/** \brief	List of updatables */
	std::list<Updatable*> UpdatableList;

	UpdatableListRef ref;

	/**********************************************************************************************//**
	 * \fn	void UpdatableManager::ProcessElements();
	 *
	 * \brief	Process the elements, goes through our list of @Updatable and calls Update on them
	 * 			
	 * \sa		Updatable::Update
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void ProcessElements();

};


#endif // !_UpdatableManager
