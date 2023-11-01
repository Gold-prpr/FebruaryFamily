#include "ui_component.h"

//コンストラクタ
IUiComponent::IUiComponent(aqua::IGameObject* parent, const std::string& object_name)
	:aqua::IGameObject(parent,object_name,"UiComponent")
{
}

//初期化
void IUiComponent::Initialize(const aqua::CVector2& position)
{
	m_Position = position;
}
