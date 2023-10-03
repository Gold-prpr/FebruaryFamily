#include "fade.h"

const float CFade::m_max_fade_time = 0.5f;
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

	m_FadeBox.Setup(aqua::CVector2::ZERO, aqua::GetWindowWidth(), aqua::GetWindowHeight(), aqua::CColor::BLACK);
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
		aqua::easing::InCubic
		(
			m_FadeTime.GetTime(),
			m_FadeTime.GetLimit(),
			m_max_fade_alpha,
			m_min_fade_alpha
		);

	return m_FadeTime.Finished();
}

/*
*  �V�[������؂�ւ�
*/
bool CFade::Out()
{
	if (m_FadeTime.Finished() && m_FadeBox.color.alpha != m_max_fade_alpha)
		m_FadeTime.Reset();

	m_FadeBox.color.alpha =
		aqua::easing::OutCubic
		(
			m_FadeTime.GetTime(),
			m_FadeTime.GetLimit(),
			m_min_fade_alpha,
			m_max_fade_alpha
		);

	return m_FadeTime.Finished();
}
