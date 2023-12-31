#include "item.h"

//コンストラクタ
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//初期化
void IItem::Initialize(aqua::CVector2* position, std::string item_file) 
{
	m_ItemSprite.Create(item_file);

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
	m_ItemSprite.Draw();
	IGameObject::Draw();
}

//解放
void IItem::Finalize()
{
	m_ItemSprite.Delete();
	IGameObject::Finalize();
}

//アイテムの位置
const aqua::CVector2& IItem::GetPosition()
{
	return m_ItemSprite.position;
}
