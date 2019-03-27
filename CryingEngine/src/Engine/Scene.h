#ifndef _Scene	
#define _Scene

class Updatable;
class UpdatableManager;

class DrawableManager;
class Drawable;

class SceneRegistrationBroker;
class CommandBase;

class Alarmable;
class AlarmableManager;

class CameraManager;


//enum class AlarmID;

class Inputable;
class InputableManager;
//enum class EVENT_TYPE;

class CollisionManager;
class Collidable;

class TerrainManager;
class TerrainObject;


#include "EnumAlarm.h"
#include "AzulCore.h"
#include "EnumEventType.h"

#include <string>

/**********************************************************************************************//**
 * \class	Scene
 *
 * \brief	A scene class for all user scenes to derive from. Integrates registration and deregistration from @GameObject and its components (@Alarmable, @Collidable, @Drawable, @Inputable, @Updatable) into the scene. Has a manager for each @GameObject component as well as a @CameraManager
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class Scene
{
	friend class SceneManager;
	friend class Updatable;
	friend class Drawable;
	friend class Alarmable;
	friend class GameObject;
	friend class Inputable;
	friend class Collidable;

public:

	/**********************************************************************************************//**
	 * \fn	Scene::Scene();
	 *
	 * \brief	Default constructor, setting up/initializing an instance of each appropriate manager ( @AlarmableManager, @CollidableManager, @DrawableManager, @InputableManager, @UpdatableManager, @CameraManager) as well as setting up a @SceneRegistrationBroker
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	Scene();

	/**********************************************************************************************//**
	 * \fn	virtual Scene::~Scene();
	 *
	 * \brief	Destructor, deleting managers and brokers created in constructor.
	 * 			
	 * \sa		Scene::Scene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	virtual ~Scene();
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	/**********************************************************************************************//**
	 * \fn	void Scene::Register(Updatable* up);
	 *
	 * \brief	Registers the @Updatable to the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	up	If non-null, the updatable.
	 **************************************************************************************************/

	void Register(Updatable* up);

	/**********************************************************************************************//**
	 * \fn	void Scene::Deregister(Updatable* up);
	 *
	 * \brief	Deregisters the @Updatable from the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	up	If non-null, the updatable.
	 **************************************************************************************************/

	void Deregister(Updatable* up);

	/**********************************************************************************************//**
	 * \fn	void Scene::Register(Drawable* draw);
	 *
	 * \brief	Registers the @Drawable to the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	draw	If non-null, the drawable.
	 **************************************************************************************************/

	void Register(Drawable* draw);

	/**********************************************************************************************//**
	 * \fn	void Scene::Deregister(Drawable* draw);
	 *
	 * \brief	Deregisters the @Drawable from the scene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	draw	If non-null, the drawable.
	 **************************************************************************************************/

	void Deregister(Drawable* draw);

	/**********************************************************************************************//**
	 * \fn	void Scene::Register(float timer, Alarmable* alarm, AlarmID alarmID);
	 *
	 * \brief	Registers the @Alarmable to the scene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param 		  	timer  	The timer.
	 * \param [in,out]	alarm  	If non-null, the alarm.
	 * \param 		  	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	void Register(float timer, Alarmable* alarm, AlarmID alarmID);

	/**********************************************************************************************//**
	 * \fn	void Scene::Deregister(Alarmable* alarm, AlarmID alarmID);
	 *
	 * \brief	Deregisters the @Alarmable from the scene
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	alarm  	If non-null, the alarm.
	 * \param 		  	alarmID	Identifier for the alarm.
	 **************************************************************************************************/

	void Deregister(Alarmable* alarm, AlarmID alarmID);

	/**********************************************************************************************//**
	 * \fn	void Scene::Register(GameObject* go);
	 *
	 * \brief	Registers the @GameObject object to the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	go	If non-null, the game object.
	 **************************************************************************************************/

	void Register(GameObject* go);

	/**********************************************************************************************//**
	 * \fn	void Scene::Deregister(GameObject* go);
	 *
	 * \brief	Deregisters the @GameObject from the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	go	If non-null, the game object.
	 **************************************************************************************************/

	void Deregister(GameObject* go);

	/**********************************************************************************************//**
	 * \fn	void Scene::Register(Inputable* in, AZUL_KEY key, EVENT_TYPE type);
	 *
	 * \brief	Registers the @Inputable to the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	in  	If non-null, the inputable.
	 * \param 		  	key 	The key.
	 * \param 		  	type	The type.
	 **************************************************************************************************/

	void Register(Inputable* in, AZUL_KEY key, EVENT_TYPE type);

	/**********************************************************************************************//**
	 * \fn	void Scene::Deregister(Inputable* in, AZUL_KEY key, EVENT_TYPE type);
	 *
	 * \brief	Deregisters the @Inputable from the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	in  	If non-null, the inputable.
	 * \param 		  	key 	The key.
	 * \param 		  	type	The type.
	 **************************************************************************************************/

	void Deregister(Inputable* in, AZUL_KEY key, EVENT_TYPE type);

	/**********************************************************************************************//**
	 * \fn	void Scene::Register(Collidable* co);
	 *
	 * \brief	Registers the @Collidable to the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	co	If non-null, the co.
	 **************************************************************************************************/

	void Register(Collidable* co);

	/**********************************************************************************************//**
	 * \fn	void Scene::Deregister(Collidable* co);
	 *
	 * \brief	Deregisters the @Collidable from the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	co	If non-null, the collidable.
	 **************************************************************************************************/

	void Deregister(Collidable* co);

	/**********************************************************************************************//**
	 * \fn	CameraManager* Scene::GetCameraManager();
	 *
	 * \brief	Gets camera manager.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \return	Null if it fails, else the camera manager.
	 **************************************************************************************************/

	CameraManager* GetCameraManager();

	/**********************************************************************************************//**
	 * \fn	float Scene::GetRemainingTime(Alarmable *alarmable, AlarmID alarmID);
	 *
	 * \brief	Gets remaining time on an alarm.
	 *
	 * \author	Alex
	 * \date	3/13/2017
	 *
	 * \param [in,out]	alarmable	If non-null, the alarmable.
	 * \param 		  	alarmID  	Identifier for the alarm.
	 *
	 * \return	The remaining time.
	 **************************************************************************************************/

	float GetRemainingTime(Alarmable *alarmable, AlarmID alarmID);

	TerrainObject* GetTerrain();



