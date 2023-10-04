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

	void Draw()override;

	void Finalize()override;

	//OffSetの取得
	const aqua::CVector2& GetScroll();

private:
	aqua::CVector2 m_Scroll;
	aqua::CSurface m_DivScreen;
	aqua::CSprite m_1PStage;
	aqua::CSprite m_2PStage;
	CPlayer* m_pPlayer;
	CStage* m_pStage;

};
