#pragma once
#include "aqua.h"
#include "stage_object/stage_object.h"

class CPlayer;
class CUnitManager;
class CStageObject;
class IUnit;
class CCommonData;

class CStage
	: public aqua::IGameObject
{
public:

	//ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	CStage(aqua::IGameObject* parent);
	//ƒfƒXƒgƒ‰ƒNƒ^
	~CStage() = default;

	//‰Šú‰»
	void Initialize(void);
	//XV
	void Update(void);
	//•`‰æ
	void Draw(void);
	//‰ğ•ú
	void Finalize(void);

	// ƒXƒNƒ[ƒ‹‚Ìİ’è
	void SetScroll(aqua::CVector2 scroll);

	//CSV“Ç‚İ‚İ
	void Parse(const std::string& file_name);

	float GetMapWidth(void);

	float GetMapHeight(void);

	//d—Í
	float GetGravity(void);

	bool CheckObject(int x, int y, StageObjectID id);

	bool CheckObject_Jamp(int x, int y, StageObjectID id);

	bool CheckObject(int x, int y);

	void ChangeAir(int x, int y, StageObjectID id);

	bool CheckObject_Jamp(int x, int y);

	//ƒS[ƒ‹”»’è
	bool CheckGoal(int x, int y);

	//ƒAƒCƒeƒ€”»’è
	bool CheckItem(int x, int y);

	bool CheckSpike(int x, int y);

	bool CheckJampRamp(int x, int y);

	bool CheckDushBrock(int x, int y);

	bool CheckKey(int x, int y);

	//—Lh“Sü”»’è
	bool CheckWire(int x, int y);

	aqua::CVector2 GetGoalPos(void);

	aqua::CVector2 m_Scroll;

private:
	static const int map_chip_size;			//TileƒTƒCƒY
	static const int num_chip_size_x;		//Tile‰æ‘œ‚Ì‰¡‚Ì”
	static const int num_chip_size_y;		//Tile‰æ‘œ‚Ìc‚Ì”
	static const int all_num_chip;			//Tile‚Ì‡Œv
	static const float m_gravity;			//d—Í

	std::vector<CStageObject*> m_StageObject;

	aqua::CSprite              m_BackGround;

	aqua::CVector2 m_GoalPos;

	aqua::CVector2 m_MapPos;

	int map_x;					//ƒ}ƒbƒv‚Ì‰¡‚Ìƒ^ƒCƒ‹‚Ì”
	int map_y;					//ƒ}ƒbƒv‚Ìc‚Ìƒ^ƒCƒ‹‚Ì”

	int m_MapTileX;
	int m_MapTileY;

<<<<<<< HEAD
	CUnitManager* m_UnitManager;
=======
	CPlayer* m_pPlayer;

	CCommonData* m_CommonData;
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
};