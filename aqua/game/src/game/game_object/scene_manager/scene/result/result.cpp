#include "result.h"
#include "../../../common_data/common_data.h"

using namespace aqua::controller;

CResult::CResult(aqua::IGameObject* parent)
	:IScene(parent,"Result",SCENE_ID::TITLE,CHANGE_SCENE_ID::SLIDE_CLOSE)
{
}

void CResult::Initialize()
{
	IScene::Initialize();
	m_GameSoundClass->Play(SOUND_ID::RESULT);

	m_pCommonData = (CCommonData*)aqua::FindGameObject("CommonData");

	int player = (int)(m_pCommonData->GetCommonDate().m_device_id) + 1;

	m_WinPlayerLabel.Create(100);
	m_WinPlayerLabel.text = "プレイヤー" + std::to_string(player) + "の勝ちです";
	m_WinPlayerLabel.position.x = (float)(aqua::GetWindowSize().x - m_WinPlayerLabel.GetTextWidth()) / 2.0f;
	m_WinPlayerLabel.position.y = (float)(aqua::GetWindowSize().x - m_WinPlayerLabel.GetFontHeight()) / 2.0f;

	m_BackGround.Create("data\\リザルト.png");
}

void CResult::Update()
{
	if (aqua::keyboard::Trigger(aqua::keyboard::KEY_ID::RETURN))
		m_ChangeSceneFlag = true;

	if (Trigger(DEVICE_ID::P1, BUTTON_ID::A) || Trigger(DEVICE_ID::P2, BUTTON_ID::A))
		m_ChangeSceneFlag = true;
}

void CResult::Draw()
{
	m_BackGround.Draw();

	m_WinPlayerLabel.Draw();
}

void CResult::Finalize()
{
	m_BackGround.Delete();

	m_GameSoundClass->Stop(SOUND_ID::RESULT);
}
