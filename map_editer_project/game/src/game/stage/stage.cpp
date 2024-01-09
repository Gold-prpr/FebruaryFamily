#include "stage.h"
#include "tile_manager/tile_manager.h"
#include "back_ground_manager/back_ground_manager.h"
#include "save_manager/save_manager.h"

const float CStage::m_mouse_size = 0.25;

CStage::CStage(aqua::IGameObject* parent)
	:aqua::IGameObject(parent, "Stage")
	, m_TileManager(nullptr)
	, writing_flag(false)
	, m_SelectCreateMode(false)
{
}

void CStage::Initialize()
{
	aqua::CreateGameObject<CBackGroundManager>(this);

	m_TileManager = aqua::CreateGameObject<CTileManager>(this);

	aqua::CreateGameObject<CSaveManager>(this);

	m_ForeGroudoSprite.Create("data\\�������.png");
	m_MouseCorsorSprite.Create("data\\mouse_corsor.png");
	m_SelectModeSprite.Create("data\\button\\�I��.png");
	m_DragSprite.Create("data\\button\\map_data�h���b�N���h���b�v.png");

	m_MouseCorsorSprite.scale = aqua::CVector2(m_mouse_size, m_mouse_size);

	IGameObject::Initialize();
}

void CStage::Update()
{
	m_MouseCorsorSprite.position = aqua::mouse::GetCursorPos();

	if (!m_SelectCreateMode)
	{
		if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::G))
		{
			m_TileManager->Initialize(aqua::GetWindowSize());
			m_SelectCreateMode = true;
		}

		if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::H))
		{
			writing_flag = true;
			m_SelectCreateMode = true;
		}
	}
	else if (!writing_flag)
	{
		IGameObject::Update();
	}

	if (writing_flag)
	{
		// ���N���b�N�Ńt�@�C���f�[�^���X�v���C�g�ɓǂݍ���
		if (aqua::mouse::Released(aqua::mouse::BUTTON_ID::LEFT))
		{
			// �h���b�N�A���h�h���b�v�����t�@�C���̌��i�t�@�C����ǂݍ��񂾂�0���Z�b�g�j
			int num = GetDragFileNum();

			// �h���b�N�A���h�h���b�v�����t�@�C���̐�΃p�X
			GetDragFilePath(buffer);

			if (num)
			{
				m_TileManager->Initialize(buffer);
				writing_flag = false;
			}

		}
	}
}

void CStage::Draw()
{
	if (writing_flag)
	{
		m_DragSprite.Draw();
	}
	else
	{
		if (m_SelectCreateMode)
		{
			IGameObject::Draw();
			m_ForeGroudoSprite.Draw();
		}
		else
		{
			m_SelectModeSprite.Draw();
		}
	}

	m_MouseCorsorSprite.Draw();
}

void CStage::Finalize()
{
	m_ForeGroudoSprite.Delete();
	m_MouseCorsorSprite.Delete();
	m_SelectModeSprite.Delete();
	m_DragSprite.Delete();
	IGameObject::Finalize();
}
