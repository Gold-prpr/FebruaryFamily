#pragma once
#include "aqua.h"
#include "tile_id.h"

class CCamera;

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

	//CSV�ǂݍ���
	void Parse(const std::string& file_name);

	float GetMapWidth(void);

	float GetMapHeight(void);

	//�d��
	float GetGravity(void);

	bool CheckHit(int x, int y);

	int GetTileSize(void);

	/*//�����蔻��
	bool CheckHit(int x, int y);

	//�S�[������
	bool CheckGoal(int x, int y);

	////�����锻��
	bool CheckFallBlock(int x, int y);

	//�A�C�e������
	bool CheckItem(int x, int y);

	////�M�~�b�N����(�j)
	bool CheckSpine(int x, int y);

	//Tile�T�C�Y���Ă�
	int GetSize(void);

	//��̃^�C���ɕύX
	void ChangeAir(int x, int y);

	////�S�[�����o
	void GoalMove(void);*/

	aqua::CSprite* m_TileSprite;			//Tile�`��

	aqua::CVector2 m_Scroll;

private:
	static const int map_chip_size;			//Tile�T�C�Y

	static const int num_chip_size_x;		//Tile�摜�̉��̐�
	static const int num_chip_size_y;		//Tile�摜�̏c�̐�

	static const int all_num_chip;			//Tile�̍��v

	static const int map_x;					//�}�b�v�̉��̃^�C���̐�
	static const int map_y;					//�}�b�v�̏c�̃^�C���̐�

	static const float m_gravity;			//�d��

	std::vector<int> m_MapData;

	aqua::CVector2 m_MapPos;

	//aqua::CSprite m_background;				//�w�i
	//aqua::CSprite m_goal;					//�S�[��

	CCamera* m_pCamera;
};