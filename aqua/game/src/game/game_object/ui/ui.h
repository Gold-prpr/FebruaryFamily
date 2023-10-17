#pragma once
#include "aqua.h"
#include "../item_manager/item_manager.h"
#include "../item_manager/item/speedup_item/speedup_item.h"
#include "../item_manager/item/item.h"

class CItemManager;

class IItem;

class CUi
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CUi(aqua::IGameObject* parent);

	//デストラクタ
	~CUi(void) = default;

	//初期化
	void Initialize(void) override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void) override;

	//解放
	void Finalize(void) override;

private:
	//ここに順位スプライト、アイテム枠スプライト、中央のポジションスプライト、アイテム効果スプライトを書く

	//1P
	aqua::CSprite		m_1PRankSprite;			//順位スプライト
	aqua::CSprite		m_1PItemFrameSprite;	//アイテム枠
	aqua::CSprite		m_1PItemSprite;			//アイテム
	aqua::CSprite		m_1PDistanceBar;		//今いる距離
	aqua::CSprite		m_1PItemEffect;			//アイテム効果

	//2P
	aqua::CSprite		m_2PRankSprite;			//順位スプライト
	aqua::CSprite		m_2PItemFrameSprite;	//アイテム枠
	aqua::CSprite		m_2PItemSprite;			//アイテム
	aqua::CSprite		m_2PDistanceBar;		//今いる距離
	aqua::CSprite		m_2PItemEffect;			//アイテム効果

	static const aqua::CVector2		m_1p_item_frame_position;		//1Pのアイテムフレーム位置
	static const aqua::CVector2		m_2p_item_frame_position;		//2Pのアイテムフレーム位置
	CItemManager* m_pItemManager;
	IItem* m_pItem;
};