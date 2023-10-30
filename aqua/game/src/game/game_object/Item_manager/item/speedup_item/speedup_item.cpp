#include "speedup_item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//�R���X�g���N�^
CSpeedUpItem::CSpeedUpItem(aqua::IGameObject* parent)
	:IItem(parent,"SpeedUpItem")
{
}

//������
void CSpeedUpItem::Initialize(aqua::CVector2* position) 
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//5�b��
	m_EffectTimer.Setup(5.0f);

	//�A�C�e���g���Ă��Ȃ����
	m_itemflag = false;
	IItem::Initialize(position, "data\\speedup.png");
}

//�X�V
void CSpeedUpItem::Update()
{
	SpeedUp();
}

//�`��
void CSpeedUpItem::Draw()
{
	//IItem::Draw();
}

//���
void CSpeedUpItem::Finalize()
{
	//IItem::Finalize();
}

//����
void CSpeedUpItem::SpeedUp()
{
	//�g���ĂȂ����͒ʏ�X�s�[�h
	if (m_itemflag == false)
		m_pPlayer->AddSpeed(1.0f);

	//��������A�C�e���g�p
	//if (Trigger(KEY_ID::S))
	if (Button(DEVICE_ID::P1, BUTTON_ID::LEFT_SHOULDER) || Button(DEVICE_ID::P2, BUTTON_ID::LEFT_SHOULDER))
		m_itemflag = true;

	//�A�C�e�����g���Ă�����
	if (m_itemflag == true)
	{
	 	m_EffectTimer.Update();
		m_pPlayer->AddSpeed(1.5f);
	}

	//�A�C�e�����ʎ��Ԃ��I�������
	if (m_EffectTimer.Finished())
		m_itemflag = false;
}
