#include "AudioHandler.h"

AudioHandler::AudioHandler()
{
	FMOD::System_Create(&mSystem);
	
	mChannel1 = 0;
	mChannel2 = 0;
	mChannel3 = 0;
	for (int i = 0; i < 4; i++)
		mGhostChannel[i] = 0;

	mListenerFlag = true;
}

AudioHandler::~AudioHandler()
{
	StopSound();

	mBackgroundSound1->release();
	mBackgroundSound2->release();
	//mCandySound->release();
	//mDeathSound->release();
	//mGhostSound->release();
	//mMenuSound->release();
	//mSuperCandySound->release();

	delete mBackgroundSound1;
	delete mBackgroundSound2;
	delete mCandySound;
	delete mDeathSound;
	delete mGhostSound;
	delete mMenuSound;
	delete mSuperCandySound;
	
	delete mChannel1;
	delete mChannel2;
	delete mChannel3;
	for (int i = 0; i < 4; i++)
		delete mGhostChannel[i];
	delete mGhostChannel;

	mSystem->close();
	mSystem->release();
	delete mSystem;
}

void AudioHandler::Initialize()
{
	mSystem->getNumDrivers( &mNumDrivers);
	mSystem->getDriverCaps( 0, &mCaps, 0, &mSpeakerMode);
	mSystem->setSpeakerMode( mSpeakerMode);

	if (mCaps & FMOD_CAPS_HARDWARE_EMULATED)
		mSystem->setDSPBufferSize(1024, 10);

	mSystem->getDriverInfo(0, mName, 256, 0);
	
	mListenerPos.x = 0;
	mListenerPos.y = 0;
	mListenerPos.z = 0;

	mListenerDir.x = 0;
	mListenerDir.y = 0;
	mListenerDir.z = 1;

	mSystem->init(100, FMOD_INIT_NORMAL, 0);
	mSystem->set3DSettings(1.0, DISTANCEFACTOR, 1.0f);

	LoadAudio();

	mChannel1->setVolume(1.0f);
	mChannel2->setVolume(1.0f);
}

void AudioHandler::LoadAudio()
{
	mSystem->createSound("Resources/Sound/a.wav", FMOD_3D, 0, &mBackgroundSound1);
    mBackgroundSound1->set3DMinMaxDistance(0.5f * DISTANCEFACTOR, 5000.0f * DISTANCEFACTOR);
    mBackgroundSound1->setMode(FMOD_LOOP_NORMAL);

	/*
	mSystem->createSound("Resources/Sound/b.wav", FMOD_3D, 0, &mBackgroundSound2);
    mBackgroundSound2->set3DMinMaxDistance(0.5f * DISTANCEFACTOR, 5000.0f * DISTANCEFACTOR);
    mBackgroundSound2->setMode(FMOD_LOOP_NORMAL);
	*/
	
	mSystem->createSound("Resources/Sound/CandySound.wav", FMOD_3D, 0, &mCandySound);
    mCandySound->setMode(FMOD_LOOP_OFF);

	mSystem->createSound("Resources/Sound/DeathSound.wav", FMOD_3D, 0, &mDeathSound);
    mDeathSound->setMode(FMOD_LOOP_OFF);

	mSystem->createSound("Resources/Sound/GhostSound.wav", FMOD_3D, 0, &mGhostSound);
    mGhostSound->set3DMinMaxDistance(0.5f * DISTANCEFACTOR, 500.0f * DISTANCEFACTOR);
    mGhostSound->setMode(FMOD_LOOP_NORMAL);
	/*
	mSystem->createSound("Resources/Sound/MenuSound.wav", FMOD_3D, 0, &mMenuSound);
    mMenuSound->setMode(FMOD_LOOP_NORMAL);
	*/
}

void AudioHandler::UpdatePosition(float lPosX, float lPosY, float lPosZ, float lDirX, float lDirY, float lDirZ)
{
	FMOD_VECTOR lForward = { 0.0f, 0.0f, 1.0f };
    FMOD_VECTOR lUp      = { 0.0f, 1.0f, 0.0f };

	mListenerPos.x = lPosX; //These were multiplied with DISTANCEFACTOR
	mListenerPos.y = lPosY;
	mListenerPos.z = lPosZ;
	
	mListenerDir.x = lDirX;
	mListenerDir.y = lDirY;
	mListenerDir.z = lDirZ;

	mSystem->set3DListenerAttributes(0, &mListenerPos, &mListenerDir, &lForward, &lUp);
	mSystem->update();
}

