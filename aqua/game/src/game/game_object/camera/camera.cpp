#include "camera.h"
#include "../unit_manager/unit/player/player.h"
#include "../unit_manager/unit_manager.h"
#include "../stage/stage.h"
#include "../Item_manager/item_manager.h"

CCamera::CCamera(IGameObject* parent)
	:IGameObject(parent, "Camera")
	, m_pPlayer(nullptr)
	, m_pStage(nullptr)
	, m_pUnitManager(nullptr)
{
}

void CCamera::Initialize()
{
	m_pStage = aqua::CreateGameObject<CStage>(this);
	m_pUnitManager = aqua::CreateGameObject<CUnitManager>(this);
	m_pPlayer = (CPlayer*)m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO,DEVICE_ID::P1);
	(CPlayer*)m_pUnitManager->CreateUnit(UNIT_ID::PLAYER, aqua::CVector2::ZERO,DEVICE_ID::P2);
	aqua::CreateGameObject<CItemManager>(this);

	aqua::IGameObject::Initialize();

	m_DivScreen.Create(aqua::GetWindowWidth(), aqua::GetWindowHeight());

	m_P1Stage.Create(m_DivScreen);
	m_P2Stage.Create(m_DivScreen);
	m_P2Stage.position.y = aqua::GetWindowHeight() / 2.0f;

	CharaCameraPos(&m_P1Stage, aqua::CVector2(0.0f, aqua::GetWindowHeight() / 2.0f));
	CharaCameraPos(&m_P2Stage, aqua::CVector2(0.0f, aqua::GetWindowHeight() / 2.0f));
}



void CCamera::Update()
{
	aqua::CVector2
		target = aqua::CVector2((float)aqua::GetWindowWidth(),
			(float)aqua::GetWindowHeight()) / 2.0f - m_pPlayer->GetPosition();

	m_Scroll += (target - m_Scroll) * 0.1f;
	m_Scroll.x = min(m_Scroll.x, 0.0f);
	m_Scroll.x = max(m_Scroll.x, (float)aqua::GetWindowWidth() - m_pStage->GetMapWidth());
	m_Scroll.y = min(m_Scroll.y, 0.0f);
	m_Scroll.y = max(m_Scroll.y, (float)aqua::GetWindowHeight() - m_pStage->GetMapHeight());

	aqua::CVector2 pos = m_pPlayer->GetPosition();

	aqua::IGameObject::Update();

}

void CCamera::CharaCameraPos(aqua::CSprite* cp, aqua::CVector2 pos)
{
	(*cp).rect.left = pos.x;
	(*cp).rect.top = pos.y;
	(*cp).rect.right = cp->rect.left + aqua::GetWindowWidth();
	(*cp).rect.bottom = cp->rect.top + aqua::GetWindowHeight() / 2.0f;
}

void CCamera::Draw()
{
	//1P用のステージ
	m_DivScreen.Begin();
	m_pStage->Draw();
	m_pPlayer->Draw();
	m_DivScreen.End();

	m_P1Stage.Draw();
	m_P2Stage.Draw();

}

void CCamera::Finalize()
{
	m_P1Stage.Delete();
	m_P2Stage.Delete();

	aqua::IGameObject::Finalize();
}

const aqua::CVector2& CCamera::GetScroll()
{
	return m_Scroll;
}