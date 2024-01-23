#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../item_manager/item_manager.h"

class CPlayer;
class CItemManager;

class CDark
	: public IUiComponent
{
public:
	//コンストラクタ
	CDark(aqua::IGameObject* parent);

	//デストラクタ
	~CDark(void) = default;

	//初期化
	void Initialize(const aqua::CVector2& position)override;

	////更新
	//void Update(void) override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	//相手の画面に描画
	void Dark(aqua::controller::DEVICE_ID other_id);

	aqua::CSprite		m_1PDark;	//1P暗闇
	aqua::CSprite		m_2PDark;	//2P暗闇
private:

	CPlayer* m_pPlayer;
	CItemManager* m_pItemManager;
};