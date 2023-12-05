#include "player.h"
#include "../../../stage/stage.h"
#include "../../../camera_manager/camera_manager.h"
#include "../../unit_manager.h"
#include "../../../stage/gimmick/gimmick.h"
#include "../../../input_manager/input_manager.h"
#include "../../../Item_manager/item_manager.h"
#include "../../../Item_manager/item/speeddown_item/speeddown_item.h"
#include "../../../Item_manager/item/playerstun_item/playerstun_item.h"
#include "../../unit/enemy/slime/slime.h"
#include "../../../ui_manager/ui_component/item_icon/item_icon.h"
#include "../../../ui_manager/ui_component/stage_pos_bar/stage_pos_bar.h"
#include "../../../ui_manager/ui_component/key_icon/key_icon.h"
#include "../../../common_data/common_data.h"

using namespace GameInputManager;

const float CPlayer::max_speed = 8.0f;//�L�����̃X�s�[�h
const float CPlayer::min_speed = 3.0f;//�L�����̍Œ�X�s�[�h
const float CPlayer::jump = -27.5f;//�L�����̃W�����v
const float CPlayer::width = 60.0f;//�L�����̕�
const float CPlayer::height = 60.0f;//�L�����̍���
const float CPlayer::radius = 30.0f;//�L�����̔��a
const float CPlayer::dash = 1.7f;//�L�����̃_�b�V����
const int CPlayer::max_interval = 10;


CPlayer::CPlayer(aqua::IGameObject* parent)
	:IUnit(parent, "Player")
	, m_pStage(nullptr)
	, m_pCamera(nullptr)
	, m_pUnitManager(nullptr)
	, m_pItemManager(nullptr)
	, m_pGimmick(nullptr)
	, m_pSpeedDownItem(nullptr)
	, m_pStunItem(nullptr)
	, m_pItemIcon(nullptr)
	, m_pCommonData(nullptr)
	, m_State(STATE::START)
	, m_Device(DEVICE_ID::P1)
{
}

void CPlayer::Initialize(const aqua::CVector2& position)
{

	m_pStage = (CStage*)aqua::FindGameObject("Stage");
	m_pUnitManager = (CUnitManager*)aqua::FindGameObject("UnitManager");
	m_pSlime = (CSlime*)aqua::FindGameObject("Slime");
	m_pItemIcon = (CItemIcon*)aqua::FindGameObject("ItemIcon");
	m_pItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");
	m_pCommonData = (CCommonData*)aqua::FindGameObject("CommonData");

	std::string name;

	if (m_Device == DEVICE_ID::P1)
		name = "data//player_1p.png";
	else
		name = "data//player_2p.png";

	m_CharaSprite.Create(name);
	m_CharaSprite.anchor.x = m_CharaSprite.GetTextureWidth() / 2.0f;
	m_CharaSprite.anchor.y = m_CharaSprite.GetTextureHeight() / 2.0f;
	m_Position = position;
	m_Velocity = aqua::CVector2::ZERO;
	m_Width = width;
	m_Height = height;
	m_UnitID = UNIT_ID::PLAYER;
	m_LandingFlag = false;
	m_Accelerator = 0.0f;
	m_Timer = 0;
	m_HitSpikeFlag = false;
	m_HitWireFlag = false;
	m_AddMaxSpeed = 0.0f;
	m_AddKeySpeed = 0.0f;
	m_AddItemSpeed = 1.0f;
	m_AddGimmickSpeed = 1.0f;

	m_HitItemFlag = false;

	m_KeyFlag = false;

	m_GoalFlag = false;

	m_GetItemFlag = false;

	m_KeyCount = 0;

	m_Speed = 0.0f;

	IGameObject::Initialize();
}

