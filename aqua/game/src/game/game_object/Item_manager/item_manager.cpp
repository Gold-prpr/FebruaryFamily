#include "item_manager.h"
#include "item/speedup_item/speedup_item.h"
#include "item/speeddown_item/speeddown_item.h"
#include "../unit_manager/unit_manager.h"
#include "../ui_manager/ui_component/item_icon/item_icon.h"

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
	

	//m_item_rand = 0;

	IGameObject::Initialize();
}

//更新
void CItemManager::Update(void)
{
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
	IItem* item = nullptr;

	switch (id)
	{
	case ITEM_ID::SPEEDUP:		item = aqua::CreateGameObject<CSpeedUpItem>(this);		break;
	case ITEM_ID::SPEEDDOWN:	item = aqua::CreateGameObject<CSpeedDownItem>(this);	break;
	}

	if (!item) return;
}

void CItemManager::RandPick(CPlayer* player)
{
	if (player->m_HitItemFlag == true)
	{
		//m_1p_item_rand = rand() % m_item;
		m_1p_item_rand = 1;

		switch (m_1p_item_rand)
		{
		case 0:Create(ITEM_ID::SPEEDUP);	break;
		case 1:Create(ITEM_ID::SPEEDDOWN);	break;
		}

		
	}
	m_pIcon = (CItemIcon*)aqua::FindGameObject("ItemIcon");
	if (m_pIcon)
	{
		m_pIcon->Check(player);
	}
	
}
