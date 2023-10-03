#pragma once
#include "../unit.h"

class CStage;
class CCamera;
class CUnitManager;

class CPlayer :public IUnit
{
private:

	enum class STATE
	{
		START,
		MOVE,
		DEAD,
		STOP,
	};

	enum class CHARA_DIR
	{
		RIGHT,
		LEFT,
	};

public:
	//�R���X�g���N�^
	CPlayer(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CPlayer()override = default;

	//������
	void Initialize(const aqua::CVector2 & position) override;

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

	void AddSpeed(float add_speed);

private:

	void State_Start();//�J�n�̏��
	void State_Move();//��������
	void State_Dead();//���񂾏��
	void State_Stop();//�S�[���������

	aqua::CAnimationSprite m_Chara;
	STATE m_State;
	CHARA_DIR m_DirNext;
	CHARA_DIR m_DirCurrent;
	CStage* m_pStage;
	CCamera* m_pCamera;
	CUnitManager* m_pUnitManager;
	float m_AddSpeed;
	static const float speed;
	static const float width;
	static const float height;
	static const float radius;
};