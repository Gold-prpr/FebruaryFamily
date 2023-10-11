#pragma once
#include "aqua.h"


class CPlayer;
class CStage;
class CUnitManager;
class CSampleScene :public aqua::IGameObject
{
	public:
		//コンストラクタ
		CSampleScene(IGameObject * parent);

		//デストラクタ
		~CSampleScene() = default;

		//初期化
		void Initialize()override;

		//更新
		void Update()override;

		void CharaCameraPos(aqua::CSprite* cp, aqua::CVector2 pos);
		//描画
		void Draw()override;

		//解放
		void Finalize()override;

	private:
		aqua::CSurface m_DivScreen;//画面の複製
		aqua::CSprite m_P1Stage;//1プレイヤーの画面
		aqua::CSprite m_P2Stage;//２プレイヤーの画面
		CPlayer* m_pPlayer;//プレイヤーのポインタ
		CStage* m_pStage;//ステージのポインタ
		CUnitManager* m_pUnitManager;//ユニットマネージャーのポインタ

};