#pragma once
#include "aqua.h"
#include "item/item_id.h"

class CItemManager
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CItemManager(aqua::IGameObject* parent);

	//デストラクタ
	~CItemManager(void) = default;

	//初期化
	void Initialize(void) override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void) override;

	//解放
	void Finalize(void) override;

	//アイテムID
	void Create(ITEM_ID id);

private:
	static const int m_item;		//アイテム数
	int m_item_rand;				//ランダムにアイテムを出す
};