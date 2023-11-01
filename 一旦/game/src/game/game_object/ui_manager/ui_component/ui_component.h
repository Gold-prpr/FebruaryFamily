#pragma once
#include "aqua.h"

class IUiComponent
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	IUiComponent(aqua::IGameObject* parent, const std::string& object_name);

	//デストラクタ
	virtual ~IUiComponent(void) = default;

	//初期化
	virtual void Initialize(const aqua::CVector2& position);

	//位置の取得
	aqua::CVector2 GetPosition(void) const { return m_Position; }

	//位置の設定
	void			SetPosition(const aqua::CVector2& position) { m_Position = position; }

protected:
	aqua::CVector2			m_Position;
};