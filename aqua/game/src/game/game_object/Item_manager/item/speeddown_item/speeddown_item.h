#pragma once
#include "../item.h"

class CItemSpeedDown
	:public IItem
{
public:
	//コンストラクタ
	CItemSpeedDown(aqua::IGameObject* parent);

	//デストラクタ
	~CItemSpeedDown(void);

	//初期化
	void	Initialize(void);

private:
	aqua::CSprite		m_Speeddown;		//スピードアップアイテム
};