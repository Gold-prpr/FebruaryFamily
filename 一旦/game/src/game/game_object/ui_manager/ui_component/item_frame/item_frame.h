#pragma once
#include "aqua.h"
#include "../ui_component.h"

class CItemFrame
	: public IUiComponent
{
public:
	//コンストラクタ
	CItemFrame(aqua::IGameObject* parent);

	//デストラクタ
	~CItemFrame(void) = default;

	//初期化
	void Initialize(const aqua::CVector2& position)override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

private:
	aqua::CSprite		m_1PItemFrameSprite;	//1Pアイテム枠
	aqua::CSprite		m_2PItemFrameSprite;	//2Pアイテム枠
};