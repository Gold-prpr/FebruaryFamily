
/*!
 *  @file       point.h
 *  @brief      �_�N���X
 *  @author     Kazuya Maruyama
 *  @date       2021/03/10
 *  @version    7.17
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

/*!
 *  @brief  aqua���O���
 */
namespace aqua
{
    /*!
     *  @class      CPoint
     *
     *  @brief      �_�N���X
     *
     *  @author     Kazuya Maruyama
     *
     *  @date       2021/03/10
     *
     *  @version    7.17
     */
    class CPoint
    {
    public:
        //! X����
        int     x;
        //! Y����
        int     y;

        /*!
         *  @brief      �R���X�g���N�^
         */
        CPoint( void );

        /*!
         *  @brief      �R���X�g���N�^
         *
         *  @param[in]  point    �_�N���X
         */
        CPoint( const CPoint& point );

        /*!
         *  @brief      �R���X�g���N�^
         *
         *  @param[in]  x   X����
         *  @param[in]  y   Y����
         */
        CPoint( int x, int y );

        /*!
         *  @brief      �f�X�g���N�^
         */
        ~CPoint( void ) = default;

        /*!
         *  @brief      �f�o�b�O���O�ɒl��\������
         */
        void    DebugLog( void );

        /*!
         *  @brief      ���Z���Z�q�̃I�[�o�[���[�h
         *
         *  @param[in]  vA  �x�N�g���N���X
         *  @param[in]  vB  �x�N�g���N���X
         *
         *  @return     �x�N�g���N���X
         */
        friend CPoint     operator-(const CPoint& vA, const CPoint& vB) { return CPoint(vA.x - vB.x, vA.y - vB.y); }

        /*!
         *  @brief      ���Z���Z�q�̃I�[�o�[���[�h
         *
         *  @param[in]  vA  �x�N�g���N���X
         *  @param[in]  vB  �x�N�g���N���X
         *
         *  @return     �x�N�g���N���X
         */
        friend CPoint     operator*(const CPoint& vA, const CPoint& vB) { return CPoint(vA.x * vB.x, vA.y * vB.y); }

        //! �v�f�����ׂ�0
        static const CPoint  ZERO;
    };
}
