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

    IUiComponent::Initialize(position);

    m_1PItemIconSprite.position = m_Position;
    m_2PItemIconSprite.position = m_Position + aqua::CVector2{ 0.0f, 540.0f };
    IGameObject::Initialize();
}

//������
void CItemIcon::Update(void)
{
    //if (Button(m_pPlayer->m_Device, BUTTON_ID::LEFT_SHOULDER))
    //{
    //    if (m_pItemManager->m_item_rand == 0)
    //    {
    //        m_1PItemIconSprite.Create("data\\speedup.png");

    //        //SpeedUpIcon();
    //    }
    //    if (m_pItemManager->m_item_rand == 1)
    //    {    
    //        m_1PItemIconSprite.Create("data\\speeddown.png");

    //       //SpeedDownIcon();
    //    }
    //}


    if (Button(DEVICE_ID::P1, BUTTON_ID::LEFT_SHOULDER))
    {
        if (m_pItemManager->m_item_rand == 0)
        {
            m_1PItemIconSprite.Create("data\\speedup.png");

            //SpeedUpIcon();
        }
        if (m_pItemManager->m_item_rand == 1)
        {
            m_1PItemIconSprite.Create("data\\speeddown.png");

            //SpeedDownIcon();
        }
    }
    if (Button(DEVICE_ID::P2, BUTTON_ID::LEFT_SHOULDER))
    {
        if (m_pItemManager->m_item_rand == 0)
        {

            m_2PItemIconSprite.Create("data\\speedup.png");

            //SpeedUpIcon();
        }
        if (m_pItemManager->m_item_rand == 1)
        {

            m_2PItemIconSprite.Create("data\\speeddown.png");

            //SpeedDownIcon();
        }
    }
}

//�`��
void CItemIcon::Draw(void)
{
    m_1PItemIconSprite.Draw();
    m_2PItemIconSprite.Draw();
}

//���
void CItemIcon::Finalize(void)
{
    m_1PItemIconSprite.Delete();
    m_2PItemIconSprite.Delete();
}

//�X�s�[�h�A�b�v�A�C�e��
void CItemIcon::SpeedUpIcon(void)
{
    if (m_pPlayer->m_Device == DEVICE_ID::P1)
        m_1PItemIconSprite.Create("data\\speedup.png");
    else 
        m_2PItemIconSprite.Create("data\\speedup.png");
}

//�X�s�[�h�_�E���A�C�e��
void CItemIcon::SpeedDownIcon(void)
{
    if (m_pPlayer->m_Device == DEVICE_ID::P1)
        m_1PItemIconSprite.Create("data\\speeddown.png");
    else 
        m_2PItemIconSprite.Create("data\\speeddown.png");
}
