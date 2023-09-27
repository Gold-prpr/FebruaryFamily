#pragma once
#include "../unit.h"

class CStage;
class CCamera;
class CUnitManager;

class CPlayer :public IUnit
{
private:

	enum class STATE
	{
		START,
		MOVE,
		DEAD,
		STOP,
	};
public:
	//コンストラクタ
	CPlayer(aqua::IGameObject* parent);
	//デストラクタ
	~CPlayer()override = default;

	//初期化
	void Initialize(const aqua::CVector2 & position) override;

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
	void Damage(void)override;

private:

	void State_Start();//開始の状態
	void State_Move();//動ける状態
	void State_Dead();//死んだ状態
	void State_Stop();//ゴールした状態

	aqua::CSprite m_Chara;
	STATE m_State;
	CStage* m_pStage;
	CCamera* m_pCamera;
	CUnitManager* m_pUnitManager;
	static const float width;
	static const float height;
	static const float radius;
};