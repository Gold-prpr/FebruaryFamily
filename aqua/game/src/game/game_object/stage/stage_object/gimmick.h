#pragma once
#include "../stage_object/gimmick_id.h"

class CGimmick :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CGimmick(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CGimmick()override = default;

	//������
	void Initialize()override;

	//�X�V
	void Update() override;

	//�`��
	void Draw()override;

	//���
	void Finalize()override;

	//Unit�̐����Ɛݒu
	void Create(STAGE_GIMMICK id);

private:

};