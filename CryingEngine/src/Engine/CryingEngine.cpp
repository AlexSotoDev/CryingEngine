#include "AzulCore.h"
#include "CryingEngine.h"

#include "TextureManager.h"
#include "ShaderManager.h"
#include "ModelManager.h"
#include "CameraManager.h"
#include "Visualizer.h"

#include "SceneManager.h"

#include "TimeManager.h"

#include "ImageManager.h"

#include "SoundEngine.h"



CryingEngine* CryingEngine::self = NULL;


CryingEngine::~CryingEngine()
{
	SceneManager::Instance().Delete();
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void CryingEngine::Initialize()
{
	// Game Window Device setup
	GameInitialize();

}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void CryingEngine::LoadContent()
{
	//First our asset managers need to be created.
	//I advise not messing with this ordering

	SoundEngine::InitializeSystem();

	ModelManager::LoadDefaultModels();

	//Load All Default Texutres
	TextureManager::LoadDefaultTextures();

	//Load Default Shader function
	ShaderManager::LoadDefaultShaders();

	Visualizer::CreatePrimitives();

	//Now we can use our Load Resources file to load in assets (using their respective managers)
	Instance().LoadAllResources();

	SceneManager::Instance().PrivateInitialize();
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void CryingEngine::Update()
{
	SceneManager::Instance().PrivateUpdate();
	TimeManager::ProcessTime(this->PrivateGetTime());
	SoundEngine::Update();
	
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void CryingEngine::Draw()
{
	SceneManager::Instance().PrivateDraw();
}



//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void CryingEngine::UnLoadContent()
{

	ShaderManager::UnloadAllShaders();
	TextureManager::UnloadAllTextures();
	ModelManager::UnloadAllModels();
	ImageManager::UnLoadAllImages();
	SceneManager::TerminateCurrentScene();
	Visualizer::Delete();

	SoundEngine::UnloadSounds();
}

void CryingEngine::Run()
{
	Instance().run();
}

int CryingEngine::PrivateGetWidth()
{
	return Instance().getWidth();
}

int CryingEngine::PrivateGetHeight()
{
	return Instance().getHeight();
}

float CryingEngine::PrivateGetTime()
{
	return Instance().GetTimeInSeconds();
}