void AudioHandler::UpdateGhostPosition(int lGhost, float lPosX, float lPosY, float lPosZ)
{
	FMOD_VECTOR lPosition;

	lPosition.x = lPosX; //These were multiplied with distancefactor
	lPosition.y = lPosY;
	lPosition.z = lPosZ;

	mGhostChannel[lGhost]->set3DAttributes(&lPosition, &mListenerDir);
}

void AudioHandler::PlayBackgroundSound()
{
    FMOD_VECTOR lPosition = { -10.0f * DISTANCEFACTOR, 0.0f, 0.0f };

    mSystem->playSound(FMOD_CHANNEL_FREE, mBackgroundSound1, true, &mChannel1);
    mChannel1->set3DAttributes(&lPosition, &mListenerDir);
    mChannel1->setPaused(false);
	
    FMOD_VECTOR lPosition2 = { 10.0f * DISTANCEFACTOR, 0.0f, 0.0f };

    mSystem->playSound(FMOD_CHANNEL_FREE, mBackgroundSound1, true, &mChannel2);
    mChannel2->set3DAttributes(&lPosition2, &mListenerDir);
    mChannel2->setPaused(false);
}

void AudioHandler::PlayCandySound()
{
	mSystem->playSound(FMOD_CHANNEL_FREE, mCandySound, true, &mChannel3);
	mChannel3->setPaused(false);
}

void AudioHandler::PlayDeathSound()
{
	mSystem->playSound( FMOD_CHANNEL_FREE, mDeathSound, true, &mChannel3 );
	mChannel3->setPaused( false );
}

void AudioHandler::PlayGhostSound( int lID, float lX, float lY, float lZ )
{
	FMOD_VECTOR lPosition = { lX, lY, lZ };
	FMOD_VECTOR lDirection = { 0, 0, 0 };

	mSystem->playSound( FMOD_CHANNEL_FREE, mGhostSound, true, &mGhostChannel[lID] );
	mGhostChannel[lID]->set3DAttributes( &lPosition, &lDirection );
	mGhostChannel[lID]->setPaused( false );
}

void AudioHandler::PlayMenuSound()
{
	mSystem->playSound(FMOD_CHANNEL_FREE, mMenuSound, true, &mChannel3);
	mChannel3->setPaused(false);
}

void AudioHandler::StopSound()
{
	mChannel1->stop();
	mChannel2->stop();
	mChannel3->stop();
	for (int i = 0; i < 4; i++)
	{
		mGhostChannel[i]->stop();
		mGhostChannel[i]->setPaused(true);
	}
	mChannel1->setPaused(true);
	mChannel2->setPaused(true);
	mChannel3->setPaused(true);

}

//From here and on it's only debug code.

float AudioHandler::getPositionX()
{
	return mListenerPos.x;
}
float AudioHandler::getPositionY()
{
	//kod är coolt för att man kan skriva den
	return mListenerPos.y;
}
float AudioHandler::getPositionZ()
{
	return mListenerPos.z;
}

void AudioHandler::PlayTest()
{
	FMOD_VECTOR lPosision1 = { -5.0f * DISTANCEFACTOR, 0.0f, 0.0f };

	FMOD_VECTOR lPosision2 = { 5.0f * DISTANCEFACTOR, 0.0f, 0.0f };

	mSystem->playSound(FMOD_CHANNEL_FREE, mBackgroundSound1, true, &mChannel1);
    mChannel1->set3DAttributes(&lPosision1, &mListenerDir);
    mChannel1->setPaused(false);

    mSystem->playSound(FMOD_CHANNEL_FREE, mBackgroundSound2, true, &mChannel2);
    mChannel2->set3DAttributes(&lPosision2, &mListenerDir);
    mChannel2->setPaused(false);
}