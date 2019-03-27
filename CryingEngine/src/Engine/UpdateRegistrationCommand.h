#ifndef _UpdateRegistrationCommand
#define _UpdateRegistrationCommand

#include "CommandBase.h"

class Updatable;

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	UpdateRegistrationCommand
 *
 * \brief	An update registration command (Command Pattern) inheriting from @CommandBase
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class UpdateRegistrationCommand : public CommandBase
{
public:

	/**********************************************************************************************//**
	 * \fn	UpdateRegistrationCommand::UpdateRegistrationCommand(Updatable* up);
	 *
	 * \brief	Constructor that takes an @Updatable and an ID for use in executing the scene registration command
	 * 			
	 * \sa		UpdateRegistrationCommand::Execute
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	up	If non-null, the updatable.
	 **************************************************************************************************/

	UpdateRegistrationCommand(Updatable* up);
	UpdateRegistrationCommand(const UpdateRegistrationCommand&) = delete;
	UpdateRegistrationCommand& operator= (const UpdateRegistrationCommand&) = delete;
	~UpdateRegistrationCommand();

	/**********************************************************************************************//**
	 * \fn	void UpdateRegistrationCommand::Execute() override;
	 *
	 * \brief	Executes this object, calling the SceneRegistration() on the corresponding @Updatable
	 * 			
	 * \sa		Updatable::SceneRegistration
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void Execute() override;


private:


	/** \brief	The updatable pointer */
	Updatable* ptrUp;
};

#endif // !_UpdateRegistrationCommand

