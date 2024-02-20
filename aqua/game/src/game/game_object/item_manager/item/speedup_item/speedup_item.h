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
	//コンストラクタ
	CSpeedUpItem(aqua::IGameObject* parent);

	//デストラクタ
	~CSpeedUpItem(void) = default;

	//初期化
	void Initialize(CPlayer* player);

	//更新
	void Update()override;

	//加速
	void SpeedUp();

private:
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectIcon* m_pEffectIcon;
	//CEffectManager* m_pEffectManager;
	//CSpeedDownEffect* m_pSpeedDownEffect;
};