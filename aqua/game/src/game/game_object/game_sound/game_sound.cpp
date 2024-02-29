#include "game_sound.h"
#include "game_sound_resource/game_sound_resource.h"

const std::pair<std::string, bool> CGameSound::m_SoundData[] =
{
	{"data\\sound\\title.mp3",true},
	{"data\\sound\\title.mp3",true},
	{"data\\sound\\game.mp3",true},
	{"data\\sound\\result.mp3",true},
	{"data\\sound\\button.mp3",false},
	{"data\\sound\\jamp.wav",false},
	{"data\\sound\\stage_select.wav",false}
};

/*
*  コンストラクト
*/
CGameSound::CGameSound(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "GameSound")
{
}

/*
*  初期化
*/
void CGameSound::Initialize()
{
}

/*
*  更新
*/
void CGameSound::Update()
{
	IGameObject::Update();
}

/*
*  解放
*/
void CGameSound::Finalize()
{
	auto sound_it = m_GameSoundList.begin();

	while (sound_it != m_GameSoundList.end())
	{
		sound_it = m_GameSoundList.erase(sound_it);

		if (sound_it != m_GameSoundList.end())
			sound_it++;
	}
}

/*
*  再生
*/
void CGameSound::Play(SOUND_ID id)
{
	int num = (int)id;

	auto sound_it = m_GameSoundList.begin();

	if (m_SoundData[num].second)
	{
		sound_it = m_GameSoundList.begin();

		while (sound_it != m_GameSoundList.end())
		{
			if ((*sound_it)->GetID() == num)
			{
				(*sound_it)->Play();
				return;
			}

			sound_it++;

		}

	}


	CGameSoundResource* s = (CGameSoundResource*)aqua::CreateGameObject<CGameSoundResource>(this);

	s->Initialize(m_SoundData[num].first, m_SoundData[num].second, num);

	s->Play();

	m_GameSoundList.push_back(s);


}

/*
*  停止
*/
void CGameSound::Stop(SOUND_ID id)
{
	int num = (int)id;

	if (m_SoundData[num].second)
	{
		auto sound_it = m_GameSoundList.begin();
		while (sound_it != m_GameSoundList.end())
		{
			if ((*sound_it)->GetID() == num)
			{
				(*sound_it)->Stop();
				(*sound_it)->Finalize();
				sound_it = m_GameSoundList.erase(sound_it);
			}

			if (sound_it != m_GameSoundList.end())
				sound_it++;
		}
	}
}

void CGameSound::ReStart(SOUND_ID id)
{
	int num = (int)id;

	if (m_SoundData[num].second)
	{
		auto sound_it = m_GameSoundList.begin();
		while (sound_it != m_GameSoundList.end())
		{
			if ((*sound_it)->GetID() == num)
			{
				(*sound_it)->Play();
				return;
			}

			if (sound_it != m_GameSoundList.end())
				sound_it++;
		}
	}
}
