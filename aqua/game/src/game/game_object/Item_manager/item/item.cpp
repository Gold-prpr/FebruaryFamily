#include "item.h"

//�R���X�g���N�^
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//������
void IItem::Initialize(/*const aqua::CVector2& position*/)
{
	m_Position = {100.0f,100.0f};

	IGameObject::Initialize();
}

//�X�V
void IItem::Update()
{
	IGameObject::Update();
}

//�`��
void IItem::Draw()
{
	IGameObject::Draw();
}

//���
void IItem::Finalize()
{
	IGameObject::Finalize();
}

//�A�C�e���̈ʒu
const aqua::CVector2& IItem::GetPosition()
{
	return m_Position;
}
