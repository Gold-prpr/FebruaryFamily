#include "camera.h"
#include "../../unit_manager/unit/player/player.h"
#include "../../unit_manager/unit_manager.h"
#include "../../stage/stage.h"

CCamera::CCamera(IGameObject* parent)
	:IGameObject(parent, "Camera")
	, m_pPlayer(nullptr)
	, m_pStage(nullptr)
{
}

void CCamera::Initialize(aqua::CVector2 position, controller::DEVICE_ID id,aqua::CSurface& surface)
{

	m_UnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	m_pStage = (CStage*)aqua::FindGameObject("Stage");

	m_Position = position;

	m_PlayerID = id;

	m_pPlayer = m_UnitManager->GetPlayer(m_PlayerID);
	
	m_SurfaceSprite.Create(surface);
	m_SurfaceSprite.position = m_Position;

	//m_SurfaceSprite.rect.top = aqua::GetWindowSize().y / 2;
	//m_SurfaceSprite.rect.bottom = m_SurfaceSprite.rect.top + aqua::GetWindowSize().y / 2;

	aqua::IGameObject::Initialize();
}

void CCamera::Update()
{
	aqua::CVector2
		target = aqua::CVector2((float)aqua::GetWindowWidth(),
			(float)aqua::GetWindowHeight()) / 2.0f - m_pPlayer->GetPosition();

	target.y += 200.0f ;

	m_Scroll += (target - m_Scroll) * 0.1f;

	m_Scroll.x = min(m_Scroll.x, 0.0f);
	m_Scroll.x = max(m_Scroll.x, (float)aqua::GetWindowWidth() - m_pStage->GetMapWidth());

	m_Scroll.y = min(m_Scroll.y, 0.0f);
	m_Scroll.y = max(m_Scroll.y, (float)aqua::GetWindowHeight() - m_pStage->GetMapHeight());

	//m_SurfaceSprite.position.x = m_Scroll.x;

	/*
	m_SurfaceSprite.rect.top = (int)(aqua::GetWindowSize().y / 2 - m_Scroll.y + m_Position.y - aqua::GetWindowSize().y / 2 * (int)m_PlayerID);
	m_SurfaceSprite.rect.bottom = m_SurfaceSprite.rect.top + aqua::GetWindowSize().y / 2;*/

	aqua::IGameObject::Update();

}

void CCamera::Draw()
{
	m_SurfaceSprite.Draw();
}

void CCamera::Finalize()
{
	m_SurfaceSprite.Delete();
}

const aqua::CVector2& CCamera::GetScroll()
{
	return m_Scroll;
}