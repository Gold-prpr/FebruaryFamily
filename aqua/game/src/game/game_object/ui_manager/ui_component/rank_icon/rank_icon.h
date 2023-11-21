#include "aqua.h"
#include "../ui_component.h"

class CRankIcon
	: public IUiComponent
{
public:
	//コンストラクタ
	CRankIcon(aqua::IGameObject* parent);

	//デストラクタ
	~CRankIcon(void) = default;

	//初期化
	void Initialize(const aqua::CVector2& position)override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void)override;

	//解放
	void Finalize(void)override;

	////順位変動
	//void ChangeRank(void);

private:

	aqua::CSprite		m_1PRankIconSprite;	//1Pアイテムアイコン
	aqua::CSprite		m_2PRankIconSprite;	//2Pアイテムアイコン
};