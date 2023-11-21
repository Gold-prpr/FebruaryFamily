#pragma once
#include "aqua.h"
#include "../ui_component.h"

class CItemManager;

class CKeyIcon
	: public IUiComponent
{
public:
	//コンストラクタ
	CKeyIcon(aqua::IGameObject* parent);

	//デストラクタ
	~CKeyIcon(void) = default;

	//初期化
	void Initialize(const aqua::CVector2& position)override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	//プレイヤーがアイテムボックスに触れたら
	void KeyCount();

private:
	aqua::CSprite		m_KeyIconSprite;	//鍵アイコン
	aqua::CLabel		m_KeyCountLabel;	//持っている鍵の数
};