void CPlayer::Update()
{
	if (!m_pCamera)
		m_pCamera = (CCameraManager*)aqua::FindGameObject("CameraManager");

	if (m_HitSpikeFlag != true)
	{
		switch (m_State)
		{
		case STATE::START: State_Start(); break;//�J�n�̏��
		case STATE::MOVE: State_Move(); break;//�L��������������
		case STATE::DEAD: State_Dead(); break;//�L���������񂾏��
		case STATE::GOAL: State_Goal(); break;//�L�������S�[���������̏��
		}

		m_PrevPosition = m_Position;

		CheckHitBlock();//�ǂ̓����蔻��
	}

	m_CharaSprite.position = m_Position;// +m_pCamera->GetScroll(m_Device);//�J�����̃X�N���[��

	m_pGimmick = (CGimmickAct*)aqua::FindGameObject("GimmickAct");
	if (m_pGimmick)
	{
		m_pGimmick->DamageAct(this);
		m_pGimmick->SlowAct(this);
		m_pGimmick->JumpAct(this);
	}

	m_pItemManager = (CItemManager*)aqua::FindGameObject("ItemManager");
	if (m_pItemManager)
		m_pItemManager->RandPick(this);

	m_pStageBar = (CStagePosBar*)aqua::FindGameObject("StagePosBar");
	if (m_pStageBar)
		m_pStageBar->Move(this);

	m_pKeyIcon = (CKeyIcon*)aqua::FindGameObject("KeyIcon");
	if (m_pKeyIcon)
	{
		m_pKeyIcon->KeyCount(this);
		m_pKeyIcon->AddKeyCount(this);
	}


	IGameObject::Update();
}

void CPlayer::CheckHitBlock(void)
{
	int x = (int)(m_Position.x);
	int y = (int)(m_Position.y);
	int nx = (int)(m_Position.x + m_Velocity.x);;
	int ny = (int)(m_Position.y + m_Velocity.y);;
	int  w = (int)m_Width;
	int h = (int)m_Height;
	int size = 60;

	if (m_pStage->CheckObject(nx, y)
		|| m_pStage->CheckObject(nx + w - 1, y)
		|| m_pStage->CheckObject(nx, y + h / 2)
		|| m_pStage->CheckObject(nx + w - 1, y + h / 2)
		|| m_pStage->CheckObject(nx, y + h - 1)
		|| m_pStage->CheckObject(nx + w - 1, y + h - 1)
		|| m_pStage->CheckObject_Jamp(nx, y + h - 1)
		|| m_pStage->CheckObject_Jamp(nx + w - 1, y + h - 1))
	{
		// ���Ɉړ����Ă���
		if (m_Velocity.x < 0)
			nx = (nx / size + 1) * size;

		// �E�Ɉړ����Ă���
		if (m_Velocity.x > 0)
			nx = ((nx + w) / size) * size - w;

		// �u���b�N�ɂ������Ă���̂ő��x������
		m_Velocity.x = 0;
	}

	if (m_pStage->CheckGoal(nx, y)
		|| m_pStage->CheckGoal(nx + w - 1, y)
		|| m_pStage->CheckGoal(nx, y + h / 2)
		|| m_pStage->CheckGoal(nx + w - 1, y + h / 2)
		|| m_pStage->CheckGoal(nx, y + h - 1)
		|| m_pStage->CheckGoal(nx + w - 1, y + h - 1))
	{
		m_GoalFlag = true;

		CCommonData::CommonData common_data = m_pCommonData->GetCommonDate();

		common_data.m_device_id = m_Device;

		m_pCommonData->SetDate(&common_data);

	}
	else
	{
		m_GoalFlag = false;
	}

	if (m_pStage->CheckSpike(nx, y)
		|| m_pStage->CheckSpike(nx + w - 1, y)
		|| m_pStage->CheckSpike(nx, y + h / 2)
		|| m_pStage->CheckSpike(nx + w - 1, y + h / 2)
		|| m_pStage->CheckSpike(nx, y + h - 1)
		|| m_pStage->CheckSpike(nx + w - 1, y + h - 1))
	{
		m_HitSpikeFlag = true;
	}
	else
	{
		m_HitSpikeFlag = false;
	}

	if (m_pStage->CheckWire(nx, y)
		|| m_pStage->CheckWire(nx + w - 1, y)
		|| m_pStage->CheckWire(nx, y + h / 2)
		|| m_pStage->CheckWire(nx + w - 1, y + h / 2)
		|| m_pStage->CheckWire(nx, y + h - 1)
		|| m_pStage->CheckWire(nx + w - 1, y + h - 1))
	{
		m_HitWireFlag = true;
	}
	else
	{
		m_HitWireFlag = false;
	}

	if (m_KeyCount >= 1)
	{
		if (m_pStage->CheckItem(nx, y)
			|| m_pStage->CheckItem(nx + w - 1, y)
			|| m_pStage->CheckItem(nx, y + h / 2)
			|| m_pStage->CheckItem(nx + w - 1, y + h / 2)
			|| m_pStage->CheckItem(nx, y + h - 1)
			|| m_pStage->CheckItem(nx + w - 1, y + h - 1)
			&& m_GetItemFlag == false)
		{
			m_HitItemFlag = true;
			m_GetItemFlag = true;
			m_KeyCount -= 1;
		}
		else
		{
			m_HitItemFlag = false;
		}
	}
	else
	{
		m_HitItemFlag = false;
	}

	if (m_pStage->CheckKey(nx, y)
		|| m_pStage->CheckKey(nx + w - 1, y)
		|| m_pStage->CheckKey(nx, y + h / 2)
		|| m_pStage->CheckKey(nx + w - 1, y + h / 2)
		|| m_pStage->CheckKey(nx, y + h - 1)
		|| m_pStage->CheckKey(nx + w - 1, y + h - 1))
	{
		m_KeyFlag = true;
	}
	else
	{
		m_KeyFlag = false;
	}
	
	if (m_LandingFlag == true)
	{
		// �����𒲂ׂău���b�N���Ȃ���Η���
		if (!m_pStage->CheckObject(x, y + h) && !m_pStage->CheckObject(x + w, y + h))

		{
			// �����Ƀu���b�N���Ȃ��̂Œ��n���Ă��Ȃ�
			m_LandingFlag = false;

			// �������n�܂�̂ŃX�s�[�h�������Ă���
			m_Velocity.y = 0;
		}
	}
	// �󒆂ɂ���
	else if (m_LandingFlag == false)
	{
		// �d�͂ŗ���������
		m_Velocity.y += m_pStage->GetGravity();

		// �㉺�̃`�F�b�N
		if (m_pStage->CheckObject(x, ny)
			|| m_pStage->CheckObject(x + w - 1, ny)
			|| m_pStage->CheckObject(x, ny + h - 1)
			|| m_pStage->CheckObject(x + w - 1, ny + h - 1))
		{

			// ��ɓ����Ă���
			if (m_Velocity.y < 0)
				ny = (ny / size + 1) * size;

			// ���ɓ����Ă���
			if (m_Velocity.y > 0)
			{
				ny = ((ny + h) / size) * size - h;

				// ���n����
				m_LandingFlag = true;
			}

			// �u���b�N�ɂ������Ă���̂ő��x������
			m_Velocity.y = 0;
		}

		if (m_pStage->CheckJampRamp(x, ny + h - 1)
			|| m_pStage->CheckJampRamp(x + w - 1, ny + h - 1))
		{
			m_JampRampFlag = true;
		}
		else
		{
			m_JampRampFlag = false;
		}
	}

	// �ʒu�̌���
	m_Position.x = (float)nx;
	m_Position.y = (float)ny;
}

