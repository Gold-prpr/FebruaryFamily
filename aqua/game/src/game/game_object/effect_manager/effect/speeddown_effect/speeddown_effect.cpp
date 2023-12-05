#include "speeddown_effect.h"

//コンストラクタ
CSpeedDownEffect::CSpeedDownEffect(aqua::IGameObject* parent)
	:IEffect(parent, "SpeedDownEffect")
{
}

//初期化
void CSpeedDownEffect::Initialize(const aqua::CVector2& position)
{
	m_SpeedDownEffectSprite.Create("data\\player_1.png");

	IEffect::Initialize(position);

	m_SpeedDownEffectSprite.anchor.x = m_SpeedDownEffectSprite.GetTextureWidth() / 2.0f;
	m_SpeedDownEffectSprite.anchor.y = m_SpeedDownEffectSprite.GetTextureHeight() / 2.0f;

	//光る位置
	m_SpeedDownEffectSprite.position = m_Position - m_SpeedDownEffectSprite.anchor;

	//消えるまでの時間
	m_SpeedDownEffectTimer.Setup(0.5f);

	//色
	m_SpeedDownEffectSprite.blend_mode = aqua::ALPHABLEND::ADD;
}

//更新
void CSpeedDownEffect::Update(void)
{
	m_SpeedDownEffectTimer.Update();

	//消える処理
	if (m_SpeedDownEffectTimer.Finished())
	{
		DeleteObject();

		m_SpeedDownEffectTimer.SetTimer(m_SpeedDownEffectTimer.GetLimit());
	}

	//透明度
	m_SpeedDownEffectSprite.color.alpha = 255 - (int)(255.0f * m_SpeedDownEffectTimer.GetTime() / m_SpeedDownEffectTimer.GetLimit());

	//エフェクト位置
	//m_SpeedDownEffectSprite.position.x += 1.0f * aqua::GetDeltaTime();
	m_SpeedDownEffectSprite.scale += aqua::CVector2::ONE * aqua::GetDeltaTime();
}

//描画
void CSpeedDownEffect::Draw(void)
{
	m_SpeedDownEffectSprite.Draw();
}

//解放
void CSpeedDownEffect::Finalize(void)
{
	m_SpeedDownEffectSprite.Delete();
}
