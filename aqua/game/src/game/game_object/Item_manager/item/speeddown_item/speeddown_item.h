#pragma once
#include "../item.h"

class CItemSpeedDown
	:public IItem
{
public:
	//�R���X�g���N�^
	CItemSpeedDown(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CItemSpeedDown(void);

	//������
	void	Initialize(void);

private:
	aqua::CSprite		m_Speeddown;		//�X�s�[�h�A�b�v�A�C�e��
};