#ifndef _Collidable
#define _Collidable

#include "AzulCore.h"

#include "GameObject.h"

#include "CollidableGroup.h"
#include "CollisionManager.h"

//Have to include in header because of templatized functions
#include "CollidableRegistrationCommand.h"
#include "CollidableDeregistrationCommand.h"
#include "SceneManager.h"

class CollisionVolumeBSphere;
class CollisionVolume;

class CommandBase;

#include "EnumCollisionVolumeType.h"

/**********************************************************************************************//**
 * \class	Collidable
 *
 * \brief	A collidable class to be put on desired game objects (through virtual inheritance) that should have collision. Uses command pattern for registration/deregistration.
 *
 * \author	Alex
 * \date	3/6/2017
 **************************************************************************************************/

class Collidable : public virtual GameObject
{
	friend class CollisionManager;

private:

	/** \brief	The registration command of our base command type */
	CommandBase* registrationCommand;

	/** \brief	The deregistration command of our base command type */
	CommandBase* deregistrationCommand;

	CollisionVolume* colVol;

	CollisionVolumeBSphere* defaultBSphere;


	/** \brief	Pointer to our collidable model */
	Model* collisionModel;

	/**********************************************************************************************//**
	* \fn	template<typename C> void Collidable::CollisionRegistration(C* c)
	*
	* \brief	Templated function for registering collision with some unknown type created/specified by the user at runtime.
	*
	* \author	Alex
	* \date	3/6/2017
	*
	* \tparam	C	Type of the collidable
	* \param [in,out]	c	If non-null, the collidable to process.
	**************************************************************************************************/

	template<typename C>
	void CollisionRegistration(C* c)
	{
		CollidableGroup<C>::Register(c);
	}

	/**********************************************************************************************//**
	* \fn	template<typename C> void Collidable::CollisionDeregistration(C* c)
	*
	* \brief	Templated function for deregistering collision with some unknown type created/specified by the user.
	*
	* \author	Alex
	* \date	3/6/2017
	*
	* \tparam	C	Type of the collidable
	* \param [in,out]	c	If non-null, the collidable to process.
	**************************************************************************************************/

	template<typename C>
	void CollisionDeregistration(C* c)
	{
		CollidableGroup<C>::Deregister(c);
	}

public:
	Collidable() {};
	virtual ~Collidable();
	Collidable(const Collidable&) = delete;
	Collidable& operator=(const Collidable&) = delete;

	/**********************************************************************************************//**
	 * \fn	virtual void Collidable::Collision(Collidable*);
	 *
	 * \brief	Default generic collision function for any collision where colliding object isn't defined. Virtual/can be overridden.
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param [in,out]	parameter1	If non-null, the first parameter.
	 **************************************************************************************************/

	virtual void Collision(Collidable*);

	/**********************************************************************************************//**
	 * \fn	template<typename C> void Collidable::SubmitCollisionRegistration(C* c)
	 *
	 * \brief	Templated function for submitting collision registration with some unknown type created/specified by user.
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \tparam	C	Type of the collidable object.
	 * \param [in,out]	c	If non-null, the collidable to process.
	 **************************************************************************************************/

	template<typename C>
	void SubmitCollisionRegistration(C* c)
	{
		registrationCommand = new CollidableRegistrationCommand<C>(c);
		SceneManager::GetCurrentScene()->SubmitCommand(registrationCommand);
		//delete registrationCommand;
	}

	/**********************************************************************************************//**
	 * \fn	template<typename C> void Collidable::SubmitCollisionDeregistration(C* c)
	 *
	 * \brief	Templated function for submitting collision deregistration with some unknown type created/specified by the user.
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \tparam	C	Type of the collidable.
	 * \param [in,out]	c	If non-null, the collidable to process.
	 **************************************************************************************************/

	template<typename C>
	void SubmitCollisionDeregistration(C* c)
	{
		deregistrationCommand = new CollidableDeregistrationCommand<C>(c);
		SceneManager::GetCurrentScene()->SubmitCommand(deregistrationCommand);
		//delete deregistrationCommand;
	}


	/**********************************************************************************************//**
	 * \fn	void Collidable::SetColliderModel(Model* mod);
	 *
	 * \brief	Sets collider model.
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param [in,out]	mod	If non-null, the modifier.
	 **************************************************************************************************/

	void SetColliderModel(Model* mod, CollisionVolumeType type);

	/**********************************************************************************************//**
	 * \fn	void Collidable::UpdateCollisionData(Matrix& mat);
	 *
	 * \brief	Updates the collision data described by matrix
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param [in,out]	mat	The matrix.
	 **************************************************************************************************/

	void UpdateCollisionData(Matrix& mat);

	CollisionVolume& GetCollisionVolume();

	CollisionVolumeBSphere* GetDefaultBSphere();

	virtual void TerrainCollision();
};

#endif // !_Collidable


