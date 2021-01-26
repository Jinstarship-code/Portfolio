#include "SoundManager.h"

SoundManager* SoundManager::m_pInstance = NULL;

SoundManager::SoundManager()
{
}

SoundManager::~SoundManager()
{
}

void SoundManager::Initialize()
{
	FMOD_System_Create(&m_pSystem);
	FMOD_System_Init(m_pSystem, 32, FMOD_INIT_NORMAL, NULL);

	for (int i = 0; i < SOUND_CHANNEL_MAX; ++i)
	 FMOD_Channel_SetVolume(m_pChannel[i], 0.5f);
}

void SoundManager::AddSound(const char* name_or_data, string _Ksy)
{
	FMOD_SOUND* Sound;

	FMOD_System_CreateSound(m_pSystem, name_or_data, FMOD_DEFAULT, 0, &Sound);

	m_pSoundList.insert(make_pair(_Ksy, Sound));
}

void SoundManager::StreamingUpdate()
{
	FMOD_System_Update(m_pSystem);
}

void SoundManager::OnPlaySound(string _Ksy, SOUND_CHANNEL_IDS _SoundState)
{
	map<string, FMOD_SOUND*>::iterator iter = m_pSoundList.find(_Ksy);

	FMOD_System_PlaySound(m_pSystem, iter->second, NULL, false, &m_pChannel[_SoundState]);
}

void SoundManager::OnCloseSound(SOUND_CHANNEL_IDS _SoundState)
{
	FMOD_Channel_Stop(m_pChannel[_SoundState]);
}

void SoundManager::SetSoundVolum(SOUND_CHANNEL_IDS _SoundState, int _Percent)
{
	FMOD_Channel_SetVolume(m_pChannel[_SoundState], float(_Percent / 100));
}

void SoundManager::Release()
{
	for (map<string, FMOD_SOUND*>::iterator iter = m_pSoundList.begin();
		iter != m_pSoundList.end(); ++iter)
	{
		FMOD_Sound_Release(iter->second);
	}

	m_pSoundList.clear();

	FMOD_System_Close(m_pSystem);
	FMOD_System_Release(m_pSystem);
}
