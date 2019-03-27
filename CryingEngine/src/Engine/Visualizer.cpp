#include "Visualizer.h"

#include "SceneManager.h"
#include "Scene.h"
#include "CameraManager.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "ColorLibrary.h"

#include "Collidable.h"

Visualizer* Visualizer::self = NULL;


Visualizer::~Visualizer()
{
	delete Instance().WFUnitSphere;
}

void Visualizer::privRenderBSphere(Matrix & S, const Vect & color)
{
	//Pass data to our list through the visData
	visualizerData temp;
	temp.wMat = S;
	temp.col = color;
	temp.volumeType = CollisionVolumeType::BSphere;
	visualizerList.push_back(temp);
}

void Visualizer::privCreatePrimitives()
{
	Vect defaultCol = Colors::White;
	Instance().WFUnitSphere = new GraphicsObject_WireframeConstantColor(ModelManager::GetModel("CRYpModelSphere"), ShaderManager::GetShader("CRYcolorConstantRender"), defaultCol);
	Instance().WFUnitBox = new GraphicsObject_WireframeConstantColor(ModelManager::GetModel("CRYpModelBox"), ShaderManager::GetShader("CRYcolorConstantRender"), defaultCol);
}

void Visualizer::privRenderAll()
{
	auto it = Instance().visualizerList.begin();
	while (it != Instance().visualizerList.end())
	{
		if ((*it).volumeType == CollisionVolumeType::BSphere)
		{
			WFUnitSphere->pWireColor->set((*it).col);
			WFUnitSphere->SetWorld((*it).wMat);
			WFUnitSphere->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());
			++it;
			visualizerList.pop_front();
		}

		else if ((*it).volumeType == CollisionVolumeType::AABB)
		{
			WFUnitBox->pWireColor->set((*it).col);
			WFUnitBox->SetWorld((*it).wMat);
			WFUnitBox->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());
			++it;
			visualizerList.pop_front();
		}

		else if ((*it).volumeType == CollisionVolumeType::OBB)
		{
			WFUnitBox->pWireColor->set((*it).col);
			WFUnitBox->SetWorld((*it).wMat);
			WFUnitBox->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());
			++it;
			visualizerList.pop_front();
		}
	}

}

void Visualizer::privDelete()
{
	delete self;
}

void Visualizer::privRenderAABB(Matrix & S, const Vect & color)
{
	//Pass data to our list through the visData
	visualizerData temp;
	temp.wMat = S;
	temp.col = color;
	temp.volumeType = CollisionVolumeType::AABB;
	visualizerList.push_back(temp);
}

void Visualizer::privRenderOBB(Matrix & S, const Vect & color)
{
	//Pass data to our list through the visData
	visualizerData temp;
	temp.wMat = S;
	temp.col = color;
	temp.volumeType = CollisionVolumeType::OBB;
	visualizerList.push_back(temp);
}

void Visualizer::ShowCollisionVolume(Collidable * collidable, const Vect & color)
{
	collidable->GetCollisionVolume().DebugView(color);
	//if (collidable->GetDefaultBSphere())
	//{
	//	collidable->GetDefaultBSphere()->DebugView(color);
	//}
}


