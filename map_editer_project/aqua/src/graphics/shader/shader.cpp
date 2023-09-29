
/*!
 *  @file       shader.cpp
 *  @brief      シェーダクラス
 *  @author     Kazuya Maruyama
 *  @date       2021/03/10
 *  @version    7.17
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#include "shader.h"
#include "..\..\debug\debug.h"

 /*
  *  コンストラクタ
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
 *  生成
 */
void
aqua::CShader::
Create(const std::string& file_name)
{
	Delete();

	std::string ps_name = file_name + ".pso";

	// ピクセルシェーダ読み込み
	m_PixelShaderHandle = LoadPixelShader(ps_name.c_str());

	AQUA_DX_ASSERT(m_PixelShaderHandle, ps_name + "の読み込みに失敗しました。");
}

/*
 *  解放
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
 *  シェーダの適用開始
 */
void
aqua::CShader::
Begin(void)
{
	// オリジナルシェーダを使用する
	MV1SetUseOrigShader(TRUE);

	// シェーダ設定
	SetUsePixelShader(m_PixelShaderHandle);

	// デフォルトライトを無効化
	SetLightEnable(FALSE);
}

/*
 *  シェーダの適用終了
 */
void
aqua::CShader::
End(void)
{
	SetTextureAddressMode(DX_TEXADDRESS_CLAMP);

	DrawPolygonIndexed2DToShader(m_Vertex, m_MaxVertex, m_PolygonIndex, 2);

	// デフォルトライトを有効化
	SetLightEnable(TRUE);

	// シェーダ解除
	SetUseVertexShader(AQUA_UNUSED_HANDLE);
	SetUsePixelShader(AQUA_UNUSED_HANDLE);

	// オリジナルシェーダを使用しない
	MV1SetUseOrigShader(FALSE);
}

/*
 *  シェーダで使用するテクスチャを設定
 */
void
aqua::CShader::
SetUseTexture(int register_id, int handle)
{
	SetUseTextureToShader(register_id, handle);
}

/*
 *  @brief      float 型定数を設定する
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
 * 頂点データ数を設定
 */
void aqua::CShader::SetMaxVertex(int max_vertex, unsigned short* intdex)
{
	m_Vertex = AQUA_NEW VERTEX2DSHADER[max_vertex];
	m_PolygonIndex = intdex;
	m_MaxVertex = max_vertex;
}
