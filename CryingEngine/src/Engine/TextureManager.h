#ifndef _TextureManager
#define _TextureManager

// Singleton texture manager

#include "AzulCore.h"

// include map
#include <map>

/**********************************************************************************************//**
 * \class	TextureManager
 *
 * \brief	Singleton manager for textures. Has methods for Loading, Unloading, and Getting textures (private functions and public accessors)
 *
 * \author	Alex
 * \date	3/6/2017
 **************************************************************************************************/

class TextureManager
{
private:

	static TextureManager *self; //pointer to itself

	TextureManager() {}; //empty contructor
	TextureManager(const TextureManager&) {};
	TextureManager& operator = (const TextureManager&) {};

	~TextureManager() {}; //destructor

						 //Instance Creation
	static TextureManager& Instance()
	{
		if (!self)
		{
			self = new TextureManager();
		}

		return *self;
	}


	/** \brief	to store all shader objs */
	std::map<std::string, Texture*> textureMap;

	/**********************************************************************************************//**
	 * \fn	void TextureManager::PrivateLoadTexture(std::string textureName, std::string filePath);
	 *
	 * \brief	Private load for textures. Loads in an external texture of desired name using a filepath. Called by public accessor function.
	 * 			
	 * \sa		TextureManager::LoadTexture
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	textureName	Name of the texture.
	 * \param	filePath   	Full pathname of the file.
	 **************************************************************************************************/

	void PrivateLoadTexture(std::string textureName, std::string filePath);

	/**********************************************************************************************//**
	 * \fn	Texture* TextureManager::PrivateGetTexture(std::string textureName);
	 *
	 * \brief	Private get texture. Returns a texture using its name. Called by public accesssor function.
	 *
	 * \sa		TextureManager::GetTexture
	 *    
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	textureName	Name of the texture.
	 *
	 * \return	Null if it fails, else a pointer to a Texture.
	 **************************************************************************************************/

	Texture* PrivateGetTexture(std::string textureName);

	/**********************************************************************************************//**
	 * \fn	void TextureManager::PrivateLoadDefaultTextures();
	 *
	 * \brief	Private load default textures included with engine. Called by public accessor function.
	 * 			
	 * \sa		TextureManager::LoadDefaultTextures
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	void PrivateLoadDefaultTextures();

	/**********************************************************************************************//**
	 * \fn	void TextureManager::PrivateUnloadAllTextures();
	 *
	 * \brief	Private unload all textures. Called by public accessor function.
	 *
	 * \sa		TextureManager::UnloadAllTextures
	 * 
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	void PrivateUnloadAllTextures();

public:

	/**********************************************************************************************//**
	 * \fn	static void TextureManager::LoadTexture(std::string textureName, std::string filePath)
	 *
	 * \brief	Loads external texture into engine using desired username and a filepath. Public accessor function that calls private method.
	 * 			
	 * \sa		TextureManager::PrivateLoadTexture
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	textureName	Name of the texture.
	 * \param	filePath   	Full pathname of the file.
	 **************************************************************************************************/

	static void LoadTexture(std::string textureName, std::string filePath) { Instance().PrivateLoadTexture(textureName, filePath); }

	/**********************************************************************************************//**
	 * \fn	static Texture* TextureManager::GetTexture(std::string textureName)
	 *
	 * \brief	Returns/Gets a texture pointer. Calls private equivalent function.
	 * 			
	 * \sa		TextureManager::PrivateGetTexture
	 * 			
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	textureName	Name of the texture.
	 *
	 * \return	Null if it fails, else the texture.
	 **************************************************************************************************/

	static Texture* GetTexture(std::string textureName) { return Instance().PrivateGetTexture(textureName); }

	/**********************************************************************************************//**
	 * \fn	static void TextureManager::LoadDefaultTextures()
	 *
	 * \brief	Public accessor function for loading default textures. Calls private equivalent function. Called by engine when loading content on initialization
	 * 			
	 * \sa		CryingEngine::LoadContent
	 * \sa		TextureManager::PrivateLoadDefaultTextures
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	static void LoadDefaultTextures() { Instance().PrivateLoadDefaultTextures(); }

	/**********************************************************************************************//**
	 * \fn	static void TextureManager::UnloadAllTextures()
	 *
	 * \brief	Public accessor function for unloading all textures. Calls private equivalent function. Called by engine when unloading content on termination
	 * 			
	 * \sa		CryingEngine::UnLoadContent
	 * \sa		TextureManager::PrivateUnloadAllTextures
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	static void UnloadAllTextures() { Instance().PrivateUnloadAllTextures(); }

};

#endif // !TextureManager

