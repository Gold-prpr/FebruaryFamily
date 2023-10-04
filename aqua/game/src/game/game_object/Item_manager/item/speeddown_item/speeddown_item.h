#pragma once
#include "../item.h"

class CSpeedDownItem
	:public IItem
{
public:
	//コンストラクタ
	CSpeedDownItem(aqua::IGameObject* parent);

	//デストラクタ
	~CSpeedDownItem(void) = default;

	//初期化
	void Initialize(aqua::CVector2 position);

	//更新
	void Update()override;

	//描画
	void Draw()override;

	//解放
	void Finalize()override;
};