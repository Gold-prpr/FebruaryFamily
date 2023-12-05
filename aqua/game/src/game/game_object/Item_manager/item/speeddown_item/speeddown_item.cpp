#include "speeddown_item.h"
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../effect_manager/effect_manager.h"

using namespace aqua::keyboard;
using namespace aqua::controller;

//�R���X�g���N�^
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
{
}

//������
void CSpeedDownItem::Initialize(aqua::controller::DEVICE_ID other_id)
{
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	m_pPlayer = m_pUnitManager->GetPlayer(other_id);

	//IItem::Initialize(position, "data\\speeddown.png");
	m_EffectTimer.Setup(5.0f);
	
	IGameObject::Initialize();
}

//�X�V
void CSpeedDownItem::Update()
{
	/*SpeedDown();*/
	//�A�C�e�����ʎ��Ԃ��I�������

	if (m_EffectTimer.Finished()&& m_ItemFlag ==true)
		if (m_pPlayer != nullptr)
		{
			m_pPlayer->AddItemSpeed(1.0f);
			m_ItemFlag = false;
			m_pEffectManager->DeleteObject();
		}

	m_EffectTimer.Update();
	
	IGameObject::Update();
}

//����
void CSpeedDownItem::SpeedDown()
{
	m_pEffectManager = (CEffectManager*)aqua::FindGameObject("EffectManager");

	m_EffectTimer.Reset();

	m_ItemFlag = true;

	m_pEffectManager->Create(EFFECT_ID::SPEEDDOWN,m_pPlayer->m_Position);

	//�A�C�e�����g���Ă�����
	if (m_pPlayer != nullptr)
		m_pPlayer->AddItemSpeed(0.6f);
}