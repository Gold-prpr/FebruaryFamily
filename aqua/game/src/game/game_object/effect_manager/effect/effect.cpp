#include "effect.h"

//�R���X�g���N�^
IEffect::IEffect(aqua::IGameObject* parent, const std::string& object_name)
	: aqua::IGameObject(parent, object_name, "Effect")
	, m_Position(aqua::CVector2::ZERO)
{
}

//������
void IEffect::Initialize(const aqua::CVector2& position)
{
	m_Position = position;
}
