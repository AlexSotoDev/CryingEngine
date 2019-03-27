#include "MathTools.h"


#include "Collidable.h"
#include <cfloat>


bool MathTools::Intersect(Collidable * collidable1, Collidable * collidable2)
{
	CollisionVolume& v1 = collidable1->GetCollisionVolume();
	CollisionVolume& v2 = collidable2->GetCollisionVolume();

	return v1.Intersect(v2);
}

float MathTools::RadiansToDegrees(float rad)
{
	float deg = rad * (180 / MATH_PI);
	return deg;
}

float MathTools::DegreesToRadians(float degrees)
{
	float rad = degrees * (MATH_PI / 180);
	return rad;
}

bool MathTools::Intersect(CollisionVolumeBSphere & A, CollisionVolumeBSphere & B)
{
	float dist = (A.GetCenter() - B.GetCenter()).mag();
	float radiiSum = A.GetRadius() + B.GetRadius();
	if (dist <= radiiSum)
	{
		return true;
	}

	return false;
}

bool MathTools::Intersect(CollisionVolumeAABB & A, CollisionVolumeAABB & B)
{
	Vect minA = A.GetCornerMin();
	Vect maxA = A.GetCornerMax();

	Vect minB = B.GetCornerMin();
	Vect maxB = B.GetCornerMax();

	bool result = false;
	//Test the negative cases
	//For each axis
	if (((maxA.X() < minB.X()) || (maxB.X() < minA.X())))
	{
		result = false;
		return result;
	}
	else
	{
		if ((maxA.Y() < minB.Y()) || (maxB.Y() < minA.Y()))
		{
			result = false;
			return result;
		}
		else
		{
			if ((maxA.Z() < minB.Z()) || (maxB.Z() < minA.Z()))
			{
				result = false;
				return result;
			}
			else
			{
				result = true;
			}
		}
	}

	return result;


}

bool MathTools::Intersect(CollisionVolumeAABB & A, CollisionVolumeBSphere & B)
{
	Vect clampedCenter = B.GetCenter();
	clampedCenter.X() = MathTools::Clamp(clampedCenter.X(), A.GetCornerMin().X(), A.GetCornerMax().X());
	clampedCenter.Y() = MathTools::Clamp(clampedCenter.Y(), A.GetCornerMin().Y(), A.GetCornerMax().Y());
	clampedCenter.Z() = MathTools::Clamp(clampedCenter.Z(), A.GetCornerMin().Z(), A.GetCornerMax().Z());

	if (((clampedCenter - B.GetCenter()).mag()) <= B.GetRadius())
	{
		return true;
	}

	return false;

}

bool MathTools::Intersect(CollisionVolumeOBB & A, CollisionVolumeBSphere & B)
{
	//Compute W^-1
	Matrix invWMatA = A.GetTrueWorld().getInv();
	//COMPUTE C' = W^-1 * C
	Vect centerPrime = B.GetCenter() * invWMatA;

	//Compute Q, version of C' (centerPrime) clamped to the OBB in local space
	Vect Q = centerPrime;
	Q.X() = MathTools::Clamp(Q.X(), A.GetCornerMin().X(), A.GetCornerMax().X());
	Q.Y() = MathTools::Clamp(Q.Y(), A.GetCornerMin().Y(), A.GetCornerMax().Y());
	Q.Z() = MathTools::Clamp(Q.Z(), A.GetCornerMin().Z(), A.GetCornerMax().Z());
	
	//Move to the clamped point in world Space. Test point (Q') vs BSphere
	Vect QPrime = Q* A.GetTrueWorld();

	float dist = (QPrime - B.GetCenter()).mag();

	//If inequality is true, then intersection

	//check magnitude against radius
	if (dist < (B.GetRadius()))
	{
		return true;
	}

	return false;
}

