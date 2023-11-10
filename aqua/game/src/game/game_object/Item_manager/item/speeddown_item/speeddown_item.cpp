#include "speeddown_item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

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

	//�A�C�e�����g���Ă�����

	m_EffectTimer.Update();
	m_pPlayer->AddSpeed(0.8f);

	//�A�C�e�����ʎ��Ԃ��I�������
	if (m_EffectTimer.Finished())
		m_pPlayer->AddSpeed(1.0f);

}
