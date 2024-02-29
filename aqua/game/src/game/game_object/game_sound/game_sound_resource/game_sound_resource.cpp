#include "game_sound_resource.h"

CGameSoundResource::CGameSoundResource(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"GameSoundResource")
{
}

void CGameSoundResource::Initialize(std::string name,bool loop,int id)
{
	m_SoundPlayer.Create(name,loop);

	m_SoundID = id;
}

void CGameSoundResource::Finalize()
{
	m_SoundPlayer.Delete();
}

void CGameSoundResource::Play()
{
	if (m_SoundPlayer.IsPlaying())
		m_SoundPlayer.Resuming();
	else
		m_SoundPlayer.Play();
}

void CGameSoundResource::Stop()
{
	m_SoundPlayer.Stop();
}

int CGameSoundResource::GetID()
{
	return m_SoundID;
}
