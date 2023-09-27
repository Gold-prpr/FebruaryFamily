#pragma once
#include "aqua.h"


class CBackGroundManager :
	public aqua::IGameObject
{
public:

	CBackGroundManager(aqua::IGameObject* parent);
	~CBackGroundManager() = default;

	void Initialize()override;
	void Update()override;
	void Draw()override;
	void Finalize()override;

	/*
	 *  @brief �摜�̕ۑ�
	 * 
	 *  @retval     true    �ۑ�����
     *  @retval     false   �ۑ����s�܂��͂��łɑ��݂��Ă���
	 */
	bool SaveSprite();

	/*
	 *  @brief �摜�̃p�X
	 * 
	 *  @return �摜�̃p�X
	 */
	std::string GetSpritePath();

private:

	/*
	 *  @brief �h���b�N�A���h�h���b�v�ŉ摜�ǂݍ���
	 */
	void DropSprite();

private:

	static const std::string m_DirectyoryName;

	char buffer[MAX_PATH];
	std::string m_FilePath;

	aqua::CSprite m_BackGroundSprite;

	aqua::CLabel  m_BackGroundFile;
	aqua::CLabel  m_FileNum;
	aqua::CLabel  m_ExePath;

	int m_DropSpiteNum;

};