protected:

	/**********************************************************************************************//**
	 * \fn	virtual void Scene::Initialize() = 0;
	 *
	 * \brief	Called on scene initialization. Overridden by user.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	virtual void Initialize() = 0;

	/**********************************************************************************************//**
	 * \fn	virtual void Scene::Terminate();
	 *
	 * \brief	Called on scene termination. Overridden by user
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	virtual void Terminate();

	/**********************************************************************************************//**
	 * \fn	void Scene::Draw();
	 *
	 * \brief	Draw cycle for the scene.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void Draw();

	/**********************************************************************************************//**
	 * \fn	void Scene::Update();
	 *
	 * \brief	Update cycle for the scene. Executes commands in @SceneRegistrationBroker and calls ProcessElements() in managers
	 * 			
	 * \sa		SceneRegistrationBroker::ExecuteCommands
	 * \sa		UpdatableManager::ProcessElements
	 * \sa		AlarmableManager::ProcessElements
	 * \sa		InputableManager::ProcessElements
	 * \sa		CollisionManager::ProcessElements
	 * 
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void Update();

	/**********************************************************************************************//**
	 * \fn	void Scene::SubmitCommand(CommandBase* command);
	 *
	 * \brief	Submit command, adding command to the current scene's scene broker (@SceneRegistrationBroker).	
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	command	If non-null, the command.
	 **************************************************************************************************/

	void SubmitCommand(CommandBase* command);

	void SetTerrain(std::string terrainName);


	/** \brief	Manager for scene updatables */
	UpdatableManager* sceneUpdatableManager;

	/** \brief	Manager for scene drawables */
	AlarmableManager* sceneAlarmableManager;


	/** \brief	The scene broker */
	SceneRegistrationBroker* sceneBroker;


	/** \brief	Manager for scene cameras */
	CameraManager* sceneCameraManager;


	/** \brief	Manager for scene inputables */
	InputableManager* sceneInputableManager;


	/** \brief	Manager for scene collidables */
	CollisionManager* sceneCollisionManager;
	

	/** \brief	Manager for scene drawables */
	DrawableManager* sceneDrawableManager;

	TerrainManager* sceneTerrainManager;

};

#endif
