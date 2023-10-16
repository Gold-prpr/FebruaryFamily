#pragma once
#include "../unit.h"

class CStage;
class CCamera;
class CUnitManager;
class CGimmick;

class CPlayer :public IUnit
{
private:

	//キャラクターの状態
	enum class STATE
	{
		START,
		MOVE,
		DEAD,
		STOP,
	};

	//キャラクターの向き
	enum class CHARA_DIR : int
	{
		LEFT = -1,
		RIGHT = 1,
	};

public:
	//コンストラクタ
	CPlayer(aqua::IGameObject* parent);
	//デストラクタ
	~CPlayer()override = default;

	//初期化
	void Initialize(const aqua::CVector2 & position,DEVICE_ID device);

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//解放
	void Finalize() override;

	//死んだときの状態
	bool IsDead();

	//ゴールした時の状態
	bool IsStop();

	//半径に当たった時の取得
	float GetHitRadius(void);

	//ダメージをくらった時の処理
	void Damage(void)override;

	//アイテムを取った時のスピードの加算
	void AddSpeed(float add_speed);

	//壁の当たり判定
	void CheckHitBlok(void);

	void SetScroll(aqua::CVector2 set_scroll);

	aqua::CAnimationSprite m_Chara;//キャラクターのアニメーションスプライト
private:

	void State_Start();//開始の状態
	void State_Move();//動ける状態
	void State_Dead();//死んだ状態
	void State_Stop();//ゴールした状態

	STATE m_State;//キャラの状態
	CHARA_DIR m_DirNext;//キャラの次の向き
	CHARA_DIR m_DirCurrent;//キャラの今の向き
	DEVICE_ID m_Device;//
	CStage* m_pStage;//ステージのポインタ
	CUnitManager* m_pUnitManager;//ユニットマネージャーのポインタ
	CGimmick* m_pGimmick;//
	aqua::CVector2 m_ScrollVec;
	float m_AddSpeed;//スピード加算
	static const float speed;//スピードの値
	static const float jump;//ジャンプの値
	static const float width;//幅
	static const float height;//高さ
	static const float radius;//半径
	static const float dash;//ダッシュの値
	bool m_LandingFlag;//空中にいるときのフラグ

};