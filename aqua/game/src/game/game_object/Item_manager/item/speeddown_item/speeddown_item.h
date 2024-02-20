#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;
class CEffectIcon;
//class CEffectManager;
//class CSpeedDownEffect;

class CSpeedDownItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CSpeedDownItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSpeedDownItem(void) = default;

	//������
	void Initialize(CPlayer* player);

	//�X�V
	void Update()override;

	//����
	void SpeedDown();

private:
	CUnitManager*		m_pUnitManager;
	CPlayer*			m_pPlayer;
	CEffectIcon*			m_pEffectIcon;
	//CEffectManager* m_pEffectManager;
	//CSpeedDownEffect* m_pSpeedDownEffect;
};