#pragma once
#include "aqua.h"

class CCamera;

class CCameraManager
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CCameraManager(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CCameraManager(void) = default;

	//������
	void Initialize(void) override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void) override;

	//���
	void Finalize(void) override;

	aqua::CVector2 GetScroll(aqua::controller::DEVICE_ID id);

private:

	std::vector<CCamera*> m_CameraClass;

};