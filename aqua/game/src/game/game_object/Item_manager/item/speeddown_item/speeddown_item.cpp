#include "speeddown_item.h"
<<<<<<< HEAD
=======
#include "../../../unit_manager/unit_manager.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../ui_manager/ui_component/effect_icon/effect_icon.h"
//#include "../../../effect_manager/effect_manager.h"
//#include "../../../effect_manager/effect/speeddown_effect/speeddown_effect.h"
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½

using namespace aqua::keyboard;
using namespace aqua::controller;

//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
CSpeedDownItem::CSpeedDownItem(aqua::IGameObject* parent)
	:IItem(parent, "SpeedDownItem")
<<<<<<< HEAD
=======
	, m_pUnitManager(nullptr)
	, m_pPlayer(nullptr)
	, m_pEffectIcon(nullptr)
	//, m_pSpeedDownEffect(nullptr)
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
{
}

//‰Šú‰»
void CSpeedDownItem::Initialize(aqua::CVector2 position)
{
<<<<<<< HEAD
	m_pPlayer = (CPlayer*)aqua::FindGameObject("Player");
=======
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");

	m_pEffectIcon = (CEffectIcon*)aqua::FindGameObject("EffectIcon");

	if(other_id == DEVICE_ID::P1)
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P2);
	else
		m_pPlayer = m_pUnitManager->GetPlayer(DEVICE_ID::P1);

	//m_pSpeedDownEffect = (CSpeedDownEffect*)aqua::FindGameObject("SpeedDownEffect");
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½

	//5•bŠÔ
	m_EffectTimer.Setup(5.0f);

	//ƒAƒCƒeƒ€g‚Á‚Ä‚¢‚È‚¢ó‘Ô
	m_itemflag = false;

	IItem::Initialize(position, "data\\speeddown.png");
}

//XV
void CSpeedDownItem::Update()
{
	SpeedDown();
}

<<<<<<< HEAD
//•`‰æ
void CSpeedDownItem::Draw()
{
	//IItem::Draw();
}

//‰ğ•ú
void CSpeedDownItem::Finalize()
{
	//IItem::Finalize();
=======
	if (m_EffectTimer.Finished()&& m_ItemFlag ==true)
		if (m_pPlayer != nullptr)
		{
			m_pPlayer->AddEffectItemSpeed(1.0f);
			m_ItemFlag = false;
			if (m_pEffectIcon)
				//m_pEffectIcon->DeleteEffect();
				m_pEffectIcon->DeleteEffect(m_pPlayer);
		}

	//m_pEffectIcon->m_1PEffectIconSprite.rect.top = m_pEffectIcon->m_1PEffectIconSprite.GetTextureHeight()*(1.0f-)

	m_EffectTimer.Update();
	
	IGameObject::Update();
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
}

//Œ¸‘¬
void CSpeedDownItem::SpeedDown()
{
	//using namespace aqua::keyboard;

	//if (Trigger(KEY_ID::S))
	//{
	//	m_pPlayer->AddSpeed(0.8);
	//}


	//g‚Á‚Ä‚È‚¢‚Í’ÊíƒXƒs[ƒh
	if (m_itemflag == false)
		m_pPlayer->AddSpeed(1.0f);

	//‰Ÿ‚µ‚½‚çƒAƒCƒeƒ€g—p
	//if (Trigger(KEY_ID::S))
	if (Button(DEVICE_ID::P1, BUTTON_ID::LEFT_SHOULDER)||Button(DEVICE_ID::P2, BUTTON_ID::LEFT_SHOULDER))
		m_itemflag = true;

	//m_pEffectManager = (CEffectManager*)aqua::FindGameObject("EffectManager");
	//m_pEffectManager->Create(EFFECT_ID::SPEEDDOWN,m_pPlayer->m_Position);

	//ƒAƒCƒeƒ€‚ğg‚Á‚Ä‚¢‚½‚ç
<<<<<<< HEAD
	if (m_itemflag == true)
	{
		m_EffectTimer.Update();
		m_pPlayer->AddSpeed(0.8f);
	}

	//ƒAƒCƒeƒ€Œø‰ÊŠÔ‚ªI‚í‚Á‚½‚ç
	if (m_EffectTimer.Finished())
		m_itemflag = false;

}
=======
	if (m_pPlayer != nullptr)
		m_pPlayer->AddEffectItemSpeed(0.6f);
}
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
