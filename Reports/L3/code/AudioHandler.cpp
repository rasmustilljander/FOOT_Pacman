#include "AudioHandler.h"

AudioHandler::AudioHandler()
{
	FMOD::System_Create(&mSystem);
	
	mChannel1 = 0;
	mChannel2 = 0;
	mChannel3 = 0;

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
	mSystem->init(100, FMOD_INIT_NORMAL, 0);
	mSystem->set3DSettings(1.0, DISTANCEFACTOR, 1.0f);

	LoadAudio();

	mChannel1->setVolume(0.75f);
	mChannel2->setVolume(1.0f);
}

void AudioHandler::LoadAudio()
{
	mSystem->createSound("Resources/Sound/a.wav", FMOD_3D, 0, &mBackgroundSound1);
    mBackgroundSound1->set3DMinMaxDistance(0.5f * DISTANCEFACTOR, 5000.0f * DISTANCEFACTOR);
    mBackgroundSound1->setMode(FMOD_LOOP_NORMAL);

	mSystem->createSound("Resources/Sound/b.wav", FMOD_3D, 0, &mBackgroundSound2);
    mBackgroundSound2->set3DMinMaxDistance(0.5f * DISTANCEFACTOR, 5000.0f * DISTANCEFACTOR);
    mBackgroundSound2->setMode(FMOD_LOOP_NORMAL);
}

void AudioHandler::UpdatePosition(float lPosX, float lPosY, float lPosZ, float lDirX, float lDirY, float lDirZ)
{
	FMOD_VECTOR lNewPosition;
	FMOD_VECTOR lVelocity;

	lNewPosition.x = lPosX * DISTANCEFACTOR;
	lNewPosition.y = lPosY * DISTANCEFACTOR;
	lNewPosition.z = lPosZ * DISTANCEFACTOR;
	
	lVelocity.x = (lNewPosition.x - mListenerPos.x) * (1000 / INTERFACE_UPDATETIME);
    lVelocity.y = (lNewPosition.y - mListenerPos.y) * (1000 / INTERFACE_UPDATETIME);
    lVelocity.z = (lNewPosition.z - mListenerPos.z) * (1000 / INTERFACE_UPDATETIME);

	mListenerPos = lNewPosition;

	mListenerDir.x = lDirX;
	mListenerDir.y = lDirY;
	mListenerDir.z = lDirZ;

	mSystem->update();
}

void AudioHandler::PlayBackgroundSound()
{
    FMOD_VECTOR lPosision = { -10.0f * DISTANCEFACTOR, 0.0f, 0.0f };

    mSystem->playSound(FMOD_CHANNEL_FREE, mBackgroundSound1, true, &mChannel1);
    mChannel1->set3DAttributes(&lPosision, &mListenerDir);
    mChannel1->setPaused(false);
	
	
    FMOD_VECTOR lPosision2 = { 10.0f * DISTANCEFACTOR, 0.0f, 0.0f };

    mSystem->playSound(FMOD_CHANNEL_FREE, mBackgroundSound2, true, &mChannel2);
    mChannel2->set3DAttributes(&lPosision2, &mListenerDir);
    mChannel2->setPaused(false);
}

void AudioHandler::StopSound()
{
	mChannel1->stop();
	mChannel2->stop();
	mChannel3->stop();
}

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
	FMOD_VECTOR lPosision2 = { 10.0f * DISTANCEFACTOR, 0.0f, 0.0f };

    mSystem->playSound(FMOD_CHANNEL_FREE, mBackgroundSound2, true, &mChannel2);
    mChannel2->set3DAttributes(&lPosision2, &mListenerDir);
    mChannel2->setPaused(false);
}