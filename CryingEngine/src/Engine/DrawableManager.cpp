#include "DrawableManager.h"

#include "Drawable.h"

#include "AzulCore.h"

#include "Visualizer.h"


void DrawableManager::Register(Drawable * draw)
{
	ref = DrawableList.insert(DrawableList.end(), draw);
	draw->SetIterator(ref);
}

void DrawableManager::Deregister(Drawable * draw)
{
	DrawableList.erase(draw->GetIterator());
}

void DrawableManager::ProcessElements()
{
	std::list<Drawable*>::iterator it = DrawableList.begin();

	//Draw 3D 
	
	while (it != DrawableList.end())
	{
		(*it)->Draw();
		it++;
	}

	//Draw Visualizer
	Visualizer::RenderAll();


	//Draw 2D 
	
	it = DrawableList.begin();
	while (it != DrawableList.end())
	{
		(*it)->Draw2D();
		it++;
	}
}

DrawableManager::~DrawableManager()
{
	DrawableList.clear();
}