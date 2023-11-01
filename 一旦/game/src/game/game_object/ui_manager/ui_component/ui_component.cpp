#include "ui_component.h"

//�R���X�g���N�^
IUiComponent::IUiComponent(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent,object_name,"UiComponent")
{
}

//������
void IUiComponent::Initialize(const aqua::CVector2& position)
{
	m_Position = position;
}
