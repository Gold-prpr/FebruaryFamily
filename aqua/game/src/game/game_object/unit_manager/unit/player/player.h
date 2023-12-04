#pragma once
#include "../unit.h"

class CStage;
class CCameraManager;
class CUnitManager;
class CGimmickAct;
class CSlime;
class CItemManager;
class CSpeedDownItem;
class CPlayerStunItem;
class CItemIcon;
class CStagePosBar;

class CPlayer :public IUnit
{
private:

	//�L�����N�^�[�̏��
	enum class STATE
	{
		START,
		MOVE,
		DEAD,
		GOAL,
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
	void Initialize(const aqua::CVector2& position);

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//���
	void Finalize() override;

	//���񂾂Ƃ��̏��
	bool IsDead();

	//�S�[���������̏��
	bool IsGoal();

	//���a�ɓ����������̎擾
	float GetHitRadius(void);

	//�_���[�W������������̏���
	void Damage(void);

	//�A�C�e������������̃X�s�[�h�̉��Z
	void AddSpeed(float add_speed);

	void AddKeySpeed(float add_key_speed);

	void Jump(void);

	aqua::CVector2 GetSpeed(void) { return m_Velocity; }

	//�ǂ̓����蔻��
	void CheckHitBlock(void);

	void SetDeviceID(DEVICE_ID device_id)override {m_Device = device_id;}

	DEVICE_ID GetDeviceID();

	void CreateItme(void);

	bool m_HitSpikeFlag;

	bool m_HitWireFlag;

	bool m_HitItemFlag;

	bool m_GetItemFlag;

	bool m_GoalFlag;

	bool m_JampRampFlag;

	aqua::CAnimationSprite m_Chara;//�L�����N�^�[�̃A�j���[�V�����X�v���C�g

	DEVICE_ID m_Device;//�v���C���[�̃R���g���[�����蓖��

private:

	void State_Start();//�J�n�̏��
	void State_Move();//��������
	void State_Dead();//���񂾏��
	void State_Goal();//�S�[���������

	STATE m_State;//�L�����̏��
	CHARA_DIR m_DirNext;//�L�����̎��̌���
	CHARA_DIR m_DirCurrent;//�L�����̍��̌���
	CStage* m_pStage;//�X�e�[�W�̃|�C���^
	CCameraManager* m_pCamera;//�J�����̃|�C���^
	CUnitManager* m_pUnitManager;//���j�b�g�}�l�[�W���[�̃|�C���^
	CGimmickAct* m_pGimmick;//
	CItemManager* m_pItemManager;
	CSlime* m_pSlime;
	CSpeedDownItem* m_pSpeedDownItem;
	CPlayerStunItem* m_pStunItem;
	CItemIcon* m_pItemIcon;
	CStagePosBar* m_pStageBar;
	
	aqua::CVector2 m_PrevPosition;// �v���C���[�̑O�t���[���̈ʒu

	float m_AddSpeed;//�X�s�[�h���Z
	float m_AddKeySpeed;//���������Ă鎞�̃X�s�[�h
	float m_Accelerator;//�����x
	int m_Timer;
	static const float max_speed;//�ō��X�s�[�h�̒l
	static const float min_speed;//�Œ�X�s�[�h�̒l
	static const float jump;//�W�����v�̒l
	static const float width;//��
	static const float height;//����
	static const float radius;//���a
	static const float dash;//�_�b�V���̒l
	static const int max_interval;
	bool m_LandingFlag;//�󒆂ɂ���Ƃ��̃t���O
};