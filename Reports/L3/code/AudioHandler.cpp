#include "AudioHandler.h"

AudioHandler::AudioHandler()
{
	FMOD::System_Create(&mSystem);
	
}


AudioHandler::~AudioHandler()
{
	delete mSystem;
	delete mSound1;
	delete mSound2;
	delete mSound3;
	delete mChannel1;
	delete mChannel2;
	delete mChannel3;
}

void AudioHandler::Initialize()
{
	mSystem->getNumDrivers(&mNumDrivers);
	mSystem->getDriverCaps(0, &mCaps, 0, &mSpeakerMode);
	mSystem->setSpeakerMode(mSpeakerMode);

	if (caps & FMOD_CAPS_HARDWARE_EMULATED)
		mSystem->setDSPBufferSize(1024, 10);

	mSystem->getDriverInfo(0, mName, 256, 0);

	if (strstr(name, "SigmaTel"))   /* Sigmatel sound devices crackle for some reason if the format is PCM 16bit.  PCM floating point output seems to solve it. */
		mSystem->setSoftwareFormat(48000, FMOD_SOUND_FORMAT_PCMFLOAT, 0,0, FMOD_DSP_RESAMPLER_LINEAR);

    if (!mSystem->init(100, FMOD_INIT_NORMAL, 0))         /* Ok, the speaker mode selected isn't supported by this soundcard.  Switch it back to stereo... */
    {
        mSystem->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
		mSystem->init(100, FMOD_INIT_NORMAL, 0);/* ... and re-init. */
    }

	mSystem->set3DSettings(1.0, DISTANCEFACTOR, 1.0f);
}

void AudioHandler::LoadAudio();
{
	mSystem->createSound("../media/drumloop.wav", FMOD_3D, 0, &mSound1);
    mSound1->set3DMinMaxDistance(0.5f * DISTANCEFACTOR, 5000.0f * DISTANCEFACTOR);
    mSound1->setMode(FMOD_LOOP_NORMAL);

	mSystem->createSound("../media/jaguar.wav", FMOD_3D, 0, &mSound2);
    mSound2->set3DMinMaxDistance(0.5f * DISTANCEFACTOR, 5000.0f * DISTANCEFACTOR);
    mSound2->setMode(FMOD_LOOP_NORMAL);

    mSystem->createSound("../media/swish.wav", FMOD_SOFTWARE | FMOD_2D, 0, &mSound3);
}