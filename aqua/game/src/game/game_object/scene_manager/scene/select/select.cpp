#include "select.h"
#include "select_stage_box/select_stage_box.h"
#include <filesystem>

namespace file_s = std::filesystem;

const float CSelect::m_max_scale = 2.5f;
const float CSelect::m_min_scale = 2.0f;

CSelect::CSelect(aqua::IGameObject* parent)
	:IScene(parent, "Select", SCENE_ID::GAME, CHANGE_SCENE_ID::SLIDE_CLOSE)
{
}

void CSelect::Initialize()
{

	m_BackGround.Create("data\\リザルト.png");

	// ファイルの取得
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

		if (m_SelectBoxSize == aqua::CVector2::ZERO)
			m_SelectBoxSize = select->GetObjectSize();

		aqua::CVector2 pos(aqua::GetWindowSize() / 2);

		pos.x += j * select->GetObjectSize().x;

		select->SetUp((pos - size), "Stage" + std::to_string(j), file);

		m_SelectStageBoxList.push_back(&select);

		++j;

		file = "data\\scene\\game\\map_data" + std::to_string(j) + ".csv";

	}

	m_MaxStage = (int)m_SelectStageBoxList.size();
}

void CSelect::Update()
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
		m_ChangeSceneFlag = true;
}

void CSelect::Draw()
{
	m_BackGround.Draw();

	IScene::Draw();

}

void CSelect::Finalize()
{
	m_BackGround.Delete();
	IScene::Finalize();
}
