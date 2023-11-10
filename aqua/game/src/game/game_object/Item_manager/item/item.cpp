#include "item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//�R���X�g���N�^
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//������
void IItem::Initialize(aqua::CVector2* position, std::string item_file) 
{
	m_ItemSprite.Create(item_file);

	//�A�C�e���g���Ă��Ȃ����
	m_itemflag = false;

	IGameObject::Initialize();
}

//�X�V
void IItem::Update()
{
	m_ItemSprite.position = aqua::CVector2(0, 0);

	//��������A�C�e���g�p
	//if (Trigger(KEY_ID::S))
	/*if (Button(DEVICE_ID::P1, BUTTON_ID::LEFT_SHOULDER) || Button(DEVICE_ID::P2, BUTTON_ID::LEFT_SHOULDER))*/
		m_itemflag = true;

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
