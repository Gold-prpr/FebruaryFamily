#include "key_icon.h"

//コンストラクタ
CKeyIcon::CKeyIcon(aqua::IGameObject* parent)
	: IUiComponent(parent, "ItemIcon")
{
}

//初期化
void CKeyIcon::Initialize(const aqua::CVector2& position)
{
	m_KeyIconSprite.Create("data\\key.png");

	m_KeyCountLabel.Create(50, 2);

	IGameObject::Initialize();
}

//更新
void CKeyIcon::Update(void)
{

	//m_KeyCountLabel.text = "×" + std::to_string();


	IGameObject::Update();
}

//描画
void CKeyIcon::Draw(void)
{
	m_KeyIconSprite.Draw();


	IGameObject::Draw();
}

//解放
void CKeyIcon::Finalize(void)
{
	m_KeyIconSprite.Delete();

	IGameObject::Finalize();
}

//鍵所持数
void CKeyIcon::KeyCount()
{
}
