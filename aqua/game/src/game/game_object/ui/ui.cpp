#include "ui.h"

const aqua::CVector2	CUi::m_1p_item_frame_position = { 0.0f,0.0f };
const aqua::CVector2	CUi::m_2p_item_frame_position = { 0.0f,540.0f };

CUi::CUi(aqua::IGameObject* parent)
	: aqua::IGameObject(parent, "Ui")
{
}

void CUi::Initialize(void)
{
	m_pItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");
	m_pItem = (IItem*)aqua::FindGameObject("Item");


	m_1PItemFrameSprite.Create("data\\frame.png");
	m_1PItemFrameSprite.position = m_1p_item_frame_position;

	//m_1PItemSprite.position = m_pItem->GetPosition();

	m_2PItemFrameSprite.Create("data\\frame.png");
	m_2PItemFrameSprite.position = m_2p_item_frame_position;

	//m_2PItemSprite.position = m_pItem->GetPosition();

	IGameObject::Initialize();
}

void CUi::Update(void)
{
	IGameObject::Update();
}

void CUi::Draw(void)
{
	m_1PItemFrameSprite.Draw();
	m_2PItemFrameSprite.Draw();
	IGameObject::Draw();
}

void CUi::Finalize(void)
{
	m_1PItemFrameSprite.Delete();
	m_2PItemFrameSprite.Delete();
	IGameObject::Finalize();
}
