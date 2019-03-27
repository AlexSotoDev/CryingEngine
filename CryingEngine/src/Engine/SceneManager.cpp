#include "SceneManager.h"
#include "..\User\DemoScene.h"
#include "NullScene.h"
#include "SoundEngine.h"

SceneManager* SceneManager::self = NULL;

SceneManager::SceneManager()
{
	nextScene = nullptr;

	//Null object pattern
	currentScene = new NullScene();
}

SceneManager::~SceneManager()
{
	delete currentScene;
	delete nextScene;

}

void SceneManager::PrivateSetDefaultScene()
{
	Scene* myDefaultDemoScene = new DemoScene();
	SetCurrentScene(myDefaultDemoScene);
}

void SceneManager::PrivateSetCurrentScene(Scene * scene)
{
	currentScene = scene;
}

Scene * SceneManager::PrivateGetCurrentScene()
{
	return currentScene;
}

void SceneManager::PrivateDraw()
{
	currentScene->Draw();
}

void SceneManager::PrivateUpdate()
{
	if (nextScene)
	{
		SoundEngine::StopAllSounds();
		Instance().PrivateChangeScene();
		nextScene = nullptr;
	}

	currentScene->Update();
}

void SceneManager::PrivateInitialize()
{
	currentScene->Initialize();
}

void SceneManager::PrivateTerminateCurrentScene()
{
	currentScene->Terminate();
}

void SceneManager::PrivateChangeScene()
{

	currentScene->Terminate();
	delete currentScene;

	currentScene = nextScene;
	currentScene->Initialize();


}

void SceneManager::PrivateSetNextScene(Scene * scene)
{
	nextScene = scene;
}

void SceneManager::Delete()
{
	delete self;
}
