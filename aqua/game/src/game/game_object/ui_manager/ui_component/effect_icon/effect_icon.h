#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../item_manager/item_manager.h"

class CPlayer;
class CItemManager;

class CEffectIcon
	: public IUiComponent
{
public:
	//コンストラクタ
	CEffectIcon(aqua::IGameObject* parent);

	//デストラクタ
	~CEffectIcon(void) = default;

	//初期化
	void Initialize(const aqua::CVector2& position)override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	//プレイヤーがアイテム使ったら
	void EffectCheck(CPlayer* player);

	//プレイヤーの効果が切れたら
	//void DeleteEffect(void);
	void DeleteEffect(CPlayer* player);

	aqua::CSprite		m_1PEffectIconSprite;	//1Pアイテム枠
	aqua::CSprite		m_2PEffectIconSprite;	//2Pアイテム枠
private:

	CPlayer* m_pPlayer;
	CItemManager* m_pItemManager;
};