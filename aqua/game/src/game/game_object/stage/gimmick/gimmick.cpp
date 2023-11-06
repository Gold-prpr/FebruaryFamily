#include "gimmick.h"
#include "../../stage/stage.h"
#include "../../unit_manager/unit/player/player.h"
#include "../../unit_manager/unit_manager.h"

const int CGimmick::alpha_cnt = 3;
const int CGimmick::alpha_interval = 10;

CGimmick::CGimmick(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Gimmick")
{
}

void CGimmick::Initialize()
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_AlphaCurrCnt = 0;
	m_AlphaTimer = 0;

	IGameObject::Initialize();
}

void CGimmick::DamageAction(CPlayer* player)
{

	if (player->m_HitFlag == true)
	{
		m_AlphaTimer += 1;

		if (m_AlphaTimer >= alpha_interval && m_AlphaCurrCnt <= alpha_cnt)
		{
			player->m_Chara.color.alpha = 0;
			m_AlphaCurrCnt += 1;
			m_AlphaTimer = 0;
		}
		else if (m_AlphaTimer >= alpha_interval && m_AlphaCurrCnt >= alpha_cnt)
		{
			player->m_Position.x -= 200.0f;
			player->m_HitFlag = false;
			m_AlphaCurrCnt = 0;
			m_AlphaTimer = 0;
		}
		else
		{
			player->m_Chara.color.alpha = 255;
		}
	}

	/*m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P2);

	if (m_pPlayer->m_HitFlag == true)
	{
		m_AlphaTimer += 1;

		if (m_AlphaTimer >= alpha_interval && m_AlphaCurrCnt <= alpha_cnt)
		{
			m_pPlayer->m_Chara.color.alpha = 0;
			m_AlphaCurrCnt += 1;
			m_AlphaTimer = 0;
		}
		else if (m_AlphaTimer >= alpha_interval && m_AlphaCurrCnt >= alpha_cnt)
		{
			m_pPlayer->m_Position.x -= 200.0f;
			m_pPlayer->m_HitFlag = false;
			m_AlphaCurrCnt = 0;
			m_AlphaTimer = 0;
		}
		else
		{
			m_pPlayer->m_Chara.color.alpha = 255;
		}
	}*/
}