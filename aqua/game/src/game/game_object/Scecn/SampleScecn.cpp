#include "SampleScecn.h"
#include "../unit_manager/unit/player/player.h"
#include "../unit_manager/unit_manager.h"
#include "../stage/stage.h"
#include "../Item_manager/item_manager.h"


CSampleScene::CSampleScene(IGameObject* parent)
	:IGameObject(parent,"SampleScene")
	, m_pPlayer(nullptr)
	, m_pStage(nullptr)
	, m_pUnitManager(nullptr)
{
}

void CSampleScene::Initialize()
{
	m_pStage = aqua::CreateGameObject<CStage>(this);
	m_pUnitManager = aqua::CreateGameObject<CUnitManager>(this);
	m_pPlayer = (CPlayer*)m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO, DEVICE_ID::P1);
	(CPlayer*)m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO, DEVICE_ID::P2);
	aqua::CreateGameObject<CItemManager>(this);
}

void CSampleScene::CharaCameraPos(aqua::CSprite* cp, aqua::CVector2 pos)
{
	(*cp).rect.left = pos.x;
	(*cp).rect.top = pos.y;
	(*cp).rect.right = cp->rect.left + aqua::GetWindowWidth();
	(*cp).rect.bottom = cp->rect.top + aqua::GetWindowHeight() / 2.0f;
}

void CSampleScene::Update()
{
}


void CSampleScene::Draw()
{
	//�X�e�[�W�̕`��
	m_DivScreen.Begin();
	m_pStage->Draw();
	m_pPlayer->Draw();
	m_DivScreen.End();

	//1P�p�̃X�e�[�W
	m_P1Stage.Draw();

	//2P�p�̃X�e�[�W
	m_P2Stage.Draw();
}

void CSampleScene::Finalize()
{
	m_P1Stage.Delete();
	m_P2Stage.Delete();

	aqua::IGameObject::Finalize();
}
