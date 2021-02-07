#include "Stage.h"

#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Ground.h"

#include "Bitmap.h"
#include "BitmapManager.h"
#include "BackGround.h"
#include "BackGround.h"

Stage::Stage()
{
}

Stage::~Stage()
{
	Release();
}

void Stage::Initialize(void)
{
	string strKey = "BackGround_";
	strKey.push_back(48 + (rand()%2+1)); //48이 아스키코드 0임.

	m_pBackGround[0] = ObjectFactory<BackGround>::CreateObject(0, 0, strKey);
	m_pBackGround[1] = ObjectFactory<BackGround>::CreateObject(WINSIZEX, 0, strKey);


	/*********************************
	   **  Stage image is insert. **
	**********************************/
	for (int i = 1; i < 2; i++)
	{
		TCHAR pBuffer[128];

		wsprintf(pBuffer, TEXT("../Resource/Image/Stage/%02d.bmp"), i);

		string str = "BackGround_";
		str.push_back(48+i);

		m_ImageList[str] = (new Bitmap)->LoadBmp(pBuffer);
	}


	m_ImageList["Ground"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Ground1.bmp");

	m_ImageList["Player"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player.bmp");
	m_ImageList["Backbuffer"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Backbuffer.bmp");
	//플레이어 생성후 오브젝트 매니저에 추가
	
	Object* pGround = ObjectFactory<Ground>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pGround->GetKey(), pGround);

	Object* pPlayer = ObjectFactory<Player>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pPlayer->GetKey(), pPlayer);

	
	Object* pBackGround = ObjectFactory<BackGround>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pBackGround->GetKey(), pBackGround);
	
	Object::SetImageList(&m_ImageList);
}

int Stage::Progress(void)
{
	for (int i = 0; i < 2; i++)
		m_pBackGround[i]->Progress();

	ObjectManager::GetInstance()->Progress();
	return 0;
}

void Stage::Render(HDC _hdc)
{
	for(int i=0;i<2;i++)
		m_pBackGround[i]->Render(m_ImageList["Backbuffer"]->GetMemDC());
	//** 스테이지 이미지가 출력된 버퍼 위에 오브젝트 이미지를 출력함.
	ObjectManager::GetInstance()->Render(m_ImageList["Backbuffer"]->GetMemDC());

	//** 최종 이미지를 HDC에 출력함.
	BitBlt(_hdc,	//** 그림을 그려 넣을곳
		0,	//** 이미지가 출력될 시작점 X
		0,	//** 이미지가 출력될 시작점 Y
		WINSIZEX, WINSIZEY,				//** 복사할 이미지의 크기만큼 복사
		m_ImageList["Backbuffer"]->GetMemDC(),	//** 복사할 이미지
		0, 0,	// 출력 시작점 좌표
		SRCCOPY);	// 고속 복사

	ObjectManager::GetInstance()->Render(_hdc);
}

void Stage::Release(void)
{
	for (int i = 0;i < 2; i++)
	{
		delete m_pBackGround[i];
		m_pBackGround[i] = NULL;
	}

	ObjectManager::GetInstance()->Release();
}
