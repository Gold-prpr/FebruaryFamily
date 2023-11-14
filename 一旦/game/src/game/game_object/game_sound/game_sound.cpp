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
*  コンストラクト
*/
CGameSound::CGameSound(aqua::IGameObject* parent)
	:aqua::IGameObject(parent,"GameSound")
{
}

/*
*  初期化
*/
void CGameSound::Initialize()
{
	m_GameSound = AQUA_NEW aqua::CSoundPlayer[(int)SOUND_ID::MAX];

	int max = (int)SOUND_ID::MAX;

	for (int i = 0; i < max; i++)
	{
		m_GameSound[i].Create(m_SoundData[i].first, m_SoundData[i].second);
	}
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
* 
* 
*/
void CGameSound::Finalize()
{
	int max = (int)SOUND_ID::MAX;

	for (int i = 0; i < max; i++)
		m_GameSound[i].Delete();

	AQUA_SAFE_DELETE_ARRAY(m_GameSound);

}

/*
*  再生
*/
void CGameSound::Play(SOUND_ID id)
{
	m_GameSound[(int)id].Play();
}

/*
*  停止
*/
void CGameSound::Stop(SOUND_ID id)
{
	m_GameSound[(int)id].Stop();
}