#pragma once
#include "aqua.h"

class CPlayer;
class CStage;
class CUnitManager;
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

	void CharaCameraPos(aqua::CSprite* cp,aqua::CVector2 pos);

	void Draw()override;

	void Finalize()override;

	//OffSetの取得
	const aqua::CVector2& GetScroll();

private:
	aqua::CVector2 m_Scroll;
	aqua::CSurface m_DivScreen;
	aqua::CSprite m_P1Stage;
	aqua::CSprite m_P2Stage;
	CPlayer* m_pPlayer;
	CStage* m_pStage;

	CUnitManager* m_pUnitManager;

};
