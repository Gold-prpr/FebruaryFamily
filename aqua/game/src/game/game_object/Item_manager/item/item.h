#pragma once
#include "aqua.h"

class IItem
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IItem(aqua::IGameObject* parent, const std::string& name);

	//�f�X�g���N�^
	virtual ~IItem(void) = default;

	//������
	virtual void Initialize(/*const aqua::CVector2& position*/) override;

	//�X�V
	virtual void Update()override;

	//�`��
	virtual void Draw()override;

	//���
	virtual void Finalize()override;

	//�A�C�e���̈ʒu
	const aqua::CVector2& GetPosition();

protected:
	aqua::CVector2				m_Position;		//�A�C�e���̈ʒu
};