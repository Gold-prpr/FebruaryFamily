#include "dark.h"

//コンストラクタ
CDark::CDark(aqua::IGameObject* parent)
	: IUiComponent(parent, "Dark")
{
}

//初期化
void CDark::Initialize(const aqua::CVector2& position)
{
	//プレイヤーの中身を読み込む
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//アイテムマネージャーの中身を読み込む
	m_pItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");

	m_1PDark.position = m_Position + aqua::CVector2::ZERO;
	m_2PDark.position = m_Position + aqua::CVector2{ 0.0f,540.0f };

	IUiComponent::Initialize(position);
	IGameObject::Initialize();
}

//描画
void CDark::Draw(void)
{
	m_1PDark.Draw();
	m_2PDark.Draw();
}

//解放
void CDark::Finalize(void)
{
	m_1PDark.Delete();
	m_2PDark.Delete();
}

//相手の画面に描画
void CDark::Dark(CPlayer* player)
{
	//アイテムを使っていたら
	if (player->GetDeviceID() == DEVICE_ID::P1)
		m_2PDark.Create("data/dark.png");
	else
		m_1PDark.Create("data/dark.png");
}
