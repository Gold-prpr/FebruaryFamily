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

	/*
	*  @brief ’â~‚µ‚½Š‚©‚çÄ¶
	*/
	void ReStart(SOUND_ID id);

private:
	static const std::pair<std::string, bool> m_SoundData[(int)SOUND_ID::MAX];

	std::list<CGameSoundResource*> m_GameSoundList; //! ‰¹Šy


};