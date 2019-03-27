#ifndef _ImageManager
#define _ImageManager

// Singleton image manager

#include "AzulCore.h"

// include map
#include <map>

/**********************************************************************************************//**
 * \class	ImageManager
 *
 * \brief	Singleton manager for Images created from Textures. Has methods for Creating, Loading, Unloading, and Getting images (private functions and public accessors)
 *
 * \author	Alex
 * \date	3/8/2017
 **************************************************************************************************/

class ImageManager
{
private:

	static ImageManager *self; //pointer to itself

	ImageManager() {}; //empty contructor
	ImageManager(const ImageManager&) {};
	ImageManager& operator = (const ImageManager&) {};

	~ImageManager() {}; //destructor

						//Instance Creation
	static ImageManager& Instance()
	{
		if (!self)
		{
			self = new ImageManager();
		}

		return *self;
	}


	/** \brief	STL Map pointers to all image objects */
	std::map<std::string, Image*> imageMap;

	/**********************************************************************************************//**
	 * \fn	void ImageManager::PrivateCreateImage(Texture* sampleTexture, Rect* rectSample, std::string imageName);
	 *
	 * \brief	Private create image called that takes a texture and uses a rectangle from the texture to sample it/create the image. Called by public accessor function.
	 *
	 * \sa		ImageManager::CreateImage
	 * 
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	sampleTexture	If non-null, the sample texture.
	 * \param [in,out]	rectSample   	If non-null, the rectangle sample.
	 * \param 		  	imageName	 	Name of the image.
	 **************************************************************************************************/

	void PrivateCreateImage(Texture* sampleTexture, Rect* rectSample, std::string imageName);

	/**********************************************************************************************//**
	 * \fn	Image* ImageManager::PrivateGetImage(std::string imageName);
	 *
	 * \brief	Private get image that uses an image name to find it within the image map and return it to the user. Called by public accessor function.
	 *
	 * \sa		ImageManager::GetImage
	 *    
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param	imageName	Name of the image.
	 *
	 * \return	Null if it fails, else a pointer to an Image.
	 **************************************************************************************************/

	Image* PrivateGetImage(std::string imageName);

	/**********************************************************************************************//**
	 * \fn	void ImageManager::PrivateLoadDefaultImages();
	 *
	 * \brief	Private load default images. Called by LoadContent within engine during initialization. For any images I might want to make default for users to have some basic assets. Called by public accessor function.
	 *
	 * \sa		ImageManager::LoadDefaultImages
	 * \sa		CryingEngine::LoadContent
	 *    
	 *    
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	void PrivateLoadDefaultImages();

	/**********************************************************************************************//**
	 * \fn	void ImageManager::PrivateUnLoadAllImages();
	 *
	 * \brief	Private un load all images. Called by UnLoad Content within engine during the termination. Unloads/clears memory of any images within image map. Called by public accessor function.
	 *
	 * \sa		CryingEngine::UnloadAllImages
	 * \sa		CryingEngine::LoadContent
	 *    
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	void PrivateUnLoadAllImages();



public:

	/**********************************************************************************************//**
	 * \fn	static void ImageManager::CreateImage(Texture* sampleTexture, Rect* rect, std::string imageName)
	 *
	 * \brief	Public accessor function for user to create an image through a name and sampling a rectangle from a texture object. Calls equivalent private function.
	 * 			
	 * \sa		ImageManager::PrivateCreateImage
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param [in,out]	sampleTexture	If non-null, the sample texture.
	 * \param [in,out]	rect		 	If non-null, the rectangle.
	 * \param 		  	imageName	 	Name of the image.
	 **************************************************************************************************/

	static void CreateImage(Texture* sampleTexture, Rect* rect, std::string imageName) { Instance().PrivateCreateImage(sampleTexture, rect, imageName); }

	/**********************************************************************************************//**
	 * \fn	static Image* ImageManager::GetImage(std::string imageName)
	 *
	 * \brief	Public accessor function for user to get a pointer to an image within their image map. Calls equivalent private function.
	 *
	 * \sa		ImageManager::GetImage
	 * 
	 * \author	Alex
	 * \date	3/8/2017
	 *
	 * \param	imageName	Name of the image.
	 *
	 * \return	Null if it fails, else the image.
	 **************************************************************************************************/

	static Image* GetImage(std::string imageName) { return Instance().PrivateGetImage(imageName); }

	/**********************************************************************************************//**
	 * \fn	static void ImageManager::LoadDefaultImages()
	 *
	 * \brief	Public accessor function for user to load the default images that come with the engine. Calls equivalent private function.
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	static void LoadDefaultImages() { Instance().PrivateLoadDefaultImages(); }

	/**********************************************************************************************//**
	 * \fn	static void ImageManager::UnLoadAllImages()
	 *
	 * \brief	Public accessor function for user to clean up memory/delete all images from map upon termination in the engine's UnLoadContent() function. Calls equivalent private function.
	 * 			
	 * \sa		ImageManager::PrivateLoadDefaultImages
	 * \sa		CryingEngine::UnLoadContent	
	 *
	 * \author	Alex
	 * \date	3/8/2017
	 **************************************************************************************************/

	static void UnLoadAllImages() { Instance().PrivateUnLoadAllImages(); }
};


#endif