bool MathTools::Intersect(CollisionVolumeOBB & A, CollisionVolumeOBB & B)
{
	const int arrayLength = 15;

	//Get world matrices of each object
	Matrix OBBa = A.GetTrueWorld();
	Matrix OBBb = B.GetTrueWorld();

	//Set up 15 axes for SAT overlap test
	Vect ALeft = OBBa.get(MatrixRowType::ROW_0);
	Vect AUp = OBBa.get(MatrixRowType::ROW_1);
	Vect AForward = OBBa.get(MatrixRowType::ROW_2);

	Vect BLeft = OBBb.get(MatrixRowType::ROW_0);
	Vect BUp = OBBb.get(MatrixRowType::ROW_1);
	Vect BForward = OBBb.get(MatrixRowType::ROW_2);

	Vect ALeftxBLeft = ALeft.cross(BLeft);
	Vect ALeftxBUp = ALeft.cross(BUp);
	Vect ALeftxBForward = ALeft.cross(BForward);

	Vect AUpxBLeft = AUp.cross(BLeft);
	Vect AUpxBUp = AUp.cross(BUp);
	Vect AUpxBForward = AUp.cross(BForward);

	Vect AForwardxBLeft = AForward.cross(BLeft);
	Vect AForwardxBUp = AForward.cross(BUp);
	Vect AForwardxBForward = AForward.cross(BForward);

	Vect axesArray[arrayLength];
	axesArray[0] = ALeft;
	axesArray[1] = AUp;
	axesArray[2] = AForward;

	axesArray[3] = BLeft;
	axesArray[4] = BUp;
	axesArray[5] = BForward;

	axesArray[6] = ALeftxBLeft;
	axesArray[7] = ALeftxBUp;
	axesArray[8] = ALeftxBForward;
	
	axesArray[9] = AUpxBLeft;
	axesArray[10] = AUpxBUp;
	axesArray[11] = AUpxBForward;

	axesArray[12] = AForwardxBLeft;
	axesArray[13] = AForwardxBUp;
	axesArray[14] = AForwardxBForward;


	//Get inverse W of each object
	Matrix OBBaInv = OBBa.getInv();
	Matrix OBBbInv = OBBb.getInv();

	//Set up for projection max

	Vect vLocalAArray[arrayLength];
	Vect vLocalBArray[arrayLength];

	//V local A
	Vect vlocalA1 = ALeft * OBBaInv;
	Vect vlocalA2 = AUp * OBBaInv;
	Vect vlocalA3 = AForward * OBBaInv;

	vLocalAArray[0] = vlocalA1;
	vLocalAArray[1] = vlocalA2;
	vLocalAArray[2] = vlocalA3;

	Vect vlocalA4 = BLeft * OBBaInv;
	Vect vlocalA5 = BUp * OBBaInv;
	Vect vlocalA6 = BForward * OBBaInv;

	vLocalAArray[3] = vlocalA4;
	vLocalAArray[4] = vlocalA5;
	vLocalAArray[5] = vlocalA6;

	Vect vlocalA7 = ALeftxBLeft * OBBaInv;
	Vect vlocalA8 = ALeftxBUp * OBBaInv;
	Vect vlocalA9 = ALeftxBForward * OBBaInv;

	vLocalAArray[6] = vlocalA7;
	vLocalAArray[7] = vlocalA8;
	vLocalAArray[8] = vlocalA9;

	Vect vlocalA10 = AUpxBLeft * OBBaInv;
	Vect vlocalA11 = AUpxBUp *  OBBaInv;
	Vect vlocalA12 = AUpxBForward * OBBaInv;

	vLocalAArray[9] = vlocalA10;
	vLocalAArray[10] = vlocalA11;
	vLocalAArray[11] = vlocalA12;

	Vect vlocalA13 = AForwardxBLeft * OBBaInv;
	Vect vlocalA14 = AForwardxBUp * OBBaInv;
	Vect vlocalA15 = AForwardxBForward * OBBaInv;

	vLocalAArray[12] = vlocalA13;
	vLocalAArray[13] = vlocalA14;
	vLocalAArray[14] = vlocalA15;

	//V local B

	Vect vlocalB1 = ALeft * OBBbInv;
	Vect vlocalB2 = AUp * OBBbInv;
	Vect vlocalB3 = AForward * OBBbInv;

	vLocalBArray[0] = vlocalB1;
	vLocalBArray[1] = vlocalB2;
	vLocalBArray[2] = vlocalB3;

	Vect vlocalB4 = BLeft * OBBbInv;
	Vect vlocalB5 = BUp * OBBbInv;
	Vect vlocalB6 = BForward * OBBbInv;

	vLocalBArray[3] = vlocalB4;
	vLocalBArray[4] = vlocalB5;
	vLocalBArray[5] = vlocalB6;

	Vect vlocalB7 = ALeftxBLeft * OBBbInv;
	Vect vlocalB8 = ALeftxBUp * OBBbInv;
	Vect vlocalB9 = ALeftxBForward * OBBbInv;

	vLocalBArray[6] = vlocalB7;
	vLocalBArray[7] = vlocalB8;
	vLocalBArray[8] = vlocalB9;

	Vect vlocalB10 = AUpxBLeft * OBBbInv;
	Vect vlocalB11 = AUpxBUp *  OBBbInv;
	Vect vlocalB12 = AUpxBForward * OBBbInv;

	vLocalBArray[9] = vlocalB10;
	vLocalBArray[10] = vlocalB11;
	vLocalBArray[11] = vlocalB12;

	Vect vlocalB13 = AForwardxBLeft * OBBbInv;
	Vect vlocalB14 = AForwardxBUp * OBBbInv;
	Vect vlocalB15 = AForwardxBForward * OBBbInv;

	vLocalBArray[12] = vlocalB10;
	vLocalBArray[13] = vlocalB11;
	vLocalBArray[14] = vlocalB12;

	float projArrA[arrayLength];
	float projArrB[arrayLength];

	//Get max of each volume
	Vect objAMax = A.GetCornerMax() - A.GetCenter();
	Vect objBMax = B.GetCornerMax() - B.GetCenter();

	//Calculate Projection max for each
	for (int i = 0; i < arrayLength; i++)
	{
		projArrA[i] = abs(vLocalAArray[i].X() * objAMax.X()) + abs(vLocalAArray[i].Y() * objAMax.Y()) + abs(vLocalAArray[i].Z() * objAMax.Z());
		projArrB[i] = abs(vLocalBArray[i].X() * objBMax.X()) + abs(vLocalBArray[i].Y() * objBMax.Y()) + abs(vLocalBArray[i].Z() * objBMax.Z());
	}


	//rho = proj_max * scale

	float rhoA[arrayLength];
	float rhoB[arrayLength];

	for (int i = 0; i < arrayLength; i++)
	{
		rhoA[i] = (projArrA[i] / axesArray[i].mag()) * A.GetScaleSquared();
		rhoB[i] = (projArrB[i] / axesArray[i].mag()) * B.GetScaleSquared();
	}

	// D = absolute value( (centerWorldB - centerworldA) * v )
	float Dist[arrayLength];

	Vect centerWorldDelta = B.GetCenterWorld() - A.GetCenterWorld();

	for (int i = 0; i < arrayLength; i++)
	{
		Dist[i] = abs(centerWorldDelta.dot(axesArray[i])) / axesArray[i].mag();
	}

	for (int i = 0; i < arrayLength; i++)
	{
		if (axesArray[i].magSqr() >= FLT_EPSILON)
		{
			if (Dist[i] >(rhoA[i] + rhoB[i]))
			{
				return false;
			}
		}
	}

	return true;
}

