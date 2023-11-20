#pragma once
#include "../item.h"

class CUnitManager;
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
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//�X�V
	void Update()override;

	//����
	void SpeedDown();

private:
	bool				m_itemflag;			//�A�C�e���g������
	CUnitManager*		m_pUnitManager;
	CPlayer* m_pPlayer;
};