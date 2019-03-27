#include "Sprite.h"
#include "ModelManager.h"
#include "ShaderManager.h"
#include "ImageManager.h"
#include "CryingEngine.h"
#include "SceneManager.h"
#include "CameraManager.h"

#include "MathTools.h"


Sprite::Sprite(std::string spriteImage)
{
	pModelSprite = ModelManager::GetModel("CRYpModelSprite");
	pShaderObject_sprite = ShaderManager::GetShader("CRYspriteRender");
	pImageSprite = ImageManager::GetImage(spriteImage);
	//Default to full size
	GraphObjSprite = new GraphicsObject_Sprite(pModelSprite, pShaderObject_sprite, pImageSprite, new Rect(0.0f, 0.0f, pImageSprite->pImageRect->width, pImageSprite->pImageRect->height));

	scaleMat.set(SCALE, 1.0f, 1.0f, 1.0f);
	zRotMat.set(ROT_Z, 0.0f);
	transMat.set(TRANS, GraphObjSprite->origPosX, GraphObjSprite->origPosY, 0.0f);
	worldMat = scaleMat * zRotMat * transMat;
	SetCenter(0.0f, 0.0f);
	GraphObjSprite->SetWorld(worldMat);
}

Sprite::~Sprite()
{
	delete GraphObjSprite;
}

void Sprite::Render()
{
	//Call render on graphics obj sprite using the current 2d cam
	GraphObjSprite->Render(SceneManager::GetCurrentScene()->GetCameraManager()->GetCurrent2DCamera());
}

void Sprite::SetPosition(float x, float y)
{
	transMat.set(TRANS,x, y, 1.0f);
	worldMat = scaleMat * zRotMat * transMat;
	GraphObjSprite->SetWorld(worldMat);
}

Vect Sprite::GetPosition()
{
	return Vect(centerX, centerY, 0.0f);
}

void Sprite::SetAngle(float angle, ANGLE_MEASURE_TYPE type)
{
	switch (type)
	{
	
	case (ANGLE_MEASURE_TYPE::RADIAN):
		spriteAngle = angle;
		break;

	case (ANGLE_MEASURE_TYPE::DEGREE):
		spriteAngle = MathTools::DegreesToRadians(angle);
		break;

	default:
		std::invalid_argument("Incorrect ANGLE_MEASURE_TYPE: Must be set to RADIAN or DEGREE");
		break;

	}

	zRotMat.set(ROT_Z, spriteAngle);
	// remove the translation part of matrix by multiplying by negative center
	// multiply by z rotation matrix
	// add translation offset back in by multiplying by center 
	zRotMat = Matrix(TRANS, -centerX, -centerY, 1) * zRotMat * Matrix(TRANS, centerX, centerY, 1);
	worldMat = scaleMat * zRotMat * transMat;
	GraphObjSprite->SetWorld(worldMat);


	// ***OLD METHOD****
	// HERE FOR REFERENCE FOR NOW IN CASE I BREAK SHIT IRREVERSIBLY
	
	//(void)type;
	
	//spriteAngle = angle;
	//zRotMat.set(ROT_Z, spriteAngle);

	//// remove the translation part of matrix by multiplying by negative center
	//// multiply by z rotation matrix
	//// add translation offset back in by multiplying by center 
	//zRotMat = Matrix(TRANS, -centerX, -centerY, 1.0f) * zRotMat * Matrix(TRANS, centerX, centerY, 1.0f);
	//worldMat = scaleMat * zRotMat * transMat;
	//GraphObjSprite->SetWorld(worldMat);

}

float Sprite::GetAngle(ANGLE_MEASURE_TYPE type)
{
	//(void)type;
	//return spriteAngle;
	// 

	float spriteAngleDeg = MathTools::RadiansToDegrees(spriteAngle);

	switch (type)
	{
	case (ANGLE_MEASURE_TYPE::RADIAN):
		return spriteAngle;
		break;

	case (ANGLE_MEASURE_TYPE::DEGREE):
		return spriteAngleDeg;
		break;

	default:
		std::invalid_argument("Incorrect ANGLE_MEASURE_TYPE: Must be set to RADIAN or DEGREE. Returning RADIAN by default.");
		return spriteAngle;
		break;
	}
}

void Sprite::SetScaleFactor(float scaleX, float scaleY)
{
	spriteScaleX = scaleX;
	spriteScaleY = scaleY;

	scaleMat.set(SCALE, spriteScaleX, spriteScaleY, 1.0f);
	worldMat = Matrix(SCALE, spriteScaleX, spriteScaleY, 1.0f) * zRotMat * transMat;

	GraphObjSprite->SetWorld(worldMat);
}

Vect Sprite::GetScaleFactor()
{
	return Vect(spriteScaleX, spriteScaleY, 1.0f);
}

void Sprite::SetScalePixel(float width, float height)
{
	spriteScaleX = width / GraphObjSprite->origWidth;
	spriteScaleY = height / GraphObjSprite->origHeight;

	SetScaleFactor(spriteScaleX, spriteScaleY);

}

void Sprite::SetCenter(float offsetX, float offsetY)
{
	centerX = offsetX;
	centerY = offsetY;
}




