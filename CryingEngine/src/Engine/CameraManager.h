#ifndef _CameraManager
#define _CameraManager

#include "AzulCore.h"

/**********************************************************************************************//**
 * \class	CameraManager
 *
 * \brief	Manager for cameras. One manager per scene.
 *
 * \author	Alex
 * \date	3/6/2017
 **************************************************************************************************/

class CameraManager 
{
private:



	/** \brief	Pointer to the current camera */
	Camera* current3DCamera;


	/** \brief	Pointer to the default camera */
	Camera *default3DCam;

	Camera* current2DCamera;

	Camera* default2DCam;



public:

	/**********************************************************************************************//**
	 * \fn	Camera* CameraManager::GetCurrent3DCamera();
	 *
	 * \brief	Gets/returns current camera. 
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 *
	 * \return	Null if it fails, else the current camera.
	 **************************************************************************************************/

	Camera* GetCurrent3DCamera();

	/**********************************************************************************************//**
	 * \fn	void CameraManager::DeleteCurrentCameras();
	 *
	 * \brief	Deletes the current camera.
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/


	void DeleteCurrentCameras();

	/**********************************************************************************************//**
	 * \fn	void CameraManager::SetDefaultCamera();
	 *
	 * \brief	Sets default camera 3D and 2D camera.
	 *
	 * \author	Alex
	 * \date	3/6/2017
	 **************************************************************************************************/

	void SetDefaultCameras();

	/**********************************************************************************************//**
	 * \fn	Camera* CameraManager::GetCurrent2DCamera();
	 *
	 * \brief	Gets/returns current 2D camera.
	 *
	 * \author	Alex
	 * \date	3/7/2017
	 *
	 * \return	Null if it fails, else the current 2D camera.
	 **************************************************************************************************/

	Camera* GetCurrent2DCamera();

	CameraManager();
	CameraManager(const CameraManager&) {};
	CameraManager& operator = (const CameraManager&) {};

	~CameraManager(); //destructor


	
};


#endif
