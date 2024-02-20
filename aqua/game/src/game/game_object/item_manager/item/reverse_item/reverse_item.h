#pragma once
#include "../item.h"

class CUnitManager;
class CPlayer;
class CEffectIcon;

class CReverseItem
	:public IItem
{
public:
	//コンストラクタ
	CReverseItem(aqua::IGameObject* parent);

	//デストラクタ
	~CReverseItem(void) = default;

	//初期化
	void Initialize(aqua::controller::DEVICE_ID other_id);

	//更新
	void Update()override;

	//操作逆
	void Reverse();


private:
	CUnitManager* m_pUnitManager;
	CPlayer* m_pPlayer;
	CEffectIcon* m_pEffectIcon;
};