DEVICE_ID CPlayer::GetDeviceID()
{
	return m_Device;
}

void CPlayer::CreateItme(void)
{
}

void CPlayer::Draw()
{
	m_CharaSprite.Draw();//�L�����̕`��
	IGameObject::Draw();
}

void CPlayer::Finalize()
{
	m_CharaSprite.Delete();//�L�����̉��
	IGameObject::Finalize();
}

bool CPlayer::IsDead()
{
	return m_State == STATE::DEAD;
}

bool CPlayer::IsGoal()
{
	return m_State == STATE::GOAL;
}

float CPlayer::GetHitRadius(void)
{
	return radius;
}

void CPlayer::Damage(void)
{
	m_State = STATE::DEAD;
}

//�X�s�[�h�̉��Z
void CPlayer::AddItemSpeed(float add_itme_speed)
{
	m_AddItemSpeed = add_itme_speed;
}

void CPlayer::AddGimmickSpeed(float add_gimmick_speed)
{
	m_AddGimmickSpeed = add_gimmick_speed;
}

void CPlayer::AddKeySpeed(float add_key_speed)
{
	m_AddKeySpeed = add_key_speed;
}

void CPlayer::AddMaxSpeed(float add_max_speed)
{
	m_AddMaxSpeed = add_max_speed;
}

