#pragma once
#include "../item.h"

class CSpeedUpItem
	:public IItem
{
public:
	//コンストラクタ
	CSpeedUpItem(aqua::IGameObject* parent);

	//デストラクタ
	~CSpeedUpItem(void) = default;

	//初期化
	  void Initialize(aqua::CVector2 position);

	//更新
	  void Update()override;

	//描画
	  void Draw()override;

	//解放
	  void Finalize()override;
};