#include "item.h"

//コンストラクタ
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//初期化
<<<<<<< HEAD
void IItem::Initialize(aqua::CVector2 position, std::string item_file)
{
	m_ItemSprite.Create(item_file);
	m_ItemSprite.position = position;
=======
void IItem::Initialize(aqua::CVector2* position, std::string item_file) 
{
	m_ItemSprite.Create(item_file);
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b

	IGameObject::Initialize();
}

//更新
void IItem::Update()
{
<<<<<<< HEAD
=======
	m_ItemSprite.position = aqua::CVector2(0, 0);
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
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
