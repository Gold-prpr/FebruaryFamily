#include "player.h"
#include "../../../stage_manager/stage/stage.h"
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

	m_Chara.Create("data//player1p.ass","right");
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

	m_Chara.Update();

	switch (m_State)
	{
	case CPlayer::STATE::START: State_Start();  break;
	case CPlayer::STATE::MOVE:  State_Move();   break;
	case CPlayer::STATE::DEAD:  State_Dead();   break;
	case CPlayer::STATE::STOP:  State_Stop();   break;
	}
	m_Chara.position = aqua::CVector2::ZERO;
   //m_pCamera->GetScroll() + GetPosition() - m_Chara.anchor;

	IGameObject::Update();
}

void CPlayer::Draw()
{
	m_Chara.Draw();
	IGameObject::Draw();
}

void CPlayer::Finalize()
{
	m_Chara.Delete();
	IGameObject::Finalize();
}

bool CPlayer::IsDead()
{
	return m_State == STATE::DEAD;
}

bool CPlayer::IsStop()
{
	return m_State == STATE::STOP;
}

float CPlayer::GetHitRadius(void)
{
	return radius;
}

void CPlayer::Damage(void)
{
	m_State = STATE::DEAD;
}

void CPlayer::State_Start()
{
	m_Position = aqua::CVector2(100.0f,100.0f);
	m_State = STATE::MOVE;
}

void CPlayer::State_Move()
{

	using namespace aqua::controller;
	using namespace aqua::keyboard;

	int inputX = (
		(Button(KEY_ID::D) || GetAnalogStickLeft(DEVICE_ID::P1).x >= 0.7f) -
		(Button(KEY_ID::A) || GetAnalogStickLeft(DEVICE_ID::P1).x <= -0.7f));
	m_Velocity.x = 8.0f * inputX;


	if (m_DirCurrent != m_DirNext)
	{
		m_DirCurrent = m_DirNext;

		switch (m_DirNext)
		{
		case CHARA_DIR::LEFT:
			m_Chara.Change("left");
			break;
		case CHARA_DIR::RIGHT:
			m_Chara.Change("right");
			break;
		default:
			break;
		}
	}
}

void CPlayer::State_Dead()
{
}

void CPlayer::State_Stop()
{
}
