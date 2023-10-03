#pragma once
#include "aqua.h"

class IItem
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	IItem(aqua::IGameObject* parent, const std::string& name);

	//デストラクタ
	virtual ~IItem(void) = default;

	//初期化
	virtual void Initialize(/*const aqua::CVector2& position*/) override;

	//更新
	virtual void Update()override;

	//描画
	virtual void Draw()override;

	//解放
	virtual void Finalize()override;

	//アイテムの位置
	const aqua::CVector2& GetPosition();

protected:
	aqua::CVector2				m_Position;		//アイテムの位置
};