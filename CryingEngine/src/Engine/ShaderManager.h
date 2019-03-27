#ifndef _ShaderManager
#define _ShaderManager

// Singleton shader manager

#include "AzulCore.h"

// include map
#include <map>

/**********************************************************************************************//**
 * \class	ShaderManager
 *
 * \brief	Singleton manager for shaders. Has methods for Loading, Unloading, and Getting shaders (private functions and public accessors)
 *
 * \author	Alex
 * \date	3/6/2017
 **************************************************************************************************/

class ShaderManager
{
private:

	static ShaderManager *self; //pointer to itself
	
	ShaderManager() {}; //empty contructor
	ShaderManager(const ShaderManager&) {};
	ShaderManager& operator = (const ShaderManager&) {};

	~ShaderManager() {}; //destructor

	//Instance Creation
	static ShaderManager& Instance()
	{
		if (!self)
		{
			self = new ShaderManager();
		}

		return *self;
	}


	/** \brief	to store all shader objs */
	std::map<std::string, ShaderObject*> shaderMap;

	/**********************************************************************************************//**
	 * \fn	void ShaderManager::PrivateLoadShader(std::string shaderName, std::string filePath);
	 *
	 * \brief	Private load shader function. Called by public accessor function
	 * 			
	 * \sa		ShaderManager::LoadShader
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	shaderName	Name of the shader.
	 * \param	filePath  	Full pathname of the file.
	 **************************************************************************************************/

	void PrivateLoadShader(std::string shaderName, std::string filePath);

	/**********************************************************************************************//**
	 * \fn	ShaderObject* ShaderManager::PrivateGetShader(std::string shaderName);
	 *
	 * \brief	Private get shader function that returns a shader object pointer. Called by public accessor function.
	 * 			
	 * \sa		ShaderManager::GetShader
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	shaderName	Name of the shader.
	 *
	 * \return	Null if it fails, else a pointer to a ShaderObject.
	 **************************************************************************************************/

	ShaderObject* PrivateGetShader(std::string shaderName);

	/**********************************************************************************************//**
	 * \fn	void ShaderManager::PrivateLoadDefaultShaders();
	 *
	 * \brief	Private load default shaders included with engine. Called by public accessor function.
	 * 			
	 * \sa		ShaderManager::LoadDefaultShaders()
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	void PrivateLoadDefaultShaders();

	/**********************************************************************************************//**
	 * \fn	void ShaderManager::PrivateUnloadAllShaders();
	 *
	 * \brief	Private unload all shaders. Callled by public accessor function.
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	void PrivateUnloadAllShaders();

public:

	/**********************************************************************************************//**
	 * \fn	static void ShaderManager::LoadShader(std::string shaderName, std::string filePath)
	 *
	 * \brief	Loads a shader. Public accessor function.
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	shaderName	Desired name of the shader.
	 * \param	filePath  	Full pathname of the file.
	 **************************************************************************************************/

	static void LoadShader(std::string shaderName, std::string filePath) { Instance().PrivateLoadShader(shaderName, filePath); }

	/**********************************************************************************************//**
	 * \fn	static ShaderObject* ShaderManager::GetShader(std::string shaderName)
	 *
	 * \brief	Returns/Gets a shader object pointer.
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	shaderName	Name of the shader.
	 *
	 * \return	Null if it fails, else the shader.
	 **************************************************************************************************/

	static ShaderObject* GetShader(std::string shaderName) { return Instance().PrivateGetShader(shaderName); }

	/**********************************************************************************************//**
	 * \fn	static void ShaderManager::LoadDefaultShaders()
	 *
	 * \brief	Loads default shaders included with engine. Public accessor function. Called in CryingEngine when loading content on initiailization
	 * 
	 * \sa		CryingEngine::LoadContent
	 * \sa		ShaderManager::PrivateLoadDefaultShaders
	 * 
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	static void LoadDefaultShaders() { Instance().PrivateLoadDefaultShaders(); }

	/**********************************************************************************************//**
	 * \fn	static void ShaderManager::UnloadAllShaders()
	 *
	 * \brief	Unload all shaders. Public accessor function. Called in CryingEngine when Unloading content before terminating engine
	 * 
	 * \sa		CryingEngine::UnLoadContent		
	 * \sa		ShaderManager::PrivateUnloadAllShaders				
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	static void UnloadAllShaders() { Instance().PrivateUnloadAllShaders(); }

};

#endif // !ShaderManager
