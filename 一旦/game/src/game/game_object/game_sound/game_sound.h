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
	*  @brief ‰Šú‰»
	*/
	void Initialize()override;

	/*
	*  @brief XV
	*/
	void Update()override;

	/*
	*  @brief ‰ğ•ú
	*/
	void Finalize()override;

	/*
	*  @brief Ä¶
	*/
	void Play(SOUND_ID id);

	/*
	*  @brief ’â~
	*/
	void Stop(SOUND_ID id);

private:
	static const std::pair<std::string, bool> m_SoundData[(int)SOUND_ID::MAX];

	aqua::CSoundPlayer* m_GameSound; //! ‰¹Šy

};