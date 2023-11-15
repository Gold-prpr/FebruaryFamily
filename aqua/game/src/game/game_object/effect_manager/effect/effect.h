#pragma once

#include "aqua.h"

class IEffect :public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	IEffect(aqua::IGameObject* parent, const std::string& object_name);

	//�f�X�g���N�^
	virtual ~IEffect() = default;

	//������
	virtual void Initialize(const aqua::CVector2& position);

protected:
	aqua::CVector2		m_Position;
};