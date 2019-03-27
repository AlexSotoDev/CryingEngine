#ifndef _DrawRegistrationCommand
#define _DrawRegistrationCommand

#include "CommandBase.h"

class Drawable;

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	DrawRegistrationCommand
 *
 * \brief	A draw registration command inheriting from the @CommandBase (Command Pattern). 
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class DrawRegistrationCommand : public CommandBase
{
public:

	/**********************************************************************************************//**
	 * \fn	DrawRegistrationCommand::DrawRegistrationCommand(Drawable* draw);
	 *
	 * \brief	Constructor that gives the reg command access to a @Drawable game object.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	draw	If non-null, the draw.
	 **************************************************************************************************/

	DrawRegistrationCommand(Drawable* draw);
	DrawRegistrationCommand(const DrawRegistrationCommand&) = delete;
	DrawRegistrationCommand& operator= (const DrawRegistrationCommand&) = delete;
	~DrawRegistrationCommand();

	/**********************************************************************************************//**
	 * \fn	void DrawRegistrationCommand::Execute() override;
	 *
	 * \brief	Executes this object, calling the Scene Registration function for a @Drawable
	 * 			
	 * \sa		Drawable::SceneRegistration
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 **************************************************************************************************/

	void Execute() override;


private:


	/** \brief	The pointer to a Drawable */
	Drawable* ptrDraw;
};

#endif // !_UpdateRegistrationCommand


