#pragma once
#include "aqua.h"
#include "game_sound_id.h"

class CGameSoundResource;

class CGameSound :
	public aqua::IGameObject
{
public:

	CGameSound(aqua::IGameObject* parent);
	~CGameSound() = default;

	/*
	*  @brief ������
	*/
	void Initialize()override;

	/*
	*  @brief �X�V
	*/
	void Update()override;

	/*
	*  @brief ���
	*/
	void Finalize()override;

	/*
	*  @brief �Đ�
	*/
	void Play(SOUND_ID id);

	/*
	*  @brief ��~
	*/
	void Stop(SOUND_ID id);

	/*
	*  @brief ��~����������Đ�
	*/
	void ReStart(SOUND_ID id);

private:
	static const std::pair<std::string, bool> m_SoundData[(int)SOUND_ID::MAX];

	std::list<CGameSoundResource*> m_GameSoundList; //! ���y


};