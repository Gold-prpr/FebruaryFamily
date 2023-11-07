#include "gimmick.h"
#include "../../stage/stage.h"
#include "../../unit_manager/unit/player/player.h"
#include "../../unit_manager/unit_manager.h"

const int CGimmickAct::alpha_cnt = 3;
const int CGimmickAct::alpha_interval = 10;

CGimmickAct::CGimmickAct(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "GimmickAct")
{
}

void CGimmickAct::Initialize()
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_AlphaCurrCnt = 0;
	m_AlphaTimer = 0;

	IGameObject::Initialize();
}

void CGimmickAct::DamageAction(CPlayer* player)
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
}