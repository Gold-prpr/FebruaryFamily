#pragma once
#include "aqua.h"

class IChangeScene :public aqua::IGameObject
{
public:
	IChangeScene(aqua::IGameObject* parent, std::string name);
	~IChangeScene() = default;

	/*
	 *  @brief �X�v���C�g�̐���
	 */
	virtual void CreateSprite(aqua::CSurface& surface);

	/*
	 *  @brief ������ 
	 */
	virtual void Initialize()override;

	/*
	 *  @brief �X�V
	 */
	virtual void Update()override;
	
	/*
	 *  @brief �`��
	 */
	virtual void Draw()override;
	
	/*
	 *  @brief ���
	 */
	virtual void Finalize()override;

	/*
	 *  @brief �؂�ւ�����V�[��
	 */
	virtual bool In();
	
	/*
	 *  @brief �V�[������؂�ւ�
	 */
	virtual bool Out();

private:



};
