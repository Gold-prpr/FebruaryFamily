#pragma once
#include "aqua.h"
#include "../ui_component.h"

class CItemFrame
	: public IUiComponent
{
public:
	//�R���X�g���N�^
	CItemFrame(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CItemFrame(void) = default;

	//������
	void Initialize(const aqua::CVector2& position)override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void)override;

	//���
	void Finalize(void)override;

private:
	aqua::CSprite		m_ItemFrameSprite;	//�A�C�e���g
};