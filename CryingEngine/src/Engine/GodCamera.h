#ifndef _GodCamera
#define _GodCamera

#include "AzulCore.h"
#include "Align16.h"

#include "Updatable.h"

class Camera;

/**********************************************************************************************//**
 * \class	GodCamera
 *
 * \brief	A god camera whose view can be changed with NUMPAD keys (4,5,6,8) for user to manipulate the current 3D camera freely. Testing/debugging tool.
 *
 * \author	Alex
 * \date	3/8/2017
 **************************************************************************************************/

class GodCamera : public Updatable, public Align16
{
private:
	Camera* godCamHandle;

	// Camera vars
	Vect CamPos;
	Matrix CamRot;	// No rotation initially
	Vect CamUp;			// Using local Y axis as 'Up'
	Vect CamDir;			// Using the local Z axis as 'forward'
	float CamTranSpeed;
	float CamRotSpeed;


public:

	GodCamera();
	~GodCamera();
	GodCamera& operator=(const GodCamera&) = delete;
	GodCamera(const GodCamera&) = delete;

	void Update() override;
};

#endif // !_GodCamera

