#pragma once
#include "../item.h"

class CSpeedUpItem
	:public IItem
{
public:
	//�R���X�g���N�^
	CSpeedUpItem(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSpeedUpItem(void) = default;

	//������
	  void Initialize(aqua::CVector2 position);

	//�X�V
	  void Update()override;

	//�`��
	  void Draw()override;

	//���
	  void Finalize()override;
};