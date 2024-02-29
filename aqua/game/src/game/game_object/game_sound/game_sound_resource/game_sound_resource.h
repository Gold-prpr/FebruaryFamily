#pragma once
#include "aqua.h"

class CGameSoundResource
	: public aqua::IGameObject
{
public:
	CGameSoundResource(aqua::IGameObject* parent);
	~CGameSoundResource() = default;

	/*
	*  @brief ‰Šú‰»
	*/
	void Initialize(std::string name,bool loop,int id);


	/*
	*  @brief ‰ğ•ú
	*/
	void Finalize()override;

	/*
	*  @brief Ä¶i“r’†‚©‚ç‚à‰Âj
	*/
	void Play();


	/*
	*  @brief ’â~
	*/
	void Stop();

	/*
	*  @brief ID‚Ìæ“¾
	*/
	int GetID();


private:

	aqua::CSoundPlayer m_SoundPlayer;

	int m_SoundID;

};

