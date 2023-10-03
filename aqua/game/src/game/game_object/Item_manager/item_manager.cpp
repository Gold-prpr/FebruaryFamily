#include "item_manager.h"
#include "item/speedup_item/speedup_item.h"
#include "item/speeddown_item/speeddown_item.h"

const int CItemManager::m_item = 2;		//アイテム数

//コンストラクタ
CItemManager::CItemManager(aqua::IGameObject* parent)
	: aqua::IGameObject(parent, "ItemManager")
{
}

//初期化
void CItemManager::Initialize(void)
{
	//m_item_rand = 0;

	IGameObject::Initialize();
}

//更新
void CItemManager::Update(void)
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::NUMPADENTER))
	{
		m_item_rand = rand() % m_item;

		switch (m_item_rand)
		{
		case 0:Create(ITEM_ID::SPEEDUP);	break;
		case 1:Create(ITEM_ID::SPEEDDOWN);	break;
		}
	}
	IGameObject::Update();
}

//描画
void CItemManager::Draw(void)
{
	IGameObject::Draw();
}

//解放
void CItemManager::Finalize(void)
{
	IGameObject::Finalize();
}

//生成
void CItemManager::Create(ITEM_ID id)
{
	IGameObject* item = nullptr;

	switch (id)
	{
	case ITEM_ID::SPEEDUP:		item = aqua::CreateGameObject<CItemSpeedUp>(this);		break;
	case ITEM_ID::SPEEDDOWN:	item = aqua::CreateGameObject<CItemSpeedDown>(this);	break;
	}

	if (!item) return;

	item->Initialize();
}
