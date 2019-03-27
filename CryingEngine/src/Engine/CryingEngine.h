#ifndef CRYINGENGINE_H
#define CRYINGENGINE_H

#include "AzulCore.h"

#include <stdio.h>


/**********************************************************************************************//**
 * \class	CryingEngine
 *
 * \brief	"A crying engine." - Accurate auto gen description. Singleton class deriving from the base Engine class. Provides basic machinery to initialize, load, update, and unload/terminate a game within engine.
 *
 * \author	Alex
 * \date	3/1/2017
 **************************************************************************************************/

class CryingEngine: public Engine
{

private:


	static CryingEngine *self; //pointer to itself

	CryingEngine() {}; //empty contructor
	CryingEngine(const CryingEngine&) {};
	CryingEngine& operator = (const CryingEngine&) {};

	~CryingEngine(); //destructor

	//Instance Creation
	static CryingEngine& Instance()
	{
		if (!self)
		{
			self = new CryingEngine();
		}

		return *self;
	}
	

	// Methods Users need to overload in their game

    /**********************************************************************************************//**
     * \fn	virtual void CryingEngine::Initialize();
     *
     * \brief	Initializes game instance by calling 
     * \sa		CryingEngine::GameInitialize()
     *
     * \author	Alex
     * \date	3/1/2017
     **************************************************************************************************/

    virtual void Initialize();

    /**********************************************************************************************//**
     * \fn	virtual void CryingEngine::LoadContent();
     *
     * \brief	Loads the game content by loading default models/textures/shaders built into engine, creates a default scene/initializes it, and loads user specified resources. Calls
     * \sa		ModelManager::LoadDefaultModels
     * \sa		TextureManager::LoadDefaultTextures
     * \sa		ShaderManager::LoadDefaultShaders
     * \sa		SceneManager::SetDefaultScene
	 * \sa		SceneManager::Initialize
	 * \sa		CryingEngine::LoadAllResources	
     * \author	Alex
     * \date	3/1/2017
     **************************************************************************************************/

    virtual void LoadContent();

	/**********************************************************************************************//**
	 * \fn	virtual void CryingEngine::Update();
	 *
	 * \brief	Calls update cycle on engine by calling
	 * \sa		SceneManager::Update
	 * 			and
	 * \sa		TimeManager::ProcessTime
	 *			which will call update on the current scene through scene manager and process time passed since last update/update the time through time manager
	 * \author	Alex
	 * \date	3/1/2017
	 **************************************************************************************************/

	virtual void Update();

    /**********************************************************************************************//**
     * \fn	virtual void CryingEngine::Draw();
     *
     * \brief	Calls draw cycle on engine by calling 
     * \sa		SceneManager::Draw
     * 			which will call draw on all drawable objects in current scene
     * \author	Alex
     * \date	3/1/2017
     **************************************************************************************************/

    virtual void Draw();

    /**********************************************************************************************//**
     * \fn	virtual void CryingEngine::UnLoadContent();
     *
     * \brief	General cleanup. Unloads all shaders, models, and textures through respective managers. Terminates scene through scene manager.
     * \sa			ShaderManager::UnloadAllShaders
     * \sa			TextureManager::UnloadAllTextures
     * \sa			ModelManager::UnloadAllModels
     * \author	Alex
     * \date	3/1/2017
     **************************************************************************************************/

    virtual void UnLoadContent();

	/**********************************************************************************************//**
	 * \fn	void CryingEngine::LoadAllResources();
	 *
	 * \brief	Loads all resources specified by user.
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 **************************************************************************************************/

	void LoadAllResources();

	/**********************************************************************************************//**
	 * \fn	void CryingEngine::GameInitialize();
	 *
	 * \brief	Game initialize. Allows user to initialize certain window properties such as window title, resolution, clear color, etc.
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 **************************************************************************************************/

	void GameInitialize();

	/**********************************************************************************************//**
	 * \fn	int CryingEngine::PrivateGetWidth();
	 *
	 * \brief	Gets window width
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 *
	 * \return	An int (width)
	 **************************************************************************************************/

	int PrivateGetWidth();

	/**********************************************************************************************//**
	 * \fn	int CryingEngine::PrivateGetHeight();
	 *
	 * \brief	Gets window height.
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 *
	 * \return	An int (height).
	 **************************************************************************************************/

	int PrivateGetHeight();

	/**********************************************************************************************//**
	 * \fn	float CryingEngine::PrivateGetTime();
	 *
	 * \brief	Returns time in seconds through the engine's internal time function
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 *
	 * \return	A float representing time passed in seconds.
	 **************************************************************************************************/

	float PrivateGetTime();




public:	

	/**********************************************************************************************//**
	 * \fn	static void CryingEngine::Run();
	 *
	 * \brief	Public accessor for internal engine run. Called in main.cpp
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 **************************************************************************************************/

	static void Run();

	/**********************************************************************************************//**
	 * \fn	static int CryingEngine::GetWidth()
	 *
	 * \brief	Public accessor for user getting the window width. Private accessor here
	 * \sa		CryingEngine::PrivateGetWidth
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 *
	 * \return	The width.
	 **************************************************************************************************/

	static int GetWidth() { return Instance().PrivateGetWidth(); }

	/**********************************************************************************************//**
	 * \fn	static int CryingEngine::GetHeight()
	 *
	 * \brief	Public accessor for user getting the window height. Private accessor here
	 * \sa		CryingEngine::PrivateGetHeight
	 * 			
	 * \author	Alex
	 * \date	3/1/2017
	 *
	 * \return	The height.
	 **************************************************************************************************/

	static int GetHeight() { return Instance().PrivateGetHeight(); }

	/**********************************************************************************************//**
	 * \fn	static float CryingEngine::GetTime()
	 *
	 * \brief	Public accessor for user to get the engine time in seconds. Private accessor link here:
	 * \sa		CryingEngine::PrivateGetTime
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 *
	 * \return	The time.
	 **************************************************************************************************/

	static float GetTime() { return Instance().PrivateGetTime(); }


};

#endif