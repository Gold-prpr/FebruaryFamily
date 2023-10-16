#include "ui.h"

const int CUi::m_2P_item_position_y = 540;		//ÉAÉCÉeÉÄêî

CUi::CUi(aqua::IGameObject* parent)
	: aqua::IGameObject(parent, "Ui")
{
}

void CUi::Initialize(void)
{
	m_pItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");

	//m_2P_item_position_y = 540;

	m_1PItemFrameSprite.Create("data\\frame.png");
	m_1PItemFrameSprite.position = { 0,0 };



	m_2PItemFrameSprite.Create("data\\frame.png");
	m_2PItemFrameSprite.position = { 0,m_2P_item_position_y };

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
