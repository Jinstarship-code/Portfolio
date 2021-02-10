#include "Stage.h"

#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Player.h"
#include "Ground.h"

#include "Bitmap.h"
#include "BitmapManager.h"
#include "BackGround.h"
#include "BackGround.h"
#include "HPBar.h"

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
	strKey.push_back(48 +1); //48�� �ƽ�Ű�ڵ� 0��.

	m_pBackGround[0] = ObjectFactory<BackGround>::CreateObject(0, 0, strKey);
	m_pBackGround[1] = ObjectFactory<BackGround>::CreateObject(WINSIZEX, 0, strKey);


	/*********************************
	   **  Stage image is insert. **
	**********************************/
	
		TCHAR pBuffer[128];

		wsprintf(pBuffer, TEXT("../Resource/Image/Stage/%02d.bmp"), 1);

		string str = "BackGround_";
		str.push_back(48+1);

		m_ImageList[str] = (new Bitmap)->LoadBmp(pBuffer);
	
	m_ImageList["Backbuffer"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Backbuffer.bmp");

	m_ImageList["Ground"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Ground1.bmp");

	m_ImageList["Player"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player.bmp");

	
	//�÷��̾� ������ ������Ʈ �Ŵ����� �߰�
	
	Object* pGround = ObjectFactory<Ground>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pGround->GetKey(), pGround);

	Object* pPlayer = ObjectFactory<Player>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pPlayer->GetKey(), pPlayer);

	Object* pHPBar = ObjectFactory<HPBar>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pHPBar->GetKey(), pHPBar);

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
	m_pBackGround[1]->Render(m_ImageList["Backbuffer"]->GetMemDC());
	//** �������� �̹����� ��µ� ���� ���� ������Ʈ �̹����� �����.
	ObjectManager::GetInstance()->Render(m_ImageList["Backbuffer"]->GetMemDC());

	//** ���� �̹����� HDC�� �����.
	BitBlt(_hdc,	//** �׸��� �׷� ������
		0,	//** �̹����� ��µ� ������ X
		0,	//** �̹����� ��µ� ������ Y
		WINSIZEX, WINSIZEY,				//** ������ �̹����� ũ�⸸ŭ ����
		m_ImageList["Backbuffer"]->GetMemDC(),	//** ������ �̹���
		0, 0,	// ��� ������ ��ǥ
		SRCCOPY);	// ���� ����

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