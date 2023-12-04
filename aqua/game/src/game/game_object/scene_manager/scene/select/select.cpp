#include "select.h"
#include "select_stage_box/select_stage_box.h"
#include "../../../input_manager/input_manager.h"
#include "../../../common_data/common_data.h"
#include <fstream>
#include <filesystem>

namespace file_s = std::filesystem;
namespace g_input = GameInputManager;
namespace g_controller = aqua::controller;

const float CSelect::m_max_scale = 2.5f;
const float CSelect::m_min_scale = 2.0f;
const float CSelect::m_distance = 200.0f;
const float CSelect::m_max_time = 0.5f;
const int   CSelect::m_max_low_select = 1;

CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, "Select", SCENE_ID::GAME, CHANGE_SCENE_ID::SLIDE_CLOSE)
	, m_SelectNowStageNam(0)
	, m_SelectPrivStageNam(0)
	, m_CountLowSpeed(0)
{
}

/*
*  初期化
*/
void CSelect::Initialize()
{
	m_CommonDataClass = (CCommonData*)aqua::FindGameObject("CommonData");

	// 存在するファイル名を検索
	std::string file;

	int j = 0;
	file = "data\\scene\\game\\map_data" + std::to_string(j) + ".csv";

	while (file_s::exists(file))
	{
		CSelectStageBox* select = nullptr;

		select = aqua::CreateGameObject<CSelectStageBox>(this);

		select->Initialize();

		select->SetSize(aqua::CVector2::ONE * m_min_scale);

		aqua::CVector2 size = select->GetObjectSize() / 2.0f;

		aqua::CVector2 pos(aqua::GetWindowSize() / 2);

		pos.x += j * select->GetObjectSize().x + j * m_distance;

		select->SetUp((pos - size), "Stage" + std::to_string(j), file);

		m_SelectStageBoxList.push_back(select);

		++j;

		file = "data\\scene\\game\\map_data" + std::to_string(j) + ".csv";

	}

	m_BackGround.Create(m_SelectStageBoxList[0]->GetStageBackGrondPath());

	m_MaxStage = (int)m_SelectStageBoxList.size();

	// 時間の設定
	m_SelectSpeed.Setup(m_max_time);

}

/*
*  更新
*/
void CSelect::Update()
{
	// ステージの決定
	if (g_input::GameTrigger(g_input::GameKey::A, g_controller::DEVICE_ID::P1) ||
		g_input::GameTrigger(g_input::GameKey::A, g_controller::DEVICE_ID::P2) || 
		aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
	{
		// シーンの移動
		m_ChangeSceneFlag = true;

		CCommonData::CommonData data = m_CommonDataClass->GetCommonDate();

		data.stage_name = m_SelectStageBoxList[m_SelectNowStageNam]->GetStageName();

		m_CommonDataClass->SetDate(&data);
	}

	// ステージの選択
	if (std::abs(g_input::GetHorizotal(g_controller::DEVICE_ID::P1)) >= 0.8f ||
		std::abs(g_input::GetHorizotal(g_controller::DEVICE_ID::P2)) >= 0.8f)
	{
		float botton =
			g_input::GetHorizotal(g_controller::DEVICE_ID::P1) +
			g_input::GetHorizotal(g_controller::DEVICE_ID::P2);

		int add = 0;

		add = (int)(botton / std::abs(botton));

		if (m_CountLowSpeed == m_max_low_select)
		{
			if (m_SelectSpeed.GetLimit() != m_max_time)
				m_SelectSpeed.SetLimit(m_max_time);
		}
		else
		{
			if (m_SelectSpeed.GetLimit() != m_max_time / 5.0f)
				m_SelectSpeed.SetLimit(m_max_time / 5.0f);
		}

		if (m_SelectSpeed.Finished())
		{
			m_CountLowSpeed++;
			m_SelectNowStageNam = aqua::Mod(m_SelectNowStageNam + add, 0, m_MaxStage - 1);
			m_SelectSpeed.Reset();
		}


		int j = 0;

		// 選択欄の移動
		for (auto& it : m_SelectStageBoxList)
		{
			int center_priv_dis = j - m_SelectPrivStageNam;
			int center_dis = j - m_SelectNowStageNam;

			if (center_dis == 0)
			{

				it->SetSize(aqua::CVector2::ONE * m_max_scale);

				m_BackGround.Delete();
				m_BackGround.Create(it->GetStageBackGrondPath());
				m_BackGround.ApplyGaussFilter(32, 800);

			}
			else
			{
				it->SetSize(aqua::CVector2::ONE * m_min_scale);
			}

			aqua::CVector2 size = it->GetObjectSize() / 4.0f;

			aqua::CVector2 start_pos(aqua::GetWindowSize() / 2);
			aqua::CVector2 gool_pos(aqua::GetWindowSize() / 2);

			start_pos.x += center_priv_dis * it->GetObjectSize().x + center_priv_dis * m_distance;
			gool_pos.x += center_dis * it->GetObjectSize().x + center_dis * m_distance;

			aqua::CVector2 now_pos;

			now_pos.x =
				aqua::easing::InBounce
				(
					m_SelectSpeed.GetTime(),
					m_SelectSpeed.GetLimit(),
					start_pos.x,
					gool_pos.x
				);

			now_pos.y = gool_pos.y;

			it->SetPosition(now_pos - size);

			j++;
		}

		m_SelectSpeed.Update();
	}
	else
	{
		m_SelectSpeed.Reset();
		m_CountLowSpeed = 0;
	}

	

	m_SelectPrivStageNam = m_SelectNowStageNam;

}

/*
*  描画
*/
void CSelect::Draw()
{
	m_BackGround.Draw();

	IScene::Draw();

}

/*
*  解放
*/
void CSelect::Finalize()
{
	m_BackGround.Delete();
	IScene::Finalize();
}