#pragma once
#include "../item.h"
#include "../../../unit_manager/unit/player/player.h"

class CPlayer;

class CSpeedDownItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CSpeedDownItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSpeedDownItem(void) = default;

	//������
	void Initialize(aqua::CVector2* position);

	//�X�V
	void Update()override;

	//�`��
	void Draw()override;

	//���
	void Finalize()override;

	//����
	void SpeedDown();

private:
	bool				m_itemflag;			//�A�C�e���g������
	aqua::CTimer		m_EffectTimer;		//���ʎ���
	CPlayer* m_pPlayer;
};