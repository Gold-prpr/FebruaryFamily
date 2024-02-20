#pragma once
#include "aqua.h"

class IItem
	:public aqua::IGameObject
{
public:
	////ƒRƒ“ƒXƒgƒ‰ƒNƒ^
	IItem(aqua::IGameObject* parent, const std::string& name);

	//ƒfƒXƒgƒ‰ƒNƒ^
	virtual ~IItem(void) = default;

	//‰Šú‰»
	void Initialize(aqua::CVector2 position ,std::string item_file);

	virtual void Initialize(aqua::CVector2 position) = 0;

	//XV
	virtual void Update()override;

	//•`‰æ
	virtual void Draw()override;

	//‰ğ•ú
	virtual void Finalize()override;

	//ƒAƒCƒeƒ€‚ÌˆÊ’u
	const aqua::CVector2& GetPosition();

<<<<<<< HEAD
=======

	aqua::CSprite				m_ItemSprite;	//ƒAƒCƒeƒ€•`‰æ
<<<<<<< HEAD
>>>>>>> 6d8c1b073599bafcac7a7c5c76a0c3664e308d4b
private:
	aqua::CSprite				m_ItemSprite;		//ƒAƒCƒeƒ€•`‰æ
=======

	bool				m_ItemFlag;		//ƒAƒCƒeƒ€Œø‰Ê’†
protected:

	aqua::CTimer		m_EffectTimer;
>>>>>>> origin/æˆ‘ã€æ–°ä¸–ç•Œä¹‹ç‹ã€€KAWAGISINï½æ¯è¦ªã®ãƒ‘ãƒ³ãƒ„ã‚’æ·»ãˆã¦ï½
};