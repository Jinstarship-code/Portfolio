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
#include "Jelly.h"
#include "Obstacle1.h"
#include "Obstacle2.h"
#include "Obstacle3.h"
#include "SliverCoin.h"
#include "Pause_Button.h"

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
	
	m_ImageList["Player"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Player.bmp");
	m_ImageList["Ground"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Ground2.bmp");
	m_ImageList["Jelly"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Jelly1.bmp");
	m_ImageList["Obstacle1"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Obstacle1.bmp");
	//m_ImageList["HPBar"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/HpBar.bmp");
	m_ImageList["SliverCoin"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/SliverCoin.bmp");
	m_ImageList["Pause_Button"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Stage/Pause_Button.bmp");
	m_ImageList["Backbuffer"] = (new Bitmap)->LoadBmp(L"../Resource/Image/Backbuffer.bmp");
	//�÷��̾� ������ ������Ʈ �Ŵ����� �߰�

	Object* pPlayer = ObjectFactory<Player>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pPlayer->GetKey(), pPlayer);
	
	Object* pGround = ObjectFactory<Ground>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pGround->GetKey(), pGround);

	

	/*****************
	BaseJelly ������Ʈ ����
	******************/

	for (int i = 0; i < 8; i++)
	{
		Object* pJelly = ObjectFactory<Jelly>::CreateObject(
		1000.f+53*i,534.f);
	
		//500,400,53,50

		//�ٴ��� ��ġ y = 625.f

		ObjectManager::GetInstance()->AddObject(pJelly->GetKey(), pJelly);
	}


	//ù��° �ǹ� ����.
	for (int i = 0; i < 6; i++)
	{
		if (i<2||i>3)
		{
			Object* pSliverCoin = ObjectFactory<SliverCoin>::CreateObject(
				1421 + 50.f * i, 534.f);

			ObjectManager::GetInstance()->AddObject(pSliverCoin->GetKey(), pSliverCoin);
		}
		else
		{
			Object* pSliverCoin = ObjectFactory<SliverCoin>::CreateObject(
				1421 + 50.f * i, 434.f);

			ObjectManager::GetInstance()->AddObject(pSliverCoin->GetKey(), pSliverCoin);
		}

	}

	//�ι�° ��������.
	for (int i = 0; i < 13; i++)
	{
		Object* pJelly = ObjectFactory<Jelly>::CreateObject(
			1720.f + 53 * i, 534.f);

		//500,400,53,50

		//�ٴ��� ��ġ y = 625.f

		ObjectManager::GetInstance()->AddObject(pJelly->GetKey(), pJelly);
	}

	//2��° �ǹ�����
	for (int i = 0; i < 6; i++)
	{
		if (i < 2 || i>3)
		{
			Object* pSliverCoin = ObjectFactory<SliverCoin>::CreateObject(
				2409 + 50.f * i, 534.f);

			ObjectManager::GetInstance()->AddObject(pSliverCoin->GetKey(), pSliverCoin);
		}
		else
		{
			Object* pSliverCoin = ObjectFactory<SliverCoin>::CreateObject(
				2409 + 50.f * i, 434.f);

			ObjectManager::GetInstance()->AddObject(pSliverCoin->GetKey(), pSliverCoin);
		}

	}


	//����° ��������.
	for (int i = 0; i < 13; i++)
	{
		Object* pJelly = ObjectFactory<Jelly>::CreateObject(
			2710.f + 53 * i, 534.f);

		//500,400,53,50

		//�ٴ��� ��ġ y = 625.f

		ObjectManager::GetInstance()->AddObject(pJelly->GetKey(), pJelly);
	}


	/********************
	Obstacle1 ������Ʈ ����.
	*********************/

	for (int i = 0; i < 3; i++)
	{
		Object* pObstacle1 = ObjectFactory<Obstacle1>::CreateObject(
			1540.f + 1000 * i, 526.f);

		ObjectManager::GetInstance()->AddObject(pObstacle1->GetKey(), pObstacle1);
	}




	/*Object* pHPBar = ObjectFactory<HPBar>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pHPBar->GetKey(), pHPBar);*/

	Object* pPause_Button = ObjectFactory<Pause_Button>::CreateObject();
	ObjectManager::GetInstance()->AddObject(pPause_Button->GetKey(), pPause_Button);

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
		SRCCOPY);	// ��� ����
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
