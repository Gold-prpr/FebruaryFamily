#pragma once
#include "../item.h"

class CSpeedDownItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CSpeedDownItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSpeedDownItem(void) = default;

	//������
	void Initialize(aqua::CVector2 position);

	//�X�V
	void Update()override;

	//�`��
	void Draw()override;

	//���
	void Finalize()override;
};