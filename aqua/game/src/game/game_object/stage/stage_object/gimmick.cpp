#include "gimmick.h"
#include "../../stage/stage.h"
#include "../../unit_manager/unit/player/player.h"

const int CGimmick::alpha_cnt = 3;
const int CGimmick::alpha_interval = 10;

CGimmick::CGimmick(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "StageGimmick")
{
}

void CGimmick::Initialize()
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	m_AlphaCurrCnt = 0;
	m_AlphaTimer = 0;
	flame = 0;

	IGameObject::Initialize();
}

void CGimmick::DamageAction(void)
{
	m_AlphaTimer += 1;

	if (m_AlphaTimer > alpha_interval && m_AlphaCurrCnt < alpha_cnt)
	{
		m_pPlayer->m_Chara.color.alpha = 0;
		m_AlphaCurrCnt += 1;
		m_AlphaTimer = 0;
	}
	else
	{
		m_pPlayer->m_Chara.color.alpha = 255;
	}
	/*aqua::DegToRad()
	m_pPlayer->m_Position = sin()*/
}