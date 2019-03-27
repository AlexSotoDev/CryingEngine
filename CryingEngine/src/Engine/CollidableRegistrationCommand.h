#ifndef _CollidableRegistrationCommand
#define _CollidableRegistrationCommand

#include "CommandBase.h"

#include "CollidableGroup.h"

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	CollidableRegistrationCommand
 *
 * \brief	Inherits from @CommandBase . Uses command pattern to register user created collidables (hence, the templated class).
 *
 * \author	Alex
 * \date	3/8/2017
 *
 * \tparam	C	Type of the collidable.
 **************************************************************************************************/

template <typename C>
class CollidableRegistrationCommand : public CommandBase
{
private:


	/** \brief	The collidable type pointer */
	C* ptrCo;

public:

	/**********************************************************************************************//**
	 * \fn	CollidableRegistrationCommand::CollidableRegistrationCommand(C* co)
	 *
	 * \brief	Constructor that takes a collidable of the templated type and sets it to be the collidable pointer for registration
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	co	If non-null, the collidable.
	 **************************************************************************************************/

	CollidableRegistrationCommand(C* co) {
		ptrCo = co;
	}


	CollidableRegistrationCommand(const CollidableRegistrationCommand&) = delete;
	CollidableRegistrationCommand& operator= (const CollidableRegistrationCommand&) = delete;

	/**********************************************************************************************//**
	 * \fn	CollidableRegistrationCommand::~CollidableRegistrationCommand()
	 *
	 * \brief	Destructor. Deletes the templated collidable pointer.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	~CollidableRegistrationCommand() {
		ptrCo = nullptr;
	}

	/**********************************************************************************************//**
	 * \fn	virtual void CollidableRegistrationCommand::Execute() override
	 *
	 * \brief	Executes function of command for the caller (register).
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	virtual void Execute() override
	{
		CollidableGroup<C>::Register(ptrCo);
	}



};

#endif // !_CollidableRegistrationCommand
