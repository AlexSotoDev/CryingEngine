#include "../Engine/CryingEngine.h"

#include "../Engine/TextureManager.h"
#include "../Engine/ShaderManager.h"
#include "../Engine/ModelManager.h"
#include "../Engine/ImageManager.h"
#include "../Engine/TerrainObjectManager.h"
#include "../Engine/SoundEngine.h"
#include "../Engine/SceneManager.h"
#include "../User/IntroScene.h"

void CryingEngine::LoadAllResources()
{

	//FINAL DEMO STUFF
	
	// PLAYER

	// Tank
	ModelManager::LoadModel("Model_TankBottom", "../Assets/Models/tank_bottom.azul");
	ModelManager::LoadModel("Model_TankTop", "../Assets/Models/tank_top.azul");
	TextureManager::LoadTexture("Texture_TankBody", "../Assets/Textures/Tank_Body.tga");
	
	// BULLETS
	
	TextureManager::LoadTexture("Texture_Red", "../Assets/Textures/red.tga");
	TextureManager::LoadTexture("Texture_Blue", "../Assets/Textures/blue.tga");

	// MISSILE

	ModelManager::LoadModel("Model_Missile", "../Assets/Models/missile.azul");
	TextureManager::LoadTexture("Texture_Missile", "../Assets/Textures/missile.tga");




	//ENVIRONMENT STUFF

	// TerrainObject
	ModelManager::LoadModel("Model_Terrain", "../Assets/Models/coolterrain.azul");
	TextureManager::LoadTexture("Texture_Terrain", "../Assets/Textures/groundtexture.tga");

	// Grass
	ModelManager::LoadModel("Model_Grass", "../Assets/Models/grass.azul");
	TextureManager::LoadTexture("Texture_Grass", "../Assets/Textures/Grass_Texture.tga");

	// Cottage
	ModelManager::LoadModel("Model_Cottage", "../Assets/Models/woodcottage.azul");
	TextureManager::LoadTexture("Texture_Cottage", "../Assets/Models/Cottage_Texture.tga");

	//UI STUFF
	TextureManager::LoadTexture("Texture_Heart", "../Assets/Texture/pixelheart.tga");
	ImageManager::CreateImage(TextureManager::GetTexture("Texture_Heart"), new Rect(0.0f, 0.0f, (float)TextureManager::GetTexture("Texture_Heart")->getWidth(), (float)TextureManager::GetTexture("Texture_Heart")->getHeight()), "Sprite_Heart");
	
	// HEART/LIFE SPRITES
	TextureManager::LoadTexture("Megaman_Texture", "../Assets/Textures/newSpriteHeart.tga");

	ImageManager::CreateImage((TextureManager::GetTexture("Megaman_Texture")), new Rect(0.0f, 0.0f, (float)TextureManager::GetTexture("Megaman_Texture")->getWidth(), (float)TextureManager::GetTexture("Megaman_Texture")->getHeight()), "Sprite_Megaman");




	// Backgrounds

	//Opening splash screen background (tank)
	TextureManager::LoadTexture("Texture_TankBackground", "../Assets/Textures/tankBackground.tga");
	ImageManager::CreateImage(TextureManager::GetTexture("Texture_TankBackground"), new Rect(0.0f, 0.0f, (float)TextureManager::GetTexture("Texture_TankBackground")->getWidth(), (float)TextureManager::GetTexture("Texture_TankBackground")->getHeight()), "Sprite_TankBackground");

	//End splash screen background (trees) GAME OVER
	TextureManager::LoadTexture("Texture_TreeBackground", "../Assets/Textures/treeBackground.tga");
	ImageManager::CreateImage(TextureManager::GetTexture("Texture_TreeBackground"), new Rect(0.0f, 0.0f, (float)TextureManager::GetTexture("Texture_TreeBackground")->getWidth(), (float)TextureManager::GetTexture("Texture_TreeBackground")->getHeight()), "Sprite_TreeBackground");

	TerrainObjectManager::LoadTerrain("Terrain_PrimaryTerrain","../Assets/Textures/HMkguys.tga", "Texture_Terrain", 5, 5, 595, 250, 3, 1.0f, -20.0f, 1.5f);


	//Audio
	SoundEngine::ErrorCheck(SoundEngine::CreateSound("song", "../Assets/Sounds/song.wav", soundMode::Sound_2D));





	//Scene stuff

	//User stuff
	//Create a Scene
	SceneManager::SetDefaultScene();
	Scene* demoScene = new IntroScene();
	SceneManager::SetCurrentScene(demoScene);
}