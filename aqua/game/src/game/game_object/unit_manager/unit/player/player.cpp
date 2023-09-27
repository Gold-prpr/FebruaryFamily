#include "player.h"
#include "../../../stage/stage.h"
#include "../../../camera/camera.h"
#include "../../unit_manager.h"

const float CPlayer::width = 60.0f;
const float CPlayer::height = 60.0f;
const float CPlayer::radius = 30.0f;

CPlayer::CPlayer(aqua::IGameObject* parent)
	:IUnit(parent,"Player")
	,m_pStage(nullptr)
	,m_pCamera(nullptr)
	,m_pUnitManager(nullptr)
	,m_State(STATE::START)
{
}

void CPlayer::Initialize(const aqua::CVector2& position)
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_pCamera = (CCamera*)aqua::FindGameObject("Camera");
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_Chara.Create("date/abe.png");
	m_Chara.anchor.x = m_Chara.GetTextureWidth() / 2.0f;
	m_Chara.anchor.y = m_Chara.GetTextureHeight() / 2.0f;
	m_Position = position;
	m_Velocity = aqua::CVector2::ZERO;
	m_Width = width;
	m_Height = height;
	m_UnitID = UNIT_ID::PLAYER;

	IGameObject::Initialize();
}

void CPlayer::Update()
{
	switch (m_State)
	{
	case CPlayer::STATE::START: State_Start();  break;
	case CPlayer::STATE::MOVE:  State_Move();   break;
	case CPlayer::STATE::DEAD:  State_Dead();   break;
	case CPlayer::STATE::STOP:  State_Stop();   break;
	}
	m_Chara.position = m_
}

void CPlayer::Draw()
{
}

void CPlayer::Finalize()
{
}

bool CPlayer::IsDead()
{
	return false;
}

bool CPlayer::IsGoal()
{
	return false;
}

float CPlayer::GetHitRadius(void)
{
	return radius;
}

void CPlayer::Damage(void)
{
}

void CPlayer::State_Start()
{
}

void CPlayer::State_Move()
{
}

void CPlayer::State_Dead()
{
}

void CPlayer::State_Goal()
{
}
