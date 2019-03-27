#include "SoundEngine.h"
#include "DebugOut.h"

SoundEngine* SoundEngine::self = NULL;

FMOD_RESULT SoundEngine::PrivateInitializeSystem(const int numChannels)
{
	//FMOD::System** sys = nullptr;
	FMOD::System_Create(&(Instance().soundSystem));
	FMOD_RESULT res= Instance().soundSystem->init(numChannels, FMOD_INIT_NORMAL, 0);

	//Adding it to my main channel group
	Instance().soundSystem->getMasterChannelGroup(&(Instance().masterGroup));

	if (res == FMOD_RESULT::FMOD_OK)
	{
		Instance().channelGroupMap["Master"] = Instance().masterGroup;
	}

	
	return res;
}

FMOD_RESULT SoundEngine::PrivateUpdate()
{
	return Instance().soundSystem->update();
}

FMOD_RESULT SoundEngine::PrivateReleaseSystem()
{
	auto it = Instance().soundMap.begin();
	while (it != Instance().soundMap.end())
	{
		it->second->release();
		it++;
	}
	Instance().soundMap.clear();

	//Clear channel groups
	Instance().channelGroupMap.clear();

	return Instance().soundSystem->release();
}

FMOD_RESULT SoundEngine::PrivateCreateSound(std::string soundName, const char * pFilePath, soundMode mode)
{
	
	Sound* pSound = nullptr;
	FMOD_RESULT res = Instance().soundSystem->createSound(pFilePath, FMOD_MODE(mode), 0, &pSound);
	if (res == FMOD_RESULT::FMOD_OK)
	{
		Instance().soundMap[soundName] = pSound;
	}
	return res;
	
}

Sound* SoundEngine::PrivateGetSound(std::string soundName)
{
	return Instance().soundMap[soundName];
}

FMOD_RESULT SoundEngine::PrivatePlaySound(std::string soundName, std::string channelGroupName, Vect& position, float volume)
{
	//Max channels playing is set by initialization
	Channel* channel;
	FMOD_RESULT res =Instance().soundSystem->playSound(soundMap[soundName], channelGroupMap[channelGroupName], 1, &channel);
	FMOD_VECTOR fVect
	{
		position.X(),
		position.Y(),
		position.Z()
	};
	channel->set3DAttributes(&fVect, 0);
	channel->setVolume(volume);
	channel->setPaused(0);
	return res;
}

FMOD_RESULT SoundEngine::PrivateCreateChannelGroup(std::string groupName)
{
	//Creating the new channel group
	FMOD::ChannelGroup* group;
	FMOD_RESULT res = Instance().soundSystem->createChannelGroup(groupName.c_str(), &group);

	//Parameters are the group we want to add to current group, whether we want to pass down the DSP properties (https://www.fmod.org/docs/content/generated/FMOD_ChannelControl_GetDSPClock.html) and address of var to receive ptr
	Instance().masterGroup->addGroup(group, true, 0);

	if (res == FMOD_RESULT::FMOD_OK)
	{
		Instance().channelGroupMap[groupName] = group;
	}	

	return res;
}

FMOD_RESULT SoundEngine::PrivateErrorCheck(FMOD_RESULT res)
{
	DebugMsg::out((char*)FMOD_ErrorString(res));
	DebugMsg::out("\n");
	return res;
}

FMOD_RESULT SoundEngine::PrivateStopAllSounds()
{
	return Instance().channelGroupMap["Master"]->stop();
}

FMOD_RESULT SoundEngine::PrivateStopAllSoundsInChannelGroup(std::string channelGroupName)
{
	return Instance().channelGroupMap[channelGroupName]->stop();
}

FMOD_RESULT SoundEngine::PrivatePauseAllSoundsInChannelGroup(std::string channelGroupName)
{
	return Instance().channelGroupMap[channelGroupName]->setPaused(true);
}

FMOD_RESULT SoundEngine::PrivateUnPauseAllSoundsInChannelGroup(std::string channelGroupName)
{
	return Instance().channelGroupMap[channelGroupName]->setPaused(false);
}

FMOD_RESULT SoundEngine::PrivatePauseAllSounds()
{
	return Instance().masterGroup->setPaused(true);
}

FMOD_RESULT SoundEngine::PrivateUnPauseAllSounds()
{
	return Instance().masterGroup->setPaused(false);
}

FMOD_RESULT SoundEngine::PrivateSetMasterVolume(const float vol)
{
	return Instance().masterGroup->setVolume(vol);
}

FMOD_RESULT SoundEngine::PrivateSetChannelGroupVolume(std::string channelGroupName, float vol)
{
	return Instance().channelGroupMap[channelGroupName]->setVolume(vol);
}

SoundEngine::~SoundEngine()
{

}
