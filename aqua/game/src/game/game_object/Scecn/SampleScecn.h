#pragma once
#include "aqua.h"


class CPlayer;
class CStage;
class CUnitManager;
class CSampleScene :public aqua::IGameObject
{
	public:
		//�R���X�g���N�^
		CSampleScene(IGameObject * parent);

		//�f�X�g���N�^
		~CSampleScene() = default;

		//������
		void Initialize()override;

		//�X�V
		void Update()override;

		void CharaCameraPos(aqua::CSprite* cp, aqua::CVector2 pos);
		//�`��
		void Draw()override;

		//���
		void Finalize()override;

	private:
		aqua::CSurface m_DivScreen;//��ʂ̕���
		aqua::CSprite m_P1Stage;//1�v���C���[�̉��
		aqua::CSprite m_P2Stage;//�Q�v���C���[�̉��
		CPlayer* m_pPlayer;//�v���C���[�̃|�C���^
		CStage* m_pStage;//�X�e�[�W�̃|�C���^
		CUnitManager* m_pUnitManager;//���j�b�g�}�l�[�W���[�̃|�C���^

};