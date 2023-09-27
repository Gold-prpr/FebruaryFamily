
/*!
 *  @file       shader.h
 *  @brief      シェーダクラス
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
  *  @brief      aqua名前空間
  */
namespace aqua
{
	/*!
	 *  @class      CShader
	 *
	 *  @brief      シェーダクラス
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
		 *  @brief      コンストラクタ
		 */
		CShader(void);

		/*!
		 *  @brief      デストラクタ
		 */
		~CShader(void) = default;

		/*!
		 *  @brief      生成
		 *
		 *  @param[in]  file_name   シェーダファイル名(拡張は指定しない)
		 */
		void    Create(const std::string& file_name);

		/*!
		 *  @brief      解放
		 */
		void    Delete(void);

		/*!
		 *  @brief      シェーダ適用開始
		 */
		void    Begin(void);

		/*!
		 *  @brief      シェーダの適用終了
		 */
		void    End(void);

		/*!
		 *  @brief      シェーダで使用するテクスチャを設定
		 *
		 *  @param[in]  register_id     レジスタID(2以降の整数を順番に使う)
		 *  @param[in]  handle          テクスチャのグラフィックスハンドル
		 */
		void    SetUseTexture(int register_id, int handle);

		/*!
		 *  @brief      float 型定数を設定する
		 *
		 *  @param[in]  constant_name		レジスタID(2以降の整数を順番に使う)
		 *  @param[in]  param				テクスチャのグラフィックスハンドル
		 */
		void	SetFloat(std::string constant_name, float param);

		/*!
		 *  @brief      float 型定数を設定する
		 * 
		 *  @param[in]  vtx					レジスタID(2以降の整数を順番に使う)
		 *  @param[in]  x					テクスチャのグラフィックスハンドル
		 *  @param[in]  y					レジスタID(2以降の整数を順番に使う)
		 *  @param[in]  u					テクスチャのグラフィックスハンドル 
		 *  @param[in]  v					テクスチャのグラフィックスハンドル 
		 */
		void Setting(int vtx_index, float x, float y, float u, float v);
		
		/*!
		 *  @brief      頂点データ数を設定
		 *
		 *	@param[in]  v					テクスチャのグラフィックスハンドル 
		 */
		void SetMaxVertex(int max_vertex, unsigned short* intdex);

	private:
		
		//! ピクセルシェーダハンドル
		int     m_PixelShaderHandle;

		//! 頂点データの最大数
		int		m_MaxVertex;
		//! 頂点データ
		VERTEX2DSHADER* m_Vertex;
		//! ポリゴン
		unsigned short*	m_PolygonIndex;

	};
}