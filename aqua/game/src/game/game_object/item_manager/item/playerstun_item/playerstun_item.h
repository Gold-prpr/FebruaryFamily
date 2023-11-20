#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;

class CCharaStunItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CCharaStunItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CCharaStunItem(void) = default;

	//������
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//�X�V
	void Update()override;

	//����
	void CharaStun();

private:
	bool				m_itemflag;			//�A�C�e���g������
	aqua::CTimer		m_EffectTimer;		//���ʎ���
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
};
