#pragma once
#include "../item.h"
#include "../../../unit_manager/unit/player/player.h"

class CPlayer;

class CSpeedUpItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CSpeedUpItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSpeedUpItem(void) = default;

	//������
	void Initialize();

	//�X�V
	void Update()override;

	//�����v�Z
	void SpeedUp();

private:
	//static const float	m_one_second;	//1�b
	//static const int	m_time_limit;	//
	//int					m_count_down;	//
	
	aqua::CTimer		m_EffectTimer;		//���ʎ���
	CPlayer*			m_pPlayer;
};