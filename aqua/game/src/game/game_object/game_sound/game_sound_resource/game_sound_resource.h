#pragma once
#include "aqua.h"

class CGameSoundResource
	: public aqua::IGameObject
{
public:
	CGameSoundResource(aqua::IGameObject* parent);
	~CGameSoundResource() = default;

	/*
	*  @brief 初期化
	*/
	void Initialize(std::string name,bool loop,int id);


	/*
	*  @brief 解放
	*/
	void Finalize()override;

	/*
	*  @brief 再生（途中からも可）
	*/
	void Play();


	/*
	*  @brief 停止
	*/
	void Stop();

	/*
	*  @brief IDの取得
	*/
	int GetID();


private:

	aqua::CSoundPlayer m_SoundPlayer;

	int m_SoundID;

};

