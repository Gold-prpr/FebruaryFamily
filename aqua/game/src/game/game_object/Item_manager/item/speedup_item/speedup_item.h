#pragma once
#include "../item.h"
#include "../../../unit_manager/unit/player/player.h"

class CPlayer;

class CSpeedUpItem
	:public IItem
{
public:
	//コンストラクタ
	CSpeedUpItem(aqua::IGameObject* parent);

	//デストラクタ
	~CSpeedUpItem(void) = default;

	//初期化
	void Initialize();

	//更新
	void Update()override;

	//加速計算
	void SpeedUp();

private:
	//static const float	m_one_second;	//1秒
	//static const int	m_time_limit;	//
	//int					m_count_down;	//
	
	aqua::CTimer		m_EffectTimer;		//効果時間
	CPlayer*			m_pPlayer;
};