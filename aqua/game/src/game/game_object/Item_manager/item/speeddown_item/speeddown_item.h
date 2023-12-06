#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;
class CEffectManager;
class CSpeedDownEffect;

class CSpeedDownItem
	:public IItem
{
public:
	//コンストラクタ
	CSpeedDownItem(aqua::IGameObject* parent);

	//デストラクタ
	~CSpeedDownItem(void) = default;

	//初期化
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//更新
	void Update()override;

	//減速
	void SpeedDown();

private:
	CUnitManager*		m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectManager* m_pEffectManager;
	CSpeedDownEffect* m_pSpeedDownEffect;
};