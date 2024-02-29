#pragma once
#include "aqua.h"

class CGameSoundResource
	: public aqua::IGameObject
{
public:
	CGameSoundResource(aqua::IGameObject* parent);
	~CGameSoundResource() = default;

	/*
	*  @brief ������
	*/
	void Initialize(std::string name,bool loop,int id);


	/*
	*  @brief ���
	*/
	void Finalize()override;

	/*
	*  @brief �Đ��i�r��������j
	*/
	void Play();


	/*
	*  @brief ��~
	*/
	void Stop();

	/*
	*  @brief ID�̎擾
	*/
	int GetID();


private:

	aqua::CSoundPlayer m_SoundPlayer;

	int m_SoundID;

};

