#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../item_manager/item_manager.h"

class CPlayer;
class CItemManager;

class CItemIcon
	: public IUiComponent
{
public:
	//コンストラクタ
	CItemIcon(aqua::IGameObject* parent);

	//デストラクタ
	~CItemIcon(void) = default;

	//初期化
	void Initialize(const aqua::CVector2 & position)override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	void Check(CPlayer* player);

private:
	aqua::CSprite		m_1PItemIconSprite;	//1Pアイテムアイコン
	aqua::CSprite		m_2PItemIconSprite;	//2Pアイテムアイコン

	CPlayer*		m_pPlayer;
	CItemManager*	m_pItemManager;
};