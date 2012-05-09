#pragma once

#include "Resources/inc/fmod.hpp"

#pragma comment (lib, "Resources/lib/fmodex_vc.lib")

namespace	//This namespace is anonymous, shoudl solve the const issues
{
	//TODO
	//Change the INTERFACE_UPDATETIME to comply with the actual later
	const int   INTERFACE_UPDATETIME = 50;      // 50ms update for interface
	const float DISTANCEFACTOR = 100.0f;          // Units per meter.  I.e feet would = 3.28.  centimeters would = 100.

};

class AudioHandler
{
public:

	AudioHandler();
	~AudioHandler();

	void Initialize();
	//Play sound functions
	void PlayBackgroundSound();
	void PlayCandySound();
	void PlayDeathSound();
	void PlayGhostSound( int lID, float lX, float lY, float lZ );
	void PlayMenuSound();
	void PlaySuperCandySound();
	void StopSound();

	void UpdatePosition(float lPosX, float lPosY, float lPosZ, float lDirX, float lDirY, float lDirZ);
	void UpdateGhostPosition(int lGhost, float lPosX, float lPosY, float lPosZ);

	float getPositionX();
	float getPositionY();
	float getPositionZ();
	void  PlayTest();

private:
	void LoadAudio();

private:
	FMOD::System*    mSystem;
	//Sounds
    FMOD::Sound*     mBackgroundSound1;
	FMOD::Sound*	 mBackgroundSound2;
	FMOD::Sound*	 mCandySound;
	FMOD::Sound*	 mDeathSound;
	FMOD::Sound*	 mGhostSound;
	FMOD::Sound*	 mMenuSound;
	FMOD::Sound*	 mSuperCandySound;
	//Channels
    FMOD::Channel*   mChannel1;
	FMOD::Channel*	 mChannel2;
	FMOD::Channel*   mChannel3;
	FMOD::Channel*	 mGhostChannel[4];
  
	int				 mNumDrivers;
    bool             mListenerFlag;
    FMOD_VECTOR      mListenerPos;
	FMOD_VECTOR		 mListenerDir;
    FMOD_SPEAKERMODE mSpeakerMode;
    FMOD_CAPS        mCaps;
    char             mName[256];

};
