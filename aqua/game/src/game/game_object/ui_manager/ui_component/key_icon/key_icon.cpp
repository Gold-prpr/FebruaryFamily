#include "key_icon.h"

//�R���X�g���N�^
CKeyIcon::CKeyIcon(aqua::IGameObject* parent)
	: IUiComponent(parent, "KeyIcon")
{
}

//������
void CKeyIcon::Initialize(const aqua::CVector2& position)
{
	//�v���C���[�̒��g��ǂݍ���
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	m_1PKeyIconSprite.Create("data\\key.png");

	m_1PKeyCountLabel.Create(50, 2);

	m_1PKeyIconSprite.position = m_Position + aqua::CVector2{ 0.0f, 180.0f };

	m_1PKeyCountLabel.position = m_Position + aqua::CVector2{ 60.0f,180.0f };

	m_2PKeyIconSprite.Create("data\\key.png");

	m_2PKeyCountLabel.Create(50, 2);

	m_2PKeyIconSprite.position = m_Position + aqua::CVector2{ 0.0f, 720.0f };

	m_2PKeyCountLabel.position = m_Position + aqua::CVector2{ 60.0f,720.0f };

	IGameObject::Initialize();
}

//�X�V
void CKeyIcon::Update(void)
{

	IGameObject::Update();
}

//�`��
void CKeyIcon::Draw(void)
{
	m_1PKeyIconSprite.Draw();
	m_1PKeyCountLabel.Draw();
	m_2PKeyIconSprite.Draw();
	m_2PKeyCountLabel.Draw();

	IGameObject::Draw();
}

//���
void CKeyIcon::Finalize(void)
{
	m_1PKeyIconSprite.Delete();
	m_1PKeyCountLabel.Delete();
	m_2PKeyIconSprite.Delete();
	m_2PKeyCountLabel.Delete();

	IGameObject::Finalize();
}

//��������
void CKeyIcon::KeyCount(CPlayer* player)
{
	if (player->GetDeviceID() == DEVICE_ID::P1)
		m_1PKeyCountLabel.text = " �~ " + std::to_string(player->m_KeyCount);
	else
		m_2PKeyCountLabel.text = " �~ " + std::to_string(player->m_KeyCount);
}

//���擾
void CKeyIcon::AddKeyCount(CPlayer* player)
{
	if (player->m_KeyFlag == true && player->m_KeyCount < 3)
	{
		player->m_KeyCount += 1;
	}
}
