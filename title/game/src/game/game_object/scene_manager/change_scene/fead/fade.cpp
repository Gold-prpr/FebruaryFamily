#include "fade.h"

const float CFade::m_max_fade_time = 3.75f;
const unsigned char CFade::m_max_fade_alpha = 0xff;
const unsigned char CFade::m_min_fade_alpha = 0x00;

CFade::CFade(aqua::IGameObject* parent)
	:IChangeScene(parent,"Fade")
{
}

/*
*  ������
*/
void CFade::Initialize()
{
	m_FadeTime.Setup(m_max_fade_time);

	m_FadeBox.Setup(aqua::CVector2::ZERO,(float)aqua::GetWindowWidth(), (float)aqua::GetWindowHeight(), aqua::CColor::BLACK);
}

/*
*  �X�V
*/
void CFade::Update()
{
	m_FadeTime.Update();
}

/*
*  �`��
*/
void CFade::Draw()
{
	m_FadeBox.Draw();
}

/*
*  ���
*/
void CFade::Finalize()
{
	m_FadeBox.visible = false;
}

/*
*  �؂�ւ�����V�[��
*/
bool CFade::In()
{
	if (m_FadeTime.Finished() && m_FadeBox.color.alpha != m_min_fade_alpha)
		m_FadeTime.Reset();

	m_FadeBox.color.alpha =
		(unsigned char)aqua::easing::InBack
		(
			m_FadeTime.GetTime(),
			m_FadeTime.GetLimit(),
			m_max_fade_alpha,
			m_min_fade_alpha
		);

	if (m_FadeTime.Finished())
		m_FadeTime.Reset();

	if (m_FadeBox.color.alpha < m_min_fade_alpha + (unsigned char)10)
		m_FadeBox.color.alpha = m_min_fade_alpha;

	return m_FadeBox.color.alpha == m_min_fade_alpha;
}

/*
*  �V�[������؂�ւ�
*/
bool CFade::Out()
{
	if (m_FadeTime.Finished() && m_FadeBox.color.alpha != m_max_fade_alpha)
		m_FadeTime.Reset();

	m_FadeBox.color.alpha =
		(unsigned char)aqua::easing::OutBack
		(
			m_FadeTime.GetTime(),
			m_FadeTime.GetLimit(),
			m_min_fade_alpha,
			m_max_fade_alpha
		);

	if (m_FadeTime.Finished())
		m_FadeTime.Reset();

	return m_FadeBox.color.alpha == m_max_fade_alpha;
}