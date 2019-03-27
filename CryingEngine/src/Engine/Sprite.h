#ifndef _Sprite
#define _Sprite

#include "AzulCore.h"

#include <string>

//including here for universal use across all objects w/ sprites
#include "EnumAngleMeasureType.h"

/**********************************************************************************************//**
 * \class	Sprite
 *
 * \brief	A sprite class that can be attached to objects in order to create/render 2D images (sprites) onto the screen in front of all 3D objects. Useful for HUD/UI.
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class Sprite : public Align16
{

private:

	/** \brief	The model sprite. Same for all */
	Model* pModelSprite;


	/** \brief	The shader object sprite. Same for all */
	ShaderObject* pShaderObject_sprite;


	/** \brief	The graphics object sprite created using model, shader, and image */
	GraphicsObject_Sprite* GraphObjSprite;


	/** \brief	The image the sprite is using */
	Image* pImageSprite;


	/** \brief	The scale matrix for the sprite */
	Matrix scaleMat;

	/** \brief	The z-rotation matrix (since it's 2D, we don't use x or y rotation) */
	Matrix zRotMat;


	/** \brief	The transformation matrix */
	Matrix transMat;


	/** \brief	The world matrix (TRS matrix) */
	Matrix worldMat;


	/** \brief	The center x coordinate */
	float centerX;

	/** \brief	The center y coordinate */
	float centerY;

	/** \brief	The sprite angle */
	float spriteAngle;


	/** \brief	The sprite scale by x  */
	float spriteScaleX;

	/** \brief	The sprite scale by y */
	float spriteScaleY;


public:

	/**********************************************************************************************//**
	 * \fn	Sprite::Sprite(std::string spriteImage);
	 *
	 * \brief	Constructor for sprites, taking a string name for an image, which finds the corresponding key in our @ImageManager and returns it for use in creation of a sprite object.
	 *
	 * \sa		ImageManager::GetImage 
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	spriteImage	The sprite image.
	 **************************************************************************************************/

	Sprite(std::string spriteImage);

	/**********************************************************************************************//**
	 * \fn	Sprite::~Sprite();
	 *
	 * \brief	Destructor. Deletes the graphics object sprite.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	~Sprite();
	Sprite(const Sprite&) = delete; //overload copy constructor
	Sprite& operator=(const Sprite&) = delete;

	/**********************************************************************************************//**
	 * \fn	void Sprite::Render();
	 *
	 * \brief	Renders this object, calling render on the graphics object sprite using the 2D camera
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 **************************************************************************************************/

	void Render();

	/**********************************************************************************************//**
	 * \fn	void Sprite::SetPosition(float x, float y);
	 *
	 * \brief	Sets a position for the sprite
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	x	The x coordinate.
	 * \param	y	The y coordinate.
	 **************************************************************************************************/

	void SetPosition(float x, float y);

	/**********************************************************************************************//**
	 * \fn	Vect Sprite::GetPosition();
	 *
	 * \brief	Gets/returns the position as a vector.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \return	The position.
	 **************************************************************************************************/

	Vect GetPosition();

	/**********************************************************************************************//**
	 * \fn	void Sprite::SetAngle(float angle, ANGLE_MEASURE_TYPE type = ANGLE_MEASURE_TYPE::RADIAN);
	 *
	 * \brief	Sets an angle for the sprite in radians or degrees (defaults to radians).
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	angle	The angle.
	 * \param	type 	(Optional) The angle measure type.
	 **************************************************************************************************/

	void SetAngle(float angle, ANGLE_MEASURE_TYPE type = ANGLE_MEASURE_TYPE::RADIAN);

	/**********************************************************************************************//**
	 * \fn	float Sprite::GetAngle(ANGLE_MEASURE_TYPE type = ANGLE_MEASURE_TYPE::RADIAN);
	 *
	 * \brief	Gets/returns an angle of the sprite in radians or degrees (default to radians)
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	type	(Optional) The angle measure type.
	 *
	 * \return	The angle.
	 **************************************************************************************************/

	float GetAngle(ANGLE_MEASURE_TYPE type = ANGLE_MEASURE_TYPE::RADIAN);

	/**********************************************************************************************//**
	 * \fn	void Sprite::SetScaleFactor(float scaleX, float scaleY);
	 *
	 * \brief	Sets scale factor for sprite
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	scaleX	The x scale.
	 * \param	scaleY	The y scale.
	 **************************************************************************************************/

	void SetScaleFactor(float scaleX, float scaleY);

	/**********************************************************************************************//**
	 * \fn	Vect Sprite::GetScaleFactor();
	 *
	 * \brief	Gets/returns scale factor as a vector.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \return	The scale factor.
	 **************************************************************************************************/

	Vect GetScaleFactor();

	/**********************************************************************************************//**
	 * \fn	void Sprite::SetScalePixel(float width, float height);
	 *
	 * \brief	Sets the scale in exact pixel size
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	width 	The width.
	 * \param	height	The height.
	 **************************************************************************************************/

	void SetScalePixel(float width, float height);

	/**********************************************************************************************//**
	 * \fn	void Sprite::SetCenter(float offsetX, float offsetY);
	 *
	 * \brief	Sets a center for the image in image space.
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	offsetX	The offset x coordinate.
	 * \param	offsetY	The offset y coordinate.
	 **************************************************************************************************/

	void SetCenter(float offsetX, float offsetY);


};


#endif
