#include "item.h"

//コンストラクタ
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//初期化
void IItem::Initialize(/*const aqua::CVector2& position*/)
{
	m_Position = {100.0f,100.0f};

	IGameObject::Initialize();
}

//更新
void IItem::Update()
{
	IGameObject::Update();
}

//描画
void IItem::Draw()
{
	IGameObject::Draw();
}

//解放
void IItem::Finalize()
{
	IGameObject::Finalize();
}

//アイテムの位置
const aqua::CVector2& IItem::GetPosition()
{
	return m_Position;
}
