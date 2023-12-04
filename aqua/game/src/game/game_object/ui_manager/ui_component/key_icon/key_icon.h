#pragma once
#include "aqua.h"
#include "../ui_component.h"

class CItemManager;

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
	void KeyCount();

private:
	aqua::CSprite		m_KeyIconSprite;	//���A�C�R��
	aqua::CLabel		m_KeyCountLabel;	//�����Ă��錮�̐�
};