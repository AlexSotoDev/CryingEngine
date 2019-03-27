#include "Plane.h"

#include "../Engine/ModelManager.h"
#include "../Engine/ShaderManager.h"
#include "../Engine/TextureManager.h"
#include "../Engine/CameraManager.h"

#include "../Engine/SceneManager.h"

Plane::Plane()
{
	SubmitDrawRegistration();

	color = Vect(1,1,1);
	position = Vect(1, 1, 1);

	gObjTL = new GraphicsObject_TextureLight(ModelManager::GetModel("Model_Terrain"), ShaderManager::GetShader("CRYtextureLightRender"), TextureManager::GetTexture("Texture_Terrain"), color, position);
	world = Matrix(SCALE, 1.0f, 1.0f, 1.0f);
	gObjTL->SetWorld(world);
}

Plane::~Plane()
{
	delete gObjTL;

	SubmitDrawDeregistration();
}

void Plane::Draw()
{
	gObjTL->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera());
}
