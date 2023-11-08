#pragma once
#include "aqua.h"
#include "stage_object/stage_object_id.h"

class CStageObject;

class CStage
	: public aqua::IGameObject
{
public:

	//�R���X�g���N�^
	CStage(aqua::IGameObject* parent);
	//�f�X�g���N�^
	~CStage() = default;

	//������
	void Initialize(void);
	//�X�V
	void Update(void);
	//�`��
	void Draw(void);
	//���
	void Finalize(void);

	// �X�N���[���̐ݒ�
	void SetScroll(aqua::CVector2 scroll);

	//CSV�ǂݍ���
	void Parse(const std::string& file_name);

	float GetMapWidth(void);

	float GetMapHeight(void);

	//�d��
	float GetGravity(void);

	bool CheckHit(int x, int y);

	int GetTileSize(void);

	//�S�[������
	bool CheckGoal(int x, int y);

	//�A�C�e������
	bool CheckItem(int x, int y);

	//�M�~�b�N����
	bool CheckGimmick(int x, int y);

	bool ChangeAir(int x, int y);

	/*//�����锻��
	bool CheckFallBlock(int x, int y);

	////�M�~�b�N����(�j)
	bool CheckSpine(int x, int y);

	//Tile�T�C�Y���Ă�
	int GetSize(void);

	//��̃^�C���ɕύX
	void ChangeAir(int x, int y);

	////�S�[�����o
	void GoalMove(void);*/

	aqua::CVector2 m_Scroll;

private:
	static const int map_chip_size;			//Tile�T�C�Y

	static const int num_chip_size_x;		//Tile�摜�̉��̐�
	static const int num_chip_size_y;		//Tile�摜�̏c�̐�

	static const int all_num_chip;			//Tile�̍��v


	static const float m_gravity;			//�d��

	std::vector<CStageObject*> m_StageObject;

	aqua::CSprite              m_BackGround;

	aqua::CVector2 m_MapPos;

	int map_x;					//�}�b�v�̉��̃^�C���̐�
	int map_y;					//�}�b�v�̏c�̃^�C���̐�

	int m_MapTileX;
	int m_MapTileY;

	bool CheckObject(int x, int y, StageObjectID id);
};