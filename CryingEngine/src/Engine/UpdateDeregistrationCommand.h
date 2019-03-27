#ifndef _UpdateDeregistrationCommand
#define _UpdateDeregistrationCommand

#include "CommandBase.h"

class Updatable;

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	UpdateDeregistrationCommand
 *
 * \brief	An update deregistration command (Command Pattern) inheriting from @CommandBase
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class UpdateDeregistrationCommand : public CommandBase
{
public:

	/**********************************************************************************************//**
	 * \fn	UpdateDeregistrationCommand::UpdateDeregistrationCommand(Updatable* up);
	 *
	 * \brief	Constructor that takes an @Updatable and sets up a pointer to it for use in the execute command
	 * 			
	 * \sa		UpdateDeregistrationCommand::Execute
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	up	If non-null, the up.
	 **************************************************************************************************/

	UpdateDeregistrationCommand(Updatable* up);
	UpdateDeregistrationCommand(const UpdateDeregistrationCommand&) = delete;
	UpdateDeregistrationCommand& operator= (const UpdateDeregistrationCommand&) = delete;
	~UpdateDeregistrationCommand();

	/**********************************************************************************************//**
	 * \fn	void UpdateDeregistrationCommand::Execute() override;
	 *
	 * \brief	Executes this object, calling the SceneDeregistration() on the corresponding @Updatable
	 * 			
	 * \sa		Updatable::SceneDeregistration
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void Execute() override;


private:

	Updatable* ptrUp;
};

#endif // !_UpdateRegistrationCommand



