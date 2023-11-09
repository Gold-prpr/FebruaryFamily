#pragma once
#include "aqua.h"

class CUi
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CUi(aqua::IGameObject* parent);

	//デストラクタ
	~CUi(void) = default;

	//初期化
	void Initialize(void) override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void) override;

	//解放
	void Finalize(void) override;

private:
	//ここに順位スプライト、アイテム枠スプライト、中央のポジションスプライト、アイテム効果スプライトを書く
};