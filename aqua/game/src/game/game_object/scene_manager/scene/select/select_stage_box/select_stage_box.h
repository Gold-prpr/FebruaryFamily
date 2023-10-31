#pragma once
#include "aqua.h"

class CSelectStageBox :
	public aqua::IGameObject
{
public:

	//コンストラクタ
	CSelectStageBox(aqua::IGameObject* parent);

	//デストラクタ
	~CSelectStageBox(void) = default;

	//初期化
	void Initialize(void) override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void) override;

	//解放
	void Finalize(void) override;

	// 設定
	void SetUp(aqua::CVector2 position, std::string file_name, std::string stage_name);

	// 座標の加算
	void AddPosition(aqua::CVector2 add);

	// 大きさの変更
	void SetSize(aqua::CVector2 scale);

	// 背景ファイル名の取得
	std::string GetStageBackGrond();

private:

	static const int m_max_font_size;

	aqua::CLabel m_StageName;

	aqua::CSprite m_SelectBox;

	std::string m_StageBackGroundName;

};