#include "item_manager.h"
#include "item/speedup_item/speedup_item.h"
#include "item/speeddown_item/speeddown_item.h"
<<<<<<< HEAD
#include "../unit_manager/unit_manager.h"
#include "../ui_manager/ui_component/item_icon/item_icon.h"

const int CItemManager::m_item = 2;		//ƒAƒCƒeƒ€”
<<<<<<< HEAD
=======
=======
#include "item/playerstun_item/playerstun_item.h"
#include "item/dark_item/dark_item.h"
#include "../unit_manager/unit_manager.h"
#include "../ui_manager/ui_component/item_icon/item_icon.h"

const int CItemManager::m_item = 3;		//ƒAƒCƒeƒ€”
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
using namespace aqua::keyboard;
using namespace aqua::controller;
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
CItemManager::CItemManager(aqua::IGameObject* parent)
	: aqua::IGameObject(parent, "ItemManager")
{
}

//‰Šú‰»
void CItemManager::Initialize(void)
{
<<<<<<< HEAD
	//m_item_rand = 0;

	//Create(ITEM_ID::SPEEDUP);

=======
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");
	

	//m_item_rand = 0;

>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
	IGameObject::Initialize();
}

//XV
void CItemManager::Update(void)
{
<<<<<<< HEAD
	using namespace aqua::keyboard;

	if (Trigger(KEY_ID::NUMPADENTER))
	{
		m_item_rand = rand() % m_item;

		switch (m_item_rand)
		{
		case 0:Create(ITEM_ID::SPEEDUP);	break;
		case 1:Create(ITEM_ID::SPEEDDOWN);	break;
		}
	}
=======
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
	IGameObject::Update();
}

//•`‰æ
void CItemManager::Draw(void)
{
	IGameObject::Draw();
}

//‰ğ•ú
void CItemManager::Finalize(void)
{
	IGameObject::Finalize();
}

//¶¬
void CItemManager::Create(ITEM_ID id)
{
	IItem* item = nullptr;

	switch (id)
	{
	case ITEM_ID::SPEEDUP:		item = aqua::CreateGameObject<CSpeedUpItem>(this);		break;
	case ITEM_ID::SPEEDDOWN:	item = aqua::CreateGameObject<CSpeedDownItem>(this);	break;
<<<<<<< HEAD
=======
	case ITEM_ID::PLAYERSTUN:	item = aqua::CreateGameObject<CPlayerStunItem>(this);	break;
	case ITEM_ID::DARK:			item = aqua::CreateGameObject<CDarkItem>(this);			break;
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
	}

	if (!item) return;
<<<<<<< HEAD
	item->Initialize(aqua::CVector2::ZERO);
=======

	item->Initialize(position);
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
}

void CItemManager::RandPick(CPlayer* player)
{
	if (player->m_HitItemFlag == true && player->m_GetItemFlag == true)
	{
<<<<<<< HEAD
		m_1p_item_rand = rand() % m_item;
=======
		m_ItemRand = rand() % m_item;
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½

		switch (m_1p_item_rand)
		{
<<<<<<< HEAD
		case 0:Create(ITEM_ID::SPEEDUP, &pos);	break;
		case 1:Create(ITEM_ID::SPEEDDOWN, &pos);	break;
=======
		case 0:Create(ITEM_ID::SPEEDDOWN);	break;
		case 1:Create(ITEM_ID::PLAYERSTUN); break;
		case 2:Create(ITEM_ID::DARK);		break;
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
		}

		
	}
	m_pIcon = (CItemIcon*)aqua::FindGameObject("ItemIcon");
	if(m_pIcon)
		m_pIcon->Check(player);
}
