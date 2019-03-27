#ifndef _Visualizer
#define _Visualizer

#include "AzulCore.h"

#include "Align16.h"
#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"

#include <list>

class Collidable;
enum class CollisionVolumeType;

/**********************************************************************************************//**
 * \class	Visualizer
 *
 * \brief	A singleton visualizer for use with graphically representing collision volumes.
 *
 * \author	Alex
 * \date	3/8/2017
 **************************************************************************************************/

class Visualizer : public Align16
{
private:
	Visualizer() {};
	Visualizer(const Visualizer&) {};
	Visualizer& operator= (const Visualizer) {};
	~Visualizer();

	static Visualizer* self;



	static Visualizer& Instance()
	{
		if (!self)
		{
			self = new Visualizer();
		}
		return *self;
	};

	static Vect DEFAULT_COLOR;
	GraphicsObject_WireframeConstantColor* WFUnitSphere;
	GraphicsObject_WireframeConstantColor* WFUnitBox;

	struct visualizerData
	{
		Matrix wMat;
		Vect col;
		CollisionVolumeType volumeType;
	};

	std::list<visualizerData> visualizerList;

	/**********************************************************************************************//**
	 * \fn	void Visualizer::privRenderBSphere(Matrix& S, const Vect& color);
	 *
	 * \brief	Private function that renders  b sphere using a matrix and color to construct itself
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	S	 	The Matrix to process.
	 * \param 		  	color	The color (as an RGBA Vector).
	 **************************************************************************************************/

	void privRenderBSphere(Matrix& S, const Vect& color = DEFAULT_COLOR);

	/**********************************************************************************************//**
	 * \fn	void Visualizer::privCreatePrimitives();
	 *
	 * \brief	Private function that creates a unit sphere wire frame using the default engine unit sphere and default constant color shader for graphical representation along with setting a default color
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	void privCreatePrimitives();

	void privRenderAll();
	
	void privDelete();

	void privRenderAABB(Matrix& S, const Vect& color = DEFAULT_COLOR);

	void privRenderOBB(Matrix& S, const Vect& color = DEFAULT_COLOR);

public:

	/**********************************************************************************************//**
	 * \fn	static void Visualizer::ShowSphere(CollisionVolumeBSphere& S, const Vect& col = DEFAULT_COLOR)
	 *
	 * \brief	Public accessor function for showing/rendering the sphere the sphere in the scene. Used for toggling on/off visuals
	 * 			
	 * \sa		Visualizer::privRenderBSphere
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	S  	The CollisionVolumeBSphere to process.
	 * \param 		  	col	(Optional) The col.
	 **************************************************************************************************/

	static void ShowSphere(CollisionVolumeBSphere& S, const Vect& col = DEFAULT_COLOR) { Instance().privRenderBSphere(S.GetWorld(), col); }

	/**********************************************************************************************//**
	 * \fn	static void Visualizer::CreatePrimitives()
	 *
	 * \brief	Public accessor function for creation of the sphere. 
	 * 			
	 * \sa		Visualizer::privCreatePrimitives
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	static void CreatePrimitives() { Instance().privCreatePrimitives(); }

	static void RenderAll() { Instance().privRenderAll(); }

	static void Delete() { Instance().privDelete(); }

	static void ShowCollisionVolume(Collidable* collidable, const Vect& color);

	static void ShowAABB(CollisionVolumeAABB& AABB, const Vect& color = DEFAULT_COLOR) { Instance().privRenderAABB(AABB.GetWorld(), color); }

	static void ShowOBB(CollisionVolumeOBB& OBB, const Vect& color = DEFAULT_COLOR) { Instance().privRenderOBB(OBB.GetWorld(), color); }
};

#endif _Visualizer
