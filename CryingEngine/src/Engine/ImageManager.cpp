#include "ImageManager.h"

ImageManager* ImageManager::self = NULL;


void ImageManager::PrivateCreateImage(Texture * sampleTexture, Rect * rectSample, std::string imageName)
{
	Instance().imageMap[imageName] = new Image(sampleTexture, rectSample);
}

Image* ImageManager::PrivateGetImage(std::string imageName)
{
	return Instance().imageMap[imageName];
}

void ImageManager::PrivateLoadDefaultImages()
{
	
}

void ImageManager::PrivateUnLoadAllImages()
{
	std::map<std::string, Image*>::iterator it = Instance().imageMap.begin();
	while (it != Instance().imageMap.end())
	{
		delete it->second;
		it->second = nullptr;
		it++;
	}

	delete self;
}
