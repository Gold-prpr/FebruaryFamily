#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"

class CPlayer;

class CKeyIcon
	: public IUiComponent
{
public:
	//�R���X�g���N�^
	CKeyIcon(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CKeyIcon(void) = default;

	//������
	void Initialize(const aqua::CVector2& position)override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

	//�v���C���[���A�C�e���{�b�N�X�ɐG�ꂽ��
	void KeyCount(CPlayer* player);

	void AddKeyCount(CPlayer* player);

private:
	aqua::CSprite		m_1PKeyIconSprite;	//1P���A�C�R��
	aqua::CLabel		m_1PKeyCountLabel;	//1P�����Ă��錮�̐�
	aqua::CSprite		m_2PKeyIconSprite;	//2P���A�C�R��
	aqua::CLabel		m_2PKeyCountLabel;	//2P�����Ă��錮�̐�

	CPlayer* m_pPlayer;
};