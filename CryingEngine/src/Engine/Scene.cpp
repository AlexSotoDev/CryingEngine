#include "Scene.h"

#include "Updatable.h"
#include "UpdatableManager.h"

#include "Drawable.h"
#include "DrawableManager.h"

#include "Alarmable.h"
#include "AlarmableManager.h"

#include "SceneRegistrationBroker.h"
#include "CommandBase.h"

#include "CameraManager.h"

#include "EnumEventType.h"

#include "InputableManager.h"
#include "Inputable.h"

#include "CollisionManager.h"
#include "Collidable.h"

#include "TerrainManager.h"


void Scene::Update()
{
	sceneBroker->ExecuteCommands();
	sceneUpdatableManager->ProcessElements();
	sceneAlarmableManager->ProcessElements();
	sceneInputableManager->ProcessElements();
	sceneCollisionManager->ProcessCollisionTest();

}

void Scene::SubmitCommand(CommandBase* command)
{
	sceneBroker->AddCommand(command);
}

void Scene::SetTerrain(std::string terrainName)
{
	sceneTerrainManager->SetTerrain(terrainName);
}

CameraManager * Scene::GetCameraManager()
{
	return sceneCameraManager;
}

float Scene::GetRemainingTime(Alarmable * alarmable, AlarmID alarmID)
{
	return sceneAlarmableManager->GetRemainingTime(alarmable, alarmID);
}

TerrainObject * Scene::GetTerrain()
{
	return sceneTerrainManager->GetTerrain();
}

void Scene::Draw()
{
	sceneTerrainManager->RenderTerrain();
	sceneDrawableManager->ProcessElements();
}

Scene::Scene()
{

	sceneUpdatableManager = new UpdatableManager();
	sceneDrawableManager = new DrawableManager();
	sceneAlarmableManager = new AlarmableManager();

	sceneBroker = new SceneRegistrationBroker();

	sceneCameraManager = new CameraManager();

	sceneCameraManager->SetDefaultCameras();

	sceneInputableManager = new InputableManager();

	sceneCollisionManager = new CollisionManager();

	sceneTerrainManager = new TerrainManager();

}

Scene::~Scene()
{
	delete sceneUpdatableManager;
	delete sceneDrawableManager;
	delete sceneAlarmableManager;
	delete sceneBroker;
	delete sceneCameraManager;
	delete sceneCollisionManager;
	delete sceneInputableManager;
	delete sceneTerrainManager;
}

void Scene::Register(Updatable * up)
{
	sceneUpdatableManager->Register(up);
}

void Scene::Deregister(Updatable * up)
{
	sceneUpdatableManager->Deregister(up);
}

void Scene::Register(Drawable * draw)
{
	sceneDrawableManager->Register(draw);
}

void Scene::Deregister(Drawable * draw)
{
	sceneDrawableManager->Deregister(draw);
}

void Scene::Register(float timer, Alarmable * alarm, AlarmID alarmID)
{
	sceneAlarmableManager->Register(timer, alarm, alarmID);
}

void Scene::Deregister(Alarmable * alarm, AlarmID alarmID)
{
	sceneAlarmableManager->Deregister(alarm, alarmID);
}

void Scene::Register(GameObject * go)
{
	go->SceneEntry();
}

void Scene::Deregister(GameObject * go)
{
	go->SceneExit();
}

void Scene::Register(Inputable * in, AZUL_KEY key, EVENT_TYPE type)
{
	sceneInputableManager->Register(in, key, type);
}

void Scene::Deregister(Inputable * in, AZUL_KEY key, EVENT_TYPE type)
{
	sceneInputableManager->Deregister(in, key, type);
}

void Scene::Register(Collidable * co)
{
	(void)co;
}

void Scene::Deregister(Collidable * co)
{
	(void)co;
}

void Scene::Initialize()
{

}

void Scene::Terminate()
{

}
