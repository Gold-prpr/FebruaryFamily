#include "sakura_effect.h"

//コンストラクタ
CSakuraEffect::CSakuraEffect(aqua::IGameObject* parent)
	:IEffect(parent, "SakuraEffect")
{
}

//初期化
void CSakuraEffect::Initialize(const aqua::CVector2& position)
{
	IEffect::Initialize(position);

	//どちらかの桜を出す
	if (aqua::Rand(1))m_Sakura.Create("data\\sakura1.png");
	else m_Sakura.Create("data\\sakura2.png");

	//上からランダムに降らす
	m_Sakura.position.x = (float)aqua::Rand(aqua::GetWindowWidth());
	m_Sakura.position.y = 0;

	//ランダムな大きさ
	m_Sakura.scale.x = (float)aqua::Rand(30) / 10.0f;
	m_Sakura.scale.y = m_Sakura.scale.x;

	m_angle = 0;
}

//更新
void CSakuraEffect::Update()
{
	//薄くなったら消える
	if (m_Sakura.color.alpha == 3)
		IGameObject::DeleteObject();

	m_angle++;

	//揺らす
	m_Sakura.position.x += cos(aqua::DegToRad((float)m_angle));

	//徐々に薄く
	m_Sakura.color.alpha -= 1;

	//下に移動
	m_Sakura.position.y += m_Sakura.scale.x * 5;
}

//描画
void CSakuraEffect::Draw()
{
	m_Sakura.Draw();
}

//解放
void CSakuraEffect::Finalize()
{
	m_Sakura.Delete();
}