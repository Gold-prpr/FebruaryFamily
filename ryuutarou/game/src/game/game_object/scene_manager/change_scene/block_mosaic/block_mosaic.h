#pragma once
#include "../change_scene.h"

class CBloackMosaic :public IChangeScene
{
public:
	CBloackMosaic(aqua::IGameObject* parent);
	~CBloackMosaic() = default;

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

	static const aqua::CPoint	m_max_block_mosaic;
	static const float			m_max_block_time;
	static const unsigned char  m_max_block_alpha;
	static const unsigned char  m_min_block_alpha;

	aqua::CBoxPrimitive*		m_MosaicBox;

	aqua::CVector2				m_MosaicSize;

	aqua::CTimer				m_BlockTime;

	int							m_CountMosaic;

};

