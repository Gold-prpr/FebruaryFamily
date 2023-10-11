#include "item.h"

//�R���X�g���N�^
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//������
void IItem::Initialize(aqua::CVector2* position, std::string item_file)
{
	m_ItemSprite.Create(item_file);
	m_Position = position;

	IGameObject::Initialize();
}

//�X�V
void IItem::Update()
{
	m_ItemSprite.position = (*m_Position);

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
