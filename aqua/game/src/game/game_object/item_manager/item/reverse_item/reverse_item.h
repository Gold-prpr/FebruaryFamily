#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;
class CEffectIcon;

class CReverseItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CReverseItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CReverseItem(void) = default;

	//������
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//�X�V
	void Update()override;

	//����t
	void Reverse();


private:
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectIcon* m_pEffectIcon;
};