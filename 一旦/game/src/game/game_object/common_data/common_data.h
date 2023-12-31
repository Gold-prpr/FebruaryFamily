#pragma once
#include "aqua.h"

class CCommonData : 
	public aqua::IGameObject
{
public:

	struct CommonData
	{
		std::string stage_name; // 生成するステージ名

		float p_one_time;		// プレイヤー1のクリア時間
		float p_two_time;		// プレイヤー2のクリア時間
	};

public:

	//コンストラクタ
	CCommonData(aqua::IGameObject* parent);

	//デストラクタ
	~CCommonData(void) = default;

	//初期化
	void Initialize(void) override;

	//解放
	void Finalize(void) override;

	//設定
	void SetDate(CommonData* date );

	//生成するステージのファイル名を設定
	void SetCreateStageName(std::string name);

	//生成するステージのファイル名を取得
	std::string GetCreateStageName();

	// 共有データの取得
	CommonData GetCommonDate();

private:

	CommonData m_CommonData;

};