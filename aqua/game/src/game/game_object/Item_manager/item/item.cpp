#include "item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//�R���X�g���N�^
IItem::IItem(aqua::IGameObject* parent, const std::string& name)
	:aqua::IGameObject(parent, name, "Item")
{
}

//������
void IItem::Initialize(std::string item_file) 
{
	m_ItemSprite.Create(item_file);

	m_ItemFlag = false;

	m_EffectTimer.Setup(0.0f);

	IGameObject::Initialize();
}

//�X�V
void IItem::Update()
{
	//��������A�C�e���g�p
	//if (Trigger(KEY_ID::S))
	/*if (Button(DEVICE_ID::P1, BUTTON_ID::LEFT_SHOULDER) || Button(DEVICE_ID::P2, BUTTON_ID::LEFT_SHOULDER))*/

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

