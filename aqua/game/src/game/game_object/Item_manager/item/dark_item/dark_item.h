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
	//コンストラクタ
	CDarkItem(aqua::IGameObject* parent);

	//デストラクタ
	~CDarkItem(void) = default;

	//初期化
	void Initialize(CPlayer* player);

	//更新
	void Update()override;

	//暗くする
	void Dark(CPlayer* player);

private:
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectIcon* m_pEffectIcon;
	CDark* m_pDark;

	aqua::CSprite		m_1PDark;
	aqua::CSprite		m_2PDark;
};