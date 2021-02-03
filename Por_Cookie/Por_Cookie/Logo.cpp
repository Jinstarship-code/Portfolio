#include "Logo.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Bitmap.h"
#include "BitmapManager.h"
#include "SceneManager.h"
#include "BackGround.h"
#include "InputManager.h"

Logo::Logo()
{
}

Logo::~Logo()
{
	Release();
}

void Logo::Initialize(void)
{
	string strKey = "BackGround_1";

	m_pBackGround = ObjectFactory<BackGround>::CreateObject(0, 0, strKey);

	m_pImageList = BitmapManager::GetInstance()->GetImageList();


	m_pImageList->insert(make_pair(strKey, (new Bitmap)->LoadBmp(L"../Resource/Image/Common/Background/01.bmp")));

	m_pImageList->insert(
		make_pair("Backbuffer", (new Bitmap)->LoadBmp(L"../Resource/Image/Backbuffer.bmp")));


	Object::SetImageList(m_pImageList);
}

int Logo::Progress(void)
{
	m_pBackGround->Progress();

	ObjectManager::GetInstance()->Progress();

	DWORD dwKey = InputManager::GetInstance()->GetKey();
	if (dwKey & KEY_LBUTTON || dwKey & KEY_RETURN)
	{
		SceneManager::GetInstance()->SetScene(SCENE_MENU);
		
	}
	return 0;
}

void Logo::Render(HDC _hdc)
{
	m_pBackGround->Render((*m_pImageList)["BackGround_1"]->GetMemDC());

	ObjectManager::GetInstance()->Render((*m_pImageList)["BackGround_1"]->GetMemDC());


	BitBlt(_hdc, 0, 0, WINSIZEX, WINSIZEY,			
		(*m_pImageList)["BackGround_1"]->GetMemDC(),	
		0, 0, SRCCOPY);	
}


/*
BitBlt( _In_ HDC hdc,		사본 DC
_In_ int x, _In_ int y,		사본 비트맵에 원본 그림이 복사될 시작좌표
_In_ int cx, _In_ int cy,   width,heighm
_In_opt_ HDC hdcSrc,		원본 DC
_In_ int x1, _In_ int y1,	원본 그림에서 복사를 시작할 좌표
_In_ DWORD rop);			그림을 복사하는 방법을 설정 SRCCOPY(원본 그대로)
*/
void Logo::Release(void)
{
	delete m_pBackGround;
	m_pBackGround = NULL;
}
