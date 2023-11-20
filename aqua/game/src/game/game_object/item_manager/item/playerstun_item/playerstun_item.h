#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;

class CCharaStunItem
	:public IItem
{
public:
	//コンストラクタ
	CCharaStunItem(aqua::IGameObject* parent);

	//デストラクタ
	~CCharaStunItem(void) = default;

	//初期化
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//更新
	void Update()override;

	//減速
	void CharaStun();

private:
	bool				m_itemflag;			//アイテム使ったか
	aqua::CTimer		m_EffectTimer;		//効果時間
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
};
