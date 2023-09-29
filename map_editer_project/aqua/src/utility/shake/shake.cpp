#include"shake.h"
#include "../../aqua.h"

/*
 * コンストラクト
 */
aqua::
CShake::CShake()
	:m_max_angle(360)
{
}

/*
 * 更新
 */
void 
aqua::CShake::Updata()
{
	if (m_ShakeCount != 0)
	{
		if (m_ShakeTimer.Finished())
		{

			m_ShakeTimer.Reset();
			m_Angle       = aqua::DegToRad((float)aqua::Rand(m_max_angle));
			m_ShakeMove.x = m_ShakeCount * cosf(m_Angle);
			m_ShakeMove.y = m_ShakeCount * sinf(m_Angle);
			m_ShakeCount--;

		}

		m_ShakeTimer.Update();
	}
	else
	{
		if (m_ShakeMove != aqua::CVector2::ZERO)
			m_ShakeMove = aqua::CVector2::ZERO;
	}
}

/*
 * 初期化
 */
void aqua::CShake::
Setup(int max_shake_count, float m_shake_interval)
{
	m_Angle = 0;

	m_ShakeMove     = aqua::CVector2::ZERO;
	m_ShakeMaxCount = max_shake_count;
	m_ShakeCount    = 0;

	m_ShakeTimer.Setup(m_shake_interval);
}

/*
 * 揺れの最大値を設定
 */
void aqua::CShake::SetMaxShakeCount(int max_shake_count)
{
	m_ShakeMaxCount = max_shake_count;
}

/*
 * 揺れの処理
 */
void aqua::CShake::
Shake()
{
	m_Angle = 0;

	m_ShakeMove  = aqua::CVector2::ZERO;
	m_ShakeCount = m_ShakeMaxCount;

	m_ShakeTimer.Reset();
}

/*
 * 揺れの大きさを取得
 */
aqua::CVector2 aqua::CShake::
GetShake()
{
	return m_ShakeMove;
}

/*
 * 揺れの終了フラグ
 */
bool aqua::CShake::GetShakeFinished()
{
	return m_ShakeCount == 0;
}
