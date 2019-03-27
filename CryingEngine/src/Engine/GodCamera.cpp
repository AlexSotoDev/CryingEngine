#include "GodCamera.h"
#include "SceneManager.h"
#include "Scene.h"
#include "CameraManager.h"

GodCamera::GodCamera()
{
	godCamHandle = SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent3DCamera();

	// Camera vars
	CamPos = Vect(50.0f, 100.0f, 500.0f);
	CamRot = Matrix(IDENTITY);		// No rotation initially
	CamUp = Vect(0, 1, 0);			// Using local Y axis as 'Up'
	CamDir = Vect(0, 0, 1);			// Using the local Z axis as 'forward'
	CamTranSpeed = 2;
	CamRotSpeed = .02f;

	Vect Target(0, 0, 0);
	CamRot.set(ROT_ORIENT, Target - CamPos, CamUp);
	SubmitUpdateRegistration();
}

GodCamera::~GodCamera()
{
	godCamHandle = nullptr;
	SubmitUpdateDeregistration();
}

void GodCamera::Update()
{
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_KP_8))
	{
		CamPos += Vect(0, 0, 1) * CamRot * CamTranSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_KP_5))
	{
		CamPos += Vect(0, 0, 1) * CamRot * -CamTranSpeed;
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_KP_4))
	{
		CamPos += Vect(1, 0, 0) * CamRot * CamTranSpeed;
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_KP_6))
	{
		CamPos += Vect(1, 0, 0) * CamRot * -CamTranSpeed;
	}

	// Camera Rotation movement (NOTE: This time, I'm NOT using time-based values for simplicity)
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		CamRot *= Matrix(ROT_Y, CamRotSpeed);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		CamRot *= Matrix(ROT_Y, -CamRotSpeed);
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
	{
		CamRot *= Matrix(ROT_AXIS_ANGLE, Vect(1, 0, 0) * CamRot, -CamRotSpeed);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		CamRot *= Matrix(ROT_AXIS_ANGLE, Vect(1, 0, 0) * CamRot, CamRotSpeed);
	}

	// Update the camera settings
	godCamHandle->setOrientAndPosition(CamUp * CamRot, CamPos + CamDir * CamRot, CamPos);
	godCamHandle->updateCamera();
}


