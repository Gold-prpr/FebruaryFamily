#include "item_icon.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//�R���X�g���N�^
CItemIcon::CItemIcon(aqua::IGameObject* parent)
	: IUiComponent(parent, "ItemIcon")
{
}

//������
void CItemIcon::Initialize(const aqua::CVector2& position)
{
	//�v���C���[�̒��g��ǂݍ���
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//�A�C�e���}�l�[�W���[�̒��g��ǂݍ���
	m_pItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");

	m_1PItemIconSprite.position = m_Position + aqua::CVector2{ 70.0f, 70.0f };
	m_2PItemIconSprite.position = m_Position + aqua::CVector2{ 70.0f, 600.0f };

	IUiComponent::Initialize(position);
	IGameObject::Initialize();
}

//������
void CItemIcon::Update(void)
{
	IGameObject::Update();
}

//�`��
void CItemIcon::Draw(void)
{
	m_1PItemIconSprite.Draw();
	m_2PItemIconSprite.Draw();

	IGameObject::Draw();
}

//���
void CItemIcon::Finalize(void)
{
	IGameObject::Finalize();
}

//�v���C���[���A�C�e���{�b�N�X�ɐG�ꂽ��
void CItemIcon::Check(CPlayer* player)
{
	if (player->m_HitItemFlag == true)
	{
		if (m_pItemManager->m_ItemRand == 0)
		{
			if (player->GetDeviceID() == DEVICE_ID::P1)
				m_1PItemIconSprite.Create("data\\speeddown.png");
			else
				m_2PItemIconSprite.Create("data\\speeddown.png");
		}
		if (m_pItemManager->m_ItemRand == 1)
		{
			if (player->GetDeviceID() == DEVICE_ID::P1)
				m_1PItemIconSprite.Create("data\\speedup.png");
			else
				m_2PItemIconSprite.Create("data\\speedup.png");
		}

		player->AddItemSpeed(2.0f);
	}
	else
	{
		//player->AddItemSpeed(0.0f);
	}
	
}

//�v���C���[���A�C�e���g������
void CItemIcon::DeleteItem(CPlayer* player)
{
	if (player->GetDeviceID() == DEVICE_ID::P1)
		m_1PItemIconSprite.Delete();
	else
		m_2PItemIconSprite.Delete();
}
