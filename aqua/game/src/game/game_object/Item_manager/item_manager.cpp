#include "item_manager.h"
#include "item/speedup_item/speedup_item.h"
#include "item/speeddown_item/speeddown_item.h"
#include "../unit_manager/unit_manager.h"

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
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//m_item_rand = 0;

	IGameObject::Initialize();
}

//更新
void CItemManager::Update(void)
{
	//m_pPlayer = m_pUnitManager->GetPlayer(aqua::controller::DEVICE_ID::P1);

	//if (Trigger(m_pPlayer->GetDeviceID(), BUTTON_ID::RIGHT_SHOULDER))
	if(m_pPlayer->m_HitItemFlag == true)
	{
		m_1p_item_rand = rand() % m_item;

		switch (m_1p_item_rand)
		{
		case 0:Create(ITEM_ID::SPEEDUP, &pos);	break;
		case 1:Create(ITEM_ID::SPEEDDOWN, &pos);	break;
		}
	}

	//m_pPlayer = m_pUnitManager->GetPlayer(aqua::controller::DEVICE_ID::P2);

	//if (m_pPlayer->m_HitItemFlag == true)
	//if (Trigger(DEVICE_ID::P2, BUTTON_ID::RIGHT_SHOULDER))
	//{
	//	m_2p_item_rand = rand() % m_item;

	//	switch (m_2p_item_rand)
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
