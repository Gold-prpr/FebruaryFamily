#include "player.h"
#include "../../../stage/stage.h"
#include "../../../camera/camera.h"
#include "../../unit_manager.h"
using namespace aqua::controller;
using namespace aqua::keyboard;

const float CPlayer::speed = 8.0f;
const float CPlayer::jump = -25.0f;
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
	m_LandingFlag = false;

	IGameObject::Initialize();
}

void CPlayer::Update()
{
	m_Chara.Update();

	m_Velocity.x = 0.0f;

	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::A))
	{
		m_DirNext = CHARA_DIR::LEFT;
		m_Velocity.x = -speed;
	}
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::D))
	{
		m_DirNext = CHARA_DIR::RIGHT;
		m_Velocity.x = speed;
	}
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::SPACE))
	{
		if (m_LandingFlag == true)
		{
			m_Velocity.y = jump;
			m_LandingFlag = false;
		}
	}

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

	CheckHitBlok();
	
	m_Chara.position = m_pCamera->GetScroll() + GetPosition() - m_Chara.anchor;

	IGameObject::Update();
}

void CPlayer::CheckHitBlok(void)
{
	int x = (int)(m_Position.x);
	int y = (int)(m_Position.y);
	int nx = (int)(m_Position.x + m_Velocity.x);
	int ny = (int)(m_Position.y + m_Velocity.y);
	int w = (int)m_Width;
	int h = (int)m_Height;
	int size = 60;

	if (m_pStage->CheckHit(nx, y)
		|| m_pStage->CheckHit(nx + w - 1, y)
		|| m_pStage->CheckHit(nx, y + h / 2)
		|| m_pStage->CheckHit(nx + w - 1, y + h / 2)
		|| m_pStage->CheckHit(nx, y + h - 1)
		|| m_pStage->CheckHit(nx + w - 1, y + h - 1))
	{
		// 左に移動している
		if (m_Velocity.x < 0)
			nx = (nx / size + 1) * size;

		// 右に移動している
		if (m_Velocity.x > 0)
			nx = ((nx + w) / size) * size - w;

		// ブロックにあたっているので速度を消す
		m_Velocity.x = 0;
	}

	if (m_LandingFlag == true)
	{
		// 足元を調べてブロックがなければ落下
		if (!m_pStage->CheckHit(x, y + h) && !m_pStage->CheckHit(x + w, y + h))
		{
			// 足元にブロックがないので着地していない
			m_LandingFlag = false;

			// 落下が始まるのでスピードを消しておく
			m_Velocity.y = 0;
		}
	}
	// 空中にいる
	else if (m_LandingFlag == false)
	{
		// 重力で落下させる
		m_Velocity.y += m_pStage->GetGravity();

		// 上下のチェック
		if (m_pStage->CheckHit(x, ny)
			|| m_pStage->CheckHit(x + w - 1, ny)
			|| m_pStage->CheckHit(x, ny + h - 1)
			|| m_pStage->CheckHit(x + w - 1, ny + h - 1))
		{
			// 上に動いている
			if (m_Velocity.y < 0)
				ny = (ny / size + 1) * size;

			// 下に動いている
			if (m_Velocity.y > 0)
			{
				ny = ((ny + h) / size) * size - h;

				// 着地した
				m_LandingFlag = true;
			}

			// ブロックにあたっているので速度を消す
			m_Velocity.y = 0;
		}
	}

	// 位置の決定
	m_Position.x = (float)nx;
	m_Position.y = (float)ny;
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

void CPlayer::AddSpeed(float add_speed)
{
	m_AddSpeed = add_speed;
}

void CPlayer::State_Start()
{
	m_Position = aqua::CVector2(100.0f,100.0f);
	m_State = STATE::MOVE;
}

void CPlayer::State_Move()
{
	
}

void CPlayer::State_Dead()
{
}

void CPlayer::State_Stop()
{
}
