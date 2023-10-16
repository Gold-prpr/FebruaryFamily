#include "game_main.h"
#include "../../../stage/stage.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../Item_manager/item_manager.h"
#include "../../../camera/camera.h"
#include "../../../stage/stage_object/gimmick.h"

CGameMain::CGameMain(aqua::IGameObject* parent)
	:IScene(parent,"GameMain",SCENE_ID::RESULT,CHANGE_SCENE_ID::FADE)
	, m_pFirstPlayer(nullptr)
	, m_pSecondPlayer(nullptr)
	, m_pStage(nullptr)
	, m_pUnitManager(nullptr)
	, m_pP1Camera(nullptr)
	, m_pP2Camera(nullptr)
{
}

void CGameMain::Initialize()
{
	m_pP1Camera = aqua::CreateGameObject<CCamera>(this);
	m_pP2Camera = aqua::CreateGameObject<CCamera>(this);
	m_pStage = aqua::CreateGameObject<CStage>(this);
	m_pUnitManager = aqua::CreateGameObject<CUnitManager>(this);

	m_pFirstPlayer = (CPlayer*)m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO, DEVICE_ID::P1);

	m_pSecondPlayer = (CPlayer*)m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO, DEVICE_ID::P2);
	
	aqua::CreateGameObject<CItemManager>(this);
	aqua::CreateGameObject<CGimmick>(this);

	IScene::Initialize();

	m_DivScreen.Create(aqua::GetWindowWidth() * 5, aqua::GetWindowHeight());

	m_P1StageSprite.Create(m_DivScreen);
	m_P2StageSprite.Create(m_DivScreen);

	m_P2StageSprite.position.y = aqua::GetWindowHeight() / 2.0f;

	CharaCameraPos(&m_P1StageSprite, aqua::CVector2(0.0f, aqua::GetWindowHeight() / 2.0f));
	CharaCameraPos(&m_P2StageSprite, aqua::CVector2(0.0f, aqua::GetWindowHeight() / 2.0f));

}

void CGameMain::Update()
{

	m_pP1Camera->SetPlayerPos(m_pFirstPlayer->GetPosition());
	m_pP2Camera->SetPlayerPos(m_pSecondPlayer->GetPosition());

	m_P1StageSprite.position = m_pP1Camera->GetScroll();

	m_P2StageSprite.position = m_pP2Camera->GetScroll();
	m_P2StageSprite.position.y = aqua::GetWindowHeight() / 2.0f;

	IScene::Update();
}

void CGameMain::CharaCameraPos(aqua::CSprite* cp, aqua::CVector2 pos)
{
	(*cp).rect.left = (int)pos.x;
	(*cp).rect.top = (int)pos.y;
	(*cp).rect.right = cp->rect.left + (int)aqua::GetWindowWidth();
	(*cp).rect.bottom = cp->rect.top + (int)aqua::GetWindowHeight() / 2;
}


void CGameMain::Draw()
{
	//1P用のステージ
	m_DivScreen.Begin();

	m_pStage->Draw();

	m_pFirstPlayer->Draw();
	m_pSecondPlayer->Draw();

	m_DivScreen.End();

	m_P1StageSprite.Draw();
	m_P2StageSprite.Draw();
}

void CGameMain::Finalize()
{
	m_P1StageSprite.Delete();
	m_P2StageSprite.Delete();
	IScene::Finalize();
}
