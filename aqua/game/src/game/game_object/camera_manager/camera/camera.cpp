#include "camera.h"
#include "../../unit_manager/unit/player/player.h"
#include "../../unit_manager/unit_manager.h"
#include "../../stage/stage.h"
#include "../../stage/gimmick/gimmick.h"
#include "../../Item_manager/item_manager.h"

CCamera::CCamera(IGameObject* parent)
	:IGameObject(parent, "Camera")
	, m_UnitManager(nullptr)
	, m_ItemManager(nullptr)
	, m_Gimmick(nullptr)
	, m_pPlayer(nullptr)
	, m_pStage(nullptr)
	, m_Surface(nullptr)
{
}

void CCamera::Initialize(aqua::CVector2 position, controller::DEVICE_ID id, aqua::CSurface* surface)
{
	m_UnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	m_pStage = (CStage*)aqua::FindGameObject("Stage");

	m_Position = position;

	m_PlayerID = id;

	m_pPlayer = m_UnitManager->GetPlayer(m_PlayerID);

	m_Surface = surface;

	//m_Surface.Create((int)m_pStage->GetMapWidth(), (int)m_pStage->GetMapHeight());
	//m_Surface.Create(aqua::GetWindowSize().x, aqua::GetWindowSize().y);

	m_SurfaceSprite.Create(*m_Surface);
	m_SurfaceSprite.position = m_Position;
	m_SurfaceSprite.rect.top = aqua::GetWindowSize().y / 2;
	m_SurfaceSprite.rect.bottom = m_SurfaceSprite.rect.top + aqua::GetWindowSize().y / 2;

	aqua::IGameObject::Initialize();
}

void CCamera::Update()
{
	if (m_SurfaceSprite.GetResourceHandle() == -1 && m_Surface)
	{
		//m_Surface.Create(aqua::GetWindowSize().x, aqua::GetWindowSize().y);
		//m_Surface.Create((int)m_pStage->GetMapWidth(), (int)m_pStage->GetMapHeight());
		m_SurfaceSprite.Create(*m_Surface);

		m_SurfaceSprite.position = m_Position;
	}

	aqua::CVector2
		target = aqua::CVector2((float)aqua::GetWindowWidth(),
			(float)aqua::GetWindowHeight()) / 2.0f - m_pPlayer->GetPosition();

	target.y += 200.0f;

	m_Scroll += (target - m_Scroll) * 0.1f;

	m_Scroll.x = min(m_Scroll.x, 0.0f);
	m_Scroll.x = max(m_Scroll.x, (float)aqua::GetWindowWidth() - m_pStage->GetMapWidth());

	m_Scroll.y = min(m_Scroll.y, 0.0f);
	m_Scroll.y = max(m_Scroll.y, (float)aqua::GetWindowHeight() - m_pStage->GetMapHeight());

	m_SurfaceSprite.position.x = m_Scroll.x;

	m_SurfaceSprite.rect.top = (int)(aqua::GetWindowSize().y / 2 - m_Scroll.y + m_Position.y - aqua::GetWindowSize().y / 2 * (int)m_PlayerID);
	m_SurfaceSprite.rect.bottom = m_SurfaceSprite.rect.top + aqua::GetWindowSize().y / 2;

	aqua::IGameObject::Update();
}

void CCamera::Draw()
{
	m_SurfaceSprite.Draw();

	m_SurfaceSprite.Delete();
}

void CCamera::Finalize()
{
	m_SurfaceSprite.Delete();
}

const aqua::CVector2& CCamera::GetScroll()
{
	return m_Scroll;
}