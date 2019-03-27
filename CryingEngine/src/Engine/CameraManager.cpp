#include "CameraManager.h"
#include "CryingEngine.h"

CameraManager::CameraManager()
{
	SetDefaultCameras();
}

CameraManager::~CameraManager()
{
	delete current3DCamera;
	delete current2DCamera;
}

void CameraManager::SetDefaultCameras()
{

	default3DCam = new Camera(Camera::Type::PERSPECTIVE_3D);
	assert(default3DCam);
	default3DCam->setViewport(0, 0, CryingEngine::GetWidth(), CryingEngine::GetHeight());
	default3DCam->setPerspective(35.0f, float(CryingEngine::GetWidth()) / float(CryingEngine::GetWidth()), 1.0f, 5000.0f);

	// Orient Camera
	Vect up3DCam(0.0f, 1.0f, 0.0f);
	Vect pos3DCam(50.0f, 50.0f, 150.0f);
	Vect lookAt3DCam(0.0f, 0.0f, 0.0f);
	default3DCam->setOrientAndPosition(up3DCam, lookAt3DCam, pos3DCam);
	default3DCam->updateCamera();  // Note: if the camera moves/changes, we need to call update again

	current3DCamera = default3DCam;
	current3DCamera->updateCamera();

	default2DCam = new Camera(Camera::Type::ORTHOGRAPHIC_2D);
	assert(default2DCam);
	default2DCam->setViewport(0, 0, CryingEngine::GetWidth(), CryingEngine::GetHeight());
	default2DCam->setOrthographic(-0.5f * CryingEngine::GetWidth(), 0.5f*CryingEngine::GetWidth(), -0.5f * CryingEngine::GetHeight(), 0.5f * CryingEngine::GetHeight(), 1.0f, 1000.0f);

	// Orient 2D Camera
	Vect up2DCam(0.0f, 1.0f, 0.0f);
	Vect pos2DCam(0.0f, 0.0f, 0.0f);
	Vect lookAt2DCam(0.0f, 0.0f, -1.0f);

	default2DCam->setOrientAndPosition(up2DCam, lookAt2DCam, pos2DCam);
	default2DCam->updateCamera();

	current2DCamera = default2DCam;
	current2DCamera->updateCamera();

}

Camera * CameraManager::GetCurrent2DCamera()
{
	return current2DCamera;
}

Camera * CameraManager::GetCurrent3DCamera()
{
	return current3DCamera;
}

void CameraManager::DeleteCurrentCameras()
{
	delete current3DCamera;
	delete current2DCamera;
	//delete default3DCam;
}




