#pragma once
#include "../change_scene.h"

class CSlideClose :public IChangeScene
{
public:
	CSlideClose(aqua::IGameObject* parent);
	~CSlideClose() = default;

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

	static const float			m_start_position_x;
	static const float			m_max_block_time;
	static const int			m_max_block;

	aqua::CBoxPrimitive*		m_MosaicBox;

	aqua::CVector2				m_MosaicSize;

	aqua::CTimer				m_BlockTime;
};

