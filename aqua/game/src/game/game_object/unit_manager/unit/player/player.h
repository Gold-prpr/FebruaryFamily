#pragma once
#include "../unit.h"

class CStage;
class CCameraManager;
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
		GOAL,
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
	void Initialize(const aqua::CVector2& position);

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//解放
	void Finalize() override;

	//死んだときの状態
	bool IsDead();

	//ゴールした時の状態
	bool IsGoal();

	//半径に当たった時の取得
	float GetHitRadius(void);

	//ダメージをくらった時の処理
	void Damage(void);

	//アイテムを取った時のスピードの加算
	void AddSpeed(float add_speed);

	//壁の当たり判定
	void CheckHitBlock(void);

	void SetDeviceID(DEVICE_ID device_id) {m_Device = device_id;}

	DEVICE_ID GetDeviceID();

	bool m_HitFlag;

	bool m_HitItemFlag;

	bool m_GoalFlag;

	aqua::CAnimationSprite m_Chara;//キャラクターのアニメーションスプライト

	DEVICE_ID m_Device;//プレイヤーのコントローラ割り当て
private:

	void State_Start();//開始の状態
	void State_Move();//動ける状態
	void State_Dead();//死んだ状態
	void State_Goal();//ゴールした状態

	STATE m_State;//キャラの状態
	CHARA_DIR m_DirNext;//キャラの次の向き
	CHARA_DIR m_DirCurrent;//キャラの今の向き
	CStage* m_pStage;//ステージのポインタ
	CCameraManager* m_pCamera;//カメラのポインタ
	CUnitManager* m_pUnitManager;//ユニットマネージャーのポインタ
	CGimmick* m_pGimmick;//
	
	float m_AddSpeed;//スピード加算
	float m_Accelerator;//加速度
	int m_Timer;
	static const float max_speed;//最高スピードの値
	static const float min_speed;//最低スピードの値
	static const float jump;//ジャンプの値
	static const float width;//幅
	static const float height;//高さ
	static const float radius;//半径
	static const float dash;//ダッシュの値
	static const int max_interval;
	bool m_LandingFlag;//空中にいるときのフラグ

};