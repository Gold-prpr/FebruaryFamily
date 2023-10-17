#include "player.h"
#include "../../../stage/stage.h"
#include "../../../camera/camera.h"
#include "../../unit_manager.h"
#include "../../../stage/stage_object/gimmick.h"
using namespace aqua::keyboard;

const float CPlayer::speed = 8.0f;//キャラのスピード
const float CPlayer::jump = -25.0f;//キャラのジャンプ
const float CPlayer::width = 60.0f;//キャラの幅
const float CPlayer::height = 60.0f;//キャラの高さ
const float CPlayer::radius = 30.0f;//キャラの半径
const float CPlayer::dash = 1.7f;//キャラのダッシュ力


CPlayer::CPlayer(aqua::IGameObject* parent)
	:IUnit(parent, "Player")
	, m_pStage(nullptr)
	, m_pCamera(nullptr)
	, m_pUnitManager(nullptr)
	, m_pGimmick(nullptr)
	, m_State(STATE::START)
	, m_Device(DEVICE_ID::P1)
{
}

void CPlayer::Initialize(const aqua::CVector2& position,DEVICE_ID device)
{
	m_pCamera = (CCamera*)aqua::FindGameObject("Camera");
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	


	m_Chara.Create("data//player1p.ass", "right");
	m_Chara.anchor.x = m_Chara.GetFrameWidth() / 2.0f;
	m_Chara.anchor.y = m_Chara.GetFrameHeight() / 2.0f;
	m_Position = position;
	m_Velocity = aqua::CVector2::ZERO;
	m_Width = width;
	m_Height = height;
	m_UnitID = UNIT_ID::PLAYER;
	m_Device = device;
	m_LandingFlag = false;

	IGameObject::Initialize();
}

void CPlayer::Update()
{

	switch (m_State)
	{
	case STATE::START: State_Start(); break;//開始の状態
	case STATE::MOVE: State_Move(); break;//キャラが動ける状態
	case STATE::DEAD: State_Dead(); break;//キャラが死んだ状態
	case STATE::STOP: State_Stop(); break;//キャラがゴールした時の状態
	}

	CheckHitBlok();//壁の当たり判定
	m_Chara.position = m_Position + m_pCamera->GetScroll();//カメラのスクロール

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

	/*if (m_pStage->CheckGoal(nx, y)
		|| m_pStage->CheckGoal(nx + w - 1, y)
		|| m_pStage->CheckGoal(nx, y + h / 2)
		|| m_pStage->CheckGoal(nx + w - 1, y + h / 2)
		|| m_pStage->CheckGoal(nx, y + h - 1)
		|| m_pStage->CheckGoal(nx + w - 1, y + h - 1))
	{
		m_Velocity.x = 0;
	}*/

	if (m_pStage->CheckGimmick(nx, y)
		|| m_pStage->CheckGimmick(nx + w - 1, y)
		|| m_pStage->CheckGimmick(nx, y + h / 2)
		|| m_pStage->CheckGimmick(nx + w - 1, y + h / 2)
		|| m_pStage->CheckGimmick(nx, y + h - 1)
		|| m_pStage->CheckGimmick(nx + w - 1, y + h - 1))
	{
		m_pGimmick = (CGimmick*)aqua::FindGameObject("StageGimmick");
		m_pGimmick->DamageAction();
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
	m_Chara.Draw();//キャラの描画
	IGameObject::Draw();
}

void CPlayer::Finalize()
{
	m_Chara.Delete();//キャラの解放
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

//スピードの加算
void CPlayer::AddSpeed(float add_speed)
{
	m_AddSpeed = add_speed;
}

//開始の状態
void CPlayer::State_Start()
{
	m_Position = aqua::CVector2(100.0f, 100.0f);
	m_State = STATE::MOVE;
}

//動ける状態
void CPlayer::State_Move()
{
	m_Chara.Update();

	/*float input_x_value = GetAnalogStickLeft(m_Device).x;
	int inputx = ((input_x_value >= 0.7f) - (input_x_value <= -0.7f));

	m_Velocity.x = speed * inputx;
	if (inputx != 0)
	{
		m_DirNext = (CHARA_DIR)inputx;
	}

	if (Button(m_Device, BUTTON_ID::X))
	{
		m_Velocity.x = m_Velocity.x * dash;
	}

	if (Trigger(m_Device, BUTTON_ID::A))
	{
		if (m_LandingFlag == true)
		{
			m_Velocity.y = jump;
			m_LandingFlag = false;
		}
	}*/

	m_Velocity.x = 0.0f;
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::A))
		m_Velocity.x -= speed;
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::D))
		m_Velocity.x += speed;
	if (aqua::keyboard::Button(aqua::keyboard::KEY_ID::SPACE))
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
}

void CPlayer::State_Dead()
{
}

void CPlayer::State_Stop()
{
}
