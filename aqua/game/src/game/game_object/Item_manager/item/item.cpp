#include "item.h"

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//‰Šú‰»
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

//XV
void IItem::Update()
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
	m_ItemSprite.position = aqua::CVector2(0, 0);
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
=======
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
	IGameObject::Update();
}

//•`‰æ
void IItem::Draw()
{
	m_ItemSprite.Draw();
	IGameObject::Draw();
}

//‰ğ•ú
void IItem::Finalize()
{
	m_ItemSprite.Delete();
	IGameObject::Finalize();
}

//ƒAƒCƒeƒ€‚ÌˆÊ’u
const aqua::CVector2& IItem::GetPosition()
{
	return m_ItemSprite.position;
}
