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

void CGimmickAct::DamageAct(CPlayer* player)
{
	if (player->m_HitSpikeFlag == true)
	{
		m_AlphaTimer += 1;
		if (m_AlphaTimer >= alpha_interval && m_AlphaCurrCnt <= alpha_cnt)
		{
			player->m_CharaSprite.color.alpha = 0;
			m_AlphaCurrCnt += 1;
			m_AlphaTimer = 0;
		}
		else if (m_AlphaTimer >= alpha_interval && m_AlphaCurrCnt >= alpha_cnt)
		{
			player->m_Position.x -= 200.0f;
			player->m_HitSpikeFlag = false;
			m_AlphaCurrCnt = 0;
			m_AlphaTimer = 0;
		}
		else
		{
			player->m_CharaSprite.color.alpha = 255;
		}
	}
}

void CGimmickAct::SlowAct(CPlayer* player)
{
	if (player->m_HitWireFlag == true)
		player->AddGimmickSpeed(0.6f);
	else
		player->AddGimmickSpeed(1.0f);
}

void CGimmickAct::JumpAct(CPlayer* player)
{
	if (player->m_JampRampFlag == true)
	{
		if (player->m_LandingFlag == true)
		{
			player->JumpRamp();
			player->m_LandingFlag = false;
		}
	}
}