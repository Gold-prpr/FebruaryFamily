#include "sakura_effect.h"

//�R���X�g���N�^
CSakuraEffect::CSakuraEffect(aqua::IGameObject* parent)
	:IEffect(parent, "SakuraEffect")
{
}

//������
void CSakuraEffect::Initialize(const aqua::CVector2& position)
{
	IEffect::Initialize(position);

	//�ǂ��炩�̍����o��
	if (aqua::Rand(1))m_Sakura.Create("data\\sakura1.png");
	else m_Sakura.Create("data\\sakura2.png");

	//�ォ�烉���_���ɍ~�炷
	m_Sakura.position.x = (float)aqua::Rand(aqua::GetWindowWidth());
	m_Sakura.position.y = 0;

	//�����_���ȑ傫��
	m_Sakura.scale.x = (float)aqua::Rand(30) / 10.0f;
	m_Sakura.scale.y = m_Sakura.scale.x;

	m_angle = 0;
}

//�X�V
void CSakuraEffect::Update()
{
	//�����Ȃ����������
	if (m_Sakura.color.alpha == 3)
		IGameObject::DeleteObject();

	m_angle++;

	//�h�炷
	m_Sakura.position.x += cos(aqua::DegToRad((float)m_angle));

	//���X�ɔ���
	m_Sakura.color.alpha -= 1;

	//���Ɉړ�
	m_Sakura.position.y += m_Sakura.scale.x * 5;
}

//�`��
void CSakuraEffect::Draw()
{
	m_Sakura.Draw();
}

//���
void CSakuraEffect::Finalize()
{
	m_Sakura.Delete();
}