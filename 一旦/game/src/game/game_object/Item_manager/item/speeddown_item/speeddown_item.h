#pragma once
#include "../item.h"
#include "../../../unit_manager/unit/player/player.h"

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
	void Initialize(aqua::CVector2* position);

	//更新
	void Update()override;

	//描画
	void Draw()override;

	//解放
	void Finalize()override;

	//減速
	void SpeedDown();

private:
	bool				m_itemflag;			//アイテム使ったか
	aqua::CTimer		m_EffectTimer;		//効果時間
	CPlayer* m_pPlayer;
};