#pragma once

#include "Resources/inc/fmod.hpp"

#pragma comment (lib, "Resources/lib/fmodex_vc.lib")

class AudioHandler
{
public:
	AudioHandler();
	~AudioHandler();

	void Initialise();
	void LoadAudio();

	void PlayGhostAudio();
	void PlayBackgroundAudio(float x, float y, float z);
private:
	FMOD::System*    mSystem;
    FMOD::Sound*     mSound1;
	FMOD::Sound*	 mSound2;
	FMOD::SOUND*	 mSound3;
    FMOD::Channel*   mChannel1 = 0;
	FMOD::Channel*	 mChannel2 = 0;
	FMOD::Channel*   mChannel3 = 0;
    int              mKey;
	int				 mNumDrivers;
    bool             mListenerFlag = true;
    FMOD_VECTOR      mListenerPos  = { 0.0f, 0.0f, -1.0f * DISTANCEFACTOR };
    FMOD_SPEAKERMODE mSpeakerMode;
    FMOD_CAPS        mCaps;
    char             mName[256];
private:

}