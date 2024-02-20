#include "dark.h"

//�R���X�g���N�^
CDark::CDark(aqua::IGameObject* parent)
	: IUiComponent(parent, "Dark")
{
}

//������
void CDark::Initialize(const aqua::CVector2& position)
{
	//�v���C���[�̒��g��ǂݍ���
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//�A�C�e���}�l�[�W���[�̒��g��ǂݍ���
	m_pItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");

	m_1PDark.position = m_Position + aqua::CVector2::ZERO;
	m_2PDark.position = m_Position + aqua::CVector2{ 0.0f,540.0f };

	IUiComponent::Initialize(position);
	IGameObject::Initialize();
}

//�`��
void CDark::Draw(void)
{
	m_1PDark.Draw();
	m_2PDark.Draw();
}

//���
void CDark::Finalize(void)
{
	m_1PDark.Delete();
	m_2PDark.Delete();
}

//����̉�ʂɕ`��
void CDark::Dark(CPlayer* player)
{
	//�A�C�e�����g���Ă�����
	if (player->GetDeviceID() == DEVICE_ID::P1)
		m_2PDark.Create("data/dark.png");
	else
		m_1PDark.Create("data/dark.png");
}
