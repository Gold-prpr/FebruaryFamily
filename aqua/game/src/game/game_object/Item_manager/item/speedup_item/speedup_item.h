#pragma once
#include "../item.h"

class CItemSpeedUp
	:public IItem
{
public:
	//�R���X�g���N�^
	CItemSpeedUp(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CItemSpeedUp(void);

	//������
	void	Initialize(void);

private:
	aqua::CSprite		m_Speedup;		//�X�s�[�h�A�b�v�A�C�e��
};