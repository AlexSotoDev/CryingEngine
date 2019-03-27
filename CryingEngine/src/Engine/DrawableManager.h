#ifndef _DrawableManager
#define _DrawableManager

#include <list>

class Drawable;
class Scene;

/**********************************************************************************************//**
 * \class	DrawableManager
 *
 * \brief	Manager for drawables, one per @Scene. Handles registering, deregistering and processing elements within our DrawableList for appropriate iterator spot for a given @Drawable so that the manager can ProcessElements() (iterate through list and call draw).
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class DrawableManager
{

	friend class Scene;

public:
	DrawableManager() = default;
	DrawableManager(const DrawableManager&) = delete;
	DrawableManager& operator = (const DrawableManager&) = delete;
	~DrawableManager();

	/**********************************************************************************************//**
	 * \fn	void DrawableManager::Register(Drawable* draw);
	 *
	 * \brief	Registers this object by inserting the drawable into the DrawableList with the appropriate iterator
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	draw	If non-null, the drawable.
	 **************************************************************************************************/

	void Register(Drawable* draw);

	/**********************************************************************************************//**
	 * \fn	void DrawableManager::Deregister(Drawable* draw);
	 *
	 * \brief	Deregisters this object by erasing it from the drawable into the DrawableList with the appropriate iterator
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	draw	If non-null, the draw.
	 **************************************************************************************************/

	void Deregister(Drawable* draw);


	/** \brief	The list iterator using drawable list reference (a list of Drawables) */
	using DrawableListRef = std::list<Drawable*>::iterator;

private:

	/** \brief	List of drawables */
	std::list<Drawable*> DrawableList;

	/**********************************************************************************************//**
	 * \property	DrawableListRef ref
	 *
	 * \brief	Gets the reference for our iterator.
	 *
	 * \return	The reference.
	 **************************************************************************************************/

	DrawableListRef ref;

	/**********************************************************************************************//**
	 * \fn	void DrawableManager::ProcessElements();
	 *
	 * \brief	Process the elements, calling Draw and Draw2D for each Drawable within our list, drawing all 3D objects first, followed by all 2D objects.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void ProcessElements();

};


#endif // !_UpdatableManager#pragma once
