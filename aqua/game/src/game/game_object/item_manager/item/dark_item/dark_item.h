#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;
class CEffectIcon;

class CDarkItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CDarkItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CDarkItem(void) = default;

	//������
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//�X�V
	void Update()override;

	//�Â�����
	void Dark(aqua::controller::DEVICE_ID other_id);

private:
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectIcon* m_pEffectIcon;

	aqua::CSprite		m_1PDark;
	aqua::CSprite		m_2PDark;
};