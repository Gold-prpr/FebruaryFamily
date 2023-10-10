#pragma once
#include "../stage_object/gimmick_id.h"

class CStage;

class CGimmick :
	public aqua::IGameObject
{
public:
	//コンストラクタ
	CGimmick(aqua::IGameObject* parent, const std::string& object_name);

	//デストラクタ
	~CGimmick()override = default;

	//初期化
	void Initialize()override;

	void DamageAction(void);

	CStage* m_pStage;
private:
};