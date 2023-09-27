#include "camera.h"
#include "../unit_manager/unit/player/player.h"
#include "../stage/stage.h"

CCamera::CCamera(IGameObject* parent)
	:IGameObject(parent,"Camera")
	,m_pPlayer(nullptr)
	,m_pStage(nullptr)
{
}

void CCamera::Initialize()
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
}

void CCamera::Update()
{
	aqua::CVector2 target = aqua::CVector2((float)aqua::GetWindowWidth(), (float)aqua::GetWindowHeight()) / 2.0f - m_pPlayer->GetPosition();
	m_Scroll += (target - m_Scroll) * 0.1f;
}

const aqua::CVector2& CCamera::GetScroll()
{
	
}