void CPlayer::Jump(void)
{
	if (m_LandingFlag == true)
	{
		m_Velocity.y = jump;
		m_LandingFlag = false;
	}
}

//�J�n�̏��
void CPlayer::State_Start()
{
	m_Position = aqua::CVector2(0.0f, 0.0f);
	m_State = STATE::MOVE;
}

//��������
void CPlayer::State_Move()
{


	float input_x_value = 0.0f;
	float input_move = GetHorizotal(m_Device);

	if (std::abs(input_move) >= 0.7f)
		input_x_value = input_move / std::abs(input_move);

	m_Velocity.x = 0;

	m_Timer += 1;

	m_Velocity.x = min_speed * input_x_value;

	m_CharaSprite.anchor;
	
	m_Speed = max_speed + (m_AddKeySpeed + m_AddItemSpeed);

	if (GameButton(GameKey::X, m_Device))
	{
		if (m_Timer >= max_interval && (m_Accelerator <= m_Speed && m_Accelerator >= -m_Speed))
		{
			m_Accelerator += input_x_value;
			m_Timer = 0;
		}

		m_Velocity.x += m_Accelerator;

	}

	if ((int)input_x_value == 0)
	{
		m_Accelerator = 0;
	}
	int v = m_Position.x - m_PrevPosition.x;

	if (GameTrigger(GameKey::A, m_Device))
	{
		Jump();
	}


	//if (m_GetItemFlag == true)
	//{

	//}
	if (Button(m_Device, BUTTON_ID::LEFT_SHOULDER) || Button(aqua::keyboard::KEY_ID::I) && m_GetItemFlag == true)
	{

		if (m_Device == DEVICE_ID::P1)
		{
			if (m_pItemManager->m_ItemRand == 0)
			{
			m_pItemManager->Create(ITEM_ID::SPEEDDOWN);
			m_pSpeedDownItem = (CSpeedDownItem*)aqua::FindGameObject("SpeedDownItem");
			m_pSpeedDownItem->Initialize(DEVICE_ID::P2);

			m_pSpeedDownItem->SpeedDown();
			m_GetItemFlag = false;
			m_pItemIcon = (CItemIcon*)aqua::FindGameObject("ItemIcon");
			}
			else
			{
			m_pItemManager->Create(ITEM_ID::PLAYERSTUN);
			m_pStunItem = (CPlayerStunItem*)aqua::FindGameObject("StunItem");
			m_pStunItem->Initialize(DEVICE_ID::P2);

			m_pStunItem->PlayerStun();
			m_GetItemFlag = false;
			m_pItemIcon = (CItemIcon*)aqua::FindGameObject("ItemIcon");
			}

			if (m_pItemIcon)
				m_pItemIcon->DeleteItem(this);
		}
		else if (m_Device == DEVICE_ID::P2)
		{
			if (m_pItemManager->m_ItemRand == 0)
			{
			m_pItemManager->Create(ITEM_ID::SPEEDDOWN);
			m_pSpeedDownItem = (CSpeedDownItem*)aqua::FindGameObject("SpeedDownItem");
			m_pSpeedDownItem->Initialize(DEVICE_ID::P1);

			m_pSpeedDownItem->SpeedDown();
			m_GetItemFlag = false;
			m_pItemIcon = (CItemIcon*)aqua::FindGameObject("ItemIcon");
			}
			else
			{
			m_pItemManager->Create(ITEM_ID::PLAYERSTUN);
			m_pStunItem = (CPlayerStunItem*)aqua::FindGameObject("StunItem");
			m_pStunItem->Initialize(DEVICE_ID::P1);

			m_pStunItem->PlayerStun();
			m_GetItemFlag = false;
			m_pItemIcon = (CItemIcon*)aqua::FindGameObject("ItemIcon");
			}

			if (m_pItemIcon)
				m_pItemIcon->DeleteItem(this);
		}
	}

	m_Velocity.x = m_Velocity.x * m_AddItemSpeed * m_AddGimmickSpeed;

	if (m_Velocity.x >= 6.0f && -6.0f >= m_Velocity.x)
	{
		if (m_pSlime)
			m_pSlime->Damage();
	}
}

void CPlayer::State_Dead()
{
}

void CPlayer::State_Goal()
{

}
