#include "result.h"
#include "../../../common_data/common_data.h"
#include "../../../effect_manager/effect_manager.h"

using namespace aqua::controller;

const int CResult::m_max_belt_sprite = 4;
const int CResult::m_max_rolling = 5;
const int CResult::m_radian = 4 * 360;
const float CResult::m_max_move_time = 3.0f;
const float CResult::m_fice_cool_time = 5.0f;
const aqua::CVector2 CResult::m_loser_position{ 450.0f,300.0f };

/*
*  �R���X�g���N�g
*/
CResult::CResult(aqua::IGameObject* parent)
	:IScene(parent, "Result", SCENE_ID::TITLE, CHANGE_SCENE_ID::SLIDE_CLOSE)
	, m_EffectFlag(false)
{
}

/*
*  ������
*/
void CResult::Initialize()
{
	IScene::Initialize();
	
	// BGM�Đ�
	m_GameSoundClass->Play(SOUND_ID::RESULT);

	// ���L�f�[�^�̎擾
	m_pCommonData = (CCommonData*)aqua::FindGameObject("CommonData");

	// ���Ԃ̏�����
	m_MoveTimer.Setup(m_max_move_time);
	m_FiceCoolTimer.Setup(m_fice_cool_time);

	// �������v���C���[ID�̎擾
	int player = (int)(m_pCommonData->GetCommonDate().m_device_id) + 1;

	// �����ƕ����摜�̑I��
	if (m_pCommonData->GetCommonDate().m_device_id == aqua::controller::DEVICE_ID::P1)
	{

		m_WinPlayerSprite.Create("data\\scene\\result\\charactor\\player_1p.ass");
		m_LosePlayerSprite.Create("data\\scene\\result\\charactor\\player_2p.ass");

	}
	else
	{

		m_WinPlayerSprite.Create("data\\scene\\result\\charactor\\player_2p.ass");
		m_LosePlayerSprite.Create("data\\scene\\result\\charactor\\player_1p.ass");

	}

	// �����҃|�W�V����
	m_WinPlayerSprite.scale = m_WinPlayerSprite.scale * 5.0f;
	m_SetPoition.x = (aqua::GetWindowWidth() - m_WinPlayerSprite.GetTextureWidth() )/ 2.0f;
	m_WinPlayerSprite.position.y = (aqua::GetWindowHeight() - m_WinPlayerSprite.GetTextureHeight() ) / 2.0f;

	// �s�k�҃|�W�V����
	m_LosePlayerSprite.position = m_loser_position;

	// �w�i
	m_BackGround.Create("data\\��.png");

	// �A�j���[�V�����̐ݒ�
	m_WinPlayerSprite.Change("wait_1");
	m_WinPlayerSprite.Play();

	m_LosePlayerSprite.Change("wait_1");
	m_LosePlayerSprite.Play();

	// ���S�_�̐ݒ�
	m_WinPlayerSprite.anchor.x = m_WinPlayerSprite.GetTextureWidth() / 10.0f;
	m_WinPlayerSprite.anchor.y = m_WinPlayerSprite.GetTextureHeight() / 8.0f;

	m_ResultWinSprite.Create("data\\scene\\result\\win.png");

	IGameObject::Initialize();
}

/*
*  �X�V
*/
void CResult::Update()
{
	// ���G�t�F�N�g
	if (m_MoveTimer.Finished() && !m_EffectFlag)
	{
		CEffectManager* effect = aqua::CreateGameObject<CEffectManager>(this);
		effect->Create(EFFECT_ID::SAKURA, { 0,0 });
		m_EffectFlag = true;
	}

	// �G���^�[�L�[�Ŏ��̃V�[���ɑJ��
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
		m_ChangeSceneFlag = true;

	// �R���g���[���[�Ŏ��̃V�[���ɑJ��
	if (Trigger(DEVICE_ID::P1, BUTTON_ID::A) || Trigger(DEVICE_ID::P2, BUTTON_ID::A))
		m_ChangeSceneFlag = true;

	// �����҃|�W�V�����ɉ摜���ړ��܂��͉�]
	m_WinPlayerSprite.position.x = m_SetPoition.x * (m_MoveTimer.GetTime() / m_MoveTimer.GetLimit());

	m_WinPlayerSprite.rotation = aqua::DegToRad((float)m_radian * (m_MoveTimer.GetTime() / m_MoveTimer.GetLimit()));

	// �ړ����Ԃ̍X�V
	if (!m_MoveTimer.Finished())
		m_MoveTimer.Update();

	// �����҉摜�̃A�j���[�V�����̃N�[���^�C��
	if (m_WinPlayerSprite.Finished())
	{
		if (m_FiceCoolTimer.Finished())
			m_FiceCoolTimer.Reset();

		m_FiceCoolTimer.Update();
	}

	// �A�j���[�V�������ēx�Đ�
	if (m_WinPlayerSprite.Finished() && m_FiceCoolTimer.Finished())
	{
		m_WinPlayerSprite.Play();
	}
	
	if (m_LosePlayerSprite.Finished())
	{
		m_LosePlayerSprite.Play();
	}

	m_WinPlayerSprite.Update();
	m_LosePlayerSprite.Update();

	IGameObject::Update();

}

/*
*  �`��
*/
void CResult::Draw()
{
	m_BackGround.Draw();
	m_ResultWinSprite.Draw();


	m_LosePlayerSprite.Draw();
	m_WinPlayerSprite.Draw();

	IGameObject::Draw();
}

/*
*  ���
*/
void CResult::Finalize()
{
	m_BackGround.Delete();

	m_ResultWinSprite.Delete();
	m_LosePlayerSprite.Delete();
	m_WinPlayerSprite.Delete();

	m_GameSoundClass->Stop(SOUND_ID::RESULT);

	IGameObject::Finalize();
}
