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
	void SetUp(aqua::CVector2 position, std::string box_name, std::string stage_name);

	// ���W�̉��Z
	void SetPosition(aqua::CVector2 add);

	// �傫���̕ύX
	void SetSize(aqua::CVector2 scale);

	// �w�i�t�@�C�����̎擾
	std::string GetStageBackGrondPath();

	std::string GetStageName();

	// �傫�����擾
	aqua::CVector2 GetObjectSize();

private:

	static const int m_max_font_size;

	aqua::CLabel m_StageNameLabel;

	aqua::CSprite m_SelectBox;

	std::string m_StageBackGroundName;
	std::string m_LabelText;
	std::string m_StageName;
	std::string m_ObjectFileName;

};