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
		if (sound_it->second >= (int)SOUND_ID::BUTTON && !sound_it->first.IsPlaying())
		{
			sound_it->first.Delete();
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

		sound_it->first.Delete();

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
	aqua::CSoundPlayer sp;
	int num = (int)id;

	sp.Create(m_SoundData[num].first, m_SoundData[num].second);
	sp.Play();

	m_GameSoundList.push_back({ sp , num });

	sp.Delete();
}

/*
*  ��~
*/
void CGameSound::Stop(SOUND_ID id)
{

}