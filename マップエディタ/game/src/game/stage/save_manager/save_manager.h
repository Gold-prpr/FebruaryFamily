#pragma once
#include "aqua.h"

class CBackGroundManager;
class CTileManager;

class CSaveManager :
	public aqua::IGameObject
{
public:

	CSaveManager(aqua::IGameObject* parent);
	~CSaveManager() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

private:

	/*
	 *  @brief �{�^���̃N���b�N���� 
	 */
	void ClickHitButton(aqua::CVector2& position);

	/*
	 *  @brief �{�^���̃T�C�Y�ύX
	 */
	void ButtonChangeSize();

	/*
	 *  @brief ���b�Z�[�W�̕\������ 
	 */
	void MessageUpdata();

private:

	static const float m_min_button_size;	   //  
	static const float m_max_button_size;	   //  
	static const float m_max_size_easing_time; //  
	static const float m_max_message_time;     //  
	static const int   m_message_font_size;    //  
	static const int   m_message_box_space;    //  

	CBackGroundManager* m_BackGroundClass;     //  �w�i�Ǘ��N���X
	CTileManager*       m_TileManagerClass;    //  �^�C���Ǘ��N���X

	aqua::CSprite m_SaveButtonSprite;          //  
	aqua::CTimer m_SizeEasingTime;			   //  
	aqua::CTimer m_MessageTime;			       //  

	aqua::CLabel m_MessageLabel;               //  

	aqua::CBoxPrimitive m_MessageBox;		   //  

	float m_SaveButtonSize;                    //  

	bool m_CursorOnButton;                     //  
	bool m_PrivCursorOnButton;				   //  
	bool m_SaveMessageFlag;  				   //  �Z�[�u���̃��b�Z�[�W�t���O

};