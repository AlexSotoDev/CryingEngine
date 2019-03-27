#ifndef SoundEngine_H
#define SoundEngine_H

#include <fmod.hpp>
#include <fmod_errors.h>
#include <map>
#include <unordered_map>
#include <string>
#include "SoundModeEnum.h"
#include "Vect.h"
#include "Align16.h"

using namespace FMOD;

class SceneManager;

//Singleton class for sound engine

class SoundEngine : public Align16
{
	//typedef FMOD::Sound* SoundObject;

	//map for all sounds
	typedef std::map<std::string, FMOD::Sound*> SoundMap;

	//map for all channel groups
	typedef std::map<std::string, FMOD::ChannelGroup*> ChannelGroupMap;


	//friend class SceneManager;

private:

	Vect defaultVector = Vect(0, 0, 0);

	//Pointer to the FMOD system
	FMOD::System *soundSystem = nullptr;

	FMOD::ChannelGroup* masterGroup = nullptr;

	


	static SoundEngine *self; //pointer to itself

							  //Instance Creation


	

	FMOD_RESULT PrivateInitializeSystem(const int numChannels);

	FMOD_RESULT PrivateUpdate();

	FMOD_RESULT PrivateReleaseSystem();

	FMOD_RESULT PrivateCreateSound(std::string soundName, const char* pFilePath, soundMode mode = soundMode::Sound_Default);

	Sound* PrivateGetSound(std::string soundName);

	FMOD_RESULT PrivatePlaySound(std::string soundName, std::string channelGroupName, Vect& position, float Volume);

	FMOD_RESULT PrivateCreateChannelGroup(std::string groupName);

	SoundMap soundMap;

	ChannelGroupMap channelGroupMap;

	FMOD_RESULT PrivateErrorCheck(FMOD_RESULT res);


	FMOD_RESULT PrivateStopAllSounds();

	FMOD_RESULT PrivateStopAllSoundsInChannelGroup(std::string channelGroupName);



	FMOD_RESULT PrivatePauseAllSoundsInChannelGroup(std::string channelGroupName);

	FMOD_RESULT PrivateUnPauseAllSoundsInChannelGroup(std::string channelGroupName);


	FMOD_RESULT PrivatePauseAllSounds();

	FMOD_RESULT PrivateUnPauseAllSounds();


	FMOD_RESULT PrivateSetMasterVolume(const float vol);

	FMOD_RESULT PrivateSetChannelGroupVolume(std::string channelGroupName, float vol);


	

public:

	static SoundEngine& Instance()
	{
		if (!self)
		{
			self = new SoundEngine();
		}

		return *self;
	}

	SoundEngine() {};
	SoundEngine(const SoundEngine& other) = delete;
	SoundEngine& operator = (const SoundEngine&) = delete;
	~SoundEngine();


	static FMOD_RESULT InitializeSystem(int numChannels = 32)
	{
		return Instance().PrivateInitializeSystem(numChannels);
	}
	
	static FMOD_RESULT Update()
	{
		return Instance().PrivateUpdate();
	}
	
	static FMOD_RESULT UnloadSounds()
	{
		return Instance().PrivateReleaseSystem();
	}

	static Sound* GetSound(std::string soundName)
	{
		return Instance().PrivateGetSound(soundName);
	}

	static FMOD_RESULT CreateSound(std::string soundName, const char* pFilePath, soundMode mode = soundMode::Sound_Default)
	{
		return Instance().PrivateCreateSound(soundName, pFilePath, mode);
	}

	static FMOD_RESULT PlaySound(std::string soundName, std::string channelGroupName = "Master", Vect& position = Instance().defaultVector , float volume = 1.0f)
	{
		return Instance().PrivatePlaySound(soundName, channelGroupName, position, volume);
	}

	static FMOD_RESULT ErrorCheck(FMOD_RESULT res)
	{
		return Instance().PrivateErrorCheck(res);
	}

	static FMOD_RESULT StopAllSounds()
	{
		return Instance().PrivateStopAllSounds();
	}

	static FMOD_RESULT StopAllSoundsInChannelGroup(std::string channelGroupName)
	{
		return Instance().StopAllSoundsInChannelGroup(channelGroupName);
	}
};


#endif // !SoundEngine_H



