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
	//�R���X�g���N�^
	CSpeedDownItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSpeedDownItem(void) = default;

	//������
	void Initialize(aqua::CVector2 position);

	//�X�V
	void Update()override;

	//�`��
	void Draw()override;

	//���
	void Finalize()override;

	//����
	void SpeedDown();

private:
<<<<<<< HEAD
	bool				m_itemflag;			//�A�C�e���g������
	aqua::CTimer		m_EffectTimer;		//���ʎ���
	CPlayer* m_pPlayer;
=======
	CUnitManager*		m_pUnitManager;
	CPlayer*			m_pPlayer;
	CEffectIcon*			m_pEffectIcon;
	//CEffectManager* m_pEffectManager;
	//CSpeedDownEffect* m_pSpeedDownEffect;
>>>>>>> origin/我、新世界之王　KAWAGISIN～母親のパンツを添えて～
};