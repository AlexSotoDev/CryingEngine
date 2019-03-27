#include "Axis.h"

#include "../Engine/ModelManager.h"
#include "../Engine/ShaderManager.h"


#include "../Engine/SceneManager.h"
#include "../Engine/CameraManager.h"

Axis::Axis()
{
	SubmitDrawRegistration();

	gObjAxis = new GraphicsObject_ColorNoTexture(ModelManager::GetModel("CRYpModelAxis"), ShaderManager::GetShader("CRYcolorNoTextureRender"));
	world = Matrix(IDENTITY);
	gObjAxis->SetWorld(world);
}

Axis::~Axis()
{
	SubmitDrawDeregistration();

	delete gObjAxis;
}

void Axis::Draw()
{
	gObjAxis->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());
}
