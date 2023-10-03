#pragma once
#include "aqua.h"

class IChangeScene :public aqua::IGameObject
{
public:
	IChangeScene(aqua::IGameObject* parent, std::string name);
	~IChangeScene() = default;

	/*
	 *  @brief スプライトの生成
	 */
	virtual void CreateSprite(aqua::CSurface& surface);

	/*
	 *  @brief 初期化 
	 */
	virtual void Initialize()override;

	/*
	 *  @brief 更新
	 */
	virtual void Update()override;
	
	/*
	 *  @brief 描画
	 */
	virtual void Draw()override;
	
	/*
	 *  @brief 解放
	 */
	virtual void Finalize()override;

	/*
	 *  @brief 切り替えからシーン
	 */
	virtual bool In();
	
	/*
	 *  @brief シーンから切り替え
	 */
	virtual bool Out();

private:



};
