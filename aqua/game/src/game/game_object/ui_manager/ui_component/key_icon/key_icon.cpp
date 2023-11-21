#include "key_icon.h"

//�R���X�g���N�^
CKeyIcon::CKeyIcon(aqua::IGameObject* parent)
	: IUiComponent(parent, "ItemIcon")
{
}

//������
void CKeyIcon::Initialize(const aqua::CVector2& position)
{
	m_KeyIconSprite.Create("data\\key.png");

	m_KeyCountLabel.Create(50, 2);

	IGameObject::Initialize();
}

//�X�V
void CKeyIcon::Update(void)
{

	//m_KeyCountLabel.text = "�~" + std::to_string();


	IGameObject::Update();
}

//�`��
void CKeyIcon::Draw(void)
{
	m_KeyIconSprite.Draw();


	IGameObject::Draw();
}

//���
void CKeyIcon::Finalize(void)
{
	m_KeyIconSprite.Delete();

	IGameObject::Finalize();
}

//��������
void CKeyIcon::KeyCount()
{
}
