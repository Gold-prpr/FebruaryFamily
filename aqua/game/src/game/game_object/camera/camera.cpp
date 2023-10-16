#include "camera.h"
#include "../unit_manager/unit/player/player.h"
#include "../unit_manager/unit_manager.h"
#include "../stage/stage.h"
#include "../Item_manager/item_manager.h"

CCamera::CCamera(IGameObject* parent)
	:IGameObject(parent, "Camera")
	, m_pPlayer(nullptr)
	, m_pStage(nullptr)
{
}

void CCamera::Initialize()
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");

	aqua::IGameObject::Initialize();
}

void CCamera::Update()
{
	aqua::CVector2	target = aqua::CVector2((float)aqua::GetWindowWidth(),(float)aqua::GetWindowHeight()) / 2.0f - m_PlayerPos;

	m_Scroll += (target - m_Scroll) * 0.1f;
	m_Scroll.x = min(m_Scroll.x, 0.0f);
	m_Scroll.x = max(m_Scroll.x, (float)aqua::GetWindowWidth() - m_pStage->GetMapWidth());
	m_Scroll.y = min(m_Scroll.y, 0.0f);
	m_Scroll.y = max(m_Scroll.y, (float)aqua::GetWindowHeight() - m_pStage->GetMapHeight());


	aqua::IGameObject::Update();

}

void CCamera::SetPlayerPos(aqua::CVector2 player_pos)
{
	m_PlayerPos = player_pos;
}

const aqua::CVector2& CCamera::GetScroll()
{
	return m_Scroll;
}