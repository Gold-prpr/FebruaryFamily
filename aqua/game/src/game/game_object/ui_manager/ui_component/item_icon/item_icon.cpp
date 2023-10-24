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

    //IUiComponent::Initialize(position);
    //m_1PItemIconSprite.Create("data\\frame.png");
    //m_2PItemIconSprite.Create("data\\frame.png");
    //m_1PItemIconSprite.position = m_Position;
    //m_2PItemIconSprite.position = m_Position + aqua::CVector2{ 0.0f, 540.0f };
    //IGameObject::Initialize();
}

//������
void CItemIcon::Update(void)
{
    if (Button(m_pPlayer->m_Device, BUTTON_ID::LEFT_SHOULDER))
    {

        if (m_pItemManager->m_item_rand == 0)
        {
            SpeedUpIcon();
        }
        if (m_pItemManager->m_item_rand == 1)
        {
            SpeedDownIcon();
        }


    }
}

//�`��
void CItemIcon::Draw(void)
{
}

//���
void CItemIcon::Finalize(void)
{
}

//�X�s�[�h�A�b�v�A�C�e��
void CItemIcon::SpeedUpIcon(void)
{
}

//�X�s�[�h�_�E���A�C�e��
void CItemIcon::SpeedDownIcon(void)
{
}
