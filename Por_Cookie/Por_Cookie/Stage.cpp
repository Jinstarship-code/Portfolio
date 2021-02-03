#include "Stage.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Bitmap.h"
#include "BitmapManager.h"
#include "BackGround.h"
#include "Ground.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize(void)
{
	//플레이어 생성후 오브젝트 매니저에 추가
	Object* pPlayer = ObjectFactory<Player>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pPlayer->GetKey(), pPlayer);

	Object* pGround = ObjectFactory<Ground>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pGround->GetKey(), pGround);
	//Object::SetImageList(&m_ImageList);
}

int Stage::Progress(void)
{
	ObjectManager::GetInstance()->Progress();
	return 0;
}

void Stage::Render(HDC _hdc)
{
	//ObjectManager::GetInstance()->Render(m_ImageList["Backbuffer"]->GetMemDC());

	ObjectManager::GetInstance()->Render(_hdc);
}

void Stage::Release(void)
{
	ObjectManager::GetInstance()->Release();
}
