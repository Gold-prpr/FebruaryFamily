#include "item_manager.h"
#include "item/speedup_item/speedup_item.h"
#include "item/speeddown_item/speeddown_item.h"

const int CItemManager::m_item = 2;		//アイテム数
using namespace aqua::keyboard;
using namespace aqua::controller;

//コンストラクタ
CItemManager::CItemManager(aqua::IGameObject* parent)
	: aqua::IGameObject(parent, "ItemManager")
{
}

//初期化
void CItemManager::Initialize(void)
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	IGameObject::Initialize();
}

//更新
void CItemManager::Update(void)
{
	//if (Trigger(KEY_ID::NUMPADENTER))
	if (Trigger(DEVICE_ID::P1, BUTTON_ID::LEFT_SHOULDER))
	{
		m_item_rand = rand() % m_item;

		switch (m_item_rand)
		{
		case 0:Create(ITEM_ID::SPEEDUP, &pos);	break;
		case 1:Create(ITEM_ID::SPEEDDOWN, &pos);	break;
		}
	}

	if (Trigger(DEVICE_ID::P2, BUTTON_ID::LEFT_SHOULDER))
	{
		m_item_rand = rand() % m_item;

		switch (m_item_rand)
		{
		case 0:Create(ITEM_ID::SPEEDUP, &pos);	break;
		case 1:Create(ITEM_ID::SPEEDDOWN, &pos);	break;
		}
	}
	
	//if (Trigger(m_pPlayer->m_Device, BUTTON_ID::LEFT_SHOULDER))
	//{
	//	m_item_rand = rand() % m_item;

	//	switch (m_item_rand)
	//	{
	//	case 0:Create(ITEM_ID::SPEEDUP, &pos);	break;
	//	case 1:Create(ITEM_ID::SPEEDDOWN, &pos);	break;
	//	}
	//}

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
void CItemManager::Create(ITEM_ID id, aqua::CVector2* position) 
{
	IItem* item = nullptr;

	switch (id)
	{
	case ITEM_ID::SPEEDUP:		item = aqua::CreateGameObject<CSpeedUpItem>(this);		break;
	case ITEM_ID::SPEEDDOWN:	item = aqua::CreateGameObject<CSpeedDownItem>(this);	break;
	}

	if (!item) return;

	item->Initialize(position);
}
