#pragma once
#include "aqua.h"

class CPlayer;
class CStage;
class CCamera
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CCamera(IGameObject* parent);

	//デストラクタ
	~CCamera() = default;

	//初期化
	void Initialize()override;

	//更新
	void Update()override;

	void SetPlayerPos(aqua::CVector2 player_pos);

	//OffSetの取得
	const aqua::CVector2& GetScroll();

private:
	aqua::CVector2 m_Scroll;
	aqua::CVector2 m_PlayerPos;
	
	CPlayer* m_pPlayer;
	CStage* m_pStage;

};