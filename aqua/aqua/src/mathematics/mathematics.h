
/*!
 *  @file       mathematics.h
 *  @brief      ���w
 *  @author     Kazuya Maruyama
 *  @date       2021/03/10
 *  @version    7.17
 *
 *  Copyright (c) 2013-2021, Kazuya Maruyama. All rights reserved.
 */

#pragma once

#include <cmath>
#include "vector\vector.h"

/*!
 *  @brief      aqua���O���
 */
namespace aqua
{
    /*!
     *  @brief      �~����
     */
    static const float PI = 3.141592653589793f;

    /*!
     *  @brief      �p�x�����W�A���ɕϊ�
     *
     *  @param[in]  degree  �p�x
     */
    float       DegToRad( float degree );

    /*!
     *  @brief      ���W�A�����p�x�ɕϊ�
     *
     *  @param[in]  radian  ���W�A��
     */
    float       RadToDeg( float radian );

    /*!
     *  @brief      ���������߂�(���̐���)
     *
     *  @param[in]  max     �ő�l
     *  @param[in]  min     �ŏ��l
     *
     *  @return     �ŏ��l����ő�l�܂ł͈̔͂ŋ��߂�ꂽ�����l
     */
    int         Rand(int max, int min = 0 );

    /*!
     *  @brief      ���l�̏㉺�����߂�
     * 
     *  @param[in]  num     ���l
     *  @param[in]  t_max   �ő�l
     *  @param[in]  t_min   �ŏ��l  
     * 
     *  @return     �ŏ��l����ő�l�܂ł̐��l
     */
    template<class ENUM,class T> ENUM Limit(T num, T t_min, T t_max)
    {
        return (ENUM)std::max<T>(t_min, std::min<T>(num, t_max));
    }

    /*!
     *  @brief      ���l�̏㉺�����߂�
     *
     *  @param[in]  num     ���l
     *  @param[in]  t_max   �ő�l
     *  @param[in]  t_min   �ŏ��l
     *
     *  @return     �ŏ��l����ő�l�܂ł̐��l
     */
    template<class T> T Limit(T num, T t_min, T t_max)
    {
        return std::max<T>(t_min, std::min<T>(num, t_max));
    }
    /*!
     *  @brief      ���l�̏㉺�����߂�
     *
     *  @param[in]  num     ���l
     *  @param[in]  t_max   �ő�l
     *  @param[in]  t_min   �ŏ��l
     *
     *  @return     �ŏ��l����ő�l�܂ł̐��l
     */
    template<class T> T Mod(T num, T t_min, T t_max)
    {
        T m_next = (T)1;

        if (num > t_max)
            return num - (t_max + m_next);

        if (num < t_min)
            return (t_max + m_next) + num;

        return num;
    }

    /*!
     *  @brief      ���l�̏㉺�����߂�
     *
     *  @param[in]  num     ���l
     *  @param[in]  t_max   �ő�l
     *  @param[in]  t_min   �ŏ��l
     *
     *  @return     �ŏ��l����ő�l�܂ł̐��l
     */
    template<class ENUM,class T> ENUM Mod(ENUM num, ENUM t_min, ENUM t_max)
    {
        T m_num = (T)num;
        T m_min = (T)t_min;
        T m_max = (T)t_max;
        T m_sub_max = (T)1;

        if (m_num > m_max)
            return (ENUM)(m_num - (m_max + m_sub_max));

        if (m_num < m_min)
            return (ENUM)((m_max + m_sub_max) + m_num);

        return num;
    }

    /*!
     *  @brief      ���l�̏㉺�����߂�
     *
     *  @param[in]  num     ���l
     *  @param[in]  t_max   �ő�l
     *  @param[in]  t_min   �ŏ��l
     *
     *  @return     �ŏ��l����ő�l�܂ł̐��l
     */
    template<class ENUM, class T> ENUM Mod(T num, ENUM t_min, ENUM t_max)
    {
        T m_min = (T)t_min;
        T m_max = (T)t_max;
        T m_sub_max = (T)1;

        if (num > m_max)
            return (ENUM)(num - (m_max + m_sub_max));

        if (num < m_min)
            return (ENUM)((m_max + m_sub_max) + num);

        return (ENUM)num;
    }

    /*!
     *  @brief      ���l�̏㉺�����߂�
     *
     *  @param[in]  num     ���l
     *  @param[in]  t_max   �ő�l
     *  @param[in]  t_min   �ŏ��l
     *
     *  @return     �ŏ��l����ő�l�܂ł̐��l
     */
    template<class ENUM, class T> ENUM Mod(T num, T t_min, T t_max)
    {
        T m_sub_max = (T)1;

        if (num > t_max)
            return (ENUM)(num - (t_max + m_sub_max));

        if (num < t_min)
            return (ENUM)((t_max + m_sub_max) + num);

        return (ENUM)num;
    }
}
