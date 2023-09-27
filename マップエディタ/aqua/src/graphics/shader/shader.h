
/*!
 *  @file       shader.h
 *  @brief      �V�F�[�_�N���X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/10
 *  @version    7.17
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include <DxLib.h>
#include <string>
#include "..\..\resources\resources.h"
#include "..\..\utility\utility.h"

 /*!
  *  @brief      aqua���O���
  */
namespace aqua
{
	/*!
	 *  @class      CShader
	 *
	 *  @brief      �V�F�[�_�N���X
	 *
	 *  @author     Kazuya Maruyama
	 *
	 *  @date       2021/03/10
	 *
	 *  @version    7.17
	 */
	class CShader
		: aqua::core::IResourceObject
	{
	public:
		/*!
		 *  @brief      �R���X�g���N�^
		 */
		CShader(void);

		/*!
		 *  @brief      �f�X�g���N�^
		 */
		~CShader(void) = default;

		/*!
		 *  @brief      ����
		 *
		 *  @param[in]  file_name   �V�F�[�_�t�@�C����(�g���͎w�肵�Ȃ�)
		 */
		void    Create(const std::string& file_name);

		/*!
		 *  @brief      ���
		 */
		void    Delete(void);

		/*!
		 *  @brief      �V�F�[�_�K�p�J�n
		 */
		void    Begin(void);

		/*!
		 *  @brief      �V�F�[�_�̓K�p�I��
		 */
		void    End(void);

		/*!
		 *  @brief      �V�F�[�_�Ŏg�p����e�N�X�`����ݒ�
		 *
		 *  @param[in]  register_id     ���W�X�^ID(2�ȍ~�̐��������ԂɎg��)
		 *  @param[in]  handle          �e�N�X�`���̃O���t�B�b�N�X�n���h��
		 */
		void    SetUseTexture(int register_id, int handle);

		/*!
		 *  @brief      float �^�萔��ݒ肷��
		 *
		 *  @param[in]  constant_name		���W�X�^ID(2�ȍ~�̐��������ԂɎg��)
		 *  @param[in]  param				�e�N�X�`���̃O���t�B�b�N�X�n���h��
		 */
		void	SetFloat(std::string constant_name, float param);

		/*!
		 *  @brief      float �^�萔��ݒ肷��
		 * 
		 *  @param[in]  vtx					���W�X�^ID(2�ȍ~�̐��������ԂɎg��)
		 *  @param[in]  x					�e�N�X�`���̃O���t�B�b�N�X�n���h��
		 *  @param[in]  y					���W�X�^ID(2�ȍ~�̐��������ԂɎg��)
		 *  @param[in]  u					�e�N�X�`���̃O���t�B�b�N�X�n���h�� 
		 *  @param[in]  v					�e�N�X�`���̃O���t�B�b�N�X�n���h�� 
		 */
		void Setting(int vtx_index, float x, float y, float u, float v);
		
		/*!
		 *  @brief      ���_�f�[�^����ݒ�
		 *
		 *	@param[in]  v					�e�N�X�`���̃O���t�B�b�N�X�n���h�� 
		 */
		void SetMaxVertex(int max_vertex, unsigned short* intdex);

	private:
		
		//! �s�N�Z���V�F�[�_�n���h��
		int     m_PixelShaderHandle;

		//! ���_�f�[�^�̍ő吔
		int		m_MaxVertex;
		//! ���_�f�[�^
		VERTEX2DSHADER* m_Vertex;
		//! �|���S��
		unsigned short*	m_PolygonIndex;

	};
}