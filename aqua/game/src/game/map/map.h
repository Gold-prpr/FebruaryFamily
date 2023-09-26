#pragma once
#include "aqua.h"
#include "tile_id.h"

class CMap
	:public aqua::IGameObject
{
public:
	//�R���X�g���N�^
	CMap(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CMap(void) = default;

	//������
	void		Initialize(void) override;

	//�X�V
	void		Update(void) override;

	//�`��
	void		Draw(void) override;

	//���
	void		Finalize(void) override;

	//�����蔻��
	bool CheckHit(int x, int y);

	//�A�C�e������
	bool CheckItem(int x, int y);

	//�d��
	float GetGravity(void) const;

	static const int		m_chip_size;	//1�}�X�̑傫��

	int						m_size;			//FMF�̃T�C�Y������
	int						m_width;		//FMF�̃}�b�v�̉�������
	int						m_height;		//FMF�̃}�b�v�̍���������

private:
	aqua::CSprite*			m_Map;			//�摜��\��
	aqua::CFMFLoader		m_Fmf;			//FMF��ǂݍ��ނ��߂̕ϐ�
	int*					m_MapData;		//���ׂĂ�MAP_ID

};
//#pragma once
//#include "aqua.h"
//#include "tile_id.h"
////#include "../character/character.h"
//#include "../scene_manager/scene_manager.h"
//
////class CCharacter;
//class CSceneManager;
//
//class CStage
//	: public aqua::IGameObject
//{
//public:
//
//	//�R���X�g���N�^
//	CStage(aqua::IGameObject* parent);
//	//�f�X�g���N�^
//	~CStage() = default;
//
//	//������
//	void Initialize(void);
//	//�X�V
//	void Update(void);
//	//�`��
//	void Draw(void);
//	//���
//	void Finalize(void);
//
//	//CSV�ǂݍ���
//	void Parse(const std::string& file_name);
//
//	//�����蔻��
//	bool CheckHit(int x, int y);
//
//	//�S�[������
//	bool CheckGoal(int x, int y);
//
//	////�����锻��
//	//bool CheckFallBlock(int x, int y);
//
//	//�A�C�e������
//	bool CheckItem(int x, int y);
//
//	////�M�~�b�N����(�j)
//	//bool CheckSpine(int x, int y);
//
//	//�d��
//	float GetGravity(void) const;
//
//	//Tile�T�C�Y���Ă�
//	int GetSize(void);
//
//	//��̃^�C���ɕύX
//	void ChangeAir(int x, int y);
//
//	////�S�[�����o
//	//void GoalMove(void);
//
//	static const int map_chip_size;			//Tile�T�C�Y
//
//	aqua::CSprite* m_TileSprite;			//Tile�`��
//
//private:
//
//	static const int num_chip_size_x;		//Tile�摜�̉��̐�
//	static const int num_chip_size_y;		//Tile�摜�̏c�̐�
//
//	static const int all_num_chip;			//Tile�̍��v
//
//	static const int map_x;					//�}�b�v�̉��̃^�C���̐�
//	static const int map_y;					//�}�b�v�̏c�̃^�C���̐�
//
//	static const float m_gravity;			//�d��
//
//	std::vector<int> m_MapData;
//
//	aqua::CSprite m_background;				//�w�i
//	//aqua::CSprite m_goal;					//�S�[��
//
//	//CCharacter* chara;
//	CSceneManager* sm;
//};