bool MathTools::Intersect(CollisionVolumeAABB & A, CollisionVolumeOBB & B)
{
	const int arrayLength = 15;

	//Get world matrices of each object
	Matrix OBBa = A.GetTrueWorld();
	Matrix OBBb = B.GetTrueWorld();

	//Set up 15 axes for SAT overlap test
	Vect ALeft = OBBa.get(MatrixRowType::ROW_0);
	Vect AUp = OBBa.get(MatrixRowType::ROW_1);
	Vect AForward = OBBa.get(MatrixRowType::ROW_2);

	Vect BLeft = OBBb.get(MatrixRowType::ROW_0);
	Vect BUp = OBBb.get(MatrixRowType::ROW_1);
	Vect BForward = OBBb.get(MatrixRowType::ROW_2);

	Vect ALeftxBLeft = ALeft.cross(BLeft);
	Vect ALeftxBUp = ALeft.cross(BUp);
	Vect ALeftxBForward = ALeft.cross(BForward);

	Vect AUpxBLeft = AUp.cross(BLeft);
	Vect AUpxBUp = AUp.cross(BUp);
	Vect AUpxBForward = AUp.cross(BForward);

	Vect AForwardxBLeft = AForward.cross(BLeft);
	Vect AForwardxBUp = AForward.cross(BUp);
	Vect AForwardxBForward = AForward.cross(BForward);

	Vect axesArray[arrayLength];
	axesArray[0] = ALeft;
	axesArray[1] = AUp;
	axesArray[2] = AForward;

	axesArray[3] = BLeft;
	axesArray[4] = BUp;
	axesArray[5] = BForward;

	axesArray[6] = ALeftxBLeft;
	axesArray[7] = ALeftxBUp;
	axesArray[8] = ALeftxBForward;

	axesArray[9] = AUpxBLeft;
	axesArray[10] = AUpxBUp;
	axesArray[11] = AUpxBForward;

	axesArray[12] = AForwardxBLeft;
	axesArray[13] = AForwardxBUp;
	axesArray[14] = AForwardxBForward;


	//Get inverse W of each object
	Matrix OBBaInv = OBBa.getInv();
	Matrix OBBbInv = OBBb.getInv();

	//Set up for projection max

	Vect vLocalAArray[arrayLength];
	Vect vLocalBArray[arrayLength];

	//V local A
	Vect vlocalA1 = ALeft * OBBaInv;
	Vect vlocalA2 = AUp * OBBaInv;
	Vect vlocalA3 = AForward * OBBaInv;

	vLocalAArray[0] = vlocalA1;
	vLocalAArray[1] = vlocalA2;
	vLocalAArray[2] = vlocalA3;

	Vect vlocalA4 = BLeft * OBBaInv;
	Vect vlocalA5 = BUp * OBBaInv;
	Vect vlocalA6 = BForward * OBBaInv;

	vLocalAArray[3] = vlocalA4;
	vLocalAArray[4] = vlocalA5;
	vLocalAArray[5] = vlocalA6;

	Vect vlocalA7 = ALeftxBLeft * OBBaInv;
	Vect vlocalA8 = ALeftxBUp * OBBaInv;
	Vect vlocalA9 = ALeftxBForward * OBBaInv;

	vLocalAArray[6] = vlocalA7;
	vLocalAArray[7] = vlocalA8;
	vLocalAArray[8] = vlocalA9;

	Vect vlocalA10 = AUpxBLeft * OBBaInv;
	Vect vlocalA11 = AUpxBUp *  OBBaInv;
	Vect vlocalA12 = AUpxBForward * OBBaInv;

	vLocalAArray[9] = vlocalA10;
	vLocalAArray[10] = vlocalA11;
	vLocalAArray[11] = vlocalA12;

	Vect vlocalA13 = AForwardxBLeft * OBBaInv;
	Vect vlocalA14 = AForwardxBUp * OBBaInv;
	Vect vlocalA15 = AForwardxBForward * OBBaInv;

	vLocalAArray[12] = vlocalA13;
	vLocalAArray[13] = vlocalA14;
	vLocalAArray[14] = vlocalA15;

	//V local B

	Vect vlocalB1 = ALeft * OBBbInv;
	Vect vlocalB2 = AUp * OBBbInv;
	Vect vlocalB3 = AForward * OBBbInv;

	vLocalBArray[0] = vlocalB1;
	vLocalBArray[1] = vlocalB2;
	vLocalBArray[2] = vlocalB3;

	Vect vlocalB4 = BLeft * OBBbInv;
	Vect vlocalB5 = BUp * OBBbInv;
	Vect vlocalB6 = BForward * OBBbInv;

	vLocalBArray[3] = vlocalB4;
	vLocalBArray[4] = vlocalB5;
	vLocalBArray[5] = vlocalB6;

	Vect vlocalB7 = ALeftxBLeft * OBBbInv;
	Vect vlocalB8 = ALeftxBUp * OBBbInv;
	Vect vlocalB9 = ALeftxBForward * OBBbInv;

	vLocalBArray[6] = vlocalB7;
	vLocalBArray[7] = vlocalB8;
	vLocalBArray[8] = vlocalB9;

	Vect vlocalB10 = AUpxBLeft * OBBbInv;
	Vect vlocalB11 = AUpxBUp *  OBBbInv;
	Vect vlocalB12 = AUpxBForward * OBBbInv;

	vLocalBArray[9] = vlocalB10;
	vLocalBArray[10] = vlocalB11;
	vLocalBArray[11] = vlocalB12;

	Vect vlocalB13 = AForwardxBLeft * OBBbInv;
	Vect vlocalB14 = AForwardxBUp * OBBbInv;
	Vect vlocalB15 = AForwardxBForward * OBBbInv;

	vLocalBArray[12] = vlocalB10;
	vLocalBArray[13] = vlocalB11;
	vLocalBArray[14] = vlocalB12;

	float projArrA[arrayLength];
	float projArrB[arrayLength];

	//Get max of each volume
	Vect objAMax = A.GetLocalCornerMax() - A.GetLocalCenter();
	Vect objBMax = B.GetCornerMax() - B.GetCenter();

	//Calculate Projection max for each
	for (int i = 0; i < arrayLength; i++)
	{
		projArrA[i] = abs(vLocalAArray[i].X() * objAMax.X()) + abs(vLocalAArray[i].Y() * objAMax.Y()) + abs(vLocalAArray[i].Z() * objAMax.Z());
		projArrB[i] = abs(vLocalBArray[i].X() * objBMax.X()) + abs(vLocalBArray[i].Y() * objBMax.Y()) + abs(vLocalBArray[i].Z() * objBMax.Z());
	}


	//rho = proj_max * scale

	float rhoA[arrayLength];
	float rhoB[arrayLength];

	for (int i = 0; i < arrayLength; i++)
	{
		rhoA[i] = (projArrA[i] / axesArray[i].mag()) * A.GetScaleSquared();
		rhoB[i] = (projArrB[i] / axesArray[i].mag()) * B.GetScaleSquared();
	}

	// D = absolute value( (centerWorldB - centerworldA) * v )
	float Dist[arrayLength];

	Vect centerWorldDelta = B.GetCenterWorld() - A.GetCenter();

	for (int i = 0; i < arrayLength; i++)
	{
		Dist[i] = abs(centerWorldDelta.dot(axesArray[i])) / axesArray[i].mag();
	}

	for (int i = 0; i < arrayLength; i++)
	{
		if (axesArray[i].magSqr() >= FLT_EPSILON)
		{
			if (Dist[i] >(rhoA[i] + rhoB[i]))
			{
				return false;
			}
		}
	}

	return true;
}

