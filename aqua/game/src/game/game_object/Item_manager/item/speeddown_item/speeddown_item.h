#pragma once
#include "../item.h"
#include "../../../unit_manager/unit/player/player.h"

class CPlayer;
class CEffectIcon;
//class CEffectManager;
//class CSpeedDownEffect;

class CSpeedDownItem
	:public IItem
{
public:
	//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	CSpeedDownItem(aqua::IGameObject* parent);

	//ƒfƒXƒgƒ‰ƒNƒ^
	~CSpeedDownItem(void) = default;

	//‰Šú‰»
	void Initialize(aqua::CVector2 position);

	//XV
	void Update()override;

	//•`‰æ
	void Draw()override;

	//‰ğ•ú
	void Finalize()override;

	//Œ¸‘¬
	void SpeedDown();

private:
<<<<<<< HEAD
	bool				m_itemflag;			//ƒAƒCƒeƒ€g‚Á‚½‚©
	aqua::CTimer		m_EffectTimer;		//Œø‰ÊŠÔ
	CPlayer* m_pPlayer;
=======
	CUnitManager*		m_pUnitManager;
	CPlayer*			m_pPlayer;
	CEffectIcon*			m_pEffectIcon;
	//CEffectManager* m_pEffectManager;
	//CSpeedDownEffect* m_pSpeedDownEffect;
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
};