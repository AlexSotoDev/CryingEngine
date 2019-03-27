#ifndef _CollidableDeregistrationCommand
#define _CollidableDeregistrationCommand

#include "CommandBase.h"

#include "CollidableGroup.h"

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	CollidableDeregistrationCommand
 *
 * \brief	Inherits from @CommandBase . Uses command pattern to deregister user created collidables (hence, the templated class).
 *
 * \author	Alex
 * \date	3/8/2017
 *
 * \tparam	C	Type of the collidable.
 **************************************************************************************************/

template <typename C>
class CollidableDeregistrationCommand : public CommandBase
{
private:


	/** \brief	The collidable type pointer */
	C* ptrCo;

public:

	/**********************************************************************************************//**
	 * \fn	CollidableDeregistrationCommand::CollidableDeregistrationCommand(C* co)
	 *
	 * \brief	Constructor that takes a collidable of the templated type and sets it to be the collidable pointer for deregistration
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	co	If non-null, the co.
	 **************************************************************************************************/

	CollidableDeregistrationCommand(C* co) {
		ptrCo = co;
	}


	CollidableDeregistrationCommand(const CollidableDeregistrationCommand&) = delete;
	CollidableDeregistrationCommand& operator= (const CollidableDeregistrationCommand&) = delete;

	/**********************************************************************************************//**
	 * \fn	CollidableDeregistrationCommand::~CollidableDeregistrationCommand()
	 *
	 * \brief	Constructor that takes a collidable of the templated type and sets it to be the collidable pointer for deregistration
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	~CollidableDeregistrationCommand() 
	{ 
		ptrCo = nullptr;
	}

	/**********************************************************************************************//**
	 * \fn	virtual void CollidableDeregistrationCommand::Execute() override
	 *
	 * \brief	Executes function of command for the caller (deregister).
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	virtual void Execute() override
	{
		CollidableGroup<C>::Deregister(ptrCo);
	}



};

#endif // !_CollidableDeregistrationCommand
