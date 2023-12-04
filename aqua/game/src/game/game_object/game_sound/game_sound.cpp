#include "game_sound.h"
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
*  �R���X�g���N�g
*/
CGameSound::CGameSound(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "GameSound")
{
}

/*
*  ������
*/
void CGameSound::Initialize()
{
}

/*
*  �X�V
*/
void CGameSound::Update()
{
	auto sound_it = m_GameSoundList.begin();

	while (sound_it != m_GameSoundList.end())
	{
		if (sound_it->second >= (int)SOUND_ID::BUTTON && !(*sound_it).first->IsPlaying())
		{
			(*sound_it).first->Delete();
			sound_it = m_GameSoundList.erase(sound_it);
		}

		if (sound_it != m_GameSoundList.end())
			sound_it++;
	}

	IGameObject::Update();
}

/*
*  ���
*
*
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
*  �Đ�
*/
void CGameSound::Play(SOUND_ID id)
{
	int num = (int)id;

	// ���[�v�Đ��̐������m�F���āA�Đ����Ă��琶�����Ȃ�
	if (m_SoundData[num].second)
	{
		auto sound_it = m_GameSoundList.begin();

		while (sound_it != m_GameSoundList.end())
		{
			if ((*sound_it).second == num)
			{
				return;
			}

			sound_it++;
		}
	}

	aqua::CSoundPlayer sp;
	sp.Create(m_SoundData[num].first, m_SoundData[num].second);
	sp.Play();

	m_GameSoundList.push_back({ &sp , num });
}

/*
*  ��~
*/
void CGameSound::Stop(SOUND_ID id)
{
	int num = (int)id;

	if (m_SoundData[num].second)
	{
		auto sound_it = m_GameSoundList.begin();

		while (sound_it != m_GameSoundList.end())
		{
			if ((*sound_it).second == num)
			{
				sound_it = m_GameSoundList.erase(sound_it);
			}

			if (sound_it != m_GameSoundList.end())
				sound_it++;
		}
	}
}