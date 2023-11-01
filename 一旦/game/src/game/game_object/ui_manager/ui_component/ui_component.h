#pragma once
#include "aqua.h"

class IUiComponent
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IUiComponent(aqua::IGameObject* parent, const std::string& object_name);

	//�f�X�g���N�^
	virtual ~IUiComponent(void) = default;

	//������
	virtual void Initialize(const aqua::CVector2& position);

	//�ʒu�̎擾
	aqua::CVector2 GetPosition(void) const { return m_Position; }

	//�ʒu�̐ݒ�
	void			SetPosition(const aqua::CVector2& position) { m_Position = position; }

protected:
	aqua::CVector2			m_Position;
};