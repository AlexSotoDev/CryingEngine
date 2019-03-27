#include "TextureManager.h"

TextureManager* TextureManager::self = NULL;

void TextureManager::PrivateLoadTexture(std::string textureName, std::string filePath)
{
	//Check if string is empty str
	assert((filePath != "" || textureName != "") && "textureName or filePath is not valid (empty string entered)!");

	//Check if it's already in shaderMap
	assert(Instance().textureMap[textureName] == NULL && "A texture with that name already exists!");

	Instance().textureMap[textureName] = new Texture(filePath.c_str());
}

Texture * TextureManager::PrivateGetTexture(std::string textureName)
{
	//Check if it's null
	assert(Instance().textureMap[textureName] != NULL && "Texture with that name cannot be found!");

	return Instance().textureMap[textureName];
}

void TextureManager::PrivateLoadDefaultTextures()
{
	LoadTexture("CRYpSpaceFrigateTex", "../Assets/Textures/space_frigate.tga");
	LoadTexture("CRYpTextPlane", "../Assets/Textures/grid.tga");
}

void TextureManager::PrivateUnloadAllTextures()
{

	std::map<std::string, Texture*>::iterator it = Instance().textureMap.begin(); //create an iterator to go through the textureMap
	while (it != Instance().textureMap.end())
	{
		delete it->second;
		it->second = nullptr;
		it++;
	}

	delete self;
	

	//Can't/shouldn't delete iterators
	// http://stackoverflow.com/questions/23578455/c-does-the-iterator-need-to-be-deleted
}
