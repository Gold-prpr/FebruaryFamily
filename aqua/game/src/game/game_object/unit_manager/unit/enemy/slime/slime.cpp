#include "slime.h"
#include "../../../../stage/stage.h"
#include "../../player/player.h"

const float CSlime::m_width = 60.0f;
const float CSlime::m_height = 60.0f;

CSlime::CSlime(aqua::IGameObject* parent)
	:IUnit(parent, "Slime")
	, m_ReflectionFlag(true)
{
}

void CSlime::Initialize(const aqua::CVector2& position)
{
	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_SlimeAnimaSprite.Create("data/slime.ass", "left");
	m_UnitID = UNIT_ID::SLIME;
	m_Width = m_width;
	m_Height = m_height;
	m_Position = position;
	m_Velocity = aqua::CVector2::ZERO;

}

void CSlime::Update()
{
	

	m_Position = aqua::CVector2(500.0f, 100.0f);

	m_Velocity.x = 8.0f;

	m_Position.x = m_Position.x + m_Velocity.x;

	CheckHitBlok();
}

void CSlime::Draw()
{
	m_SlimeAnimaSprite.Draw();
}

void CSlime::Finalize()
{
	m_SlimeAnimaSprite.Delete();
}

void CSlime::CheckHitBlok(void)
{
	int x = (int)(m_Position.x);
	int y = (int)(m_Position.y);
	int nx = (int)(m_Position.x + m_Velocity.x);;
	int ny = (int)(m_Position.y + m_Velocity.y);;
	int  w = (int)m_Width;
	int h = (int)m_Height;
	int size = 60;

	if (m_pStage->CheckObject(nx, y)
		|| m_pStage->CheckObject(nx + w - 1, y)
		|| m_pStage->CheckObject(nx, y + h / 2)
		|| m_pStage->CheckObject(nx + w - 1, y + h / 2)
		|| m_pStage->CheckObject(nx, y + h - 1)
		|| m_pStage->CheckObject(nx + w - 1, y + h - 1))
	{
		// 左に移動している
		if (m_Velocity.x < 0)
			nx = (nx / size + 1) * size;

		// 右に移動している
		if (m_Velocity.x > 0)
			nx = ((nx + w) / size) * size - w;

		// ブロックにあたっているので速度を消す
		m_Velocity.x = 0;

		if (m_ReflectionFlag && m_Velocity.x < 0.0f)
		{
			m_ReflectionFlag = false;
		}

		if (!m_ReflectionFlag && m_Velocity.x > 0.0f)
		{
			m_ReflectionFlag = true;
		}

		if (m_ReflectionFlag)
		{
			m_SlimeAnimaSprite.Change("left");
		}
		if (m_ReflectionFlag)
		{
			m_SlimeAnimaSprite.Change("right");
		}
	}


	if (m_LandingFlag == true)
	{
		// 足元を調べてブロックがなければ落下
		if (!m_pStage->CheckObject(x, y + h) && !m_pStage->CheckObject(x + w, y + h))
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
		if (m_pStage->CheckObject(nx, y)
			|| m_pStage->CheckObject(nx + w - 1, y)
			|| m_pStage->CheckObject(nx, y + h - 1)
			|| m_pStage->CheckObject(nx + w - 1, y + h - 1))
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

void CSlime::Damage()
{
		DeleteObject();
}
