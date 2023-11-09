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
	 void Initialize(aqua::CVector2 position);

	//�X�V
	 void Update()override;

	//�`��
	 void Draw()override;

	//���
	 void Finalize()override;

	 //�����v�Z
	 void SpeedUp();

private:
	//static const float	m_one_second;	//1�b
	//static const int	m_time_limit;	//
	//int					m_count_down;	//
	bool				m_itemflag;			//�A�C�e���g������
	aqua::CTimer		m_EffectTimer;		//���ʎ���
	CPlayer*			m_pPlayer;
};