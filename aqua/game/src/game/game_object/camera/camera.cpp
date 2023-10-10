#include "camera.h"
#include "../unit_manager/unit/player/player.h"
#include "../stage/stage.h"

CCamera::CCamera(IGameObject* parent)
	:IGameObject(parent, "Camera")
	, m_pPlayer(nullptr)
	, m_pStage(nullptr)
{
}

void CCamera::Initialize()
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_P1DivScreen.Create(aqua::GetWindowWidth(), aqua::GetWindowHeight() / 2);
	m_P2DivScreen.Create(aqua::GetWindowWidth(), aqua::GetWindowHeight() / 2);
	m_P1Stage.Create(m_P1DivScreen);
	m_P2Stage.Create(m_P2DivScreen);
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

}

void CCamera::Draw()
{
	m_P1DivScreen.Begin();

	m_P1DivScreen.End();
	m_P1Stage.Draw();



	m_P2DivScreen.Begin();

	m_P2DivScreen.End();
	m_P2Stage.Draw();
}

void CCamera::Finalize()
{
	m_P1Stage.Delete();
	m_P2Stage.Delete();
}

const aqua::CVector2& CCamera::GetScroll()
{
	return m_Scroll;
}
