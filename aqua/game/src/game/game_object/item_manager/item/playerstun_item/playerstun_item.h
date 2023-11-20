#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;

class CPlayerStunItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CPlayerStunItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CPlayerStunItem(void) = default;

	//������
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//�X�V
	void Update()override;

	//����
	void PlayerStun();

private:
	bool				m_itemflag;			//�A�C�e���g������
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
};
