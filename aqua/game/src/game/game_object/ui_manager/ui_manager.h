#pragma once
#include "aqua.h"

class CUiManager
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CUiManager(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CUiManager(void) = default;

	//������
	void Initialize(void) override;

private:
	static const aqua::CVector2		m_ui_item_frame_position;		//�A�C�e���t���[���̈ʒu
};
