#pragma once
#include "aqua.h"

class CStageManager
	:public aqua::IGameObject
{
	//コンストラクタ
	CStageManager(aqua::IGameObject* parent);
	//デストラクタ
	~CStageManager() = default;

	//初期化
	void Initialize(const aqua::CVector2& map_1p_pos, const aqua::CVector2& map_2p_pos);
private:

};