#pragma once
#include "../unit.h"

class CStage;
class CCamera;
class CUnitManager;
class CGimmick;

class CPlayer :public IUnit
{
private:

	//�L�����N�^�[�̏��
	enum class STATE
	{
		START,
		MOVE,
		DEAD,
		STOP,
	};

	//�L�����N�^�[�̌���
	enum class CHARA_DIR : int
	{
		LEFT = -1,
		RIGHT = 1,
	};

public:
	//�R���X�g���N�^
	CPlayer(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CPlayer()override = default;

	//������
	void Initialize(const aqua::CVector2 & position,DEVICE_ID device);

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//���
	void Finalize() override;

	//���񂾂Ƃ��̏��
	bool IsDead();

	//�S�[���������̏��
	bool IsStop();

	//���a�ɓ����������̎擾
	float GetHitRadius(void);

	//�_���[�W������������̏���
	void Damage(void)override;

	//�A�C�e������������̃X�s�[�h�̉��Z
	void AddSpeed(float add_speed);

	//�ǂ̓����蔻��
	void CheckHitBlok(void);

	void SetScroll(aqua::CVector2 set_scroll);

	aqua::CAnimationSprite m_Chara;//�L�����N�^�[�̃A�j���[�V�����X�v���C�g
private:

	void State_Start();//�J�n�̏��
	void State_Move();//��������
	void State_Dead();//���񂾏��
	void State_Stop();//�S�[���������

	STATE m_State;//�L�����̏��
	CHARA_DIR m_DirNext;//�L�����̎��̌���
	CHARA_DIR m_DirCurrent;//�L�����̍��̌���
	DEVICE_ID m_Device;//
	CStage* m_pStage;//�X�e�[�W�̃|�C���^
	CUnitManager* m_pUnitManager;//���j�b�g�}�l�[�W���[�̃|�C���^
	CGimmick* m_pGimmick;//
	aqua::CVector2 m_ScrollVec;
	float m_AddSpeed;//�X�s�[�h���Z
	static const float speed;//�X�s�[�h�̒l
	static const float jump;//�W�����v�̒l
	static const float width;//��
	static const float height;//����
	static const float radius;//���a
	static const float dash;//�_�b�V���̒l
	bool m_LandingFlag;//�󒆂ɂ���Ƃ��̃t���O

};