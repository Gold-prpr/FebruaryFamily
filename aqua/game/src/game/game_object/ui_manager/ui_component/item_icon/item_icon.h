#pragma once
#include "aqua.h"
#include "../ui_component.h"

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

private:
	aqua::CSprite		m_1PItemIconSprite;	//1P�A�C�e���g
	aqua::CSprite		m_2PItemIconSprite;	//2P�A�C�e���g
};