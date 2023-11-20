#pragma once
#include "aqua.h"

class IItem
	:public aqua::IGameObject
{
public:
	////�R���X�g���N�^
	IItem(aqua::IGameObject* parent, const std::string& name);

	//�f�X�g���N�^
	virtual ~IItem(void) = default;

	//������
	void Initialize(std::string item_file);


	//�X�V
	virtual void Update()override;

	//�`��
	virtual void Draw()override;

	//���
	virtual void Finalize()override;


	aqua::CSprite				m_ItemSprite;	//�A�C�e���`��

protected:

	bool				m_itemflag;			//�A�C�e���g������

	aqua::CTimer		m_EffectTimer;
};