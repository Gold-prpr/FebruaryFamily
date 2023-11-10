#include "item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//コンストラクタ
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//初期化
void IItem::Initialize(aqua::CVector2* position, std::string item_file) 
{
	m_ItemSprite.Create(item_file);

	//アイテム使っていない状態
	m_itemflag = false;

	IGameObject::Initialize();
}

//更新
void IItem::Update()
{
	m_ItemSprite.position = aqua::CVector2(0, 0);

	//押したらアイテム使用
	//if (Trigger(KEY_ID::S))
	/*if (Button(DEVICE_ID::P1, BUTTON_ID::LEFT_SHOULDER) || Button(DEVICE_ID::P2, BUTTON_ID::LEFT_SHOULDER))*/
		m_itemflag = true;

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
