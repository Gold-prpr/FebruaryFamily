#include "speeddown_item.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//�R���X�g���N�^
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
{
}

//������
void CSpeedDownItem::Initialize()
{
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");

	//IItem::Initialize(position, "data\\speeddown.png");

	IGameObject::Initialize();
}

//�X�V
void CSpeedDownItem::Update()
{
	/*SpeedDown();*/
	IGameObject::Update();
}

//����
void CSpeedDownItem::SpeedDown()
{
	//�A�C�e�����g���Ă�����
	m_EffectTimer.Setup(5.0f);
	m_EffectTimer.Update();
	m_pPlayer->AddSpeed(0.2f);

	//�A�C�e�����ʎ��Ԃ��I�������
	if (m_EffectTimer.Finished())
		m_pPlayer->AddSpeed(1.0f);

}