#pragma once
#include "aqua.h"
#include "tile_id.h"

class CMap
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CMap(aqua::IGameObject* parent);

	//デストラクタ
	~CMap(void) = default;

	//初期化
	void		Initialize(void) override;

	//更新
	void		Update(void) override;

	//描画
	void		Draw(void) override;

	//解放
	void		Finalize(void) override;

	//当たり判定
	bool CheckHit(int x, int y);

	//アイテム判定
	bool CheckItem(int x, int y);

	//重力
	float GetGravity(void) const;

	static const int		m_chip_size;	//1マスの大きさ

	int						m_size;			//FMFのサイズを入れる
	int						m_width;		//FMFのマップの横を入れる
	int						m_height;		//FMFのマップの高さを入れる

private:
	aqua::CSprite*			m_Map;			//画像を表示
	aqua::CFMFLoader		m_Fmf;			//FMFを読み込むための変数
	int*					m_MapData;		//すべてのMAP_ID

};
//#pragma once
//#include "aqua.h"
//#include "tile_id.h"
////#include "../character/character.h"
//#include "../scene_manager/scene_manager.h"
//
////class CCharacter;
//class CSceneManager;
//
//class CStage
//	: public aqua::IGameObject
//{
//public:
//
//	//コンストラクタ
//	CStage(aqua::IGameObject* parent);
//	//デストラクタ
//	~CStage() = default;
//
//	//初期化
//	void Initialize(void);
//	//更新
//	void Update(void);
//	//描画
//	void Draw(void);
//	//解放
//	void Finalize(void);
//
//	//CSV読み込み
//	void Parse(const std::string& file_name);
//
//	//当たり判定
//	bool CheckHit(int x, int y);
//
//	//ゴール判定
//	bool CheckGoal(int x, int y);
//
//	////落ちる判定
//	//bool CheckFallBlock(int x, int y);
//
//	//アイテム判定
//	bool CheckItem(int x, int y);
//
//	////ギミック判定(針)
//	//bool CheckSpine(int x, int y);
//
//	//重力
//	float GetGravity(void) const;
//
//	//Tileサイズを呼ぶ
//	int GetSize(void);
//
//	//空のタイルに変更
//	void ChangeAir(int x, int y);
//
//	////ゴール演出
//	//void GoalMove(void);
//
//	static const int map_chip_size;			//Tileサイズ
//
//	aqua::CSprite* m_TileSprite;			//Tile描画
//
//private:
//
//	static const int num_chip_size_x;		//Tile画像の横の数
//	static const int num_chip_size_y;		//Tile画像の縦の数
//
//	static const int all_num_chip;			//Tileの合計
//
//	static const int map_x;					//マップの横のタイルの数
//	static const int map_y;					//マップの縦のタイルの数
//
//	static const float m_gravity;			//重力
//
//	std::vector<int> m_MapData;
//
//	aqua::CSprite m_background;				//背景
//	//aqua::CSprite m_goal;					//ゴール
//
//	//CCharacter* chara;
//	CSceneManager* sm;
//};