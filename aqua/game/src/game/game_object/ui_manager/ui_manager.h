#pragma once
#include "aqua.h"

class CUiManager
	:public aqua::IGameObject
{
public:
	//コンストラクタ
	CUiManager(aqua::IGameObject* parent);

	//デストラクタ
	~CUiManager(void) = default;

	//初期化
	void Initialize(void) override;

	void Update(void) override;

	void Draw(void) override;

	void Finalize(void) override;

	void Create(void);
private:
	static const aqua::CVector2		m_ui_item_frame_position;		//アイテムフレームの位置
	static const aqua::CVector2		m_ui_item_icon_position;		//アイテムアイコンの位置
};
