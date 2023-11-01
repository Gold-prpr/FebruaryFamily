#pragma once

#include "../change_scene.h"

class CFade :public IChangeScene
{
public:
	CFade(aqua::IGameObject* parent);
	~CFade() = default;

	/*
	 *  @brief ������
	 */
	void Initialize()override;

	/*
	 *  @brief �X�V
	 */
	void Update()override;

	/*
	 *  @brief �`��
	 */
	void Draw()override;

	/*
	 *  @brief ���
	 */
	void Finalize()override;

	/*
	 *  @brief �؂�ւ�����V�[��
	 */
	bool In()override;

	/*
	 *  @brief �V�[������؂�ւ�
	 */
	bool Out()override;

private:

	static const float m_max_fade_time;
	static const unsigned char m_max_fade_alpha;
	static const unsigned char m_min_fade_alpha;

	aqua::CBoxPrimitive m_FadeBox;

	aqua::CTimer		m_FadeTime;

};

