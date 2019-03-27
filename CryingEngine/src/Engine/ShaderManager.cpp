#include "ShaderManager.h"

ShaderManager* ShaderManager::self = NULL;

void ShaderManager::PrivateLoadShader(std::string shaderName, std::string filePath)
{
	//Check if string is empty str
	assert((filePath != "" || shaderName != "") && "shaderName or filePath is not valid (empty string entered)!");

	//Check if it's already in shaderMap
	assert(Instance().shaderMap[shaderName] == NULL && "A shader with that name already exists!");

	Instance().shaderMap[shaderName] = new ShaderObject(filePath.c_str());
}

ShaderObject * ShaderManager::PrivateGetShader(std::string shaderName)
{
	//Check if it's null
	assert(Instance().shaderMap[shaderName] != NULL && "Shader with that name cannot be found!");

	return Instance().shaderMap[shaderName];
}

void ShaderManager::PrivateLoadDefaultShaders()
{
	//Don't need shadermanager:: because we're in it
	LoadShader("CRYtextureFlatRender", "../Assets/Shaders/textureFlatRender");
	LoadShader("CRYtextureLightRender", "../Assets/Shaders/textureLightRender");
	LoadShader("CRYcolorConstantRender", "../Assets/Shaders/colorConstantRender");
	LoadShader("CRYcolorNoTextureRender", "../Assets/Shaders/colorNoTextureRender");
	LoadShader("CRYcolorVaryRender", "../Assets/Shaders/colorVaryRender");
	LoadShader("CRYcolorNoTextureLightRender", "../Assets/Shaders/colorNoTextureLightRender");
	LoadShader("CRYspriteRender", "../Assets/Shaders/spriteRender");
	LoadShader("CRYspriteLineRender", "../Assets/Shaders/spriteLineRender");

}

void ShaderManager::PrivateUnloadAllShaders()
{
	std::map<std::string, ShaderObject*>::iterator it = Instance().shaderMap.begin(); //create an iterator to go through the textureMap
	while (it != Instance().shaderMap.end())
	{
		delete it->second;
		it->second = nullptr;
		it++;
	}

	delete self;


}
