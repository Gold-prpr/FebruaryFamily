#pragma once
#include "aqua.h"
#include "tile_id.h"

class CCamera;

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

	//CSV読み込み
	void Parse(const std::string& file_name);

	float GetMapWidth(void);

	float GetMapHeight(void);

	void  GetScroll(aqua::CVector2 scroll);

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

	aqua::CSprite* m_TileSprite;			//Tile描画

	aqua::CVector2 m_Scroll;

private:
	static const int map_chip_size;			//Tileサイズ

	static const int num_chip_size_x;		//Tile画像の横の数
	static const int num_chip_size_y;		//Tile画像の縦の数

	static const int all_num_chip;			//Tileの合計

	static const int map_x;					//マップの横のタイルの数
	static const int map_y;					//マップの縦のタイルの数

	static const aqua::CVector2 m_Scale;

	static const float m_gravity;			//重力

	std::vector<int> m_MapData;

	aqua::CVector2 m_MapPos;

	//aqua::CSprite m_background;			//背景
	//aqua::CSprite m_goal;					//ゴール

	int m_MapTileX;
	int m_MapTileY;

	CCamera* m_pCamera;
};