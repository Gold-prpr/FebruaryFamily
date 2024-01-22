#include "item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//コンストラクタ
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//初期化
void IItem::Initialize(std::string item_file) 
{
	m_ItemSprite.Create(item_file);

	m_ItemFlag = false;

	m_EffectTimer.Setup(0.0f);

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

