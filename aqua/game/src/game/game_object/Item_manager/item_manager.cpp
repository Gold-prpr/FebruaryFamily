#include "item_manager.h"
#include "item/speedup_item/speedup_item.h"
#include "item/speeddown_item/speeddown_item.h"

const int CItemManager::m_item = 2;		//�A�C�e����
using namespace aqua::keyboard;
using namespace aqua::controller;

//�R���X�g���N�^
CItemManager::CItemManager(aqua::IGameObject* parent)
	: aqua::IGameObject(parent, "ItemManager")
{
}

//������
void CItemManager::Initialize(void)
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	IGameObject::Initialize();
}

//�X�V
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

//�`��
void CItemManager::Draw(void)
{
	IGameObject::Draw();
}

//���
void CItemManager::Finalize(void)
{
	IGameObject::Finalize();
}

//����
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
