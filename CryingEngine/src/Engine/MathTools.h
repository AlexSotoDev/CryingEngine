#ifndef _MathTools
#define _MathTools

#include "CollisionVolumeBSphere.h"
#include "CollisionVolumeAABB.h"
#include "CollisionVolumeOBB.h"
//class CollisionVolumeBSphere;

/**********************************************************************************************//**
 * \class	MathTools
 *
 * \brief	Includes mathematical functions for added math user utilities
 *
 * \author	Alex
 * \date	3/11/2017
 **************************************************************************************************/
class Collidable;

class MathTools 

{

public:

	/**********************************************************************************************//**
	 * \fn	static bool MathTools::Intersect(CollisionVolumeBSphere& A, CollisionVolumeBSphere& B);
	 *
	 * \brief	Returns whether there's intersection/overlap between two b-sphere vollision volume
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param [in,out]	A	The first CollisionVolumeBSphere to process.
	 * \param [in,out]	B	The other CollisionVolumeBSphere to process.
	 *
	 * \return	True if it succeeds, false if it fails.
	 **************************************************************************************************/

	static bool Intersect(Collidable* collidable1, Collidable* collidable2);

	/**********************************************************************************************//**
	 * \fn	static float MathTools::RadiansToDegrees(float rad);
	 *
	 * \brief	Converts radians to degrees
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	rad	The radians.
	 *
	 * \return	A float.
	 **************************************************************************************************/

	static float RadiansToDegrees(float rad);

	/**********************************************************************************************//**
	 * \fn	static float MathTools::DegreesToRadians(float degrees);
	 *
	 * \brief	Converts degrees to radians
	 *
	 * \author	Alex
	 * \date	3/12/2017
	 *
	 * \param	degrees	The degrees.
	 *
	 * \return	A float.
	 **************************************************************************************************/

	static float DegreesToRadians(float degrees);

	static bool Intersect(CollisionVolumeBSphere & A, CollisionVolumeBSphere & B);
	
	static bool Intersect(CollisionVolumeAABB & A, CollisionVolumeAABB & B);

	static bool Intersect(CollisionVolumeAABB & A, CollisionVolumeBSphere & B);

	static bool Intersect(CollisionVolumeOBB & A, CollisionVolumeBSphere & B);

	static bool Intersect(CollisionVolumeOBB & A, CollisionVolumeOBB & B);

	static bool Intersect(CollisionVolumeAABB & A, CollisionVolumeOBB & B);

	static Vect CalculateCornerMin(Model* pMod, Matrix& worldMat);

	static Vect CalculateCornerMax(Model* pMod, Matrix& worldMat);

	static Vect CalculateCenter(Vect& min, Vect& max);

	static float Clamp(float val, float min, float max);

	static Vect CalculateMinVect(Vect& vectA, Vect& vectB);

	static Vect CalculateMaxVect(Vect& vectA, Vect& vectB);
	


	//static CollisionVolumeAABB ConstructAABBFromBSphere(CollisionVolumeBSphere& bSphere);

	//static bool Intersect(CollisionVolumeBSphere & A, Vect &vect);

};





#endif // !_MathTools

