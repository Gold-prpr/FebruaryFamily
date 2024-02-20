#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;
class CEffectIcon;
//class CPlayerStunEffect;
//class CEffectManager;

class CPlayerStunItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CPlayerStunItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CPlayerStunItem(void) = default;

	//������
	void Initialize(CPlayer* player);

	//�X�V
	void Update()override;

	//�~�߂�
	void PlayerStun();

private:
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectIcon* m_pEffectIcon;
	//CEffectManager* m_pEffectManager;
	//CPlayerStunEffect* m_pPlayerStunEffect;
};
