#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../item_manager/item_manager.h"

class CPlayer;
class CItemManager;

class CDark
	: public IUiComponent
{
public:
	//�R���X�g���N�^
	CDark(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CDark(void) = default;

	//������
	void Initialize(const aqua::CVector2& position)override;

	////�X�V
	//void Update(void) override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	//����̉�ʂɕ`��
	void Dark(aqua::controller::DEVICE_ID other_id);

	aqua::CSprite		m_1PDark;	//1P�È�
	aqua::CSprite		m_2PDark;	//2P�È�
private:

	CPlayer* m_pPlayer;
	CItemManager* m_pItemManager;
};