#include "aqua.h"
#include "../ui_component.h"

class CStage;
class CPlayer;

class CStagePosBar
	: public IUiComponent
{
public:
	//コンストラクタ
	CStagePosBar(aqua::IGameObject* parent);

	//デストラクタ
	~CStagePosBar(void) = default;

	//初期化
	void Initialize(const aqua::CVector2& position)override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	void Move(CPlayer* player);

private:
	aqua::CSprite		m_StageBar;
	aqua::CSprite		m_Pos1p;
	aqua::CSprite		m_Pos2p;

	float m_PlayerRatio;

	CStage* m_pStage;
	CPlayer* m_pPlayer;
};