#include "game_main.h"
#include "../../../stage/stage.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../Item_manager/item_manager.h"
#include "../../../camera/camera.h"

CGameMain::CGameMain(aqua::IGameObject* parent)
	:IScene(parent,"GameMain",SCENE_ID::RESULT,CHANGE_SCENE_ID::FADE)
	, m_pPlayer(nullptr)
	, m_pStage(nullptr)
	, m_pUnitManager(nullptr)
{
}

void CGameMain::Initialize()
{
	aqua::CreateGameObject<CCamera>(this);
	m_pStage = aqua::CreateGameObject<CStage>(this);
	m_pUnitManager = aqua::CreateGameObject<CUnitManager>(this);
	m_pPlayer = (CPlayer*)m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO, DEVICE_ID::P1);
	(CPlayer*)m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO, DEVICE_ID::P2);
	aqua::CreateGameObject<CItemManager>(this);

	IScene::Initialize();

	m_DivScreen.Create(aqua::GetWindowWidth(), aqua::GetWindowHeight());

	m_P1Stage.Create(m_DivScreen);
	m_P2Stage.Create(m_DivScreen);
	m_P2Stage.position.y = aqua::GetWindowHeight() / 2.0f;

	CharaCameraPos(&m_P1Stage, aqua::CVector2(0.0f, aqua::GetWindowHeight() / 2.0f));
	CharaCameraPos(&m_P2Stage, aqua::CVector2(0.0f, aqua::GetWindowHeight() / 2.0f));

}

void CGameMain::Update()
{
	IScene::Update();
}

void CGameMain::CharaCameraPos(aqua::CSprite* cp, aqua::CVector2 pos)
{
	(*cp).rect.left = (int)pos.x;
	(*cp).rect.top = (int)pos.y;
	(*cp).rect.right = cp->rect.left + (int)aqua::GetWindowWidth();
	(*cp).rect.bottom = cp->rect.top + (int)aqua::GetWindowHeight() / 2.0f;
}


void CGameMain::Draw()
{
	//1P用のステージ
	m_DivScreen.Begin();
	m_pStage->Draw();
	m_pPlayer->Draw();
	m_DivScreen.End();

	m_P1Stage.Draw();
	m_P2Stage.Draw();
}

void CGameMain::Finalize()
{
	m_P1Stage.Delete();
	m_P2Stage.Delete();
	IScene::Finalize();
}
