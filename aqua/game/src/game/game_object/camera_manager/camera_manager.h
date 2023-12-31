#pragma once
#include "aqua.h"

class CCamera;

class CCameraManager
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CCameraManager(aqua::IGameObject* parent);

	//デストラクタ
	~CCameraManager(void) = default;

	//初期化
	void Initialize(void) override;

	//更新
	void Update(void) override;

	//描画
	void Draw(void) override;

	//解放
	void Finalize(void) override;

	aqua::CVector2 GetScroll(aqua::controller::DEVICE_ID id);

private:

	std::vector<CCamera*> m_CameraClass;

};