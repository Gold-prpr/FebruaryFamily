#include "back_ground_manager.h"
#include <filesystem>
#include <fstream>

namespace file_sys = std::filesystem;

const std::string CBackGroundManager::m_DirectyoryName = "data\\map_data";

CBackGroundManager::CBackGroundManager(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "BackGroundManager")
{
}

void CBackGroundManager::Initialize()
{
	// �f�B���N�g���𐶐�
	file_sys::create_directory(m_DirectyoryName);

	m_BackGroundFile.Create(20);
	m_FileNum.Create(20);

	m_FileNum.text = "�h���b�N�A���h�h���b�v : " + std::to_string(0);
}

void CBackGroundManager::Update()
{
	DropSprite();
}

void CBackGroundManager::Draw()
{
	if (m_BackGroundSprite.GetResourceHandle() != -1)
	{

		m_BackGroundSprite.Draw();
		m_BackGroundFile.Draw();

	}

	m_FileNum.Draw();
}

void CBackGroundManager::Finalize()
{

	if (m_BackGroundSprite.GetResourceHandle() != -1)
	{
		SaveSprite();
		m_BackGroundSprite.Delete();
	}

	m_BackGroundFile.Delete();
	m_FileNum.Delete();
}

void CBackGroundManager::DropSprite()
{
	// ���N���b�N�Ńt�@�C���f�[�^���X�v���C�g�ɓǂݍ���
	if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
	{
		// �h���b�N�A���h�h���b�v�����t�@�C���̌��i�t�@�C����ǂݍ��񂾂�0���Z�b�g�j
		m_DropSpiteNum = GetDragFileNum();

		// �t�@�C�����𕶎����
		m_FileNum.text = "�h���b�N�A���h�h���b�v : " + std::to_string(m_DropSpiteNum);

		// �h���b�N�A���h�h���b�v�����t�@�C���̐�΃p�X
		GetDragFilePath(buffer);

		if (m_DropSpiteNum >= 1)
		{
			if (m_BackGroundSprite.GetResourceHandle() != -1)
				m_BackGroundSprite.Delete();

			m_BackGroundFile.text = buffer;

			m_BackGroundFile.position.y = (float)m_FileNum.GetFontHeight();

			m_BackGroundSprite.Create(buffer);
		}

	}
}
/*
 *  �摜�̕ۑ�
 */
bool CBackGroundManager::SaveSprite()
{
	if (m_BackGroundSprite.GetResourceHandle() == -1)return false;

	int file_buffer_num = 0;

	// �t�@�C�������擾
	for (int i = MAX_PATH; i > 0; i--)
	{
		if (buffer[i] == '\\')
		{
			file_buffer_num = i + 1;
			break;
		}
	}

	m_FilePath = m_DirectyoryName + "\\";

	// �R�s�[��̎Q�ƃp�X���쐬
	for (int i = file_buffer_num; i < MAX_PATH; i++)
	{

		if (buffer[i] != '\0') // �p�X�̏I�[
			m_FilePath += buffer[i];
		else
			break;

	}

	// �t�@�C�������݂��Ȃ���̓R�s�[��ɕۑ�����
	if (!file_sys::exists(m_FilePath))
		file_sys::copy_file(buffer, m_FilePath);

	return true;
}

std::string CBackGroundManager::GetSpritePath()
{
	return m_FilePath;
}
