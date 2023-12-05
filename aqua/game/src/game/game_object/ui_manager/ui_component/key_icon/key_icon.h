#pragma once
#include "aqua.h"
#include "../ui_component.h"
#include "../../../unit_manager/unit/player/player.h"

class CPlayer;

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
	void KeyCount(CPlayer* player);

	void AddKeyCount(CPlayer* player);

private:
	aqua::CSprite		m_1PKeyIconSprite;	//1P鍵アイコン
	aqua::CLabel		m_1PKeyCountLabel;	//1P持っている鍵の数
	aqua::CSprite		m_2PKeyIconSprite;	//2P鍵アイコン
	aqua::CLabel		m_2PKeyCountLabel;	//2P持っている鍵の数

	CPlayer* m_pPlayer;
};