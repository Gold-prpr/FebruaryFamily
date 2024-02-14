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
class CDarkItem;
class CSpeedUpItem;
class CItemIcon;
class CStagePosBar;
class CKeyIcon;
class CCommonData;
class CEffectIcon;
class CReverseItem;
//class CSpeedDownEffect;
//class CPlayerStunEffect;

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

	void AddEffectItemSpeed(float add_effect_item_speed);

	//�A�C�e������������̃X�s�[�h�̉��Z
	void AddItemSpeed(float add_item_speed);

	void AddGimmickSpeed(float add_gimmick_speed);

	void AddKeySpeed(float add_key_speed);

	void AddMaxSpeed(float add_max_speed);

	void Jump(void);

	void JumpRamp(void);

	aqua::CVector2 GetSpeed(void) { return m_Velocity; }

	//�ǂ̓����蔻��
	void CheckHitBlock(void);

	void SetDeviceID(DEVICE_ID device_id)override {m_Device = device_id;}

	DEVICE_ID GetDeviceID();

	void CreateItme(void);

	void UseItem(CPlayer* player);

	void AttackAct(CPlayer* player);

	//void EffectPosition(CPlayer* player);

	bool m_HitSpikeFlag;

	bool m_HitWireFlag;

	bool m_HitItemFlag;

	bool m_GetItemFlag;

	bool m_BrickFlag;

	bool m_GoalFlag;

	bool m_JampRampFlag;

	int m_KeyCount;

	bool m_KeyFlag;

	//aqua::CAnimationSprite m_Chara;//�L�����N�^�[�̃A�j���[�V�����X�v���C�g
	aqua::CSprite m_CharaSprite;

	DEVICE_ID m_Device;//�v���C���[�̃R���g���[�����蓖��

	bool m_LandingFlag;//�󒆂ɂ���Ƃ��̃t���O
	int max_interval;

	float m_VeloTemp;

	bool m_ReverseFlag;

private:

	void State_Start();//�J�n�̏��
	void State_Move();//��������
	void State_Dead();//���񂾏��
	void State_Goal();//�S�[���������

	std::string name;

	STATE m_State;//�L�����̏��
	CStage* m_pStage;//�X�e�[�W�̃|�C���^
	CCameraManager* m_pCamera;//�J�����̃|�C���^
	CUnitManager* m_pUnitManager;//���j�b�g�}�l�[�W���[�̃|�C���^
	CGimmickAct* m_pGimmick;//�M�~�b�N�̃|�C���^
	CItemManager* m_pItemManager;//�A�C�e���}�l�[�W���[�̃|�C���^
	CSlime* m_pSlime;
	CSpeedDownItem* m_pSpeedDownItem;
	CPlayerStunItem* m_pStunItem;
	CItemIcon* m_pItemIcon;
	CStagePosBar* m_pStageBar;
	CKeyIcon* m_pKeyIcon;
	CCommonData* m_pCommonData;
	CEffectIcon* m_pEffectIcon;
	CDarkItem* m_pDarkItem;
	CSpeedUpItem* m_pSpeedUpItem;
	CReverseItem* m_pReverseItem;

	//CSpeedDownEffect* m_pSpeedDownEffect;
	//CPlayerStunEffect* m_pPlayerStunEffect;
	
	aqua::CVector2 m_PrevPosition;// �v���C���[�̑O�t���[���̈ʒu

	float m_AddMaxSpeed;
	float m_AddKeySpeed;//���������Ă鎞�̃X�s�[�h
	float m_AddEffectItemSpeed;
	float m_AddItemSpeed;
	float m_AddGimmickSpeed;
	float m_Accelerator;//�����x]
	float m_Speed;
	int m_Timer;
	static const float max_speed;//�ō��X�s�[�h�̒l
	static const float min_speed;//�Œ�X�s�[�h�̒l
	static const float jump;//�W�����v�̒l
	static const float width;//��
	static const float height;//����
	static const float radius;//���a
	static const float dash;//�_�b�V���̒l
};