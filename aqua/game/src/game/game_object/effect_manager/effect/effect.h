#pragma once

#include "aqua.h"

class IEffect :public aqua::IGameObject
{
public:
	//コンストラクタ
	IEffect(aqua::IGameObject* parent, const std::string& object_name);

	//デストラクタ
	virtual ~IEffect() = default;

	//初期化
	virtual void Initialize(const aqua::CVector2& position);

protected:
	aqua::CVector2		m_Position;
};