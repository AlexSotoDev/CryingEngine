#ifndef _NullScene
#define _NullScene

#include "Scene.h"

/**********************************************************************************************//**
 * \class	NullScene
 *
 * \brief	A null scene for use when initializing a scene using the Null object design pattern.
 *
 * \author	Alex
 * \date	3/12/2017
 **************************************************************************************************/

class NullScene : public Scene
{
private:



public:

	void Initialize() override;
	void SceneEnd();

};


#endif
