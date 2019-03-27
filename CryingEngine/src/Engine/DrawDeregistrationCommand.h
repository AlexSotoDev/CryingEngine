#ifndef _DrawDeregistrationCommand
#define _DrawDeregistrationCommand

#include "CommandBase.h"

class Drawable;

//Inherit from command base so we can use execute

/**********************************************************************************************//**
 * \class	DrawDeregistrationCommand
 *
 * \brief	A draw deregistration command inheriting from the @CommandBase (Command Pattern). 
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/

class DrawDeregistrationCommand : public CommandBase
{
public:

	/**********************************************************************************************//**
	 * \fn	DrawDeregistrationCommand::DrawDeregistrationCommand(Drawable* draw);
	 *
	 * \brief	Constructor that gives the dereg command access to a @Drawable game object.
	 *
	 * \author	Alex
	 * \date	3/11/2017
	 *
	 * \param [in,out]	draw	If non-null, the drawable.
	 **************************************************************************************************/

	DrawDeregistrationCommand(Drawable* draw);
	DrawDeregistrationCommand(const DrawDeregistrationCommand&) = delete;
	DrawDeregistrationCommand& operator= (const DrawDeregistrationCommand&) = delete;
	~DrawDeregistrationCommand();

	/**********************************************************************************************//**
	 * \fn	void DrawDeregistrationCommand::Execute() override;
	 *
	 * \brief	Executes this object, calling the Scene Deregistration function for a @Drawable
	 * 			
	 * \sa		Drawable::SceneDeregistration
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
