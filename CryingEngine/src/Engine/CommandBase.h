#ifndef _CommandBase
#define _CommandBase

/**********************************************************************************************//**
 * \class	CommandBase
 *
 * \brief	A base class for all derived command classes to inherit from. Has a virtual execute function for overriding.
 *
 * \author	Alex
 * \date	3/8/2017
 **************************************************************************************************/

class CommandBase
{
public:
	CommandBase() {};
	virtual ~CommandBase() {};
	CommandBase(const CommandBase&) = delete;
	CommandBase& operator=(const CommandBase&) = delete;

	/**********************************************************************************************//**
	 * \fn	virtual void CommandBase::Execute()
	 *
	 * \brief	Executes the command. Made for derived classes to override with their execute command
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	virtual void Execute() {};
	

};

#endif // !_CommandBase
