#include "item.h"

//�R���X�g���N�^
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//������
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

//�X�V
void IItem::Update()
{
<<<<<<< HEAD
<<<<<<< HEAD
=======
	m_ItemSprite.position = aqua::CVector2(0, 0);
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
=======
>>>>>>> origin/我、新世界之王　KAWAGISIN～母親のパンツを添えて～
	IGameObject::Update();
}

//�`��
void IItem::Draw()
{
	m_ItemSprite.Draw();
	IGameObject::Draw();
}

//���
void IItem::Finalize()
{
	m_ItemSprite.Delete();
	IGameObject::Finalize();
}

//�A�C�e���̈ʒu
const aqua::CVector2& IItem::GetPosition()
{
	return m_ItemSprite.position;
}
