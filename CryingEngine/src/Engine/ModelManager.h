#ifndef _ModelManager
#define _ModelManager

// Singleton model manager

#include "AzulCore.h"

// include map
#include <map>

/**********************************************************************************************//**
 * \class	ModelManager
 *
 * \brief	Singleton manager for game models. Has methods for Loading, Unloading, and Getting models (private functions and public accessors)
 *
 * \author	Alex
 * \date	3/1/2017
 **************************************************************************************************/

class ModelManager
{
private:

	static ModelManager *self; //pointer to itself

	ModelManager() {}; //empty contructor
	ModelManager(const ModelManager&) {};
	ModelManager& operator = (const ModelManager&) {};

	~ModelManager() {}; //destructor

	//Instance Creation
	static ModelManager& Instance()
	{
		if (!self)
		{
			self = new ModelManager();
		}

		return *self;
	}


	/** \brief	to store all models within an STL map */
	std::map<std::string, Model*> modelMap;

	/**********************************************************************************************//**
	 * \fn	void ModelManager::PrivateLoadModel(std::string modelName, std::string filePath);
	 *
	 * \brief	Private load model done by specifying modelname and a filepath.Called by public accessor function.
	 * 			
	 * \sa		ModelManager::LoadModel
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 *
	 * \param	modelName	Name of the model.
	 * \param	filePath 	Full pathname of the file.
	 **************************************************************************************************/

	void PrivateLoadModel(std::string modelName, std::string filePath);

	/**********************************************************************************************//**
	 * \fn	void ModelManager::PrivateLoadModel(std::string modelName, Model::PreMadedeModels model);
	 *
	 * \brief	Alternate method to load models that are within our list of premade/default models. Called by public accessor function.
	 * 			
	 * \sa		ModelManager::LoadModel		
	 * \sa		Model::PremadedeModels
	 *
	 * \author	Alex
	 * \date	3/1/2017
	 *
	 * \param	modelName	Desired name of this user instance of model.
	 * \param	model	 	The premade model name.
	 **************************************************************************************************/

	void PrivateLoadModel(std::string modelName, Model::PreMadedeModels model);

	/**********************************************************************************************//**
	 * \fn	Model* ModelManager::PrivateGetModel(std::string modelName);
	 *
	 * \brief	Private function for getting a pointer to an already loaded model. Called by public accessor function.
	 * 			
	 * \sa		ModelManager::GetModel
	 * 
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	modelName	Name of the model.
	 *
	 * \return	Null if it fails, else a pointer to a Model.
	 **************************************************************************************************/

	Model* PrivateGetModel(std::string modelName);

	/**********************************************************************************************//**
	 * \fn	void ModelManager::PrivateLoadDefaultModels();
	 *
	 * \brief	Private load default models. Called by public accessor function
	 * 
	 * \sa		ModelManager::LoadDefaultModels		
	 * \sa		CryingEngine::LoadContent			
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	void PrivateLoadDefaultModels();

	/**********************************************************************************************//**
	 * \fn	void ModelManager::PrivateUnloadAllModels();
	 *
	 * \brief	Private unload all models. Called by public accessor function.
	 * 			
	 * \sa		ModelManager::UnloadAllModels
	 * \sa		CryingEngine::UnLoadContent
	 * 			
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	void PrivateUnloadAllModels();


public:

	/**********************************************************************************************//**
	 * \fn	static void ModelManager::LoadModel(std::string modelName, std::string filePath)
	 *
	 * \brief	Public accessor function for user that loads an external model asset into game using a filepath. Calls private load
	 * 			
	 * \sa		ModelManager::PrivateLoadModel
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	modelName	Desired name of the model.
	 * \param	filePath 	Full pathname of the file.
	 **************************************************************************************************/

	static void LoadModel(std::string modelName, std::string filePath) { Instance().PrivateLoadModel(modelName, filePath); }

	/**********************************************************************************************//**
	 * \fn	static void ModelManager::LoadModel(std::string modelName, Model::PreMadedeModels model)
	 *
	 * \brief	Public accessor function for user that loads an internal model (premade/included in engine) into game. Calls private load
	 * 			
	 * \sa		ModelManager::PrivateLoadModel
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	modelName	Desired user name of the model instance.
	 * \param	model	 	The model name within the pre made model enum
	 **************************************************************************************************/

	static void LoadModel(std::string modelName, Model::PreMadedeModels model) { Instance().PrivateLoadModel(modelName, model); };

	/**********************************************************************************************//**
	 * \fn	static Model* ModelManager::GetModel(std::string modelName)
	 *
	 * \brief	Public accessor function for getting a model pointer. Calls private version function
	 * 			
	 * \sa		ModelManager::PrivateGetModel
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \param	modelName	Name of the model.
	 *
	 * \return	Null if it fails, else the model.
	 **************************************************************************************************/

	static Model* GetModel(std::string modelName) { return Instance().PrivateGetModel(modelName); }

	/**********************************************************************************************//**
	 * \fn	static void ModelManager::LoadDefaultModels()
	 *
	 * \brief	Public accessor function. Loads default models. Calls private version function
	 * 			
	 * \sa		ModelManager::PrivateLoadDefaultModels
	 * \sa		CryingEngine::LoadContent
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	static void LoadDefaultModels() { Instance().PrivateLoadDefaultModels(); }

	/**********************************************************************************************//**
	 * \fn	static void ModelManager::UnloadAllModels()
	 *
	 * \brief	Public accessor function. Unloads default models. Calls private version function
	 * 	
	 * \sa		ModelManager::PrivateUnloadAllModels
	 * \sa		CryingEngine::UnLoadContent
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	static void UnloadAllModels() { Instance().PrivateUnloadAllModels(); }

};

#endif // !ModelManager
