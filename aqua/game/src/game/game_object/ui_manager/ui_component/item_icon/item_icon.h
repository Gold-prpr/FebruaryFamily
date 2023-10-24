#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../item_manager/item_manager.h"

class CPlayer;
class CItemManager;

class CItemIcon
	: public IUiComponent
{
public:
	//�R���X�g���N�^
	CItemIcon(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CItemIcon(void) = default;

	//������
	void Initialize(const aqua::CVector2& position)override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	//�X�s�[�h�A�b�v�A�C�e��
	void SpeedUpIcon(void);

	//�X�s�[�h�_�E���A�C�e��
	void SpeedDownIcon(void);

private:
	aqua::CSprite		m_1PItemIconSprite;	//1P�A�C�e���g
	aqua::CSprite		m_2PItemIconSprite;	//2P�A�C�e���g

	CPlayer*			m_pPlayer;
	CItemManager*		m_pItemManager;
};