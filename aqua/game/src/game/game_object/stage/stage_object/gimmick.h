#pragma once
#include "../stage_object/gimmick_id.h"

class CGimmick :public aqua::IGameObject
{
public:
	//コンストラクタ
	CGimmick(aqua::IGameObject* parent);

	//デストラクタ
	~CGimmick()override = default;

	//初期化
	void Initialize()override;

	//更新
	void Update() override;

	//描画
	void Draw()override;

	//解放
	void Finalize()override;

	//Unitの生成と設置
	void Create(STAGE_GIMMICK id);

private:

};