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
	void Initialize(const aqua::CVector2 & position)override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	//�v���C���[���A�C�e���{�b�N�X�ɐG�ꂽ��
	void Check(CPlayer* player);

	//�v���C���[���A�C�e�����g������
	void DeleteItem(CPlayer* player);

private:
	aqua::CSprite		m_1PItemIconSprite;	//1P�A�C�e���A�C�R��
	aqua::CSprite		m_2PItemIconSprite;	//2P�A�C�e���A�C�R��

	CPlayer*		m_pPlayer;
	CItemManager*	m_pItemManager;
};