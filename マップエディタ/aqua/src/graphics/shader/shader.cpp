
/*!
 *  @file       shader.cpp
 *  @brief      �V�F�[�_�N���X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/10
 *  @version    7.17
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "shader.h"
#include "..\..\debug\debug.h"

 /*
  *  �R���X�g���N�^
  */
aqua::CShader::
CShader(void)
	: aqua::core::IResourceObject(aqua::core::RESOURCE_TYPE::LOAD_SHADER)
	, m_PixelShaderHandle(AQUA_UNUSED_HANDLE)
	, m_Vertex(nullptr)
	, m_PolygonIndex(nullptr)
	, m_MaxVertex(0)
{
}

/*
 *  ����
 */
void
aqua::CShader::
Create(const std::string& file_name)
{
	Delete();

	std::string ps_name = file_name + ".pso";

	// �s�N�Z���V�F�[�_�ǂݍ���
	m_PixelShaderHandle = LoadPixelShader(ps_name.c_str());

	AQUA_DX_ASSERT(m_PixelShaderHandle, ps_name + "�̓ǂݍ��݂Ɏ��s���܂����B");
}

/*
 *  ���
 */
void
aqua::CShader::
Delete(void)
{

	DeleteShader(m_PixelShaderHandle);

	m_PixelShaderHandle = AQUA_UNUSED_HANDLE;

	if (m_Vertex)
		AQUA_SAFE_DELETE_ARRAY(m_Vertex);

	if (m_PolygonIndex)
		AQUA_SAFE_DELETE_ARRAY(m_PolygonIndex);

}

/*
 *  �V�F�[�_�̓K�p�J�n
 */
void
aqua::CShader::
Begin(void)
{
	// �I���W�i���V�F�[�_���g�p����
	MV1SetUseOrigShader(TRUE);

	// �V�F�[�_�ݒ�
	SetUsePixelShader(m_PixelShaderHandle);

	// �f�t�H���g���C�g�𖳌���
	SetLightEnable(FALSE);
}

/*
 *  �V�F�[�_�̓K�p�I��
 */
void
aqua::CShader::
End(void)
{
	SetTextureAddressMode(DX_TEXADDRESS_CLAMP);

	DrawPolygonIndexed2DToShader(m_Vertex, m_MaxVertex, m_PolygonIndex, 2);

	// �f�t�H���g���C�g��L����
	SetLightEnable(TRUE);

	// �V�F�[�_����
	SetUseVertexShader(AQUA_UNUSED_HANDLE);
	SetUsePixelShader(AQUA_UNUSED_HANDLE);

	// �I���W�i���V�F�[�_���g�p���Ȃ�
	MV1SetUseOrigShader(FALSE);
}

/*
 *  �V�F�[�_�Ŏg�p����e�N�X�`����ݒ�
 */
void
aqua::CShader::
SetUseTexture(int register_id, int handle)
{
	SetUseTextureToShader(register_id, handle);
}

/*
 *  @brief      float �^�萔��ݒ肷��
 */
void aqua::CShader::SetFloat(std::string constant_name, float param)
{
	SetPSConstSF(GetConstIndexToShader(constant_name.c_str(), m_PixelShaderHandle), param);
}

void aqua::CShader::Setting(int vtx_index, float x, float y, float u, float v)
{
	if (vtx_index < m_MaxVertex && vtx_index >= 0)
	{
		m_Vertex[vtx_index].pos = VGet(x, y, 0.0f);
		m_Vertex[vtx_index].u = u;
		m_Vertex[vtx_index].v = v;
		m_Vertex[vtx_index].su = u;
		m_Vertex[vtx_index].sv = v;
		m_Vertex[vtx_index].rhw = 1.0f;
		m_Vertex[vtx_index].dif = GetColorU8(255, 255, 255, 255);
		m_Vertex[vtx_index].spc = GetColorU8(0, 0, 0, 0);
	}
}

/*
 * ���_�f�[�^����ݒ�
 */
void aqua::CShader::SetMaxVertex(int max_vertex, unsigned short* intdex)
{
	m_Vertex = AQUA_NEW VERTEX2DSHADER[max_vertex];
	m_PolygonIndex = intdex;
	m_MaxVertex = max_vertex;
}
