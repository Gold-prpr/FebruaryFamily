#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;
class CEffectIcon;

class CDarkItem
	:public IItem
{
public:
	//コンストラクタ
	CDarkItem(aqua::IGameObject* parent);

	//デストラクタ
	~CDarkItem(void) = default;

	//初期化
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//更新
	void Update()override;

	//暗くする
	void Dark(aqua::controller::DEVICE_ID other_id);

private:
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectIcon* m_pEffectIcon;

	aqua::CSprite		m_1PDark;
	aqua::CSprite		m_2PDark;
};