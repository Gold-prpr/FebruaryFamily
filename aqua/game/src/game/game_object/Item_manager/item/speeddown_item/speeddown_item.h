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
	//コンストラクタ
	CSpeedDownItem(aqua::IGameObject* parent);

	//デストラクタ
	~CSpeedDownItem(void) = default;

	//初期化
	void Initialize(CPlayer* player);

	//更新
	void Update()override;

	//減速
	void SpeedDown();

private:
	CUnitManager*		m_pUnitManager;
	CPlayer*			m_pPlayer;
	CEffectIcon*			m_pEffectIcon;
	//CEffectManager* m_pEffectManager;
	//CSpeedDownEffect* m_pSpeedDownEffect;
};