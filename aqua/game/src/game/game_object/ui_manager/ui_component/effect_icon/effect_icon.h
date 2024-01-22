#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"
#include "../../../item_manager/item_manager.h"

class CPlayer;
class CItemManager;

class CEffectIcon
	: public IUiComponent
{
public:
	//�R���X�g���N�^
	CEffectIcon(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CEffectIcon(void) = default;

	//������
	void Initialize(const aqua::CVector2& position)override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	//�v���C���[���A�C�e���g������
	void EffectCheck(CPlayer* player);

	//�v���C���[�̌��ʂ��؂ꂽ��
	//void DeleteEffect(void);
	void DeleteEffect(CPlayer* player);

	aqua::CSprite		m_1PEffectIconSprite;	//1P�A�C�e���g
	aqua::CSprite		m_2PEffectIconSprite;	//2P�A�C�e���g
private:

	CPlayer* m_pPlayer;
	CItemManager* m_pItemManager;
};