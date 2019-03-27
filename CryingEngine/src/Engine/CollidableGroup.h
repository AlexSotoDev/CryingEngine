#ifndef _CollidableGroup
#define _CollidableGroup

#include "CollidableGroupBase.h"

#include <set>
#include "Align16.h"


/**********************************************************************************************//**
 * \class	CollidableGroup
 *
 * \brief	Singleton manager through templated collidable group class created so that we can use the collision system with user created/dynamic objects. Holds a collection of collidable types and manages them. Inherits from @CollidableGroupBase
 *
 * \author	Alex
 * \date	3/8/2017
 *
 * \tparam	C	Type of the collidable
 **************************************************************************************************/
class CollisionVolumeAABB;

template <typename C>
class CollidableGroup : public CollidableGroupBase, public Align16
{

private:

	/**********************************************************************************************//**
	 * \fn	void CollidableGroup::privRegister(C* co);
	 *
	 * \brief	Private register function. Calls the public register function
	 * 			
	 * \sa		CollidableGroup
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	co	If non-null, the collidable.
	 **************************************************************************************************/

	void privRegister(C* co);

	/**********************************************************************************************//**
	 * \fn	void CollidableGroup::privDeregister(C* co);
	 *
	 * \brief	Private deregister function. Calls the public deregister function
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	co	If non-null, the collidable.
	 **************************************************************************************************/

	void privDeregister(C* co);

	void privUpdateAABB();

	void privTerminate();

	CollisionVolumeAABB* groupAABB;

	Vect minAABB;
	Vect maxAABB;


public:

	static CollidableGroup *self;

	CollidableGroup();
	CollidableGroup(const CollidableGroup&) {};
	CollidableGroup& operator = (const CollidableGroup&) {};

	~CollidableGroup();

	//Instance Creation
	static CollidableGroup& Instance()
	{
		if (!self)
		{
			self = new CollidableGroup();
		}

		return *self;
	};

	/**********************************************************************************************//**
	 * \typedef	std::set<C*> CollidableCollection
	 *
	 * \brief	Defines an templated type representing collection (data struct: STL set) of all collidables of one type.
	 **************************************************************************************************/

	typedef std::set<C*> CollidableCollection;
	CollidableCollection collideCol;

	/**********************************************************************************************//**
	 * \fn	static CollidableCollection& CollidableGroup::GetColliderCollection()
	 *
	 * \brief	Gets/returns collider collection.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \return	The collider collection.
	 **************************************************************************************************/

	static CollidableCollection& GetColliderCollection()
	{
		return Instance().collideCol;
	}

	/**********************************************************************************************//**
	 * \fn	static void CollidableGroup::Register(C * co)
	 *
	 * \brief	Registers this object to the corresponding collidable group. Calls public accessor function.
	 * 	
	 * \sa		CollidableGroup::Register
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	co	If non-null, the collidable
	 **************************************************************************************************/

	static void Register(C * co) { Instance().privRegister(co); }

	/**********************************************************************************************//**
	 * \fn	static void CollidableGroup::Deregister(C * co)
	 *
	 * \brief	Deregisters this object to the corresponding collidable group. Calls public accessor function.
	 * 	
	 * \sa		CollidableGroup::Deregister					
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	co	If non-null, the collidable
	 **************************************************************************************************/

	static void Deregister(C * co) { Instance().privDeregister(co); }

	static void UpdateAABB() { Instance().privUpdateAABB(); }

	void Terminate() override { Instance().privTerminate(); }

	CollisionVolumeAABB* GetAABB();
};


template <typename C>
CollidableGroup<C>* CollidableGroup<C>::self = NULL;


template<typename C>
inline CollidableGroup<C>::CollidableGroup()
{
	groupAABB = new CollisionVolumeAABB();
}

template<typename C>
inline CollidableGroup<C>::~CollidableGroup()
{
	//collideCol.clear();
	//delete self;
	//self = NULL;
	//delete groupAABB;
}

/**********************************************************************************************//**
 * \fn	template<typename C> inline void CollidableGroup<C>::privRegister(C * co)
 *
 * \brief	Private version of register function. Inserts a C collidable into the corresponding collidable group.
 * 			
 * \sa		CollidableGroup::Register
 *
 * \author	Alex
 * \date	3/8/2017
 *
 * \tparam	C	Type of the collidable.
 * \param [in,out]	co	If non-null, the co.
 **************************************************************************************************/

template<typename C>
inline void CollidableGroup<C>::privRegister(C * co)
{
	Instance().collideCol.insert(co);
}

/**********************************************************************************************//**
 * \fn	template<typename C> inline void CollidableGroup<C>::privDeregister(C * co)
 *
 * \brief	Private version of deregister function. Erases a C collidable from the corresponding collidable group.
 * 			
 * \sa		CollidableGroup::Deregister
 *
 * \author	Alex
 * \date	3/8/2017
 *
 * \tparam	C	Type of the collidable
 * \param [in,out]	co	If non-null, the co.
 **************************************************************************************************/

template<typename C>
inline void CollidableGroup<C>::privDeregister(C * co)
{
	Instance().collideCol.erase(co);
}

template<typename C>
inline void CollidableGroup<C>::privUpdateAABB()
{
	//Init to the first obj's min/max
	if (!collideCol.empty())
	{
		auto it = collideCol.begin();

		minAABB = (*it)->GetDefaultBSphere()->GetMinAABB();
		maxAABB = (*it)->GetDefaultBSphere()->GetMaxAABB();
	}

	for (auto it = collideCol.begin(); it != collideCol.end(); it++)
	{
		
		Vect currBSphereMin = (*it)->GetDefaultBSphere()->GetMinAABB();
		Vect currBSphereMax = (*it)->GetDefaultBSphere()->GetMaxAABB();

		minAABB = MathTools::CalculateMinVect(minAABB, currBSphereMin);
		maxAABB = MathTools::CalculateMaxVect(maxAABB, currBSphereMax);
		
	}

	groupAABB->ComputeData(minAABB, maxAABB);

}

template<typename C>
inline void CollidableGroup<C>::privTerminate()
{
	collideCol.clear();
	delete self;
	self = NULL;
}

template<typename C>
inline CollisionVolumeAABB * CollidableGroup<C>::GetAABB()
{
	return Instance().groupAABB;
}


#endif // !_CollidableGroup
