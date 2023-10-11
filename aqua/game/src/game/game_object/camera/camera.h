#pragma once
#include "aqua.h"

class CPlayer;
class CStage;
class CUnitManager;
class CCamera
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CCamera(IGameObject* parent);

	//�f�X�g���N�^
	~CCamera() = default;

	//������
	void Initialize()override;

	//�X�V
	void Update()override;

	//OffSet�̎擾
	const aqua::CVector2& GetScroll();

private:
	aqua::CVector2 m_Scroll;//�X�N�[���[��
	aqua::CSurface m_DivScreen;//��ʂ̕���
	aqua::CSprite m_P1Stage;//1�v���C���[�̉��
	aqua::CSprite m_P2Stage;//�Q�v���C���[�̉��
	CPlayer* m_pPlayer;//�v���C���[�̃|�C���^
	CStage* m_pStage;//�X�e�[�W�̃|�C���^
	CUnitManager* m_pUnitManager;//���j�b�g�}�l�[�W���[�̃|�C���^

};
