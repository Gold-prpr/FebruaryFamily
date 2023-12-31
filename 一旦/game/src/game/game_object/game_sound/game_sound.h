#pragma once
#include "aqua.h"
#include "game_sound_id.h"

class CGameSound :
	public aqua::IGameObject
{
public:

	CGameSound(aqua::IGameObject* parent);
	~CGameSound() = default;

	/*
	*  @brief 初期化
	*/
	void Initialize()override;

	/*
	*  @brief 更新
	*/
	void Update()override;

	/*
	*  @brief 解放
	*/
	void Finalize()override;

	/*
	*  @brief 再生
	*/
	void Play(SOUND_ID id);

	/*
	*  @brief 停止
	*/
	void Stop(SOUND_ID id);

private:
	static const std::pair<std::string, bool> m_SoundData[(int)SOUND_ID::MAX];

	aqua::CSoundPlayer* m_GameSound; //! 音楽

};