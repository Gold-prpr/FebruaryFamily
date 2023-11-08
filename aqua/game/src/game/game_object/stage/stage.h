#pragma once
#include "aqua.h"
#include "stage_object/stage_object_id.h"

class CStageObject;

class CStage
	: public aqua::IGameObject
{
public:

	//コンストラクタ
	CStage(aqua::IGameObject* parent);
	//デストラクタ
	~CStage() = default;

	//初期化
	void Initialize(void);
	//更新
	void Update(void);
	//描画
	void Draw(void);
	//解放
	void Finalize(void);

	// スクロールの設定
	void SetScroll(aqua::CVector2 scroll);

	//CSV読み込み
	void Parse(const std::string& file_name);

	float GetMapWidth(void);

	float GetMapHeight(void);

	//重力
	float GetGravity(void);

	bool CheckHit(int x, int y);

	int GetTileSize(void);

	//ゴール判定
	bool CheckGoal(int x, int y);

	//アイテム判定
	bool CheckItem(int x, int y);

	//ギミック判定
	bool CheckGimmick(int x, int y);

	bool ChangeAir(int x, int y);

	/*//落ちる判定
	bool CheckFallBlock(int x, int y);

	////ギミック判定(針)
	bool CheckSpine(int x, int y);

	//Tileサイズを呼ぶ
	int GetSize(void);

	//空のタイルに変更
	void ChangeAir(int x, int y);

	////ゴール演出
	void GoalMove(void);*/

	aqua::CVector2 m_Scroll;

private:
	static const int map_chip_size;			//Tileサイズ

	static const int num_chip_size_x;		//Tile画像の横の数
	static const int num_chip_size_y;		//Tile画像の縦の数

	static const int all_num_chip;			//Tileの合計


	static const float m_gravity;			//重力

	std::vector<CStageObject*> m_StageObject;

	aqua::CSprite              m_BackGround;

	aqua::CVector2 m_MapPos;

	int map_x;					//マップの横のタイルの数
	int map_y;					//マップの縦のタイルの数

	int m_MapTileX;
	int m_MapTileY;

	bool CheckObject(int x, int y, StageObjectID id);
};