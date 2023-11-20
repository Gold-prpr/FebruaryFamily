#include "stage_pos_bar.h"
#include "../../../stage/stage.h"
#include "../../../unit_manager/unit/player/player.h"

CStagePosBar::CStagePosBar(aqua::IGameObject* parent)
	: IUiComponent(parent, "StagePosBar")
{
}

void CStagePosBar::Initialize(const aqua::CVector2& position)
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	IUiComponent::Initialize(position);

	m_StageBar.Create("data//stage_bar.png");
	m_Pos1p.Create("data//pos_1p_ui.png");
	m_Pos2p.Create("data//pos_2p_ui.png");

	m_Pos1p.anchor = aqua::CVector2((float)m_Pos1p.GetTextureWidth() / 2.0f, (float)m_Pos1p.GetTextureHeight());
	m_Pos2p.anchor = aqua::CVector2((float)m_Pos2p.GetTextureWidth() / 2.0f, (float)0.0f);

	aqua::CVector2 half_text =
		aqua::CVector2(
			m_StageBar.GetTextureWidth() / 2.0f,
			m_StageBar.GetTextureHeight() / 2.0f);

	m_StageBar.position =
		aqua::CVector2(
			aqua::GetWindowWidth() / 2.0f - half_text.x,
			aqua::GetWindowHeight() / 2.0f - half_text.y);

	m_Pos1p.position =
		aqua::CVector2(
			0.0f,
			m_StageBar.position.y);

	m_Pos2p.position =
		aqua::CVector2(
			0.0f,
			m_StageBar.position.y);

	IGameObject::Initialize();
}

void CStagePosBar::Update(void)
{
	IGameObject::Update();
}

void CStagePosBar::Draw(void)
{
	m_StageBar.Draw();
	m_Pos1p.Draw();
	m_Pos2p.Draw();

	IGameObject::Draw();
}

void CStagePosBar::Finalize(void)
{
	m_StageBar.Delete();
	m_Pos1p.Delete();
	m_Pos2p.Delete();

	IGameObject::Finalize();
}

void CStagePosBar::Move(CPlayer* player)
{
	if (m_pStage->GetGoalPos().x != 0.0f)
	{
		m_PlayerRatio = (player->m_Position.x / m_pStage->GetGoalPos().x);

		if(player->GetDeviceID() == DEVICE_ID::P1)
			m_Pos1p.position.x = m_StageBar.position.x + ((m_StageBar.GetTextureWidth()) * m_PlayerRatio) + 30.0f;
		else
			m_Pos2p.position.x = m_StageBar.position.x + ((m_StageBar.GetTextureWidth()) * m_PlayerRatio) + 30.0f;
	}
}