Vect MathTools::CalculateCornerMin(Model * pMod, Matrix & worldMat)
{
	Vect* vertArray = pMod->getVectList();
	Vect temp;
	float minX = (vertArray[0] * worldMat).X();
	float minY = (vertArray[0] * worldMat).Y();
	float minZ = (vertArray[0] * worldMat).Z();

	for (int i = 0; i < pMod->getVectNum(); i++)
	{
		temp = vertArray[i] * worldMat;
		if (temp.X() < minX)
		{
			minX = temp.X();
		}
		if (temp.Y() < minY)
		{
			minY = temp.Y();
		}
		if (temp.Z() < minZ)
		{
			minZ = temp.Z();
		}
	}

	Vect result = Vect(minX, minY, minZ);

	return result;

}

Vect MathTools::CalculateCornerMax(Model * pMod, Matrix & worldMat)
{
	Vect* vertArray = pMod->getVectList();
	Vect temp;
	float maxX = (vertArray[0] * worldMat).X();
	float maxY = (vertArray[0] * worldMat).Y();
	float maxZ = (vertArray[0] * worldMat).Z();

	for (int i = 0; i < pMod->getVectNum(); i++)
	{
		temp = vertArray[i] * worldMat;
		if (temp.X() > maxX)
		{
			maxX = temp.X();
		}
		if (temp.Y() > maxY)
		{
			maxY = temp.Y();
		}
		if (temp.Z() > maxZ)
		{
			maxZ = temp.Z();
		}
	}

	Vect result = Vect(maxX, maxY, maxZ);

	return result;
}

