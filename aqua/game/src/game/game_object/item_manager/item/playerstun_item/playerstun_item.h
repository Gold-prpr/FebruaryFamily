#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;

class CPlayerStunItem
	:public IItem
{
public:
	//コンストラクタ
	CPlayerStunItem(aqua::IGameObject* parent);

	//デストラクタ
	~CPlayerStunItem(void) = default;

	//初期化
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//更新
	void Update()override;

	//減速
	void PlayerStun();

private:
	bool				m_itemflag;			//アイテム使ったか
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
};
