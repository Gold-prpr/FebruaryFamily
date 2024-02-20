#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;
class CEffectIcon;
class CDark;

class CDarkItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CDarkItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CDarkItem(void) = default;

	//������
	void Initialize(CPlayer* player);

	//�X�V
	void Update()override;

	//�Â�����
	void Dark(CPlayer* player);

private:
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectIcon* m_pEffectIcon;
	CDark* m_pDark;

	aqua::CSprite		m_1PDark;
	aqua::CSprite		m_2PDark;
};