Vect MathTools::CalculateCenter(Vect & min, Vect & max)
{
	Vect temp = min + max;
	temp.X() = temp.X() / 2.0f;
	temp.Y() = temp.Y() / 2.0f;
	temp.Z() = temp.Z() / 2.0f;
	return temp;
}

float MathTools::Clamp(float val, float min, float max)
{
	float result = val;
	if (result < min)
	{
		result = min;
	}
	else if (result > max)
	{
		result = max;
	}

	return result;

}

Vect MathTools::CalculateMinVect(Vect & vectA, Vect & vectB)
{
	float absoluteMinX;
	float absoluteMinY;
	float absoluteMinZ;
	//X
	if (vectA.X() <= vectB.X())
	{
		absoluteMinX = vectA.X();
	}

	else
	{
		absoluteMinX = vectB.X();
	}


	//Y
	if (vectA.Y() <= vectB.Y())
	{
		absoluteMinY = vectA.Y();
	}

	else
	{
		absoluteMinY = vectB.Y();
	}
	

	//Z
	if (vectA.Z() <= vectB.Z())
	{
		absoluteMinZ = vectA.Z();
	}

	else
	{
		absoluteMinZ = vectB.Z();
	}

	return Vect(absoluteMinX, absoluteMinY, absoluteMinZ, 0);
}

Vect MathTools::CalculateMaxVect(Vect & vectA, Vect & vectB)
{
	float absoluteMaxX;
	float absoluteMaxY;
	float absoluteMaxZ;
	//X
	if (vectA.X() >= vectB.X())
	{
		absoluteMaxX = vectA.X();
	}

	else
	{
		absoluteMaxX = vectB.X();
	}


	//Y
	if (vectA.Y() >= vectB.Y())
	{
		absoluteMaxY = vectA.Y();
	}

	else
	{
		absoluteMaxY = vectB.Y();
	}


	//Z
	if (vectA.Z() >= vectB.Z())
	{
		absoluteMaxZ = vectA.Z();
	}

	else
	{
		absoluteMaxZ = vectB.Z();
	}

	return Vect(absoluteMaxX, absoluteMaxY, absoluteMaxZ, 0);
}

//CollisionVolumeAABB MathTools::ConstructAABBFromBSphere(CollisionVolumeBSphere & bSphere)
//{
//	(void)bSphere;
//	//float radius = bSphere.GetRadius();
//	//Vect center = bSphere.GetCenter();
//	//CollisionVolumeAABB()
//	//return CollisionVolumeAABB();
//}



