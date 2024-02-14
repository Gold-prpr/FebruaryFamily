#pragma once
#include "../unit.h"

class CStage;
class CCameraManager;
class CUnitManager;
class CGimmickAct;
class CSlime;
class CItemManager;
class CSpeedDownItem;
class CPlayerStunItem;
class CDarkItem;
class CSpeedUpItem;
class CItemIcon;
class CStagePosBar;
class CKeyIcon;
class CCommonData;
class CEffectIcon;
class CReverseItem;
//class CSpeedDownEffect;
//class CPlayerStunEffect;

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

	void AddEffectItemSpeed(float add_effect_item_speed);

	//アイテムを取った時のスピードの加算
	void AddItemSpeed(float add_item_speed);

	void AddGimmickSpeed(float add_gimmick_speed);

	void AddKeySpeed(float add_key_speed);

	void AddMaxSpeed(float add_max_speed);

	void Jump(void);

	void JumpRamp(void);

	aqua::CVector2 GetSpeed(void) { return m_Velocity; }

	//壁の当たり判定
	void CheckHitBlock(void);

	void SetDeviceID(DEVICE_ID device_id)override {m_Device = device_id;}

	DEVICE_ID GetDeviceID();

	void CreateItme(void);

	void UseItem(CPlayer* player);

	void AttackAct(CPlayer* player);

	//void EffectPosition(CPlayer* player);

	bool m_HitSpikeFlag;

	bool m_HitWireFlag;

	bool m_HitItemFlag;

	bool m_GetItemFlag;

	bool m_BrickFlag;

	bool m_GoalFlag;

	bool m_JampRampFlag;

	int m_KeyCount;

	bool m_KeyFlag;

	//aqua::CAnimationSprite m_Chara;//キャラクターのアニメーションスプライト
	aqua::CSprite m_CharaSprite;

	DEVICE_ID m_Device;//プレイヤーのコントローラ割り当て

	bool m_LandingFlag;//空中にいるときのフラグ
	int max_interval;

	float m_VeloTemp;

	bool m_ReverseFlag;

private:

	void State_Start();//開始の状態
	void State_Move();//動ける状態
	void State_Dead();//死んだ状態
	void State_Goal();//ゴールした状態

	std::string name;

	STATE m_State;//キャラの状態
	CStage* m_pStage;//ステージのポインタ
	CCameraManager* m_pCamera;//カメラのポインタ
	CUnitManager* m_pUnitManager;//ユニットマネージャーのポインタ
	CGimmickAct* m_pGimmick;//ギミックのポインタ
	CItemManager* m_pItemManager;//アイテムマネージャーのポインタ
	CSlime* m_pSlime;
	CSpeedDownItem* m_pSpeedDownItem;
	CPlayerStunItem* m_pStunItem;
	CItemIcon* m_pItemIcon;
	CStagePosBar* m_pStageBar;
	CKeyIcon* m_pKeyIcon;
	CCommonData* m_pCommonData;
	CEffectIcon* m_pEffectIcon;
	CDarkItem* m_pDarkItem;
	CSpeedUpItem* m_pSpeedUpItem;
	CReverseItem* m_pReverseItem;

	//CSpeedDownEffect* m_pSpeedDownEffect;
	//CPlayerStunEffect* m_pPlayerStunEffect;
	
	aqua::CVector2 m_PrevPosition;// プレイヤーの前フレームの位置

	float m_AddMaxSpeed;
	float m_AddKeySpeed;//鍵を持ってる時のスピード
	float m_AddEffectItemSpeed;
	float m_AddItemSpeed;
	float m_AddGimmickSpeed;
	float m_Accelerator;//加速度]
	float m_Speed;
	int m_Timer;
	static const float max_speed;//最高スピードの値
	static const float min_speed;//最低スピードの値
	static const float jump;//ジャンプの値
	static const float width;//幅
	static const float height;//高さ
	static const float radius;//半径
	static const float dash;//ダッシュの値
};