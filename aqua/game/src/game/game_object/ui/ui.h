#pragma once
#include "aqua.h"

class CUi
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CUi(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CUi(void) = default;

	//������
	void Initialize(void) override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void) override;

	//���
	void Finalize(void) override;

private:
	//�����ɏ��ʃX�v���C�g�A�A�C�e���g�X�v���C�g�A�����̃|�W�V�����X�v���C�g�A�A�C�e�����ʃX�v���C�g������
};