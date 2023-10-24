#pragma once
#include "aqua.h"
#include "../ui_component.h"

class CItemIcon
	: public IUiComponent
{
public:
	//コンストラクタ
	CItemIcon(aqua::IGameObject* parent);

	//デストラクタ
	~CItemIcon(void) = default;

	//初期化
	void Initialize(const aqua::CVector2& position)override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

private:
	aqua::CSprite		m_1PItemIconSprite;	//1Pアイテム枠
	aqua::CSprite		m_2PItemIconSprite;	//2Pアイテム枠
};