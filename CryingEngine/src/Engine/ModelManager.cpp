#include "ModelManager.h"

ModelManager* ModelManager::self = NULL;

void ModelManager::PrivateLoadModel(std::string modelName, std::string filePath)
{
	//Check if string is empty str
	assert((filePath != "" || modelName != "") && "modelName or filePath is not valid (empty string entered)!");

	//Check if it's already in modelMap
	assert(Instance().modelMap[modelName] == NULL && "A model with that name already exists!");

	Instance().modelMap[modelName] = new Model(filePath.c_str());
}

void ModelManager::PrivateLoadModel(std::string modelName, Model::PreMadedeModels model)
{
	assert(modelName != "" && "modelName not valid (empty string entered)!");
	assert(Instance().modelMap[modelName] == NULL && "A model with that name already exists!");
	Instance().modelMap[modelName] = new Model(model);
}

Model * ModelManager::PrivateGetModel(std::string modelName)
{
	//Check if it's null
	assert(Instance().modelMap[modelName] != NULL && "Model with that name cannot be found!");

	return Instance().modelMap[modelName];
}

void ModelManager::PrivateLoadDefaultModels()
{
	//OLDER DEMO STUFF
	ModelManager::LoadModel("CRYpModelAxis", "../Assets/Models/Axis.azul");
	ModelManager::LoadModel("CRYpModelPlane", "../Assets/Models/Plane.azul");
	ModelManager::LoadModel("CRYpModelSpaceFrigate", "../Assets/Models/space_frigate.azul");
	//From premade

	LoadModel("CRYpModelSphere", Model::PreMadedeModels::UnitSphere);
	LoadModel("CRYpModelSprite", Model::PreMadedeModels::UnitSquareXY);
	LoadModel("CRYpModelBox", Model::PreMadedeModels::UnitBox_WF);
}

void ModelManager::PrivateUnloadAllModels()
{
	std::map<std::string, Model*>::iterator it = Instance().modelMap.begin();
	while (it != Instance().modelMap.end())
	{
		delete it->second;
		it->second = nullptr;
		it++;
	}

	delete self;
}
