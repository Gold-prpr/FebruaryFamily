#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;
class CEffectIcon;
//class CEffectManager;
//class CSpeedDownEffect;

class CSpeedUpItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CSpeedUpItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSpeedUpItem(void) = default;

	//������
	void Initialize(CPlayer* player);

	//�X�V
	void Update()override;

	//����
	void SpeedUp();

private:
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectIcon* m_pEffectIcon;
	//CEffectManager* m_pEffectManager;
	//CSpeedDownEffect* m_pSpeedDownEffect;
};