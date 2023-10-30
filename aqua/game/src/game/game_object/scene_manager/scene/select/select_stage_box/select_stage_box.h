#pragma once
#include "aqua.h"

class CSelectStageBox :
	public aqua::IGameObject
{
public:

	//�R���X�g���N�^
	CSelectStageBox(aqua::IGameObject* parent);

	//�f�X�g���N�^
	~CSelectStageBox(void) = default;

	//������
	void Initialize(void) override;

	//�X�V
	void Update(void) override;

	//�`��
	void Draw(void) override;

	//���
	void Finalize(void) override;

	// �ݒ�
	void SetUp(aqua::CVector2 position, std::string file_name, std::string stage_name);

	// ���W�̉��Z
	void AddPosition(aqua::CVector2 add);

	// �傫���̕ύX
	void SetSize(aqua::CVector2 scale);

	// �w�i�t�@�C�����̎擾
	std::string GetStageBackGrond();

private:

	static const int m_max_font_size;

	aqua::CLabel m_StageName;

	aqua::CSprite m_SelectBox;

	std::string m_StageBackGroundName;

};