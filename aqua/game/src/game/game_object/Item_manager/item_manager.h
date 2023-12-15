#pragma once
#include "aqua.h"
#include "item/item_id.h"

class CUnitManager;
class CPlayer;
class CItemIcon;

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

<<<<<<< HEAD
	//アイテムID
	void Create(ITEM_ID id);
=======
	//生成
	void Create(ITEM_ID id, aqua::CVector2* position);
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b

	void RandPick(CPlayer* player);

	int m_1p_item_rand;				//1Pのアイテムをランダムに出す
	int m_2p_item_rand;				//2Pのアイテムをランダムに出す
private:
	static const int m_item;		//アイテム数
<<<<<<< HEAD
=======

	aqua::CVector2 pos;

	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CItemIcon* m_pIcon;
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
};