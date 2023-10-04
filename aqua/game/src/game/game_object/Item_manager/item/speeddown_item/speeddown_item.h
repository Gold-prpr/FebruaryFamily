#pragma once
#include "../item.h"
#include "../../../unit_manager/unit/player/player.h"

class CPlayer;

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

	//����
	void SpeedDown();

private:
	CPlayer* m_pPlayer;
};