#include "Logo.h"
#include "Button.h"
#include "InputManager.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Bitmap.h"
#include "BitmapManager.h"
#include "SceneManager.h"
#include "SoundManager.h"
#include "BackGround.h"
#include "LogoObject.h"

Logo::Logo()
{
}

Logo::~Logo()
{
	Release();
}

void Logo::Initialize(void)
{
	string strKey = "BackGround_";
	strKey.push_back(48 + (rand() % 4 + 1));

	m_pBackGround[0] = ObjectFactory<BackGround>::CreateObject(0,0,strKey);

	m_pImageList = BitmapManager::GetInstance()->GetImageList();

	for (int i = 1; i < 5; i++)
	{
		TCHAR pBuffer[128];
		wsprintf(pBuffer, TEXT("../Resource/Image/Logo/MainScene.bmp"), i);

		string str = "BackGround_";
		str.push_back(48 + i);
		
		m_pImageList->insert(make_pair(str, (new Bitmap)->LoadBmp(pBuffer)));
	}

	m_pImageList->insert(
		make_pair("Backbuffer", (new Bitmap)->LoadBmp(L"../Resource/Image/Backbuffer.bmp")));


	/*m_pImageList->insert(
		make_pair("StartButton",)*/
	
	Object::SetImageList(m_pImageList);

	SoundManager::GetInstance()->OnPlaySound("Logo", SOUND_CHANNEL_ID_LOGO);

}

void Logo::Progress(void)
{

	for (int i =0 ; i < 2; i++)
		m_pBackGround[i]->Progress();

	ObjectManager::GetIsntance()->Progress();

	DWORD dwKey = InputManager::GetInstance()->GetKey();

	if (dwKey & KEY_RETURN || dwKey & KEY_ESCAPE)
		SceneManager::GetInstance()->SetScene(SCENE_MENU);


}

void Logo::Render(HDC _hdc)
{
	for (int i = 0; i < 2; i++)
		m_pBackGround[i]->Render((*m_pImageList)["Backbuffer"]->GetMemDC());
	ObjectManager::GetIsntance()->Render((*m_pImageList)["Backbuffer"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WINSIZEX, WINSIZEY,
		(*m_pImageList)["Backbuffer"]->GetMemDC(),
		0, 0,
		SRCCOPY);

}

void Logo::Release(void)
{
	for (int i = 0; i < 2; i++)
	{
		delete m_pBackGround[i];
		m_pBackGround[i] == NULL;
	}
}
