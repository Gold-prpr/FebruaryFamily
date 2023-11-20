#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;

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
	bool				m_itemflag;			//アイテム使ったか
	CUnitManager*		m_pUnitManager;
	CPlayer* m_pPlayer;
};