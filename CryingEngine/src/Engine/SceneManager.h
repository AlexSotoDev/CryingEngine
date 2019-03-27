#ifndef _SceneManager
#define _SceneManager

#include "Scene.h"
#include "AzulCore.h"

/**********************************************************************************************//**
 * \class	SceneManager
 *
 * \brief	Singleton manager for scenes with methods for all kind of scene control/maintenance within a game and proper get/sets as necessary to scene objects. One @SceneManager per game.
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class SceneManager
{
	friend class Scene;
	friend class CryingEngine;
	

private:

	static SceneManager *self; //pointer to itself

	SceneManager();
	SceneManager(const SceneManager&) {};
	SceneManager& operator = (const SceneManager&) {};

	~SceneManager(); //destructor

						//Instance Creation
	static SceneManager& Instance()
	{
		if (!self)
		{
			self = new SceneManager();
		}

		return *self;
	}

	/**********************************************************************************************//**
	 * \fn	void SceneManager::PrivateSetDefaultScene();
	 *
	 * \brief	Private set default scene. Called by public accessor function.
	 * 			
	 * \sa		SceneManager::SetDefaultScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void PrivateSetDefaultScene();

	/**********************************************************************************************//**
	 * \fn	void SceneManager::PrivateSetCurrentScene(Scene* scene);
	 *
	 * \brief	Private set current scene. Called by public accessor function.
	 * 			
	 * \sa		SceneManager::SetCurrentScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	scene	If non-null, the scene.
	 **************************************************************************************************/

	void PrivateSetCurrentScene(Scene* scene);


	/** \brief	The current scene */
	Scene *currentScene;

	/** \brief	The next scene */
	Scene *nextScene;

	/**********************************************************************************************//**
	 * \fn	Scene* SceneManager::PrivateGetCurrentScene();
	 *
	 * \brief	Private get current scene. Called by public accessor function.
	 *
	 * \sa		SceneManager::GetCurrentScene
	 * 
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \return	Null if it fails, else a pointer to a Scene.
	 **************************************************************************************************/

	Scene* PrivateGetCurrentScene();

	/**********************************************************************************************//**
	 * \fn	void SceneManager::PrivateDraw();
	 *
	 * \brief	Private draw. Calls the current scene's Draw(). Called by public accessor function.
	 * 			
	 * \sa		SceneManager::Draw
	 * \sa		Scene::Draw 			
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void PrivateDraw();

	/**********************************************************************************************//**
	 * \fn	void SceneManager::PrivateUpdate();
	 *
	 * \brief	Private update. Calls the current scene's Update(). Called by public accessor function.
	 * 			
	 * \sa		SceneManager::Update
	 * \sa		Scene::Update
	 * 			
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void PrivateUpdate();

	/**********************************************************************************************//**
	 * \fn	void SceneManager::PrivateInitialize();
	 *
	 * \brief	Private initialize. Calls the current scene's Initialize(). Called by public accessor function
	 * 			
	 * \sa		SceneManager::Initialize
	 * \sa		Scene::Initialize
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void PrivateInitialize();

	/**********************************************************************************************//**
	 * \fn	void SceneManager::PrivateTerminate();
	 *
	 * \brief	Private terminate. Calls the current scene's Terminate(). Called by public accessor function
	 * 			
	 * \sa		SceneManager::Terminate
	 * \sa		Scene::Terminate
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void PrivateTerminateCurrentScene();

	/**********************************************************************************************//**
	 * \fn	void SceneManager::PrivateChangeScene();
	 *
	 * \brief	Private change scene. Called by public accessor function.
	 * 			
	 * \sa		SceneManager::ChangeScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void PrivateChangeScene();

	/**********************************************************************************************//**
	 * \fn	void SceneManager::PrivateSetNextScene(Scene* nextScene);
	 *
	 * \brief	Private set next scene. Called by public accessor function.
	 * 			
	 * \sa		SceneManager::SetNextScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	nextScene	If non-null, the next scene.
	 **************************************************************************************************/

	void PrivateSetNextScene(Scene* nextScene);

	void Delete();

	

public:

	/**********************************************************************************************//**
	 * \fn	static void SceneManager::SetCurrentScene(Scene* scene)
	 *
	 * \brief	Sets current scene. Public accessor function. Calls private equivalent
	 * 			
	 * \sa		SceneManager::PrivateSetCurrentScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	scene	If non-null, the scene.
	 **************************************************************************************************/

	static void SetCurrentScene(Scene* scene) { Instance().PrivateSetCurrentScene(scene); }

	/**********************************************************************************************//**
	 * \fn	static Scene* SceneManager::GetCurrentScene()
	 *
	 * \brief	Gets current scene. Public accessor function. Calls private equivalent.
	 * 			
	 * \sa		SceneManager::PrivateGetCurrentScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \return	Null if it fails, else the current scene.
	 **************************************************************************************************/

	static Scene* GetCurrentScene() { return Instance().PrivateGetCurrentScene(); }

	/**********************************************************************************************//**
	 * \fn	static void SceneManager::SetDefaultScene()
	 *
	 * \brief	Sets default scene. Public accessor function. Calls private equivalent.
	 * 			
	 * \sa		SceneManager::PrivateSetDefaultScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	static void SetDefaultScene() { Instance().PrivateSetDefaultScene(); }


	/**********************************************************************************************//**
	 * \fn	static void SceneManager::TerminateCurrentScene()
	 *
	 * \brief	Public accessor function to call Terminate on current scene. Calls private equivalent.
	 * 			
	 * \sa		SceneManager::PrivateTerminate
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	static void TerminateCurrentScene() { Instance().PrivateTerminateCurrentScene(); }

	/**********************************************************************************************//**
	 * \fn	static void SceneManager::SetNextScene(Scene* scene)
	 *
	 * \brief	Public accessor function to set next scene. Calls private equivalent
	 * 			
	 * \sa		SceneManager::PrivateSetNextScene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	scene	If non-null, the scene.
	 **************************************************************************************************/

	static void SetNextScene(Scene* scene) { Instance().PrivateSetNextScene(scene); }
};

#endif // !_SceneManager

