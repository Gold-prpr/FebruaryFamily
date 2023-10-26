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

	void Update(void) override;

	void Draw(void) override;

	void Finalize(void) override;

	void Create(void);
private:
	static const aqua::CVector2		m_ui_item_frame_position;		//�A�C�e���t���[���̈ʒu
	static const aqua::CVector2		m_ui_item_icon_position;		//�A�C�e���A�C�R���̈ʒu
};
