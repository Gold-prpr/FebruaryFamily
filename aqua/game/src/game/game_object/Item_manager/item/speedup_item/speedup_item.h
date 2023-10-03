#pragma once
#include "../item.h"

class CItemSpeedUp
	:public IItem
{
public:
	//コンストラクタ
	CItemSpeedUp(aqua::IGameObject* parent);

	//デストラクタ
	~CItemSpeedUp(void);

	//初期化
	void	Initialize(void);

private:
	aqua::CSprite		m_Speedup;		//スピードアップアイテム
};