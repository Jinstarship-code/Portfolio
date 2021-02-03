#include "Menu.h"
#include "ObjectFactory.h"
#include "ObjectManager.h"
#include "Bitmap.h"
#include "BitmapManager.h"
#include "BackGround.h"
#include "SceneManager.h"
Menu::Menu()
{
}

Menu::~Menu()
{
}

void Menu::Initialize(void)
{
	string strKey = "BackGround_1";

    m_pBackGround = ObjectFactory<BackGround>::CreateObject(0, 0);

    m_pImageList = BitmapManager::GetInstance()->GetImageList();

	m_pImageList->insert(make_pair(strKey, (new Bitmap)->LoadBmp(L"../Resource/Image/Menu/MenuBack.bmp")));

	Object::SetImageList(m_pImageList);

}

int Menu::Progress(void)
{
    m_pBackGround->Progress();

    for (int i = 0; i < m_pButtonList.size(); i++)
    {
        int iResult = m_pButtonList[i]->Progress();


		if (iResult == 1)
		{
			SceneManager::GetInstance()->SetScene(SCENE_STAGE);
			return 0;
		}
		else if (iResult == 2)
		{
			return 0;
		}
		else if (iResult == 3)
		{
			DestroyWindow(g_hWnd);
			return 0;
		}
    }
    return 0;
}

void Menu::Render(HDC _hdc)
{
	m_pBackGround->Render((*m_pImageList)["BackGround_1"]->GetMemDC());

	for (int i = 0; i < m_pButtonList.size(); i++)
		m_pButtonList[i]->Render((*m_pImageList)["BackGround_1"]->GetMemDC());

	BitBlt(_hdc,
		0, 0,
		WINSIZEX, WINSIZEY,
		(*m_pImageList)["BackGround_1"]->GetMemDC(),
		0, 0,
		SRCCOPY);

	
}

void Menu::Release(void)
{
}
