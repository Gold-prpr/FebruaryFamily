#pragma once
#include "aqua.h"

class CPlayer;
class CStage;
class CUnitManager;
class CCamera
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CCamera(IGameObject* parent);

	//デストラクタ
	~CCamera() = default;

	//初期化
	void Initialize()override;

	//更新
	void Update()override;

	//OffSetの取得
	const aqua::CVector2& GetScroll();

private:
	aqua::CVector2 m_Scroll;//スクーロール
	aqua::CSurface m_DivScreen;//画面の複製
	aqua::CSprite m_P1Stage;//1プレイヤーの画面
	aqua::CSprite m_P2Stage;//２プレイヤーの画面
	CPlayer* m_pPlayer;//プレイヤーのポインタ
	CStage* m_pStage;//ステージのポインタ
	CUnitManager* m_pUnitManager;//ユニットマネージャーのポインタ

};
