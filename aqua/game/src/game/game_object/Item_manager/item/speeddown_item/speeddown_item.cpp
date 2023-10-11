#include "speeddown_item.h"

//�R���X�g���N�^
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
{
}

//������
void CSpeedDownItem::Initialize(aqua::CVector2* position)
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//5�b��
	m_EffectTimer.Setup(5.0f);

	//�A�C�e���g���Ă��Ȃ����
	m_itemflag = false;

	IItem::Initialize(position, "data\\speeddown.png");
}

//�X�V
void CSpeedDownItem::Update()
{
	SpeedDown();
}

//�`��
void CSpeedDownItem::Draw()
{
	//IItem::Draw();
}

//���
void CSpeedDownItem::Finalize()
{
	//IItem::Finalize();
}

//����
void CSpeedDownItem::SpeedDown()
{
	//using namespace aqua::keyboard;

	//if (Trigger(KEY_ID::S))
	//{
	//	m_pPlayer->AddSpeed(0.8);
	//}

	using namespace aqua::keyboard;

	//�g���ĂȂ����͒ʏ�X�s�[�h
	if (m_itemflag == false)
		m_pPlayer->AddSpeed(1.0f);

	//��������A�C�e���g�p
	if (Trigger(KEY_ID::S))
		m_itemflag = true;

	//�A�C�e�����g���Ă�����
	if (m_itemflag == true)
	{
		m_EffectTimer.Update();
		m_pPlayer->AddSpeed(0.8f);
	}

	//�A�C�e�����ʎ��Ԃ��I�������
	if (m_EffectTimer.Finished())
		m_itemflag = false;

}
